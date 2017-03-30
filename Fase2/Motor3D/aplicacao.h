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
		Aplicacao(string, vector<Aplicacao>, vector<Ponto>, Transformacao);
		vector<Ponto> getPontos() {return pontos;}
		vector<Aplicacao> getFilhos() { return filhos;}
		string getNome() { return nome;}
		Transformacao getTransformacao() { return transformacao;}
		void setNome( string n) { nome=n;}
		void setPontos(vector<Ponto> p) {pontos = p;}
		void setFilhos(vector<Aplicacao> f) {filhos=f;}
		void setTransformacao(Transformacao t) { transformacao = t;}

		/*
		void printapp() {

			cout << "############################################################" << endl;
			cout << "NOME: " << id << endl;

			Escala* app = transformacao->getEscala();
			Translacao* ttr = transformacao->getTranslacao();
			Rotacao* r = transformacao->getRotacao();

			//for(int i = 0 ; app.size() ; i++){
				cout << "X: " << app->getEX() << "! Y: " << app->getEY() << "! Z: " << app->getEZ() << endl;
				cout << "Xtrans: " << ttr->getTX() << "! Ytrans: " << ttr->getTY() << "! Ztrans: " << ttr->getTZ() << endl;
				cout << "Angulo: " << r->getAngulo() << " | X: " << r->geteixoX() << "| Y: " << r->geteixoY() << "| Z: " << r->geteixoZ() << endl;
			//}

			cout << "FILHOS: ";
			for(int i=0; i<filhos.size(); i++){
				cout << filhos[i]->getId() << " | " << endl;
			}
			cout << "############################################################" << endl;
		}
		*/

};

//#endif