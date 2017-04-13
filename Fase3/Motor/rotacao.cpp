#include "rotacao.h"

Rotacao::Rotacao(){
	tempo = 0.0;
	eixoX = 0.0;
	eixoY = 0.0;
	eixoZ = 0.0;

};

Rotacao::Rotacao(float a, float b, float c, float d){
	tempo = d;
	eixoX = a;
	eixoY = b;
	eixoZ = c;
};


