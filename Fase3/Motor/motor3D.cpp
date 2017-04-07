#include "motor3D.h"


//vetor com os pontos lidos do ficheiro
vector<Ponto> pontos;

// vetor de aplicacoes
vector<Aplicacao> aplicacoes;




float R = 1, G = 1, B = 1;
float size;
float w = 1;
float xrot= 0, yrot = 0, zpos = 30, xpos = 0;
float zx = 6, zy = 6, zz = -4;


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
    glTranslatef(0, -1, zz);
    
    //define ship
	defineShip();
    

    glRotatef(xrot,1.0,0.0,0.0);
    glRotatef(yrot,0.0,1.0,0.0);
    glTranslated(-xpos,0,-zpos);
    
	glBegin(GL_TRIANGLES);

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

	
		glColor3f(t.getCor().getR(), t.getCor().getG(), t.getCor().getB());

		for (int i = 0; i < pontos.size(); i++){
			glVertex3f(pontos[i].getX(), pontos[i].getY(), pontos[i].getZ());
		}
		
		glEnd();
		glPopMatrix();

	}

	glEnd();


    glColor3f(0.4f,0.21f,0.0f);
    glPushMatrix();
        glScalef(1.8,0.5,1.8);
        glTranslated(52.7,0,0);
        glRotatef(120.0, 1.0, 0.0, 0.0);
        glutWireTorus(0.25,1.75,28,28);
    glPopMatrix();

	// End of frame
	glutSwapBuffers();
}



void keyboardspecial(int key_code, int x , int y){
	switch(key_code){
		case GLUT_KEY_UP: 	if(xrot > -45) xrot-=5;
                  			if (xrot < -360) xrot += 360;
                  			break;
		case GLUT_KEY_DOWN:	if(xrot < 45) xrot +=5;
                  			if (xrot >360) xrot -= 360;
                  			break;
		case GLUT_KEY_LEFT: yrot-=5;
                  			if (yrot < -360) yrot += 360;
                  			break;
		case GLUT_KEY_RIGHT:yrot +=5;
                  			if (yrot >360) yrot -= 360;
                  			break;
	}
	glutPostRedisplay();
}

void letrasKeyboard(unsigned char key, int x, int y){
	switch (key) {
        case'a':
        case'A': xpos -=cos(yrot /180 * 3.141592653589793);
                 zpos -=sin(yrot /180 * 3.141592653589793);
                 break;

        case'd':
        case'D': xpos +=cos(yrot /180 * 3.141592653589793);
                 zpos +=sin(yrot /180 * 3.141592653589793);
                 break;

        case'w':
        case'W': zpos -=cos(yrot /180 * 3.141592653589793);
                 xpos +=sin(yrot /180 * 3.141592653589793);
                 break;

        case's':
        case'S': zpos +=1 * cos(yrot /180 * 3.141592653589793);
                 xpos -=1 * sin(yrot /180 * 3.141592653589793);
                 break;

		case '+': glTranslatef(zx+=1, zy+=1, zz+=1);
			break;

		case '-': 	glTranslatef(zx-=1, zy-=1, zz-=1);
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
	Escala es;
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
		Escala esc = Escala::Escala(0.5,0.5,0.5);
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
    
	
	// enter GLUT's main loop
	glutMainLoop(); 

	
   }
 	return 0;
	
  }

