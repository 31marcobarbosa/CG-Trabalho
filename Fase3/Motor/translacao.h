#pragma once

#define _MAIN

#include <vector>
#include "ponto.h"
using namespace std;


class Translacao{
	float tempo;
	int size;
	vector<Ponto> pointTrans;
	vector<Ponto> pointCurv;


public: 
	Translacao();
	Translacao(float);
	Translacao(float , vector<Ponto> , int);
	vector<Ponto> getPontosTrans() { return pointTrans; }
	vector<Ponto> getPontosCurva() { return pointTrans; }
	float getTempo() { return tempo; }
	int getSize() { return size; }
	void setTempo( float a) {  tempo = a; }
	void setSize( int a) {  size = a; }
	void setPontosTrans( vector <Ponto> p) { pointTrans = p; }
	void setPontosCurv( vector <Ponto> p) { pointCurv = p; }
	void Translacao::getGlobalCatmullRomPoint( float , float * , vector<Ponto> );
	void Translacao::desenhaCurvas();
	void Translacao::getCatmullRomPoint(float, int* , float*,vector<Ponto>);
};
