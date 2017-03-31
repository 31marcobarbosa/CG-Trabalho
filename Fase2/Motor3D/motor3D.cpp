#include "motor3D.h"


//vetor com os pontos lidos do ficheiro
vector<Ponto> pontos;

// vetor de aplicacoes
vector<Aplicacao> aplicacoes;




float R = 1, G = 1, B = 1;
float size;
float a = 1, w = 1;
float camX = 0, camY = 0, camZ = 0;
float zx = 6, zy = 6, zz = 6;
int xinicio, yinicio , tracking = 0;
int k = 5 , alpha = 0 , beta = 0;
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
	

	gluLookAt(zx,zy,zz,
		      0.0,0.0,0.0,
			  0.0f,1.0f,0.0f);
   

	// put drawing instructions here
    glPolygonMode(GL_FRONT_AND_BACK,linha);
    glTranslatef(camX,camY,camZ);
    glRotatef(a,0.0,1.0,0.0);
    glRotatef(w,1.0,0.0,0.0);
	glBegin(GL_TRIANGLES);

	int inicia = 1;
	int j;

	for(j = 0; j < aplicacoes.size(); j++){

		glPushMatrix();
		Transformacao t = aplicacoes[j].getTransformacao();

		glRotatef(t.getRotacao().getAngulo(), t.getRotacao().geteixoX(), t.getRotacao().geteixoY(), t.getRotacao().geteixoZ());
		glTranslatef(t.getTranslacao().getX(), t.getTranslacao().getY(), t.getTranslacao().getZ());
		glScalef(t.getEscala().getX(), aplicacoes[j].getTransformacao().getEscala().getY(), aplicacoes[j].getTransformacao().getEscala().getZ());
		glColor3f(t.getCor().getR(), t.getCor().getG(), t.getCor().getB());
		pontos.clear();
		pontos = aplicacoes[j].getPontos();

		glBegin(GL_TRIANGLES);

		if (inicia) {
			glColor3f(1.0f,1.0f,0.0f);
			inicia = 0;
		} else {
			glColor3f(t.getCor().getR(), t.getCor().getG(), t.getCor().getB());
		}

		for (int i = 0; i < pontos.size(); i++){
			glVertex3f(pontos[i].getX(), pontos[i].getY(), pontos[i].getZ());
		}
		
		glEnd();
		glPopMatrix();

	}

	glEnd();

	// End of frame
	glutSwapBuffers();
}



void keyboardspecial(int key_code, int x , int y){
	switch(key_code){
		case GLUT_KEY_UP: 	camY+=1;
						 	break;
		case GLUT_KEY_DOWN:	camY-=1;
							break;
		case GLUT_KEY_LEFT: camX-=1;
							break;
		case GLUT_KEY_RIGHT:camX+=1; 
							break;
	}
	glutPostRedisplay();
}

void letrasKeyboard(unsigned char key, int x, int y){
	switch (key) {
		
		case 'a':	
		case 'A': a+=3;
			break;
	
		case 'd':
		case 'D': a-=3;
			break;

		case 'w': 
		case 'W': w+=3;
			break;

		case 's':
		case 'S': w-=3;
			break;

		case 'p':
		case 'P': linha = GL_POINT;
			break;

		case 'l':
		case 'L': linha = GL_LINE;
	   	    break;

		case 'o':
		case 'O': linha = GL_FILL;
			break;

		case '-': gluLookAt(zx+=2,zy+=2,zz+=2,0.0,0.0,0.0,0.0f,1.0f,0.0f);
			break;

		case '+': gluLookAt(zx-=2,zy-=2,zz-=2,0.0,0.0,0.0,0.0f,1.0f,0.0f);
			break;

		case 'r':
		case 'R': glColor3f(R,G-=0.05,B-= 0.05);
			break;

		case 't':
		case 'T': glColor3f(R,G+=0.05,B+= 0.05);
			break;

		case 'g':
		case 'G': glColor3f(R-=0.05,G,B-=0.05);
			break;

		case 'h':
		case 'H': glColor3f(R+=0.05,G,B+=0.05);
			break;

		case 'b':
		case 'B': glColor3f(R-=0.05,G-=0.05,B);
			break;

		case 'n':
		case 'N': glColor3f(R+=0.05,G+=0.05,B);
			break;

		case 'c':
		case 'C':{
					glColor3f(R=1,G=1,B=1); 
					gluLookAt(zx=6,zy=6,zz=6,0.0,0.0,0.0,0.0f,1.0f,0.0f);
					glTranslatef(camX=0 ,camY=0,camZ=0);
					glRotatef(a=1,0,1,0);
    				glRotatef(w=1,1,0,0);
    				linha = GL_LINE;

				 }
			break;	
	}

	glutPostRedisplay();
}


void lerficheiro(string ficheiro) {

	string linha,token,delimiter = ",";
	Ponto p;
	int pos;
	double a,b,c;

	ifstream file(ficheiro);
	if (file.is_open()){

		while(getline(file,linha)){

			pos = linha.find(delimiter);
			token = linha.substr(0,pos);
			a = atof(token.c_str());
			linha.erase(0,pos + delimiter.length());
			p.setX(a);

			pos = linha.find(delimiter);
			token = linha.substr(0,pos);
			b = atof(token.c_str());
			linha.erase(0,pos + delimiter.length());
			p.setY(b);

			pos = linha.find(delimiter);
			token = linha.substr(0, pos);
			c = atof(token.c_str());
			linha.erase(0, pos + delimiter.length());
			p.setZ(c);

			pontos.push_back(p);
		}
		file.close();			
	}
	else {
		cout << "ERRO AO LER O FICHEIRO" << endl;
	}

}



Transformacao alteracaoValores(Translacao tr , Escala es , Rotacao ro , Cor cr, Transformacao transf){


	Transformacao valores;
	tr.setX(tr.getX() + transf.getTranslacao().getX());
	tr.setY(tr.getY() + transf.getTranslacao().getY());
	tr.setZ(tr.getZ() + transf.getTranslacao().getZ());
	ro.setAngulo(ro.getAngulo() + transf.getRotacao().getAngulo());
	ro.setEixoX(ro.geteixoX() + transf.getRotacao().geteixoX());
	ro.setEixoY(ro.geteixoY() + transf.getRotacao().geteixoY());
	ro.setEixoZ(ro.geteixoZ() + transf.getRotacao().geteixoZ());
	es.setX(es.getX() * transf.getEscala().getX());
	es.setY(es.getY() * transf.getEscala().getY());
	es.setZ(es.getZ() * transf.getEscala().getZ());
	cr.setR(cr.getR());
	cr.setG(cr.getG());
	cr.setB(cr.getB());

	valores = Transformacao::Transformacao(tr,ro,es,cr);

	return valores;
}




// Parse do xml tendo em conta os níveis hirarquicos
void parseNivelado(XMLElement *grupo , Transformacao transf){
	
	Transformacao trans;
	Translacao tr;
	Rotacao ro;
	Escala es = Escala::Escala(1,1,1);
	Cor cr;
	float ang, rotX, rotY, rotZ, transX, transY, transZ, escX, escY, escZ, tx, ty, tz;
	ang = rotX = rotY = rotZ = transX = transY = transZ = escX = escY = escZ = 1;

	if (strcmp(grupo->FirstChildElement()->Value(), "grupo") == 0)
		grupo = grupo->FirstChildElement();


	//transformações para um grupo
	XMLElement* transformacao = grupo->FirstChildElement();

	for (transformacao; (strcmp(transformacao->Value(), "modelos") != 0); transformacao = transformacao->NextSiblingElement()) {
		if (strcmp(transformacao->Value(), "translacao") == 0){
			if(transformacao->Attribute("X")) 
				transX = stof(transformacao->Attribute("X"));
			else transX = 0;
			if (transformacao->Attribute("Y"))
				 transY = stof(transformacao->Attribute("Y"));
			else transY = 0;
			if (transformacao->Attribute("Z")) 
				transZ = stof(transformacao->Attribute("Z"));
			else transZ = 0;
			tr = Translacao::Translacao(transX, transY, transZ);
		}
		if (strcmp(transformacao->Value(), "rotacao") == 0){
			if (transformacao->Attribute("angulo")) 
				ang = stof(transformacao->Attribute("angulo"));
			else ang = 0;
			if (transformacao->Attribute("eixoX")) 
				rotX = stof(transformacao->Attribute("eixoX"));
			else rotX = 0;
			if (transformacao->Attribute("eixoY")) 
				rotY = stof(transformacao->Attribute("eixoY"));
			else rotY = 0;
			if (transformacao->Attribute("eixoZ")) 
				rotZ = stof(transformacao->Attribute("eixoZ"));
			else rotZ = 0;
			ro = Rotacao::Rotacao(ang, rotX, rotY, rotZ);
		}
		if (strcmp(transformacao->Value(), "escala") == 0){
			if (transformacao->Attribute("X")) 
				escX = stof(transformacao->Attribute("X"));
			else escX = 1;
			if (transformacao->Attribute("Y")) 
				escY = stof(transformacao->Attribute("Y"));
			else escY = 1;
			if (transformacao->Attribute("Z")) 
				escZ = stof(transformacao->Attribute("Z"));
			else escZ = 1;
			es.setX(escX);
			es.setY(escY);
			es.setZ(escZ);
		}
		if (strcmp(transformacao->Value(), "cor") == 0) {
			if (transformacao->Attribute("R"))
				tx = stof(transformacao->Attribute("R"));
			else tx = 0;
			if (transformacao->Attribute("G"))
				ty = stof(transformacao->Attribute("G"));
			else ty = 0;
			if (transformacao->Attribute("B"))
				tz = stof(transformacao->Attribute("B"));
			else tz = 0;
			cr.setR(tx);
			cr.setG(ty);
			cr.setB(tz);
		}
			
	}
	

	trans = alteracaoValores(tr, es, ro, cr, transf);

	for (XMLElement* modelo = grupo->FirstChildElement("modelos")->FirstChildElement("modelo"); modelo; modelo = modelo->NextSiblingElement("modelo")) {
		
		Aplicacao app;
		app.setNome(modelo->Attribute("ficheiro"));
		cout << app.getNome() << endl;
		lerficheiro(app.getNome());
		app.setPontos(pontos);
		pontos.clear();

		app.setTransformacao(trans);


		cout << "Translacao: " << trans.getTranslacao().getX() << " - " << trans.getTranslacao().getY() << " - " << trans.getTranslacao().getZ() << endl;
		cout << "Rotacao   : " << trans.getRotacao().getAngulo() << " - " << trans.getRotacao().geteixoX() << " - " << trans.getRotacao().geteixoY() << " - " << trans.getRotacao().geteixoZ() << endl;
		cout << "Escala    : " << trans.getEscala().getX() << " - " << trans.getEscala().getY() << " - " << trans.getEscala().getZ() << endl;
		cout << "Cor       : " << trans.getCor().getR() << " - " << trans.getCor().getG() << " - " << trans.getCor().getB() << endl;

		aplicacoes.push_back(app);
	}

	//verifica os grupos dos filhos
	if (grupo->FirstChildElement("grupo")) {
		parseNivelado(grupo->FirstChildElement("grupo"), trans);
	}

	//verifica os grupos dos irmãos
	if (grupo->NextSiblingElement("grupo")) {
		parseNivelado(grupo->NextSiblingElement("grupo"), transf);
	}

}


// Leitura do ficheiro XML
void lerXML(string ficheiro) {
	XMLDocument docxml;
	
	if (!(docxml.LoadFile(ficheiro.c_str()))) {
		
		XMLElement * cena = docxml.FirstChildElement("cena");
		XMLElement * grupo = cena -> FirstChildElement("grupo");

	
		Transformacao t = Transformacao::Transformacao();
		Escala esc = Escala::Escala(0.4,0.4,0.4);
		t.setEscala(esc);
		parseNivelado(grupo, t);
	}
	else {
		cout << "Ficheiro XML não foi encontrado" << endl;
	}
}





int main(int argc, char **argv) {


    if(argc > 1){
		


	// put GLUT init here

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(580,150);
    glutInitWindowSize(1200,800);
    glutCreateWindow("Projeto_de_CG"); 

    // leitura do ficheiro xml
    lerXML(argv[1]);


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

	
   }
 	return 0;
	
  }

