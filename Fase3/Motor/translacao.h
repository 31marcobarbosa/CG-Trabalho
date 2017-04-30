#pragma once

#define _MAIN

#include <vector>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"
using namespace std;


class Translacao{

	float x, y, z;

	float tempo;
	int size;
	vector<Ponto> pointTrans;
	vector<Ponto> pointCurv;

public: 
	Translacao();
	Translacao(float, float, float);
	Translacao(float);
	Translacao(float , vector<Ponto> , int);
	void addPonto(Ponto);
	vector<Ponto> getPontosTrans() { return pointTrans; }
	vector<Ponto> getPontosCurva() { return pointCurv; }
	float getTempo() { return tempo; }
	int getSize() { return size; }
	float getX() { return x;} 
	float getY() { return y;}
	float getZ() {return z;}
	void setTempo( float a) {  tempo = a; }
	void setSize( int a) {  size = a; }
	void setPontosTrans( vector <Ponto> p) { pointTrans = p; }
	void setPontosCurv( vector <Ponto> p) { pointCurv = p; }
	void getGlobalCatmullRomPoint( float , float * , vector<Ponto> );
	void desenhaCurvas();
	void getCatmullRomPoint(float, int* , float*,vector<Ponto>);
	bool isEmpty();
};
