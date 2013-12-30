%option main
 #include <stdio.h>

letra [a-zA-Z]+
digito [0-9]+
reservada else|if|int|return|void|while|str
simbolo "+"|"-"|"*"|"/"|"<"|"<="|">"|">="|"=="|"!="|"="|";"|","|"("|")"|"["|"]"|"{"|"}"

espaço \ 
ID {letra}{letra}*
NUM {digito}{digito}*
ERRID [{simbolo}{digito}{letra}]({simbolo}|{digito}|{letra})*

%{/*numero de comentários*/
	int numCOM = 0;
%}

%x COM 
%x STR

%%

"/*" 		{	/*inicio de comentário*/
			numCOM = 1;
			printf("COM: ");		
			BEGIN( COM );
		}

["]		{	/*inicio da string*/
			printf("STR: ");
			BEGIN( STR );
		}

.|\n|\r		{/*faz nada*/}


<COM>"*/"	{	numCOM--;
			if (numCOM == 0){
				/*fim do comentário*/
				BEGIN( INITIAL );
				putchar('\n');
			}else{ /*ainda há comentarios aninhados*/
				putchar('*');
				putchar('/');
			}

		}

<COM>"/*"	{	
			/*comentário aninhado*/
			numCOM++;
			/*para imprimir o comentário*/
			putchar('/');
			putchar('*');
		}	

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
