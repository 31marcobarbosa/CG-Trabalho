#pragma once

#include "translacao.h"
#include "rotacao.h"
#include "escala.h"
#include "cor_orbita.h"

class Transformacao{
	Translacao translacao;
	Rotacao rotacao;
	Escala escala;
	Cor_Orbita cor_orbita;

	public:
		Transformacao();
		Transformacao(Translacao, Rotacao, Escala, Cor_Orbita);
		Translacao getTranslacao() { return translacao; }
		Rotacao getRotacao() { return rotacao; }
		Escala getEscala() { return escala; }
		Cor_Orbita getCor_Orbita() { return cor_orbita;}
		void setTranslacao(Translacao t){ translacao = t; }
		void setRotacao(Rotacao r){ rotacao = r; }
		void setEscala(Escala e){ escala = e; }
		void setCor(Cor_Orbita c){ cor_orbita = c; }
		bool transformacaoVazia();
		virtual ~Transformacao() {};

};