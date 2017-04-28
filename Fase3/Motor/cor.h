#pragma once

class Cor{
	float r;
	float g;
	float b;


public: 
	Cor();
	Cor(float, float, float);
	float getR() { return r; }
	float getG() { return g; }
	float getB() { return b; }
	void setR( float a) {  r = a; }
	void setG( float a) {  g = a; }
	void setB( float a) {  b = a; }
	bool isEmpty();
};
