#include "aplicacao.h"

Aplicacao::Aplicacao( ){
	transformacao = Transformacao::Transformacao();
	nome = "";
	filhos = vector<Aplicacao>();
	pontos = vector<Ponto>();
}

Aplicacao::Aplicacao(string n, vector<Aplicacao> a, vector<Ponto> p, Transformacao t){

	nome = n;
	filhos = a;
	pontos = p;
	transformacao = t;
}

