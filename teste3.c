int variavel[42];
/*o identificador abaixo nÃ£o Ã© vÃ¡lido*/
int minha_var;

/*abaixo temos um erro sintÃ¡tico, mas nÃ£o lÃ©xico*/
int main({
	/*a seguir, um erro semÃ¢ntico, mas nada de errado do ponto de vista lÃ©xico*/
	variavel = 1234;
	/*agora a gente tem um erro lÃ©xico*/
	variavel = 12ab;
	/*e isso tambÃ©m Ã© um erro lÃ©xico*/
	minha_var = "12";
	/*e mais um erro lÃ©xico /*esquecendo de fechar um dos comentÃ¡rios*/
	/*o mesmo vale para strings*/*/
}
