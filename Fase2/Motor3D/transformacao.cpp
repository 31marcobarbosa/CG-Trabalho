#include "transformacao.h"

Transformacao::Transformacao() {

	translacao = Translacao::Translacao();
	rotacao =Rotacao::Rotacao();
	escala = Escala::Escala();
}

Transformacao::Transformacao(Translacao t , Rotacao r, Escala e) {
	translacao = t;
	rotacao = r;
	escala = e;
}