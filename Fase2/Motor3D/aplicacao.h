#ifndef _MAIN
#define _MAIN

#include <vector>
#include <GL\glut.h>
#include "ponto.h"
#include "transformacao.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;


class Aplicacao{

	string nome;
	vector<Aplicacao> filhos;
	vector<Ponto> pontos;
	Transformacao trans;


public: 
		Aplicacao();
		Aplicacao(string nome, vector<Aplicacao> a, vector<Ponto> p, Transformacao t);
		Transformacao getTransformacao() { return transformacao;}
		vector<Ponto> getPontos() {return pontos;}
		vector<Aplicacao> getFilhos() { return filhos;}
		string getNome() { return nome;}
		void setNome( string n) { nome=n;}
		void setPontos(vetor<Ponto> p) {pontos = p;}
		void setFilhos(vetor<Aplicacao> f) {filhos=f;}
		void setTransformacao(Transformacao t) { transformacao = t;}

};

#endif