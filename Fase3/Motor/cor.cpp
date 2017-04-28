#include "cor.h"

Cor::Cor(){
	r = 1;
	g = 1;
	b = 1;
}

Cor::Cor(float a, float b , float c){
	r = a;
	g = b;
	b = c;
}

bool Cor::isEmpty() {
	bool res = false;
	if (r == 0 && g == 0 && b == 0)
		res = true;

	return res;
}