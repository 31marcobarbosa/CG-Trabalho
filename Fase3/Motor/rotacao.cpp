#include "rotacao.h"

Rotacao::Rotacao(){
	tempo = 0.0;
	eixoX = 0.0;
	eixoY = 0.0;
	eixoZ = 0.0;

};

Rotacao::Rotacao(float a, float b, float c, float d){
	tempo = a;
	eixoX = b;
	eixoY = c;
	eixoZ = d;
};


