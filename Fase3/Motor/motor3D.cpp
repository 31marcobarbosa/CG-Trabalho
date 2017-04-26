#include "motor3D.h"


//vetor com os pontos lidos do ficheiro
vector<Ponto> pontos;

// vetor de aplicacoes
vector<Aplicacao> aplicacoes;



// Vars. para utilização rato e teclado
float R = 1, G = 1, B = 1;
float size;
float w = 1;
float xrot= 0, yrot = 0, zrot = 0, zpos = 0, xpos = 0 , ypos = 0;
float zx = -30, zy = 30, zz = 20;
int line = GL_LINE;
float rato = 0, ratoX, ratoY;
int alpha = 0 , beta = 0;

//Vars. para fps
int frame = 0 , timeb = 0;



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


void fps() {
	float fpsec;
	int time;
	char sol[64];

	frame++;
	time = glutGet(GLUT_ELAPSED_TIME);

	if (time - timeb > 1000) {
		fpsec = frame*1000.0 / (time - timeb);
		timeb = time;
		frame = 0;
		sprintf(sol,"FPS: %f6.2",fpsec);
		glutSetWindowTitle(sol);
	}
}

// função que desenha as órbitas 
void renderCatmullRomCurve( vector<Ponto> pontos) {
	int x = pontos.size();
	float npts[3];
	int i;

	glBegin(GL_LINE_LOOP);

	for(i=0; i < x ; i ++) {
		npts[0] = pontos[i].getX();
		npts[1] = pontos[i].getY();
		npts[2] = pontos[i].getZ();

		glVertex3fv(npts);
		}
	
	glEnd();
 }


void renderScene(void) {
	
	int j , k;
	float res[3];
	float tget, gt, rt, gr;


	// clear buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // set the camera
    glLoadIdentity();
    gluLookAt(zx, zy, zz,
		0.0, 0.0, 0.0,
		0.0f, 1.0f, 0.0f);
    

    glRotatef(xrot,1.0,0.0,0.0);
    glRotatef(yrot,0.0,1.0,0.0);
    glRotatef(yrot,0.0,0.0,1.0);
    glTranslatef(xpos,ypos,zpos);
    

	

	for(j = 0; j < aplicacoes.size(); j++){

		glPushMatrix();
		Transformacao t = aplicacoes[j].getTransformacao();

		//desenhar os planetas
		if(t.getTranslacao().getTempo() != 0) {
			tget = glutGet(GLUT_ELAPSED_TIME) % (int)(t.getTranslacao().getTempo() *1000);
			gt = tget / (t.getTranslacao().getTempo() * 1000);
			vector<Ponto> vecpts = t.getTranslacao().getPontosTrans();
			renderCatmullRomCurve(t.getTranslacao().getPontosCurva());
			t.getTranslacao().getGlobalCatmullRomPoint(gt,res,vecpts);
			vecpts.clear();
			glTranslatef(res[0],res[1],res[2]);
		}

		if(t.getRotacao().getTempo() != 0){
			rt = glutGet(GLUT_ELAPSED_TIME) % (int)(t.getRotacao().getTempo() * 1000);
			gr = (rt * 360) / (t.getRotacao().getTempo() * 1000);
			glRotatef(gr,t.getRotacao().geteixoX(),t.getRotacao().geteixoY(),t.getRotacao().geteixoZ());
		}
		glScalef(t.getEscala().getX(),t.getEscala().getY(),t.getEscala().getZ());


		// desenhar luas e anéis
		if(aplicacoes[j].getFilhos().size() != 0) {
			vector<Aplicacao> filhos = aplicacoes[j].getFilhos();

			for(k = 0; k < filhos.size(); k++) {
				glPushMatrix();
				Transformacao transfilho = filhos[k].getTransformacao();

				if(transfilho.getTranslacao().getTempo() != 0) {
					tget = glutGet(GLUT_ELAPSED_TIME) % (int)(transfilho.getTranslacao().getTempo() *1000);
					gt = tget / (transfilho.getTranslacao().getTempo() * 1000);
					vector<Ponto> fvpts = transfilho.getTranslacao().getPontosTrans();
					renderCatmullRomCurve(transfilho.getTranslacao().getPontosTrans());
					transfilho.getTranslacao().getGlobalCatmullRomPoint(gt, res, fvpts);
					fvpts.clear();
					glTranslatef(res[0],res[1],res[2]);
				}

				if(transfilho.getRotacao().getTempo() != 0 ){
					rt = glutGet(GLUT_ELAPSED_TIME) % (int)(transfilho.getRotacao().getTempo() * 1000);
					gr = (rt * 360) / (transfilho.getRotacao().getTempo() * 1000);
					glRotatef(gr,transfilho.getRotacao().geteixoX(),transfilho.getRotacao().geteixoY(),transfilho.getRotacao().geteixoZ());
				}
				glScalef(transfilho.getEscala().getX(),transfilho.getEscala().getY(),transfilho.getEscala().getZ());

			//	filhos[k].draw();

				glPopMatrix();
			}
		}

		// VBO'S
		// faz no initGL
		//aplicacoes[j].prep();
		aplicacoes[j].draw();

		
		//aplicacoes[j].construir();

		glPopMatrix();

		}
		
	fps();
	glutSwapBuffers();
}



void resetCamara() {
	xpos = ypos = zpos = 0.0f;
	xrot = yrot = zrot = 0.0f;
	alpha = 0;
	beta = 0;
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

        case 'p':
		case 'P': line = GL_POINT;
				  break;

		case 'l':
		case 'L': line = GL_LINE;
	   	   		  break;

		case 'o':
		case 'O': line = GL_FILL;
				  break;

		case 'r':
		case 'R': resetCamara(); break;

		case '+': glTranslatef(zx+=1, zy+=1, zz+=1);
			break;

		case '-': 	glTranslatef(zx-=1, zy-=1, zz-=1);
			break;	
	}

	glutPostRedisplay();
}


void botoesRato(int but , int stt , int x , int y) {

	if( but == GLUT_LEFT_BUTTON){
		if (stt == GLUT_DOWN) {
			rato = 1;
			ratoX = x;
			ratoY = y;
		}
		else if ( stt == GLUT_UP)
				rato = 0;
	}
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
	es.setX(es.getX() * transf.getEscala().getX());
	es.setY(es.getY() * transf.getEscala().getY());
	es.setZ(es.getZ() * transf.getEscala().getZ());
	
	valores = Transformacao::Transformacao(tr,ro,es,cr);

	return valores;
}




// Parse do xml tendo em conta os níveis hirarquicos
void parseNivelado(tinyxml2::XMLElement *grupo , Transformacao transf, char pai){
	
	Transformacao trans;
	Translacao tr;
	Rotacao ro;
	Escala es;
	Cor cr;
	float tmp, rotX, rotY, rotZ, transX, transY, transZ, escX, escY, escZ, tx, ty, tz, ang, time;
	ang = rotX = rotY = rotZ = transX = transY = transZ = escX = escY = escZ = 1;

	if (strcmp(grupo->FirstChildElement()->Value(), "group") == 0)
		grupo = grupo->FirstChildElement();


	//transformações para um grupo
	tinyxml2::XMLElement* transformacao = grupo->FirstChildElement();

	for (; (strcmp(transformacao->Value(), "models") != 0); transformacao = transformacao->NextSiblingElement()) {
		
		if (strcmp(transformacao->Value(), "translate") == 0){

				vector<Ponto> translPontos;
				tinyxml2::XMLElement* ponto;

				if(transformacao->Attribute("time")) {
					time = stof(transformacao->Attribute("time"));
				} 
				else {
					time = 0;
				}

				for (ponto = transformacao->FirstChildElement("point"); ponto; ponto = ponto->NextSiblingElement("point")) {


					if(transformacao->Attribute("X")) 
						 transX = stof(transformacao->Attribute("X"));
					else transX = 0;
					if (transformacao->Attribute("Y"))
						 transY = stof(transformacao->Attribute("Y"));
					else transY = 0;
					if (transformacao->Attribute("Z")) 
						transZ = stof(transformacao->Attribute("Z"));
					else transZ = 0;
					
					Ponto pontt = Ponto::Ponto(transX,transY,transZ);	 
					translPontos.push_back(pontt);
				}

				tr = Translacao::Translacao(time,translPontos,translPontos.size());
				tr.desenhaCurvas();

	}

		if (strcmp(transformacao->Value(), "rotate") == 0){
			if (transformacao->Attribute("time")) 
				tmp = stof(transformacao->Attribute("time"));
			else tmp = 0;
			if (transformacao->Attribute("eixoX")) 
				rotX = stof(transformacao->Attribute("eixoX"));
			else rotX = 0;
			if (transformacao->Attribute("eixoY")) 
				rotY = stof(transformacao->Attribute("eixoY"));
			else rotY = 0;
			if (transformacao->Attribute("eixoZ")) 
				rotZ = stof(transformacao->Attribute("eixoZ"));
			else rotZ = 0;
			ro = Rotacao::Rotacao(rotX, rotY, rotZ, tmp);
		}
		if (strcmp(transformacao->Value(), "scale") == 0){
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
		if (strcmp(transformacao->Value(), "colour") == 0) {
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

	for (tinyxml2::XMLElement* modelo = grupo->FirstChildElement("models")->FirstChildElement("model"); modelo; modelo = modelo->NextSiblingElement("model")) {
		
		Aplicacao app;
		app.setNome(modelo->Attribute("file"));
		cout << app.getNome() << endl;
		lerficheiro(app.getNome());
		app.setPontos(pontos);
		pontos.clear();

		app.setTransformacao(trans);


		cout << "Translacao: " << trans.getTranslacao().getTempo() << endl;
		cout << "Rotacao   : " << trans.getRotacao().getTempo() << " , " << trans.getRotacao().geteixoX() << " , " << trans.getRotacao().geteixoY() << " , " << trans.getRotacao().geteixoZ() << endl;
		cout << "Escala    : " << trans.getEscala().getX() << " , " << trans.getEscala().getY() << " , " << trans.getEscala().getZ() << endl;
		cout << "Cor       : " << trans.getCor().getR() << " , " << trans.getCor().getG() << " , " << trans.getCor().getB() << endl;


		int qtd = aplicacoes.size()-1;

		if( pai == 'F') {
			aplicacoes[qtd].setFilho(app);
		}
		else if (pai == 'P') {
			aplicacoes[qtd].setFilho(app);
		}
		else {
			aplicacoes.push_back(app);
		}

	}

	//verifica o caso se for filho e tiver irmaos
	if ((grupo->NextSiblingElement("group"))  && (pai == 'F' || pai == 'P')) {
		parseNivelado(grupo->NextSiblingElement("group"), transf,'P');
	}

	//verifica o caso de possuir filhos
	if (grupo->FirstChildElement("group")) {
		cout << "Teste ao filho" << endl;
		parseNivelado(grupo->FirstChildElement("group"), trans, 'F');
	}

	//verifica os grupos dos irmãos
	if ((grupo->NextSiblingElement("group")) && (pai != 'F' || pai != 'P') ) {
		cout << "teste ao irmao " << endl;
		parseNivelado(grupo->NextSiblingElement("group"), transf,'I');
	}

}


// Leitura do ficheiro XML
void lerXML(string ficheiro) {
	XMLDocument docxml;
	
	if (!(docxml.LoadFile(ficheiro.c_str()))) {
		
		tinyxml2::XMLElement * cena = docxml.FirstChildElement("scene");
		tinyxml2::XMLElement * grupo = cena -> FirstChildElement("group");

	
		Transformacao t = Transformacao::Transformacao();
		Escala esc = Escala::Escala();
		Translacao translacao = Translacao::Translacao();
		t.setEscala(esc);
		t.setTranslacao(0.0);
		parseNivelado(grupo, t, 'I');
	}
	else {
		cout << "Ficheiro XML não foi encontrado" << endl;
	}
}


void initGL() {

	size_t j = 0, w = 0;

	// definições para o OpenGL
	glPolygonMode(GL_FRONT, GL_LINE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	// incialização dos VBOs
	for (; j < aplicacoes.size(); j++){
		aplicacoes[j].prep();

		if (aplicacoes[j].getFilhos().size() != 0){
			vector<Aplicacao> filhos = aplicacoes[j].getFilhos();
			for (; w < filhos.size(); w++){
				filhos[w].prep();
			}
			aplicacoes[j].setFilhos(filhos);
		}
	}
}


int main(int argc, char **argv){


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
    glutIdleFunc(renderScene);
    glutReshapeFunc(changeSize);
   

    glutSpecialFunc(keyboardspecial);
    glutKeyboardFunc(letrasKeyboard);
    glutMouseFunc(botoesRato);
    
    //OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	

    //glewInit();

    initGL();


	//enter GLUT's main loop
	glutMainLoop();
	} 

return 0;
}












