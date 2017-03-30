//#ifndef _TRANSFORMACAO_H
//#define _TRANSFORMACAO_H


#include "translacao.h"
#include "rotacao.h"
#include "escala.h"

class Transformacao{
	Translacao translacao;
	Rotacao rotacao;
	Escala escala;

	public:
		Transformacao();
		Transformacao(Translacao, Rotacao, Escala);
		Translacao getTranslacao() { return translacao; }
		Rotacao getRotacao() { return rotacao; }
		Escala getEscala() { return escala; }
		void setTranslacao(Translacao t){ translacao = t; }
		void setRotacao(Rotacao r){ rotacao = r; }
		void setEscala(Escala e){ escala = e; }

};

//#endif