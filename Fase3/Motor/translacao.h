#pragma once

#define _MAIN

#include <vector>


class Translacao{
	float x;
	float y;
	float z;


public: 
	Translacao();
	Translacao(float x, float y, float z);
	float getX() { return x; }
	float getY() { return y; }
	float getZ() { return z; }
	void setX( float a) {  x = a; }
	void setY( float a) {  y = a; }
	void setZ( float a) {  z = a; }


};
