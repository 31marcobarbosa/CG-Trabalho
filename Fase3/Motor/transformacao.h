#pragma once


#include "translacao.h"
#include "rotacao.h"
#include "escala.h"
#include "cor.h"

class Transformacao{
	Translacao translacao;
	Rotacao rotacao;
	Escala escala;
	Cor cor;

	public:
		Transformacao();
		Transformacao(Translacao, Rotacao, Escala, Cor);
		Translacao getTranslacao() { return translacao; }
		Rotacao getRotacao() { return rotacao; }
		Escala getEscala() { return escala; }
		Cor getCor() { return cor; }
		void setTranslacao(Translacao t){ translacao = t; }
		void setRotacao(Rotacao r){ rotacao = r; }
		void setEscala(Escala e){ escala = e; }
		void setCor(Cor c){ cor = c; }
		bool transformacaoVazia();

};
