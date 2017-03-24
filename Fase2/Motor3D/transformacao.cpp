#include "transformacao.h"

Transformacao::Transformacao() {

	translacao = Translacao::Translacao();
	//rotacao = Rotacao::Rotacao();
	escala = Escala::Escala(); 
}

// Transformacao::Transformacao(Translacao T ,Rotacao r, Escala e);
Transformacao::Transformacao(Translacao t , Escala e) {
	trans = t;
	// rot = r;
	esc = e;
}