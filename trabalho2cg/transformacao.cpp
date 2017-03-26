#include "transformacao.h"

Transformacao::Transformacao() {

	translacao = Translacao();
	//rotacao = Rotacao::Rotacao();
	escala = Escala(); 
}

// Transformacao::Transformacao(Translacao T ,Rotacao r, Escala e);
Transformacao::Transformacao(Translacao t , Escala e) {
	translacao = t;
	// rot = r;
	escala = e;
}