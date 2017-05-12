#include "transformacao.h"

Transformacao::Transformacao() {
	translacao = Translacao::Translacao();
	rotacao = Rotacao::Rotacao();
	escala = Escala::Escala();
	cor_orbita = Cor_Orbita::Cor_Orbita();
}

Transformacao::Transformacao(Translacao t , Rotacao r, Escala e, Cor_Orbita c) {
	translacao = t;
	rotacao = r;
	escala = e;
	cor_orbita = c;
}

bool Transformacao::transformacaoVazia() {
	bool res = false;
	if (translacao.isEmpty() && rotacao.isEmpty() && escala.isEmpty() && cor_orbita.isEmpty())
		res = true;

	return res;
}