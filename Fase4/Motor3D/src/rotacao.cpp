#include "rotacao.h"

Rotacao::Rotacao(){
	tempo = 0.0;
	eixoX = 0.0;
	eixoY = 0.0;
	eixoZ = 0.0;

}

Rotacao::Rotacao(float a, float b, float c, float d){
	eixoX = a;
	eixoY = b;
	eixoZ = c;
	tempo = d;
}

bool Rotacao::isEmpty() {
	return (tempo == 0 && eixoX == 0 && eixoY == 0 && eixoZ == 0) ? true : false;
}