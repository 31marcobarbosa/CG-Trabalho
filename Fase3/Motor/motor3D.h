#pragma once


#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/glew.h>
#endif


#include "tinyxml2.h"
#include "escala.h"
#include "transformacao.h"
#include "aplicacao.h"
#include "ponto.h"
#include "rotacao.h"
#include "translacao.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#define _USE_MATH_DEFINES


using namespace tinyxml2;
using namespace std;

