#pragma once

class Cor_Orbita{
	float r;
	float g;
	float b;

public:
	Cor_Orbita();
	
	Cor_Orbita(float, float, float);
	
	float getR(){ 
		return r; 
	}

	float getG() { 
		return g; 
	}

	float getB() { 
		return b; 
	}

	void setR(float rr){ 
		r = rr;
	}

	void setG(float gg){ 
		g = gg;
	}

	void setB(float bb){
		b = bb;
	}

	bool isEmpty();
	
	virtual ~Cor_Orbita() {};
};