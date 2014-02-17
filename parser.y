%{

#include "abstrata.h"
#include "abstrataf.h"


void yyerror(char *s);

%}

%expect 1

%union {
	int ival; char *sval; 
	A_programa t_programa;
	A_declaracao_lista t_declaracao_lista;
	A_declaracao t_declaracao;
	A_var_declaracao t_var_declaracao;
	A_fun_declaracao t_fun_declaracao;
	A_params t_params;
	A_param_lista t_param_lista;
	A_param t_param;
	A_composto_decl t_composto_decl;
	A_local_declaracoes t_local_declaracoes;
	A_statement_lista t_statement_lista;
	A_statement t_statement;
	A_expressao_decl t_expressao_decl;
	A_selecao_decl t_selecao_decl;
	A_iteracao_decl t_iteracao_decl;
	A_return_decl t_return_decl;
	A_expressao t_expressao;
	A_var t_var;
	A_simples_expressao t_simples_expressao;
	A_soma_expressao t_soma_expressao;
	A_termo t_termo;
	A_fator t_fator;
	A_ativacao t_ativacao;
	A_args t_args;
	A_arg_lista t_arg_lista;
	A_vazio t_vazio;
	A_soma t_soma;
	A_mult t_mult;
	A_tipo_especificador t_tipo_especificador;
	A_relacional t_relacional;

	};

%token ELSE
%token IF
%token RETURN
%token WHILE 
%token ATRIBUICAO
%token PONTOEVIRGULA
%token VIRGULA 
%token ABREPARENTESE
%token FECHAPARENTESE
%token ABRECOLCHETE 
%token FECHACOLCHETE 
%token ABRECHAVE 
%token FECHACHAVE 
%token T_INT
%token T_VOID 
%token T_STRING
%token MAIS 
%token MENOS 
%token MULT 
%token DIV 
%token MENOR
%token MENORIGUAL
%token MAIOR
%token MAIORIGUAL
%token IGUAL 
%token DIFERENTE
%token <sval> STR 
%token <sval> ID 
%token <ival> NUM

%type <t_programa> programa
%type <t_declaracao_lista> declaracao_lista
%type <t_declaracao> declaracao
%type <t_var_declaracao> var_declaracao
%type <t_fun_declaracao> fun_declaracao
%type <t_params> params
%type <t_param_lista> param_lista
%type <t_param> param
%type <t_composto_decl> composto_decl
%type <t_local_declaracoes> local_declaracoes
%type <t_statement_lista> statement_lista
%type <t_statement> statement
%type <t_expressao_decl> expressao_decl
%type <t_selecao_decl> selecao_decl
%type <t_iteracao_decl> iteracao_decl
%type <t_return_decl> return_decl
%type <t_expressao> expressao
%type <t_var> var
%type <t_simples_expressao> simples_expressao
%type <t_soma_expressao> soma_expressao
%type <t_termo> termo
%type <t_fator> fator
%type <t_ativacao> ativacao
%type <t_args> args
%type <t_arg_lista> arg_lista
%type <t_tipo_especificador> tipo_especificador
%type <t_relacional> relacional
%type <t_soma> soma
%type <t_mult> mult



%start programa

%%

programa :
		declaracao_lista {$$ = A_Programa($1);}
	 ;

declaracao_lista: 
		declaracao_lista declaracao {$$ = A_ListaDeclaracao_lista($1, $2);} |
		 declaracao {$$ = A_SimplesDeclaracao_lista($1);};

declaracao: 
		var_declaracao {$$ = A_VarDeclaracao_lista($1);}|
 		fun_declaracao {$$ = A_FunDeclaracao_lista($1);}
	;

var_declaracao:
	tipo_especificador ID PONTOEVIRGULA {$$ = A_IdentVar_declaracao($1, $2);} |
	tipo_especificador ID ABRECOLCHETE NUM FECHACOLCHETE PONTOEVIRGULA 
			{$$ = A_IdentnumVar_declaracao($1, $2, $4);} 
	;

tipo_especificador: T_INT {$$ = A_int;}| T_VOID {$$ = A_void;}| T_STRING {$$ = A_string;};

fun_declaracao:
	tipo_especificador ID ABREPARENTESE params FECHAPARENTESE composto_decl
	{$$ = A_Fun_declaracao($1, $2, $4, $6);}
	;

params:
	param_lista {$$ = A_ListaParams($1);}|T_VOID {$$ = A_VoidParams(A_void);}
	;

param_lista: 
	param_lista VIRGULA param {$$ = A_ListaParam_lista($1, $3);}|
	param {$$ = A_SimplesParam_simples($1);} 
	;


param :
	tipo_especificador ID {$$ = A_NormalParam($1,$2);}|
	tipo_especificador ID ABRECOLCHETE FECHACOLCHETE {$$ = A_ParamParam($1, $2);}
	;

composto_decl:
	ABRECHAVE local_declaracoes statement_lista FECHACHAVE {$$ = A_Composto_decl($2, $3);}
	;

local_declaracoes: 
	local_declaracoes var_declaracao {$$ = A_Lista_Local_declaracoes($1, $2);}|
	{$$ = A_NadaLocal_declaracoes(A_Vazio());}
	;

statement_lista:
	statement_lista statement{$$ = A_ListaStatement_lista($1, $2);}
	|{$$ = A_NadaStatement_lista(A_Vazio()) ;}
		
	;

statement:
	expressao_decl {$$ = A_ExpressaoStatement_lista($1);}|
	composto_decl {$$ = A_CompostoStatement_lista($1);}|
	selecao_decl {$$ = A_SelecaoStatement_lista($1);}|
	iteracao_decl {$$ = A_IteracaoStatement_lista($1);}|
	return_decl {$$ = A_ReturnStatement_lista($1);}
	;
expressao_decl:
	expressao PONTOEVIRGULA {$$ = A_ListaExpressao_decl($1);}|
	PONTOEVIRGULA {$$ = A_NadaExpressao_decl();}
	;

selecao_decl:
	IF ABREPARENTESE expressao FECHAPARENTESE statement {$$ = A_IFSelecao_decl($3, $5);}|
	IF ABREPARENTESE expressao FECHAPARENTESE statement ELSE statement {$$ = A_IF_ELSESelecao_decl($3, $5, $7);}
	;

iteracao_decl:
	WHILE ABREPARENTESE expressao FECHAPARENTESE statement {$$ = A_Iteracao_decl($3, $5);}
	;

return_decl:
	RETURN PONTOEVIRGULA {$$ =A_SemexpReturn_decl();}|
	RETURN expressao PONTOEVIRGULA {$$ = A_ComexpReturn_decl($2);}
	;


expressao:
	var ATRIBUICAO expressao {$$ = A_AtribExpressao($1, $3);}|
	simples_expressao {$$ = A_SimpExpressao($1);}
	;


var:
	ID {$$ = A_IdentVar($1);}|
	ID ABRECOLCHETE expressao FECHACOLCHETE {$$ = A_AtribVar($1, $3);}
	;


simples_expressao:
	soma_expressao relacional soma_expressao {$$ = A_RelacionalSimples_expressao($1, $2, $3);}|
	soma_expressao {$$ = A_Simples_expressao($1);}
	;

relacional: 	
		MENOR {$$ = A_menor;}|
		MENORIGUAL {$$ = A_menorigual;}|
		MAIOR {$$ = A_maior;}| 
		MAIORIGUAL {$$ = A_maiorigual;}|
		IGUAL {$$ = A_igual;}|
		DIFERENTE {$$ = A_diferente;}
	;

soma_expressao:
	soma_expressao soma termo {$$ = A_ListaSoma_expressao($1, $2, $3);}|
	termo {$$ = A_Soma_expressao($1);}
	;


soma: MAIS {$$ = A_mais;}| MENOS {$$ = A_menos;};


termo:
	termo mult fator {$$ = A_MultTermo($1, $2, $3);}|
	fator {$$ = A_FatorTermo($1);}
	;

mult: MULT {$$ = A_multip;}| DIV {$$ = A_div;};

fator:
	ABREPARENTESE expressao FECHAPARENTESE {$$ = A_ExpressaoFator($2);}|
	var {$$ = A_VarFator($1);}|
	ativacao {$$ = A_AtivacaoFator($1);}|
	NUM {$$ = A_NumFator($1);}|
	STR{$$ = A_StrFator($1);}
	;


ativacao:
	ID ABREPARENTESE args FECHAPARENTESE {$$ = A_Ativacao($1, $3);}
	;

args:
	arg_lista {$$ = A_ListaArgs($1);}|{$$ = A_VazioArgs(A_Vazio());}
	;

arg_lista:
	arg_lista VIRGULA expressao {$$ = A_ListaArg_lista($1, $3);}|
	expressao {$$ = A_ExpressaoArg_lista($1);}
	;


%%

#include <stdlib.h>
#include <stdio.h>

void yyerror(char *s){
	fprintf(stderr, "Erro Sintático!\t:(\n");
	exit(1);
}

main(){
	yyparse();
	fprintf(stderr, "Sem Erros sintaticos!\t:)\n");
	return 0;
}
