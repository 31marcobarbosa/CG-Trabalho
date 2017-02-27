#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


#define CONST 0.1f;

#include <math.h>


float angle = 0.0f;
float size;
float xr = 0, yr = 0, zr = 0;
float camX = 0, camY = 0, camZ = 0;
int xinicio, yinicio , tracking = 0;
int k = 5 , alpha = 0 , beta = 0;
vector<Ponto> vertices; //vetor com os pontos lidos do ficheiro


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
	gluLookAt(camX,camY,camZ,
		      0.0,0.0,0.0,
			  0.0f,1.0f,0.0f);
    angle +=0.01;

// drawing instructions here

	//glTranslatef(xr, yr, zr);
	//glRotatef( angle, 0.0f, 1.0f, 0.0f);


	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 1.0f);

	for (int i = 0; i < vertices.size(); i++)
		glVertex3f(vertices[i].x, vertices[i].y, vertices[i].z);

	glEnd();


	glutSwapBuffers();
}



void letrasKeyboard(unsignedchar t , int x , int y) {

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
	}
	glutPostRedisplay();

}


// setas
void keyboardspecial(int key, int a, int b) {
	a = b = 0;
	switch (key){
		case(GLUT_KEY_LEFT) : angle -= CONST;
			break;
		case(GLUT_KEY_RIGHT): angle += CONST;
			break;
	}
	glutPostRedisplay();

}





int main(int argc, char **argv) {

// put GLUT init here

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(800,800);
    glutCreateWindow("CG@DI");


// put callback registration here

    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);

// OpenGL settings

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glClearColor(0.0f,0.0f,0.0f,0.0f);

// enter GLUT's main loop
	glutMainLoop();

	return 1;
}
