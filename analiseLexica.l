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

aspa \\["]

exp1 ([^"\n]?*)
exp2 (\\t|\\n|\\\")?*

STR \"({exp1}|{exp2})?*\"
ERRSTR \"({exp1}|{exp2})?*

espaco " "
ESPACO {espaco}|\t|\n|\r

ERRO .|({ID}|{NUM})+ 

%{
	int numCOM;
%}

%x COM

%%

{LCOM} 		{	/*inicio de comentário*/
			numCOM = 1;

			BEGIN( COM );
		}


<COM>{LCOM}	{	/*comentário aninhado*/
			numCOM++;
			/*putchar('/');
			putchar('*');*/
		}

<COM>{RCOM}	{	numCOM--;
			if (numCOM == 0){/*fim de comentário*/				
				BEGIN( INITIAL );
				printf("COM\n");		
				/*putchar('\n');
				putchar(')');
				printf(" ");*/

			}else{ /*ainda há comentarios aninhados*/
				/*putchar('*');
				putchar('/');*/
			}
		}

<COM>.|\n|\t		{}
<COM><<EOF>>	{	BEGIN( INITIAL );
			printf("ERROCOM- não fechou comentario\n");			
		}


{STR}		{printf("STR(%s)\n",yytext);}
{ERRSTR}	{printf("ERRSTR->String sem aspas: %s\n",yytext);}

{ELSE}		{printf("ELSE\n");}
{IF} 		{printf("IF\n");}
{INT} 		{printf("INT\n");}
{RETURN}	{printf("RETURN\n");}
{VOID} 		{printf("VOID\n");}
{WHILE} 	{printf("WHILE\n");}
{STRING}	{printf("STRING\n");}

{PLUS} 		{printf("PLUS\n");}
{MENOS}		{printf("MENOS\n");}
{MULT} 		{printf("MULT\n");} 
{DIV} 		{printf("DIV\n");}


{MENOR} 	{printf("MENOR\n");}
{MENORIGUAL}	{printf("MENORIGUAL\n");}
{MAIOR}		{printf("MAIOR\n");}
{MAIORIGUAL}	{printf("MAIORIGUAL\n");}
{EQUIVALE}	{printf("EQUIVALE\n");}
{DIFERENTE} 	{printf("DIFERENTE\n");}


{ATRIB}		{printf("ATRIB\n");}


{EOC}		{printf("EOC\n");}


{VIRG} 		{printf("VIRG\n");}


{LPARENT} 	{printf("LPARENT\n");}
{RPARENT} 	{printf("RPARENT\n");}


{LCOLC}		{printf("LCOLC\n");}
{RCOLC}		{printf("RCOLC\n");}


{LCHAVE}	{printf("LCHAVE\n");}
{RCHAVE}	{printf("RCHAVE\n");}


{ID}		{printf("ID(%s)\n", yytext);}
{NUM}		{printf("NUM(%s)\n", yytext);}


{ESPACO}	{/*faz nada, pois encontra espaço ou quebra de linha*/}

{ERRO}		{printf("ERRO(%s)", yytext);printf("\n");}
