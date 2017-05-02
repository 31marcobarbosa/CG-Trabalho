#pragma once

#pragma comment(lib,"devil.lib")

#include <vector>
#include <stdlib.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#include <IL/il.h>
#else
#include <GL/glut.h>
#include <GL/glew.h>
#endif




#include "ponto.h"
#include "Transformacao.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Aplicacao{

	string nome;
	string textura;
	vector<Aplicacao> filhos;
	vector<Ponto> pontos;
	vector<Ponto> normais;
	vector<Ponto> texturas;
	Transformacao transformacao;
	//VBOs
	GLuint buffers[3];
	float *v; //Pontos
	float *n; //Normais
	float *tex; //Texturas
	int nvertex;
	int nnormais;
	int ntexturas;
	//Textura:
	unsigned int t, tw, th;
	unsigned int texID;
	unsigned char *texData;

public:
	Aplicacao();
	Aplicacao(string n, vector<Aplicacao>, vector<Ponto>, Transformacao);
	string getNome(){ return nome; }
	string getTextura(){ return textura; }
	unsigned getTexID() { return texID; }
	vector<Ponto> getPontos() { return pontos; }
	vector<Ponto> getNormais() { return normais; }
	vector<Ponto> getTexturas() { return texturas; }
	vector<Aplicacao> getFilhos(){ return filhos; }
	Transformacao getTransformacao(){ return transformacao; }
	void setTextura(string t){ textura = t; }
	void setNome(string n){ nome = n; }
	void setFilho(Aplicacao f){ filhos.push_back(f); }
	void setFilhos(vector<Aplicacao> f){ filhos.clear(); filhos = f; }
	void setPontos(vector<Ponto> p){ pontos = p; }
	void setNormais(vector<Ponto> n){ normais = n; }
	void setTexturas(vector<Ponto> t){ texturas = t; }
	void setTransformacao(Transformacao t){ transformacao = t; }
	void preparar();
	void desenhar();
	void construir();
	void criarTextura();
	virtual ~Aplicacao() {};
}; 