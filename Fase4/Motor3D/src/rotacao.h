#pragma once

class Rotacao{
	float tempo;
	float eixoX;
	float eixoY;
	float eixoZ;

public:
	Rotacao();
	
	Rotacao(float, float, float, float);
	
	float geteixoX(){ 
		return eixoX; 
	}

	float geteixoY(){
	 	return eixoY;
	}

	float geteixoZ(){ 
		return eixoZ;
	}

	float getTime(){ 
		return tempo;
	}

	void setTime(float a){ 
		tempo = a; 
	}

	void setEixoX(float x){ 
		eixoX = x;
	}

	void setEixoY(float y){ 
		eixoY = y;
	}

	void setEixoZ(float z){
		eixoZ = z;
	}

	bool isEmpty();

	virtual ~Rotacao(){};
};