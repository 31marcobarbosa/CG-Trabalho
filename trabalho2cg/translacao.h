//#ifndef _MAIN
//#define _MAIN

#include <vector>


class Translacao{
	float x;
	float y;
	float z;


public: 
	Translacao();
	Translacao(float x, float y, float z);
	float getTX() { return x; }
	float getTY() { return y; }
	float getTZ() { return z; }
	void setTX( float a) {  x = a; }
	void setTY( float a) {  y = a; }
	void setTZ( float a) {  z = a; }


};

//#endif