#include "transformacao.h"

Transformacao::Transformacao() {
	translacao = Translacao::Translacao();
	rotacao = Rotacao::Rotacao();
	escala = Escala::Escala();
	cor = Cor::Cor();
}

Transformacao::Transformacao(Translacao t , Rotacao r, Escala e, Cor c) {
	translacao = t;
	rotacao = r;
	escala = e;
	cor = c;
}