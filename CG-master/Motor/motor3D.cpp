#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


#define CONST 3.0;

#include <math.h>
#include "tinyxml2.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
//#include <Type.h>
//#include <Transformation.h>
//#include <Point.h>
//#include <Model.h>

struct Ponto
{
	double x;
	double y;
	double z;
};


using namespace tinyxml2;
using namespace std;


float angle = 0.0f;
float angle2 = 0.0f;
float size;
float xr = 0, yr = 0, zr = 0;
float camX = 0, camY = 0, camZ = 0;
int xinicio, yinicio , tracking = 0;
int k = 5 , alpha = 0 , beta = 0;
vector<Ponto> vertices; //vetor com os pontos lidos do ficheiro
int linha = GL_LINE;


void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window with zero width).
	if(h == 0)
		h = 1;

	// compute window's aspect ratio
	float ratio = w * 1.0 / h;

	// Set the projection matrix as current
	glMatrixMode(GL_PROJECTION);
	// Load Identity Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
    glViewport(0, 0, w, h);

	// Set perspective
	gluPerspective(45.0f ,ratio, 1.0f ,1000.0f);

	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
}



void renderScene(void) {

	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glLoadIdentity();
	gluLookAt(5.0,5.0,5.0,
		      0.0,0.0,0.0,
			  0.0f,1.0f,0.0f);
   

	// put drawing instructions here
    glPolygonMode(GL_FRONT_AND_BACK,linha);
    glRotatef(angle,0,1,0);
    glRotatef(angle2,0,0,1);
	glBegin(GL_TRIANGLES);
	glColor3f(1,1,1);

	for (int i = 0; i < vertices.size(); i++)
		glVertex3f(vertices[i].x, vertices[i].y, vertices[i].z);

	glEnd();

	// End of frame
	glutSwapBuffers();
}



void letrasKeyboard(unsigned char t , int x , int y) {

	switch (t) {
		case 'a':
		case 'A': xr -= CONST;
			break;
		case 'd':
		case 'D': xr += CONST;
		 	break;
		case 'w':
		case 'W': yr += CONST;
		 	break;
		case 's':
		case 'S': yr -= CONST;
			break;
		case 'e':
		case 'E': zr -= CONST;
			break;
		case 'q':
		case 'Q': zr += CONST;
		 	break;
		case 'p': linha = GL_POINT;
			break;
		case 'l': linha = GL_LINE;
	   	    break;
		case 'o': linha = GL_FILL;
			break;
	}
	glutPostRedisplay();

}


// setas
void keyboardspecial(int key, int a, int b) {
	a = b = 0;
	switch (key){
		case GLUT_KEY_LEFT : angle -= CONST;
			break;
		case GLUT_KEY_RIGHT: angle += CONST;
			break;
		case GLUT_KEY_UP : angle2 -= CONST;
			break;
		case GLUT_KEY_DOWN: angle2 += CONST;
			break;
	}
	glutPostRedisplay();

}



void lerficheiro(string ficheiro) {

	string linha,token,delimiter = ",";
	int pos;
	double a,b,c;
	Ponto p;

	ifstream file(ficheiro);
	if (file.is_open()){

		while(getline(file,linha)){

			pos = linha.find(delimiter);
			token = linha.substr(0,pos);
			a = atof(token.c_str());
			linha.erase(0,pos + delimiter.length());
			p.x = a;

			pos = linha.find(delimiter);
			token = linha.substr(0,pos);
			b = atof(token.c_str());
			linha.erase(0,pos + delimiter.length());
			p.y = b;

			pos = linha.find(delimiter);
			token = linha.substr(0, pos);
			c = atof(token.c_str());
			linha.erase(0, pos + delimiter.length());
			p.z = c;

			//cout << p.x << " " << p.y << " " << p.z << endl;
			vertices.push_back(p);
		}
		file.close();			
	}
	else {
		cout << "ERRO AO LER O FICHEIRO" << endl;
	}


}



// Leitura do ficheiro XML
void lerXML(string ficheiro) {
	XMLDocument docxml;

	if (!(docxml.LoadFile(ficheiro.c_str()))) {
		XMLElement* root = docxml.FirstChildElement();
		for(XMLElement *elemento = root -> FirstChildElement();elemento != NULL; elemento = elemento -> NextSiblingElement()){
			string fich = elemento -> Attribute("file");
			cout << "Ficheiro: " << fich << " lido com sucesso " << endl;
			lerficheiro(fich);
		}		
	}
	else {
		cout << "Ficheiro XML não foi encontrado" << endl;
	}
}





int main(int argc, char **argv) {

    if(argc > 1){
		lerXML(argv[1]);
	}

	// put GLUT init here

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(800,800);
    glutCreateWindow("Projeto_de_CG"); 


	// put callback registration here

    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutSpecialFunc(keyboardspecial);
    glutKeyboardFunc(letrasKeyboard);
    
	// OpenGL settings

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	
	// enter GLUT's main loop
	glutMainLoop(); 

	return 1;
}
