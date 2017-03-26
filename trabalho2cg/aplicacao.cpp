#include "aplicacao.h"

Aplicacao::Aplicacao(){
	nome="";
	transformacao = Transformacao();
	filhos = vector<Aplicacao>();
	pontos = vector<Ponto>();
}

Aplicacao::Aplicacao(string nome, vector<Aplicacao> a, vector<Ponto> p, Transformacao t){

	string n = nome;
	filhos = a;
	pontos = p;
	transformacao = t;
}