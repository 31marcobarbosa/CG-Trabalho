#ifndef _MAIN
#define _MAIN

class Ponto{
	float x;
	float y;
	float z;


public: 
	Ponto();
	Ponto(float x, float y, float z);
	float getX() { return x; }
	float getY() { return y; }
	float getZ() { return z; }
	void setX( float a) {  x = a; }
	void setY( float a) {  y = a; }
	void setZ( float a) {  z = a; }


};

#endif