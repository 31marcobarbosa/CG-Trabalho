#include "cor_orbita.h"

Cor_Orbita::Cor_Orbita(){
	r = 1;
	g = 1;
	b = 1;
};

Cor_Orbita::Cor_Orbita(float rr, float gg, float bb){
	r = rr;
	g = gg;
	b = bb;
};
bool Cor_Orbita::isEmpty() {
	return (r == 0 && g == 0 && b == 0) ? true : false;
}