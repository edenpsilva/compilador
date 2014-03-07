int a;
void b;

int func(){
	/*aqui uma string nÃ£o fechada causa um erro atÃ© as prÃ³ximas aspas ou fim de linha... tudo fica bagunÃ§ado*/
	b = "uma string dando trabalho
	a = 27;
	/*a seguir, mais um erro semÃ¢ntico, nada de errado do ponto de vista sintÃ¡tico ou lÃ©xico.*/
	a = "minha \t \" string";
	
	b = "mais uma string nÃ£o fechada; b = "aqui a gente vai ter um monte de identificadores perdidos por causa das aspas faltantes" /*e, por fim, uma string nÃ£o fechada*/
}
