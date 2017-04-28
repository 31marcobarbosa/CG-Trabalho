#include "escala.h"

Escala::Escala() {
	x = 1;
	y = 1;
	z = 1;
}

Escala::Escala(float a, float b , float c){
	x = a;
	y = b;
	z = c;
}
bool Escala::isEmpty() {
	bool res = false;
	if (x == 0 && y == 0 && z == 0)
		res = true;

	return res;
}

