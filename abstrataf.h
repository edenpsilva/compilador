#include <stdlib.h>
#include "abstrata.h"

/*
struct A_programa_ { A_declaracao_lista declaracao_lista;};
A_programa A_Programa(A_declaracao_lista declaracao_lista);

*/
A_programa A_Programa(A_declaracao_lista declaracao_lista){
	A_programa p = malloc(sizeof(*p));
	p->declaracao_lista = declaracao_lista;
	return p;
}

/*
struct A_declaracao_lista {enum {dl_lista, dl_simples} kind;
			union {struct {A_declaracao_lista declaracao_lista; 
					A_declaracao declaracao;} lista;
				 struct {A_declaracao declaracao;} simples;
				} u;
			};
A_declaracao_lista A_ListaDeclaracao_lista(A_declaracao_lista declaracao_lista, A_declaracao declaracao);
A_declaracao_lista A_SimplesDeclaracao_lista(A_declaracao declaracao);
*/
A_declaracao_lista A_ListaDeclaracao_lista(A_declaracao_lista declaracao_lista, A_declaracao declaracao){
	A_declaracao_lista dl = malloc(sizeof(*dl));
	dl->u.lista.declaracao_lista = declaracao_lista;
	dl->u.lista.declaracao = declaracao;
	dl->kind = dl_lista;
	return dl;
}

A_declaracao_lista A_SimplesDeclaracao_lista(A_declaracao declaracao){
	A_declaracao_lista dl = malloc(sizeof(*dl));
	dl->u.simples.declaracao = declaracao;
	dl->kind = dl_simples;
	return dl;

}
/*
struct A_declaracao {enum {tipo_var, tipo_fun} kind;
			union {struct {A_var_declaracao var_declaracao;} var;
				 struct {A_fun_declaracao fun_declaracao;} fun;
				} u;
			};

A_declaracao A_VarDeclaracao_lista(A_var_declaracao var_declaracao);
A_declaracao A_FunDeclaracao_lista(A_fun_declaracao fun_declaracao);

*/
A_declaracao A_VarDeclaracao_lista(A_var_declaracao var_declaracao){
	A_declaracao d = malloc(sizeof(*d));
	d->u.var.var_declaracao = var_declaracao;
	d->kind = tipo_var;
	return d;

}

A_declaracao A_FunDeclaracao_lista(A_fun_declaracao fun_declaracao){
	A_declaracao d = malloc(sizeof(*d));
	d->u.fun.fun_declaracao = fun_declaracao;
	d->kind = tipo_fun;
	return d;
}


/*
struct A_var_declaracao_ { enum{tipo_ID,  tipo_ID_NUM} kind;
			union {struct {A_tipo_especificador tipo; char* id;} ident;
				 struct {A_tipo_especificador tipo; char* id; int num;} identnum;
				} u;
			};

A_var_declaracao A_IdentVar_declaracao(A_tipo_especificador tipo, char* id );
A_var_declaracao A_IdentnumVar_declaracao(A_tipo_especificador tipo, char* id, int num);

*/

A_var_declaracao A_IdentVar_declaracao(A_tipo_especificador tipo, char* id ){
	A_var_declaracao vd = malloc(sizeof(*vd));
	vd->u.ident.tipo = tipo;
	vd->u.ident.id = id;
	vd->kind = tipo_ID;
	return vd;
}

A_var_declaracao A_IdentnumVar_declaracao(A_tipo_especificador tipo, char* id, int num){
	A_var_declaracao vd = malloc(sizeof(*vd));
	vd->u.identnum.id = id;
	vd->u.identnum.tipo = tipo;
	vd->u.identnum.num = num;
	vd->kind = tipo_ID;
	return vd;
}

/*
struct A_fun_declaracao_ { A_tipo_especificador tipo; char* id; A_params params; A_composto_decl composto_decl; };

A_fun_declaracao A_Fun_declaracao(A_tipo_especificador tipo, char* id, A_params params, A_composto_decl composto_decl);
*/
A_fun_declaracao A_Fun_declaracao(A_tipo_especificador tipo, char* id, A_params params, 					A_composto_decl composto_decl){
	A_fun_declaracao fd = malloc(sizeof(*fd));
	fd->id = id;
	fd->tipo = tipo;
	fd->params = params;
	fd->composto_decl = composto_decl;
	
	return fd;
}

/*
struct A_params_ {enum {p_lista, p_void} kind;
			union {struct {A_param_lista param_lista;} lista;
				 A_tipo_especificador tp_void;
				} u;
			};

A_params A_ListaParams(A_param_lista param_lista);	
A_params A_VoidParams(A_tipo_especificador tp_void);	

*/

A_params A_ListaParams(A_param_lista param_lista){
	A_params prms = malloc(sizeof(*prms));
	prms->u.lista.param_lista = param_lista;
	prms->kind = p_lista;	
	return prms;

}	

A_params A_VoidParams(A_tipo_especificador tp_void){
	A_params prms = malloc(sizeof(*prms));
	prms->u.tp_void = tp_void;
	prms->kind = p_void;	
	return prms;

}	


/*
struct A_param_lista{enum {pl_lista, pl_simples} kind;
			union {struct {A_param_lista param_lista; A_param param;} lista;
				 struct {A_param param;} simples;
				} u;
			};

A_param_lista A_ListaParam_lista(A_param_lista param_lista, A_param param);	
A_param_lista A_SimplesParam_simples(A_param param);	
*/
A_param_lista A_ListaParam_lista(A_param_lista param_lista, A_param param){
	A_param_lista prml = malloc(sizeof(*prml));
	prml->u.lista.param_lista = param_lista;
	prml->u.lista.param = param;
	prml->kind = pl_lista;	
	return prml;

}	

A_param_lista A_SimplesParam_simples(A_param param){
	A_param_lista prml = malloc(sizeof(*prml));
	prml->u.lista.param = param;
	prml->kind = pl_simples;	
	return prml;

}	


/*
struct A_param_ {enum {normal, param} kind;
		union{		
			struct {A_tipo_especificador tipo; char* id;} normal;
			struct {A_tipo_especificador tipo; char* id;} param;
			} u;		
		};


A_param A_NormalParam(A_tipo_especificador tipo, char* id);
A_param A_ParamParam(A_tipo_especificador tipo, char* id);

*/

A_param A_NormalParam(A_tipo_especificador tipo, char* id){
	A_param prm = malloc(sizeof(*prm));
	prm->u.normal.id = id;
	prm->u.normal.tipo = tipo;
	prm->kind = normal;	
	return prm;

}

A_param A_ParamParam(A_tipo_especificador tipo, char* id){
	A_param prm = malloc(sizeof(*prm));
	prm->u.param.id = id;
	prm->u.param.tipo = tipo;
	prm->kind = param;		
	return prm;

}

/*struct A_composto_decl_{A_local_declaracoes local_declaracoes};
*/
A_composto_decl A_Composto_decl(A_local_declaracoes local_declaracoes, A_statement_lista statement_lista){
	A_composto_decl cd = malloc(sizeof(*cd));
	cd->local_declaracoes = local_declaracoes;
	cd->statement_lista = statement_lista;

	return cd;
}	

/*
struct A_local_declaracoes{enum {l_lista, l_vazio} kind;
			union {struct {A_local_declaracoes local_declaracoes; A_var_declaracao var_declaracao;} lista;
				 struct {A_vazio vazio;} nada;
				} u;
			};

A_local_declaracoes A_Lista_Local_declaracoes(A_local_declaracoes local_declaracoes, A_var_declaracao var_declaracao);	
A_local_declaracoes A_NadaLocal_declaracoes(A_vazio vazio);

*/

A_local_declaracoes A_Lista_Local_declaracoes(A_local_declaracoes local_declaracoes, 							A_var_declaracao var_declaracao){
	A_local_declaracoes ld = malloc(sizeof(*ld));
	ld->u.lista.local_declaracoes = local_declaracoes;
	ld->u.lista.var_declaracao = var_declaracao;
	ld->kind = l_lista;		
	return ld;

}

A_local_declaracoes A_NadaLocal_declaracoes(A_vazio vazio){
	A_local_declaracoes ld = malloc(sizeof(*ld));
	ld->u.nada.vazio = vazio;
	ld->kind = l_vazio;		
	return ld;
}

/*
struct A_statement_lista{enum {s_lista, s_vazio} kind;
			union {struct {A_statement_lista statement_lista; A_statement statement;} 					lista;
				 struct {A_vazio vazio;} vazio;
				} u;
			};

A_statement_lista A_ListaStatement_lista(A_statement_lista statement_lista, A_statement statement);
A_statement_lista A_NadaStatement_lista(A_vazio vazio);

*/

A_statement_lista A_ListaStatement_lista(A_statement_lista statement_lista, A_statement statement){
	A_statement_lista sl = malloc(sizeof(*sl));
	sl->u.lista.statement_lista = statement_lista;
	sl->u.lista.statement = statement;
	sl->kind = s_lista;		
	return sl;

}

A_statement_lista A_NadaStatement_lista(A_vazio vazio){
	A_statement_lista sl = malloc(sizeof(*sl));
	sl->u.vazio.vazio = vazio;
	sl->kind = s_vazio;		
	return sl;

}


/*
struct A_statement_ {enum {tipo_expressao_decl, tipo_composto_decl, tipo_selecao_decl, tipo_iteracao_decl, tipo_return_decl} kind;
			union {struct {A_expressao_decl expressao_decl;} expressao;
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
*/

A_statement A_ExpressaoStatement_lista(A_expressao_decl expressao_decl){
	A_statement s = malloc(sizeof(*s));
	s->u.expressao.expressao_decl = expressao_decl;
	s->kind = tipo_expressao_decl;		
	return s;
}

A_statement A_CompostoStatement_lista(A_composto_decl composto_decl){
	A_statement s = malloc(sizeof(*s));
	s->u.composto.composto_decl = composto_decl;
	s->kind = tipo_composto_decl;		
	return s;
}

A_statement A_SelecaoStatement_lista(A_selecao_decl selecao_decl){
	A_statement s = malloc(sizeof(*s));
	s->u.selecao.selecao_decl = selecao_decl;
	s->kind = tipo_selecao_decl;		
	return s;
}

A_statement A_IteracaoStatement_lista(A_iteracao_decl iteracao_decl){
	A_statement s = malloc(sizeof(*s));
	s->u.iteracao.iteracao_decl = iteracao_decl;
	s->kind = tipo_iteracao_decl;		
	return s;
}

A_statement A_ReturnStatement_lista(A_return_decl return_decl){
	A_statement s = malloc(sizeof(*s));
	s->u.t_return.return_decl = return_decl;
	s->kind = tipo_return_decl;		
	return s;
}



/*
struct A_expressao_decl {enum { ed_lista, ed_vazio} kind;
				union {struct {A_expressao expressao;} lista;
					A_Vazio nada;
					} u;
			};

A_expressao_decl A_ListaExpressao_decl(A_expressao expressao);	
A_expressao_decl A_NadaExpressao_decl();

*/

A_expressao_decl A_ListaExpressao_decl(A_expressao expressao){
	A_expressao_decl ed = malloc(sizeof(*ed));
	ed->u.lista.expressao = expressao;
	ed->kind = ed_lista;		
	return ed;

}


A_expressao_decl A_NadaExpressao_decl(){
	A_expressao_decl ed = malloc(sizeof(*ed));
	ed->u.nada = A_Vazio();
	ed->kind = ed_vazio;		
	return ed;

}


/*
struct A_selecao_decl{enum { selecao_decl_IF, selecao_decl_IF_ELSE} kind;
			union {struct {A_expressao expressao; A_statement statement;} selecaoIF;
				 struct {A_expressao expressao; A_statement statementIF; A_statement 							statementELSE;} selIF_ELSE;
				} u;
			};

A_selecao_decl A_IFSelecao_decl(A_expressao expressao, A_statement statement);	
A_selecao_decl A_IF_ELSESelecao_decl(A_expressao expressao, A_statement statementIF, A_statement statementELSE);

*/


A_selecao_decl A_IFSelecao_decl(A_expressao expressao, A_statement statement){
	A_selecao_decl sd = malloc(sizeof(*sd));
	sd->u.selecaoIF.expressao = expressao;
	sd->u.selecaoIF.statement = statement;
	sd->kind = selecao_decl_IF;		
	return sd;

}

A_selecao_decl A_IF_ELSESelecao_decl(A_expressao expressao, A_statement statementIF, A_statement statementELSE){
	A_selecao_decl sd = malloc(sizeof(*sd));
	sd->u.selIF_ELSE.expressao = expressao;
	sd->u.selIF_ELSE.statementIF = statementIF;
	sd->u.selIF_ELSE.statementELSE = statementELSE;
	sd->kind = selecao_decl_IF_ELSE;		
	return sd;

}


/*
struct A_iteracao_decl{A_expressao expressao; A_statement statement;};

A_iteracao_decl A_Iteracao_decl(A_expressao expressao, A_statement statement);

*/

A_iteracao_decl A_Iteracao_decl(A_expressao expressao, A_statement statement){
	A_iteracao_decl it = malloc(sizeof(*it));
	it->expressao = expressao;
	it->statement = statement;
	return it;
}

/*
struct A_return_decl{enum { cExpressao, sExpressao} kind;
			union {struct {A_expressao expressao;} comExpressao;
				 A_Vazio semExpressao;
				} u;
			};	
A_return_decl A_ComexpReturn_decl(A_expressao expressao);	
A_return_decl A_SemexpReturn_decl();

*/

A_return_decl A_ComexpReturn_decl(A_expressao expressao){
	A_return_decl rd = malloc(sizeof(*rd));
	rd->u.comExpressao.expressao = expressao;
	rd->kind = cExpressao;		
	return rd;

}

A_return_decl A_SemexpReturn_decl(){
	A_return_decl rd = malloc(sizeof(*rd));
	rd->u.semExpressao = A_Vazio();
	rd->kind = sExpressao;		
	return rd;

}


/*
struct A_expressao{enum { e_atribuicao, e_simples} kind;
			union {struct {A_var var ; A_expressao expressao;} atribuicao;
				 struct {A_simples_expressao simples_expressao; } simples;
				} u;
			};	
A_expressao A_AtribExpressao(A_var var, A_expressao expressao);	
A_expressao A_SimpExpressao(A_simples_expressao simples_expressao);
*/

A_expressao A_AtribExpressao(A_var var, A_expressao expressao){
	A_expressao e = malloc(sizeof(*e));
	e->u.atribuicao.var = var;
	e->u.atribuicao.expressao = expressao;
	e->kind = e_atribuicao;		
	return e;

}

A_expressao A_SimpExpressao(A_simples_expressao simples_expressao){
	A_expressao e = malloc(sizeof(*e));
	e->u.simples.simples_expressao = simples_expressao;
	e->kind = e_simples;		
	return e;

}

/*
struct A_var{enum { v_ident, v_atrib} kind;
			union { struct {char* id; } ident;
				struct {char* id ; A_expressao expressao;} atrib;
				} u;
			};	

A_var A_IdentVar(char* id);
A_var A_AtribVar(char* id, A_expressao expressao);	
*/
A_var A_IdentVar(char* id){
	A_var v = malloc(sizeof(*v));
	v->u.ident.id = id;
	v->kind = v_ident;		
	return v;

}

A_var A_AtribVar(char* id, A_expressao expressao){
	A_var v = malloc(sizeof(*v));
	v->u.atrib.id = id;
	v->u.atrib.expressao = expressao;
	v->kind = v_atrib;		
	return v;

}


/*
struct A_simples_expressao_{enum { se_relacional, se_simples} kind;
			union { struct { A_soma_expressao expressao1;
					A_relacional op_relacional;
					A_soma_expressao expressao2;  
					} relacional;
				struct {A_soma_expressao expressao;} simples;
				} u;
			};	

*/

A_simples_expressao A_RelacionalSimples_expressao(A_soma_expressao expressao1,	A_relacional op_relacional, A_soma_expressao expressao2){
	A_simples_expressao se = malloc(sizeof(*se));
	se->u.relacional.expressao1 = expressao1;
	se->u.relacional.op_relacional = op_relacional;
	se->u.relacional.expressao2 = expressao2;
	se->kind = se_relacional;		
	return se;

}

A_simples_expressao A_Simples_expressao(A_soma_expressao expressao){
	A_simples_expressao se = malloc(sizeof(*se));
	se->u.simples.expressao = expressao;
	se->kind = se_simples;		
	return se;

}

/*
struct A_soma_expressao_{enum { sm_lista, sm_simples} kind;
			union { struct { A_soma_expressao soma_expressao; A_soma op_soma;	
				 A_termo termo; }lista;
				struct {A_termo termo;} simples;
				} u;
			};	

*/

A_soma_expressao A_ListaSoma_expressao(A_soma_expressao soma_expressao, A_soma op_soma, A_termo termo){
	A_soma_expressao sme = malloc(sizeof(*sme));
	sme->u.lista.soma_expressao = soma_expressao;
	sme->u.lista.termo = termo;
	sme->kind = sm_lista;		
	return sme;

}

A_soma_expressao A_Soma_expressao(A_termo termo){
	A_soma_expressao sme = malloc(sizeof(*sme));
	sme->u.simples.termo = termo;
	sme->kind = sm_simples;		
	return sme;

}

/*
struct A_termo_{enum { t_lista, t_simples} kind;
			union { struct { A_termo termo; A_mult op_mult; A_fator fator;}lista;
				struct {A_fator fator;} simples;
				} u;
			};	

A_termo A_MultTermo(A_termo termo, A_mult op_mult, A_fator fator);
A_termo A_FatorTermo(A_fator fator);

*/
A_termo A_MultTermo(A_termo termo, A_mult op_mult, A_fator fator){
	A_termo mt = malloc(sizeof(*mt));
	mt->u.lista.termo = termo;
	mt->u.lista.op_mult = op_mult;
	mt->u.lista.fator = fator;
	mt->kind = t_lista;		
	return mt;

}

A_termo A_FatorTermo(A_fator fator){
	A_termo mt = malloc(sizeof(*mt));
	mt->u.simples.fator = fator;
	mt->kind = t_simples;		
	return mt;

}

/*
struct A_fator{enum { f_expressao, f_var, f_ativacao, f_num} kind;
			union { struct { A_expressao expressao;}expressao;
				struct {A_var var;} var;
				struct {A_ativacao ativacao;} ativacao;
				struct {int num;} num;
				} u;
			};	

A_fator A_ExpressaoFator(A_expressao expressao);
A_fator A_VarFator(A_var var);
A_fator A_AtivacaoFator(A_ativacao ativacao);
A_fator A_NumFator(int num);

*/



A_fator A_ExpressaoFator(A_expressao expressao){
	A_fator f = malloc(sizeof(*f));
	f->u.expressao.expressao = expressao;
	f->kind = f_expressao;		
	return f;

}

A_fator A_VarFator(A_var var){
	A_fator f = malloc(sizeof(*f));
	f->u.var.var = var;
	f->kind = f_var;		
	return f;

}

A_fator A_AtivacaoFator(A_ativacao ativacao){
	A_fator f = malloc(sizeof(*f));
	f->u.ativacao.ativacao = ativacao;
	f->kind = f_ativacao;		
	return f;

}

A_fator A_NumFator(int num){
	A_fator f = malloc(sizeof(*f));
	f->u.num.num = num;
	f->kind = f_num;		
	return f;

}

A_fator A_StrFator(char *str){
	A_fator f = malloc(sizeof(*f));
	f->u.str.str = str;
	f->kind = f_str;		
	return f;

}


/*
struct A_ativacao_{char* id; A_args args;};

A_ativacao A_Ativacao(char* id, A_args args);

*/

A_ativacao A_Ativacao(char* id, A_args args){
	A_ativacao at = malloc(sizeof(*at));
	at->id = id;
	at->args = args;		
	return at;

}

/*
struct A_args{enum { a_lista, a_vazio } kind;
			union { struct { A_arg_lista arg_lista;} lista;
				struct {A_vazio vazio;} vazio;
				} u;
			};	

A_args A_ListaArgs(A_arg_lista arg_lista);
A_args A_VazioArgs(A_vazio vazio);

*/

A_args A_ListaArgs(A_arg_lista arg_lista){
	A_args as = malloc(sizeof(*as));
	as->u.lista.arg_lista = arg_lista;
	as->kind = a_lista;		
	return as;

}

A_args A_VazioArgs(A_vazio vazio){
	A_args as = malloc(sizeof(*as));
	as->u.vazio.vazio = vazio;
	as->kind = a_vazio;		
	return as;

}


/*
struct A_arg_lista{enum { al_lista, al_expressao } kind;
			union { struct { A_arg_lista arg_lista; A_expressao expressao;} lista;
				struct {A_expressao expressao;} expressao;
				} u;
			};	

A_arg_lista A_ListaArg_lista(A_arg_lista arg_lista, A_expressao expressao);
A_arg_lista A_ExpressaoArg_lista(A_expressao expressao);
*/

A_arg_lista A_ListaArg_lista(A_arg_lista arg_lista, A_expressao expressao){
	A_arg_lista al = malloc(sizeof(*al));
	al->u.lista.arg_lista = arg_lista;
	al->u.lista.expressao = expressao;
	al->kind = al_lista;		
	return al;

}


A_arg_lista A_ExpressaoArg_lista(A_expressao expressao){
	A_arg_lista al = malloc(sizeof(*al));
	al->u.expressao.expressao = expressao;
	al->kind = al_expressao;		
	return al;

}


/*
struct A_vazio_{};

A_vazio A_Vazio();
*/

A_vazio A_Vazio(){
	A_vazio v = malloc(sizeof(*v));
	return v;

}

