#include "transformacao.h"

Transformacao::Transformacao() {
	translacao = Translacao::Translacao();
	rotacao = Rotacao::Rotacao();
	escala = Escala::Escala();
}

Transformacao::Transformacao(Translacao t , Rotacao r, Escala e) {
	translacao = t;
	rotacao = r;
	escala = e;
}

bool Transformacao::transformacaoVazia() {
	bool res = false;
	if (translacao.isEmpty() && rotacao.isEmpty() && escala.isEmpty())
		res = true;

	return res;
}