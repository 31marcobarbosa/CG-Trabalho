#pragma once
#pragma comment(lib,"devil.lib")
#include <vector>
#include <stdlib.h>
#ifdef __APPLE__
#include <IL/il.h>
#include <GL/glut.h>
#else
#include <IL/il.h>
#include <GL/glew.h>
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
	string textura;
	vector<Aplicacao> filhos;
	vector<Ponto> pontos;
	Transformacao transformacao;
	vector<Ponto> normais;
	vector<Ponto> texturas;
	
	//VBOs
	GLuint buffers[3];
	float *v; //Pontos
	float *n; //Normais
	float *tex; //Texturas
	int nvertex;
	int nnormais;
	int ntexturas;
	
	//Textura:
	unsigned int t, width, height;
	unsigned int texID;
	unsigned char *data;

public:
	Aplicacao();
	Aplicacao(string n, vector<Aplicacao>, vector<Ponto>, Transformacao);
	string getTextura(){ 
		return textura;
	}

	unsigned getTexID(){ 
		return texID;
	}

	vector<Ponto> getPontos(){ 
		return pontos; 
	}

	vector<Ponto> getNormais(){ 
		return normais; 
	}

	vector<Ponto> getTexturas(){
	 	return texturas; 
	}

	vector<Aplicacao> getFilhos(){ 
		return filhos; 
	}

	string getNome(){
		return nome; 
	}

	Transformacao getTransformacao(){ 
		return transformacao; 
	}

	void setTextura(string t){ 
		textura = t; 
	}

	void setNome(string n){ 
		nome = n; 
	}

	void setFilho(Aplicacao f){ 
		filhos.push_back(f); 
	}

	void setFilhos(vector<Aplicacao> f){ 
		filhos.clear(); filhos = f; 
	}

	void setPontos(vector<Ponto> p){ 
		pontos = p; 
	}

	void setNormais(vector<Ponto> n){ 
		normais = n; 
	}

	void setTexturas(vector<Ponto> t){ 
		texturas = t; 
	}

	void setTransformacao(Transformacao t){ 
		transformacao = t; 
	}

	void prep();

	void draw();

	void construir();

	void criarTextura();

	virtual ~Aplicacao(){};
}; 