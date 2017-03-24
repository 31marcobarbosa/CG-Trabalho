#include "aplicacao.h"

Aplicacao::Aplicacao(){
	nome="";
	transformacao = Transformacao::Transformacao();
	filhos = vector<Aplicacao>();
	pontos = vetor<Ponto>();
}

Aplicacao::Aplicacao(string nome, vector<Aplicacao> a, vector<Ponto> p, Transformacao t){

	nome = n;
	filhos = a;
	pontos = p;
	transformacao = t;
}