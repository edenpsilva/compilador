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



%%




"/*" 		{	/*comentário*/
				int numCOM = 1;
				register char c;
				
		 
		        for ( ; ; ){
		        	while ( ((c = input()) != '*') && (c !='/') && c != EOF )
				    	;

				    if ( c == '*' ){
				    	while ( (c = input()) == '*' )
				    	    ;
				        if ( (c == '/') ){
							numCOM--;
							if ( numCOM == 0){
								printf("COM ");
								break;
							}	
						}
					
					}

					/*comentário aninhado*/
					if (c =='/'){
							if( (c = input()) == '*'){
							numCOM++;
						}	
					}
					
					/*comentário se marcador de final e fim de arquivo*/						 
				    if ( c == EOF ){
				    	printf( "ERRO(EOF em comentário)" );
				      	break;
				    }
		        }
            }


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

<<EOF>>		{puts("\n");return ;}
