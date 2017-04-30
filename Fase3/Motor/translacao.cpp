#include "translacao.h"


Translacao::Translacao() {
	tempo = 0;
}

Translacao::Translacao(float a, float b, float c){
	x = a;
	y = b;
	z = c;
	tempo = 0;
}

Translacao::Translacao(float t){
	tempo = t;
}


Translacao::Translacao(float t, vector<Ponto> p , int num) {
	tempo = t;
	size = num;
	pointTrans = p;
}

void Translacao::addPonto(Ponto p){
	pointTrans.push_back(p);
}

bool Translacao::isEmpty() {
	return (tempo == 0 && pointTrans.size() == 0) ? true : false;
}


void Translacao::getCatmullRomPoint(float gtt , int* indices , float* res , vector<Ponto> transp){
	float novo[4];
	float ttt , tt;
	int ind1 , ind2 , ind3 , ind4;
	Ponto p0 , p1, p2 , p3;

	res[0] = res[1] = res[2] = 0.0;
	ttt = pow(gtt,3);
	tt = pow(gtt,2);

	float m[4][4] = {{ -0.5f, 1.5f, -1.5f, 0.5f },
					 { 1.0f, -2.5f, 2.0f, -0.5f },
					 { -0.5f, 0.0f, 0.5f, 0.0f },
					 { 0.0f, 1.0f, 0.0f, 0.0f } };


	novo[0] = ttt*m[0][0] + tt*m[1][0] + gtt*m[2][0] + m[3][0];
	novo[1] = ttt*m[0][1] + tt*m[1][1] + gtt*m[2][1] + m[3][1];
	novo[2] = ttt*m[0][2] + tt*m[1][2] + gtt*m[2][2] + m[3][2];
	novo[3] = ttt*m[0][3] + tt*m[1][3] + gtt*m[2][3] + m[3][3];

	ind1 = indices[0];
	ind2 = indices[1];
	ind3 = indices[2];
	ind4 = indices[3];

	p0 = transp[ind1];
	p1 = transp[ind2];
	p2 = transp[ind3];
	p3 = transp[ind4];

	res[0] = novo[0]*p0.getX() + novo[1]*p1.getX() + novo[2]*p2.getX() + novo[3]*p3.getX();
	res[1] = novo[0]*p0.getY() + novo[1]*p1.getY() + novo[2]*p2.getY() + novo[3]*p3.getY();
	res[2] = novo[0]*p0.getZ() + novo[1]*p1.getZ() + novo[2]*p2.getZ() + novo[3]*p3.getZ();

}




void Translacao::getGlobalCatmullRomPoint( float t, float *res, vector<Ponto> transp) {

	int tam , index; 
	float gtt;
	int indices[4];

	tam = transp.size();
	gtt = t * tam;
	index = floor(gtt); // floor arredonda para o menor ou maior inteiro
	gtt = gtt - index;

	// armazenar os pontos
	indices[0] = (index + tam -1) % tam; 
	indices[1] = (indices[0] + 1) % tam;
	indices[2] = (indices[1] + 1) % tam;
	indices[3] = (indices[2] + 1) % tam;

	getCatmullRomPoint(gtt,indices,res,transp);
}

	


void Translacao::desenhaCurvas(){

	float res[3];
	float t;

	for( t = 0; t<1 ; t += 0.01) {

		getGlobalCatmullRomPoint(t,res,pointTrans);

		Ponto pto = Ponto::Ponto(res[0],res[1],res[2]);
		pointCurv.push_back(pto);
	}
}


