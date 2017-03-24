#ifndef _MAIN
#define _MAIN

#include "translacao.h"
#include "rotacao.h"
#include "escala.h"

class Transformacao{
	Translacao transformacao;
	//Rotacao rotacao;
	Escala escala;

	public:
		Transformacao();
		Transformacao(Translacao t, Rotacao r,  Escala e);
		Translacao getTranslacao() { return transformacao; }
		//Rotacao getRotacao() { return rotacao; }
		Escala getEscala() { return escala; }
		void setTranslacao(Translacao t){ transformacao = t; }
		//void setRotacao(Rotacao r){ rotacao = r; }
		void setEscala(Escala e){ escala = e; }
};

#endif