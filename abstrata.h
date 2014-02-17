#ifndef ABSTRATA_H
#define ABSTRATA_H

typedef struct A_programa_ *A_programa;
typedef struct A_declaracao_lista_ *A_declaracao_lista;
typedef struct A_declaracao_ *A_declaracao;
typedef struct A_var_declaracao_ *A_var_declaracao;
typedef struct A_fun_declaracao_ *A_fun_declaracao;
typedef struct A_params_ *A_params;
typedef struct A_param_lista_ *A_param_lista;
typedef struct A_param_ *A_param;
typedef struct A_composto_decl_ *A_composto_decl;
typedef struct A_local_declaracoes_ *A_local_declaracoes;
typedef struct A_statement_lista_ *A_statement_lista;
typedef struct A_statement_ *A_statement;
typedef struct A_expressao_decl_ *A_expressao_decl;
typedef struct A_selecao_decl_ *A_selecao_decl;
typedef struct A_iteracao_decl_ *A_iteracao_decl;
typedef struct A_return_decl_ *A_return_decl;
typedef struct A_expressao_ *A_expressao;
typedef struct A_var_ *A_var;
typedef struct A_simples_expressao_ *A_simples_expressao;
typedef struct A_soma_expressao_ *A_soma_expressao;
typedef struct A_simples_expressao_ *A_simples_expressao;
typedef struct A_soma_expressao_ *A_soma_expressao;
typedef struct A_termo_ *A_termo;
typedef struct A_fator_ *A_fator;
typedef struct A_ativacao_ *A_ativacao;
typedef struct A_args_ *A_args;
typedef struct A_arg_lista_ *A_arg_lista;
typedef struct A_vazio_ *A_vazio;

typedef enum {A_igual, A_diferente, A_menor, A_menorigual, A_maior, A_maiorigual} A_relacional;
typedef enum {A_mais, A_menos} A_soma;
typedef enum {A_multip, A_div} A_mult;
typedef enum {A_int, A_string, A_void} A_tipo_especificador;

/*
programa:
	declaracao_lista	
	;
*/
struct A_programa_ { A_declaracao_lista declaracao_lista;};
A_programa A_Programa(A_declaracao_lista declaracao_lista);

/*
declaracao_lista:
	declaracao_lista declaracao|
	declaracao
	; 
*/
struct A_declaracao_lista_ {enum {dl_lista, dl_simples} kind;
			union {struct {A_declaracao_lista declaracao_lista; 
					A_declaracao declaracao;} lista;
				 struct {A_declaracao declaracao;} simples;
				} u;
			};
A_declaracao_lista A_ListaDeclaracao_lista(A_declaracao_lista declaracao_lista, A_declaracao declaracao);
A_declaracao_lista A_SimplesDeclaracao_lista(A_declaracao declaracao);

/*
declaracao:
	var_declaracao | 
	fun_declaracao
	;

*/
struct A_declaracao_ {enum {tipo_var, tipo_fun} kind;
			union {struct {A_var_declaracao var_declaracao;} var;
				 struct {A_fun_declaracao fun_declaracao;} fun;
				} u;
			};

A_declaracao A_VarDeclaracao_lista(A_var_declaracao var_declaracao);
A_declaracao A_FunDeclaracao_lista(A_fun_declaracao fun_declaracao);

/*
var_declaracao:
	tipo_especificador T_ID PONTOEVIRGULA |
	tipo_especificador T_ID ABRECOLCHETE T_NUM FECHACOLCHETE PONTOEVIRGULA
	;
*/
struct A_var_declaracao_ { enum{tipo_ID,  tipo_ID_NUM} kind;
			union {struct {A_tipo_especificador tipo; char* id;} ident;
				 struct {A_tipo_especificador tipo; char* id; int num;} identnum;
				} u;
			};

A_var_declaracao A_IdentVar_declaracao(A_tipo_especificador tipo, char* id );
A_var_declaracao A_IdentnumVar_declaracao(A_tipo_especificador tipo, char* id, int num);


/*
fun_declaracao:
	tipo_especificador ID ABREPARENTESES params FECHAPARENTESES composto_decl
	;
*/
struct A_fun_declaracao_ { A_tipo_especificador tipo; char* id; A_params params; A_composto_decl composto_decl; };

A_fun_declaracao A_Fun_declaracao(A_tipo_especificador tipo, char* id, A_params params, A_composto_decl composto_decl);

/*
params:
	param_lista | 
	T_VOID
	;
*/
struct A_params_ {enum {p_lista, p_void} kind;
			union {struct {A_param_lista param_lista;} lista;
				 A_tipo_especificador tp_void;
				} u;
			};

A_params A_ListaParams(A_param_lista param_lista);	
A_params A_VoidParams(A_tipo_especificador tp_void);	

/*

param_lista: 
	param_lista VIRGULA param |
	param
	;
*/
struct A_param_lista_ {enum {pl_lista, pl_simples} kind;
			union {struct {A_param_lista param_lista; A_param param;} lista;
				 struct {A_param param;} simples;
				} u;
			};

A_param_lista A_ListaParam_lista(A_param_lista param_lista, A_param param);	
A_param_lista A_SimplesParam_simples(A_param param);	


/*
param :
	tipo_especificador ID |
	tipo_especificador ID ABRECOLCHETE FECHACOLCHETE
	;
*/
struct A_param_ {enum {normal, param} kind;
		union{		
			struct {A_tipo_especificador tipo; char* id;} normal;
			struct {A_tipo_especificador tipo; char* id;} param;
			} u;		
		};


A_param A_NormalParam(A_tipo_especificador tipo, char* id);
A_param A_ParamParam(A_tipo_especificador tipo, char* id);

/*
composto_decl:
	ABRECHAVE local_declaracoes statement_lista FECHACHAVE FECHACHAVE
	;
*/
struct A_composto_decl_ {A_local_declaracoes local_declaracoes; 
			A_statement_lista statement_lista;
			};

A_composto_decl A_Composto_decl(A_local_declaracoes local_declaracoes, A_statement_lista statement_lista);	

/*
local_declaracoes: 
	local_declaracoes var_declaração |
	vazio	
	;
*/
struct A_local_declaracoes_ {enum {l_lista, l_vazio} kind;
			union {struct {A_local_declaracoes local_declaracoes; A_var_declaracao var_declaracao;} lista;
				 struct {A_vazio vazio;} nada;
				} u;
			};

A_local_declaracoes A_Lista_Local_declaracoes(A_local_declaracoes local_declaracoes, A_var_declaracao var_declaracao);	
A_local_declaracoes A_NadaLocal_declaracoes(A_vazio vazio);

/*
statement_lista:
	statement_lista statement|
	vazio	
	;
*/
struct A_statement_lista_{enum {s_lista, s_vazio} kind;
			union {struct {A_statement_lista statement_lista; A_statement statement;} 					lista;
				 struct {A_vazio vazio;} vazio;
				} u;
			};

A_statement_lista A_ListaStatement_lista(A_statement_lista statement_lista, A_statement statement);
A_statement_lista A_NadaStatement_lista(A_vazio vazio);

/*
statement:
	expressao_decl |
	composto_decl |
	selecao_decl |
	iteracao_decl |
	return_decl
	;

*/
struct A_statement_ {enum {tipo_expressao_decl, tipo_composto_decl, tipo_selecao_decl, tipo_iteracao_decl, tipo_return_decl} kind;
			union {	 struct {A_expressao_decl expressao_decl;} expressao;
				 struct {A_composto_decl composto_decl;} composto;
				 struct {A_selecao_decl selecao_decl;} selecao;
				 struct {A_iteracao_decl iteracao_decl;} iteracao;
				 struct {A_return_decl return_decl;} t_return;
				} u;
			};

A_statement A_ExpressaoStatement_lista(A_expressao_decl expressao_decl);
A_statement A_CompostoStatement_lista(A_composto_decl composto_decl);	
A_statement A_SelecaoStatement_lista(A_selecao_decl selecao_decl);
A_statement A_IteracaoStatement_lista(A_iteracao_decl iteracao_decl);	
A_statement A_ReturnStatement_lista(A_return_decl return_decl);

/*
expressao_decl:
	expressao PONTOEVIRGULA |
	PONTOEVIRGULA
	;

*/
struct A_expressao_decl_ {enum { ed_lista, ed_vazio} kind;
				union {struct {A_expressao expressao;} lista;
					A_vazio nada;
					} u;
			};

A_expressao_decl A_ListaExpressao_decl(A_expressao expressao);	
A_expressao_decl A_NadaExpressao_decl();

/*
selecao_decl:
	IF LPARENT expressao RPARENT statement |
	IF LPARENT expressao RPARENT statement ELSE statement
	;
*/
struct A_selecao_decl_ {enum { selecao_decl_IF, selecao_decl_IF_ELSE} kind;
			union {struct {A_expressao expressao; A_statement statement;} selecaoIF;
				 struct {A_expressao expressao; A_statement statementIF; A_statement 							statementELSE;} selIF_ELSE;
				} u;
			};

A_selecao_decl A_IFSelecao_decl(A_expressao expressao, A_statement statement);	
A_selecao_decl A_IF_ELSESelecao_decl(A_expressao expressao, A_statement statementIF, A_statement statementELSE);

/*
iteracao_decl:
	WHILE LPARENT expressao RPARENT statement
	;
*/
struct A_iteracao_decl_{A_expressao expressao; A_statement statement;};

A_iteracao_decl A_Iteracao_decl(A_expressao expressao, A_statement statement);


/*
return_decl:
	RETURN PONTOEVIRGULA |
	RETURN expressao PONTOEVIRGULA
	;
*/
struct A_return_decl_{enum { cExpressao, sExpressao} kind;
			union {struct {A_expressao expressao;} comExpressao;
				 A_vazio semExpressao;
				} u;
			};	
A_return_decl A_ComexpReturn_decl(A_expressao expressao);	
A_return_decl A_SemexpReturn_decl();


/*
expressao:
	var ATRIBUICAO expressao |
	simples_expressao
	;
*/
struct A_expressao_ {enum { e_atribuicao, e_simples} kind;
			union {struct {A_var var ; A_expressao expressao;} atribuicao;
				 struct {A_simples_expressao simples_expressao; } simples;
				} u;
			};	
A_expressao A_AtribExpressao(A_var var, A_expressao expressao);	
A_expressao A_SimpExpressao(A_simples_expressao simples_expressao);

/*var:
	ID |
	ID ABRECOLCHETE expressao FECHACOLCHETE
	;
*/
struct A_var_{enum { v_ident, v_atrib} kind;
			union { struct {char* id; } ident;
				struct {char* id ; A_expressao expressao;} atrib;
				} u;
			};	

A_var A_IdentVar(char* id);
A_var A_AtribVar(char* id, A_expressao expressao);	

/*
simples_expressao:
	soma_expressao relacional soma_expressao |
	soma_expressao
	;

*/

struct A_simples_expressao_{enum { se_relacional, se_simples} kind;
			union { struct { A_soma_expressao expressao1;
					A_relacional op_relacional;
					A_soma_expressao expressao2;  
					} relacional;
				struct {A_soma_expressao expressao;} simples;
				} u;
			};	

A_simples_expressao A_RelacionalSimples_expressao(A_soma_expressao expressao1, A_relacional op_relacional, A_soma_expressao expressao2);
A_simples_expressao A_Simples_expressao(A_soma_expressao expressao);

/*
soma_expressao:
	soma_expressao soma termo |
	termo
	;

*/
struct A_soma_expressao_{enum { sm_lista, sm_simples} kind;
			union { struct { A_soma_expressao soma_expressao; A_soma op_soma;	
				 A_termo termo; }lista;
				struct {A_termo termo;} simples;
				} u;
			};	

A_soma_expressao A_ListaSoma_expressao(A_soma_expressao soma_expressao,A_soma op_soma, A_termo termo);
A_soma_expressao A_Soma_expressao(A_termo termo);

/*
termo:
	termo mult fator |
	fator
	;

*/
struct A_termo_{enum { t_lista, t_simples} kind;
			union { struct { A_termo termo; A_mult op_mult; A_fator fator;}lista;
				struct {A_fator fator;} simples;
				} u;
			};	

A_termo A_MultTermo(A_termo termo, A_mult op_mult, A_fator fator);
A_termo A_FatorTermo(A_fator fator);

/*
fator:
	ABREPARENTESES expressao FECHAPARENTESES |
	var |
	ativacao |
	NUM	
	;
*/
struct A_fator_{enum { f_expressao, f_var, f_ativacao, f_num, f_str} kind;
			union { struct { A_expressao expressao;}expressao;
				struct {A_var var;} var;
				struct {A_ativacao ativacao;} ativacao;
				struct {int num;} num;
				struct {char *str;} str;
				} u;
			};	

A_fator A_ExpressaoFator(A_expressao expressao);
A_fator A_VarFator(A_var var);
A_fator A_AtivacaoFator(A_ativacao ativacao);
A_fator A_NumFator(int num);
A_fator A_StrFator(char * str);
/*
ativacao:
	ID ABREPARENTESES args FECHAPARENTESES
	;

*/


struct A_ativacao_{char* id; A_args args;};

A_ativacao A_Ativacao(char* id, A_args args);

/*
args:
	arg_lista |
	vazio
	;
*/
struct A_args_{enum { a_lista, a_vazio } kind;
			union { struct { A_arg_lista arg_lista;} lista;
				struct {A_vazio vazio;} vazio;
				} u;
			};	

A_args A_ListaArgs(A_arg_lista arg_lista);
A_args A_VazioArgs(A_vazio vazio);


/*
arg_lista:
	arg_lista VIRGULA expressao |
	expressao
	;
*/
struct A_arg_lista_{enum { al_lista, al_expressao } kind;
			union { struct { A_arg_lista arg_lista; A_expressao expressao;} lista;
				struct {A_expressao expressao;} expressao;
				} u;
			};	

A_arg_lista A_ListaArg_lista(A_arg_lista arg_lista, A_expressao expressao);
A_arg_lista A_ExpressaoArg_lista(A_expressao expressao);


/*vazio*/
struct A_vazio_ {};

A_vazio A_Vazio();


#endif
