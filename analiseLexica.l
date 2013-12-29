%option main
 #include <stdio.h>

letra [a-zA-Z]+
digito [0-9]+
reservada else|if|int|return|void|while|str
simbolo "+"|"-"|"*"|"/"|"<"|"<="|">"|">="|"=="|"!="|"="|";"|","|"("|")"|"["|"]"|"{"|"}"

ID {letra}{letra}*
NUM {digito}{digito}*
ERRID (simbolo|{letra}|{digito})(simbolo|{letra}|{digito})+


%x COM 
%x STR

%%

"/*" 		{	/*inicio de comentário*/
			printf("COM: ");		
			BEGIN( COM );
		}

["]		{	/*inicio da string*/
			printf("STR: ");
			BEGIN( STR );
		}

.|\n|\r		{/*faz nada*/}

<COM>"*/"	{	/*fim do comentário*/
			BEGIN( INITIAL );
			putchar('\n');}

<STR>["]	{	/*fim da string*/
			putchar('\n');
			BEGIN( INITIAL );			
		}	

<STR>\\["]	{putchar('"');}

<COM>.|\n|\r	{ECHO;}

<STR>.		{ECHO;}

{reservada}	{printf("reservada: %s\n", yytext);}
{simbolo}	{printf("simbolo: %s",yytext);}

{ID}		{printf("ID: %s\n", yytext);}
{NUM}		{printf("NUM: %s\n", yytext);}
{ERRID}		{printf("ERRID: %s\n", yytext);}
