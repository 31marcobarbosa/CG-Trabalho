#ifndef _MAIN
#define _MAIN

class Escala{
	float x;
	float y;
	float z;


public: 
	Escala();
	Escala(float x, float y, float z);
	float getEX() { return x; }
	float getEY() { return y; }
	float getEZ() { return z; }
	void setEX( float a) {  x = a; }
	void setEY( float a) {  y = a; }
	void setEZ( float a) {  z = a; }


};

#endif