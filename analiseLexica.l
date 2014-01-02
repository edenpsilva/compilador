%option main
 #include <stdio.h>


ELSE else
IF if
INT int
RETURN return
VOID void
WHILE while
STRING str


PLUS [+]
MENOS [-]
MULT [*] 
DIV [/]


MENOR <
MENORIGUAL <=
MAIOR >
MAIORIGUAL >=
EQUIVALE ==
DIFERENTE !=


ATRIB =


EOC ;


VIRG ,


LPARENT [(]
RPARENT [)]


LCOLC [[]
RCOLC []]


LCHAVE [{]
RCHAVE [}]

LCOM "/*"
RCOM "*/"


letra [a-zA-Z]
ID {letra}{letra}*


digito [0-9]
NUM {digito}{digito}*


espaco " "
ESPACO {espaco}|\t|\n|\r


ERRO .|({ID}|{NUM})+


S ["]([^\\"]|\\([^0-7xX]|0|[0-7]{3}|[xX][0-9a-fA-F]{2}))*["]


%{/*numero de comentários*/
	int numCOM = 0;
%}


%x COM 
%x STR


%%

{LCOM} 		{	/*inicio de comentário*/
			numCOM = 1;
			printf("COM(");		
			BEGIN( COM );
		}


<COM>{RCOM}	{	numCOM--;
			if (numCOM == 0){
				/*fim de comentário*/
				BEGIN( INITIAL );
				/*putchar('\n');*/
				putchar(')');
				printf(" ");

			}else{ /*ainda há comentarios aninhados*/
				putchar('*');
				putchar('/');
			}
		}

<COM>{LCOM}	{	
			/*comentário aninhado*/
			numCOM++;
			/*para imprimir o comentário*/
			putchar('/');
			putchar('*');
		}
	
<COM>.|\n|\r	{ECHO;}


<STR>["]	{	/*fim da string*/
			/*putchar('\n');*/
			putchar(')');
			printf(" ");
			BEGIN( INITIAL );			
		}
	
<STR>^[{ql}]	{ECHO;}

<STR>\\["]	{putchar('"');}


{ELSE}		{printf("ELSE");printf(" ");}
{IF} 		{printf("IF");printf(" ");}
{INT} 		{printf("INT");printf(" ");}
{RETURN}	{printf("RETURN");printf(" ");}
{VOID} 		{printf("VOID");printf(" ");}
{WHILE} 	{printf("WHILE");printf(" ");}
{STRING}	{printf("STRING");printf(" ");}

{PLUS} 		{printf("PLUS");printf(" ");}
{MENOS}		{printf("MENOS");printf(" ");}
{MULT} 		{printf("MULT");printf(" ");} 
{DIV} 		{printf("DIV");printf(" ");}


{MENOR} 	{printf("MENOR");printf(" ");}
{MENORIGUAL}	{printf("MENORIGUAL");printf(" ");}
{MAIOR}		{printf("MAIOR");printf(" ");}
{MAIORIGUAL}	{printf("MAIORIGUAL");printf(" ");}
{EQUIVALE}	{printf("EQUIVALE");printf(" ");}
{DIFERENTE} 	{printf("DIFERENTE");printf(" ");}


{ATRIB}		{printf("ATRIB");printf(" ");}


{EOC}		{printf("EOC");printf(" ");}


{VIRG} 		{printf("VIRG");printf(" ");}


{LPARENT} 	{printf("LPARENT");printf(" ");}
{RPARENT} 	{printf("RPARENT");printf(" ");}


{LCOLC}		{printf("LCOLC");printf(" ");}
{RCOLC}		{printf("RCOLC");printf(" ");}


{LCHAVE}	{printf("LCHAVE");printf(" ");}
{RCHAVE}	{printf("RCHAVE");printf(" ");}


{ID}		{printf("ID(%s)", yytext);printf(" ");}
{NUM}		{printf("NUM(%s)", yytext);printf(" ");}


{ESPACO}	{/*faz nada, pois encontra espaço ou quebra de linha*/}

{ERRO}		{printf("ERRO(%s)", yytext);printf(" ");}

<<EOF>>		{puts("\n"); return ;}
