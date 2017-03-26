//#ifndef _MAIN
//#define _MAIN

#include <vector>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
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
	Transformacao transformacao;


public: 
		Aplicacao();
		Aplicacao(string nome, vector<Aplicacao> a, vector<Ponto> p, Transformacao t);
		vector<Ponto> getPontos() {return pontos;}
		vector<Aplicacao> getFilhos() { return filhos;}
		string getNome() { return nome;}
		Transformacao getTransformacao() { return transformacao;}
		void setNome( string n) { nome=n;}
		void setPontos(vector<Ponto> p) {pontos = p;}
		void setFilhos(vector<Aplicacao> f) {filhos=f;}
		void setTransformacao(Transformacao t) { transformacao = t;}

};

//#endif