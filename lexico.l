%option noyywrap
 
   

ELSE else
IF if
INT int
RETURN return
VOID void
WHILE while
STRING str


MAIS [+]
MENOS [-]
MULT [*] 
DIV [/]


MENOR <
MENORIGUAL <=
MAIOR >
MAIORIGUAL >=
IGUAL ==
DIFERENTE !=


ATRIBUICAO =


PONTOEVIRGULA ;


VIRGULA ,


ABREPARENTESE [(]
FECHAPARENTESE [)]


ABRECOLCHETE [[]
FECHACOLCHETE []]


ABRECHAVE [{]
FECHACHAVE [}]

ABRECOMENTARIO "/*"
FECHACOMENTARIO "*/"


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
vazio \

%{
	#include "abstrata.h"
	#include "parser.h"
	#include <stdio.h>
	
	int numCOM;
%}

%x COM

%%

{ABRECOMENTARIO} 		{	/*inicio de comentário*/
			numCOM = 1;

			BEGIN( COM );
		}


<COM>{ABRECOMENTARIO}	{	/*comentário aninhado*/
			numCOM++;
			/*putchar('/');
			putchar('*');*/
		}

<COM>{FECHACOMENTARIO}	{	numCOM--;
			if (numCOM == 0){/*fim de comentário*/				
				BEGIN( INITIAL );
				printf("COMENTARIO ");
			}
		}

<COM>.|\n|\t	{}
<COM><<EOF>>	{	BEGIN( INITIAL );{printf("Erro lexico!COM ");}
			
		}


{STR}		{printf("STR ");return STR;}
{ERRSTR}	{printf("ERROSRT");}

{ELSE}		{printf("ELSE ");return IF;}
{IF} 		{printf("IF ");return ELSE;}
{INT} 		{printf("INT ");return T_INT;}
{RETURN}	{printf("RETURN ");return RETURN;}
{VOID} 		{printf("VOID ");return T_VOID;}
{WHILE} 	{printf("WHILE ");return WHILE;}
{STRING}	{printf(" STRING ");return T_STRING;}

{MAIS} 		{printf("MAIS "); return MAIS;}
{MENOS}		{printf("MENOS ");return MENOS;}
{MULT} 		{printf("MULT ");return MULT;} 
{DIV} 		{printf("DIV ");return DIV;}


{MENOR} 	{printf("MENOR");return MENOR;}
{MENORIGUAL}	{printf("MENORIGUAL");return MENORIGUAL;}
{MAIOR}		{printf("MAIOR ");return MAIOR;}
{MAIORIGUAL}	{printf("MAIORIGUAL ");return MAIORIGUAL;}
{IGUAL}		{printf("IGUAL");return IGUAL;}
{DIFERENTE} 	{printf("DIFERENTE");return DIFERENTE;}


{ATRIBUICAO}		{printf("ATRIBUICAO ");return ATRIBUICAO;}


{PONTOEVIRGULA}		{printf("PONTOEVIRGULA ");return PONTOEVIRGULA;}


{VIRGULA} 		{printf("VIRGULA ");return VIRGULA;}


{ABREPARENTESE} 	{printf("ABREPARENTESE ");return ABREPARENTESE;}
{FECHAPARENTESE} 	{printf("FECHAPARENTESE ");return FECHAPARENTESE;}


{ABRECOLCHETE}		{printf("ABRECOLCHETE ");return ABRECOLCHETE;}
{FECHACOLCHETE}		{printf("FECHACOLCHETE ");return FECHACOLCHETE;}


{ABRECHAVE}	{printf("ABRECHAVE ");return ABRECHAVE;}
{FECHACHAVE}	{printf("FECHACHAVE ");return FECHACHAVE;}

{ID}		{printf("ID ");return ID;}
{NUM}		{printf("NUM ");return NUM;}


{ESPACO}	{/*faz nada, pois encontra espaço ou quebra de linha*/}

{ERRO}		{printf ("Erro lexico!");}
