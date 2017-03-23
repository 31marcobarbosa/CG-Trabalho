#ifndef _MAIN
#define _MAIN

class Escala{
	float x;
	float y;
	float z;


public: 
	Escala();
	Escala(float x, float y, float z);
	float getX() { return x; }
	float getY() { return y; }
	float getZ() { return z; }
	void setX( float a) {  x = a; }
	void setY( float a) {  y = a; }
	void setZ( float a) {  z = a; }


};

#endif