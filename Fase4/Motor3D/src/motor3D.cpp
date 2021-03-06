#include "motor3D.h"


// Vetores com os pontos lidos do ficheiro:
vector<Ponto> pontos;
vector<Ponto> normais;
vector<Ponto> texturas;

// Aplicacao do sistema solar
vector<Aplicacao> aplicacoes;

#define CONST 1.0f;

// Variaveis para utilização do teclado e rato:
float radius = 5.0f;
float camX = -30, camY = 30, camZ = 20;
float anguloX = 0.0f, anguloY = 0.0f, anguloZ = 0.0f;
float coordX = 0, coordY = 0, coordZ = 0;
int startX, startY, tracking = 0;
int alpha = 0, beta = 0, r = 5;
int line = GL_LINE;


/* FPS */
int timeb = 0, frame = 0;

/* Luz */
string tipo;
float posX, posY, posZ;



void fps(){
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

void changeSize(int w, int h){
	// Prevent a divide by zero, when window is too short
	// (you cant make a window with zero width).
	if (h == 0)
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
	gluPerspective(45.0f, ratio, 1.0f, 1000.0f);

	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
}


//Desenho das orbitas
void renderCatmullRomCurve(vector<Ponto> pontos, float r, float g, float b){
	int n = pontos.size();
	float pp[3];

	glBegin(GL_LINE_LOOP);
	
	for (int i = 0; i < n; i++) {
		pp[0] = pontos[i].getX(); 
		pp[1] = pontos[i].getY();
		pp[2] = pontos[i].getZ();
		glColor3f(r,g,b);
		glVertex3fv(pp);
	}
	glEnd();
}

void renderScene(void){
	float res[3];
	float te, gt, r, gr;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(camX, camY, camZ, 0.0, 0.0, 0.0, 0.0f, 1.0f, 0.0f);
	glRotatef(anguloX, 1, 0, 0);
	glRotatef(anguloY, 0, 1, 0);
	glRotatef(anguloZ, 0, 0, 1);
	glTranslatef(coordX, coordY, coordZ);

	
	for (size_t j = 0; j < aplicacoes.size(); j++){
		glPushMatrix();
		Transformacao t = aplicacoes[j].getTransformacao();
		
		
		if (j == 0) {
			GLfloat pos[4] = { posX, posY, posZ, 1 };
			GLfloat amb[3] = { 0.0, 0.0, 0.0 };
			GLfloat diff[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
			GLfloat matt[3] = { 1, 1, 1 };

			glMaterialf(GL_FRONT, GL_SHININESS, 20);
			glLightfv(GL_LIGHT0, GL_POSITION, pos); // posição da luz
			glLightfv(GL_LIGHT0, GL_AMBIENT, amb); // luz ambiente
			glLightfv(GL_LIGHT0, GL_DIFFUSE, diff); // luz difusa

			glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, matt);
		}
		else {
			GLfloat matt[3] = { 0, 0, 0 };
			glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, matt);
		}

		//Desenhar aplicacao (p.e. planetas)
		if (t.getTranslacao().getTime() != 0){

			te = glutGet(GLUT_ELAPSED_TIME) % (int)(t.getTranslacao().getTime() * 1000);
			gt = te / (t.getTranslacao().getTime() * 1000);
			vector<Ponto> vp = t.getTranslacao().getPontosTrans();
			renderCatmullRomCurve(t.getTranslacao().getPontosCurva(), t.getCor_Orbita().getR(),t.getCor_Orbita().getG(),t.getCor_Orbita().getB());
			t.getTranslacao().getGlobalCatmullRomPoint(gt, res, vp);
			vp.clear();
			glTranslatef(res[0], res[1], res[2]);
		}

		if (t.getRotacao().getTime() != 0){

			r = glutGet(GLUT_ELAPSED_TIME) % (int)(t.getRotacao().getTime() * 1000);
			gr = (r * 360) / (t.getRotacao().getTime() * 1000);
			glRotatef(gr, t.getRotacao().geteixoX(), t.getRotacao().geteixoY(), t.getRotacao().geteixoZ());
		}

		glScalef(t.getEscala().getX(), t.getEscala().getY(), t.getEscala().getZ());

		//Desenhar filhos (p.e. luas)
		if (aplicacoes[j].getFilhos().size() != 0){

			vector<Aplicacao> filhos = aplicacoes[j].getFilhos();
			for (size_t k = 0; k < filhos.size(); k++){
				glPushMatrix();
				Transformacao tfilho = filhos[k].getTransformacao();
				if (tfilho.getTranslacao().getTime() != 0){
					te = glutGet(GLUT_ELAPSED_TIME) % (int)(tfilho.getTranslacao().getTime() * 1000);
					gt = te / (tfilho.getTranslacao().getTime() * 1000);
					vector<Ponto> vp = tfilho.getTranslacao().getPontosTrans();
					renderCatmullRomCurve(tfilho.getTranslacao().getPontosCurva(),tfilho.getCor_Orbita().getR(),tfilho.getCor_Orbita().getG(),tfilho.getCor_Orbita().getB());
					tfilho.getTranslacao().getGlobalCatmullRomPoint(gt, res, vp);
					vp.clear();
					glTranslatef(res[0], res[1], res[2]);
				}

				if (tfilho.getRotacao().getTime() != 0){

					r = glutGet(GLUT_ELAPSED_TIME) % (int)(tfilho.getRotacao().getTime() * 1000);
					gr = (r * 360) / (tfilho.getRotacao().getTime() * 1000);
					glRotatef(gr, tfilho.getRotacao().geteixoX(), tfilho.getRotacao().geteixoY(), tfilho.getRotacao().geteixoZ());
				}

				glScalef(tfilho.getEscala().getX(), tfilho.getEscala().getY(), tfilho.getEscala().getZ());
				
				glBindTexture(GL_TEXTURE_2D, filhos[k].getTexID());
				glEnable(GL_LIGHTING);
				filhos[k].draw();
				glDisable(GL_LIGHTING);
				glBindTexture(GL_TEXTURE_2D, 0);

				glPopMatrix();
			}
		}
		
		//VBOs
		glBindTexture(GL_TEXTURE_2D, aplicacoes[j].getTexID());
		glEnable(GL_LIGHTING);
		aplicacoes[j].draw();	
		glDisable(GL_LIGHTING);
		glBindTexture(GL_TEXTURE_2D, 0);
		
		glPopMatrix();
	}

	fps();

	glutSwapBuffers();
}

// Funções de processamento do teclado
void resetCamara(){
	anguloX = anguloY = anguloZ = 0.0f;
	coordX = coordY = coordZ = 0;
	alpha = 0.0f;
	beta = 0.5f;
}

void normalkeyboard(unsigned char tecla, int x, int y){
	
	switch (tecla){
		case 'W':
		case 'w': anguloX += 5;
				  break;

		case 'S':;
		case 's': anguloX -= 5;
				  break;

		case 'A':
		case 'a': anguloY += 5;
				  break;

		case 'D':;
		case 'd': anguloY -= 5;
				  break;

		case 'q':
		case 'Q': anguloZ += 5;
				  break;

		case 'e':;
		case 'E': anguloZ -= 5; 
				  break;

		case 'R':
		case 'r': resetCamara();
				  break;

		case '+': coordY += 5; 
				  break;

		case '-': coordY -= 5; 
				  break;

		case 'f':
		case 'F': glDisable(GL_LIGHTING);
				  glDisable(GL_LIGHT0);	
				  break;

		case 'o':
		case 'O': glEnable(GL_LIGHTING);
				  glEnable(GL_LIGHT0);
				  break;
	}

	glutPostRedisplay();
}

void specialKeys(int key, int x, int y){
	
	switch (key) {
		case GLUT_KEY_UP: coordZ += 5.0f; 
						  break;

		case GLUT_KEY_DOWN: coordZ -= 5.0f;
							break;

		case GLUT_KEY_LEFT: coordX += 5;
							break;

		case GLUT_KEY_RIGHT: coordX -= 5;
							 break;
	}
}

// Funções de processamento do rato
void processMouseButtons(int button, int state, int xx, int yy){

	if (state == GLUT_DOWN){

		startX = xx;
		startY = yy;
		if (button == GLUT_LEFT_BUTTON)
			tracking = 1;
		else if (button == GLUT_RIGHT_BUTTON)
			tracking = 2;
		else
			tracking = 0;
	}

	else if (state == GLUT_UP){

		if (tracking == 1) {
			alpha += (xx - startX);
			beta += (yy - startY);
		}

		else if (tracking == 2){

			r -= yy - startY;
			if (r < 3)
				r = 3.0;
		}

		tracking = 0;
	}
}

void processMouseMotion(int xx, int yy){
	int deltaX, deltaY;
	int alphaAux, betaAux;
	int rAux;

	if (!tracking)
		return;

	deltaX = xx - startX;
	deltaY = yy - startY;

	if (tracking == 1) {
		alphaAux = alpha + deltaX;
		betaAux = beta + deltaY;

		if (betaAux > 85.0)
			betaAux = 85.0;
		else if (betaAux < -85.0)
			betaAux = -85.0;

		rAux = r;
	}
	else if (tracking == 2) {

		alphaAux = alpha;
		betaAux = beta;
		rAux = r - deltaY;
		if (rAux < 3)
			rAux = 3;
	}
	camX = rAux * sin(alphaAux * 3.14 / 180.0) * cos(betaAux * 3.14 / 180.0);
	camZ = rAux * cos(alphaAux * 3.14 / 180.0) * cos(betaAux * 3.14 / 180.0);
	camY = rAux * sin(betaAux * 3.14 / 180.0);
}

// Função de leitura do ficheiro com os pontos:
void readFile(string filename){
	string linha, token, delimiter = ",";
	int pos;
	double a, b, c;
	Ponto p;
	int npontos, camadasV, camadasH;
	int count = 0;

	ifstream file(filename);
	if (file.is_open()){

		//N de pontos
		getline(file, linha);
		pos = linha.find(delimiter);
		token = linha.substr(0, pos);
		npontos = atof(token.c_str());
		linha.erase(0, pos + delimiter.length());

		//Camadas horizontais
		getline(file, linha);
		pos = linha.find(delimiter);
		token = linha.substr(0, pos);
		camadasH = atof(token.c_str());
		linha.erase(0, pos + delimiter.length());

		//Camadas verticais
		getline(file, linha);
		pos = linha.find(delimiter);
		token = linha.substr(0, pos);
		camadasV = atof(token.c_str());
		linha.erase(0, pos + delimiter.length());

		//Pontos da aplicacao:
		while (count < npontos && getline(file, linha)){

			pos = linha.find(delimiter);
			token = linha.substr(0, pos);
			a = atof(token.c_str());
			linha.erase(0, pos + delimiter.length());
			p.setX(a);

			pos = linha.find(delimiter);
			token = linha.substr(0, pos);
			b = atof(token.c_str());
			linha.erase(0, pos + delimiter.length());
			p.setY(b);

			pos = linha.find(delimiter);
			token = linha.substr(0, pos);
			c = atof(token.c_str());
			linha.erase(0, pos + delimiter.length());
			p.setZ(c);

			pontos.push_back(p);
			count++;
		}

		//Normais da aplicacao:
		count = 0;
		while (count < npontos && getline(file, linha)){

			pos = linha.find(delimiter);
			token = linha.substr(0, pos);
			a = atof(token.c_str());
			linha.erase(0, pos + delimiter.length());
			p.setX(a);

			pos = linha.find(delimiter);
			token = linha.substr(0, pos);
			b = atof(token.c_str());
			linha.erase(0, pos + delimiter.length());
			p.setY(b);

			pos = linha.find(delimiter);
			token = linha.substr(0, pos);
			c = atof(token.c_str());
			linha.erase(0, pos + delimiter.length());
			p.setZ(c);

			normais.push_back(p);
			count++;
		}

		//Texturas da aplicacao:
		count = 0;
		while (count < npontos && getline(file, linha)){

			pos = linha.find(delimiter);
			token = linha.substr(0, pos);
			a = atof(token.c_str());
			linha.erase(0, pos + delimiter.length());
			p.setX(a);

			pos = linha.find(delimiter);
			token = linha.substr(0, pos);
			b = atof(token.c_str());
			linha.erase(0, pos + delimiter.length());
			p.setY(b);

			pos = linha.find(delimiter);
			token = linha.substr(0, pos);
			c = atof(token.c_str());
			linha.erase(0, pos + delimiter.length());
			p.setZ(c);

			texturas.push_back(p);
			count++;
		}

		file.close();
	}

	else{
		cout << "Nao foi possivel ler o ficheiro" << endl;
	}
	
}

void parseGrupo(XMLElement* grupo, Transformacao transf, char parent){
	Transformacao trans;
	Translacao tr;
	Rotacao ro;
	Escala es;
	Cor_Orbita cr;
	float rotX, rotY, rotZ, transX, transY, transZ, escX, escY, escZ, corR, corG,corB, time;
	rotX = rotY = rotZ = transX = transY = transZ = escX = escY = escZ = corR = corG = corB = 1;

	if (strcmp(grupo->FirstChildElement()->Value(), "grupo") == 0)
		grupo = grupo->FirstChildElement();

	//transformações para um grupo
	XMLElement* transformacao = grupo->FirstChildElement();

	for (transformacao; (strcmp(transformacao->Value(), "modelos") != 0); transformacao = transformacao->NextSiblingElement()){

		if (strcmp(transformacao->Value(), "translacao") == 0){

			if(transformacao->Attribute("tempo")) time = stof(transformacao->Attribute("tempo"));
			else time = 0;
			
			//procurar todos os pontos e guardá-los num vetor de pontos
			vector<Ponto> trpontos;
			
			for (XMLElement* ponto = transformacao->FirstChildElement("ponto"); ponto; ponto = ponto->NextSiblingElement("ponto")){
				transX = transY = transZ = 0;

				if (ponto->Attribute("X"))
					transX = stof(ponto->Attribute("X"));

				if (ponto->Attribute("Y"))
					transY = stof(ponto->Attribute("Y"));

				if (ponto->Attribute("Z"))
					transZ = stof(ponto->Attribute("Z"));

				Ponto pt = Ponto::Ponto(transX, transY, transZ);
				trpontos.push_back(pt);
			}

			tr = Translacao::Translacao(time, trpontos, trpontos.size());
			tr.execCurvas();
		}

		if (strcmp(transformacao->Value(), "rotacao") == 0){

			if (transformacao->Attribute("tempo")) time = stof(transformacao->Attribute("tempo"));
			else time = 0;
			if (transformacao->Attribute("eixoX")) rotX = stof(transformacao->Attribute("eixoX"));
			else rotX = 0;
			if (transformacao->Attribute("eixoY")) rotY = stof(transformacao->Attribute("eixoY"));
			else rotY = 0;
			if (transformacao->Attribute("eixoZ")) rotZ = stof(transformacao->Attribute("eixoZ"));
			else rotZ = 0;
			ro = Rotacao::Rotacao(rotX, rotY, rotZ, time);
		}

		if (strcmp(transformacao->Value(), "escala") == 0){

			if (transformacao->Attribute("X")) escX = stof(transformacao->Attribute("X"));
			else escX = 1;
			if (transformacao->Attribute("Y")) escY = stof(transformacao->Attribute("Y"));
			else escY = 1;
			if (transformacao->Attribute("Z")) escZ = stof(transformacao->Attribute("Z"));
			else escZ = 1;
			es.setX(escX);
			es.setY(escY);
			es.setZ(escZ);
		}

		if (strcmp(transformacao->Value(), "cor_orbita") == 0){

			if (transformacao->Attribute("R")) corR = stof(transformacao->Attribute("R"));
			else corR = 1;
			if (transformacao->Attribute("G")) corG = stof(transformacao->Attribute("G"));
			else corG = 1;
			if (transformacao->Attribute("B")) corB = stof(transformacao->Attribute("B"));
			else corG = 1;
			cr = Cor_Orbita::Cor_Orbita(corR,corG,corB);
		}
	}

	//Calculo da escala em relaçao ao pai
	if (parent == 'F'){
		es.setX(es.getX() * transf.getEscala().getX());
		es.setY(es.getY() * transf.getEscala().getY());
		es.setZ(es.getZ() * transf.getEscala().getZ());
	}
	trans = Transformacao::Transformacao(tr, ro, es, cr);
		
	//para o mesmo grupo, quais os modelos que recebem as transformações
	for (XMLElement* modelo = grupo->FirstChildElement("modelos")->FirstChildElement("modelo"); modelo; modelo = modelo->NextSiblingElement("modelo")){
		
		Aplicacao p;
		p.setNome(modelo->Attribute("ficheiro"));
		if (modelo->Attribute("textura")) p.setTextura(modelo->Attribute("textura"));
		cout << p.getNome() << endl;
		readFile(p.getNome());
		p.setPontos(pontos);
		p.setNormais(normais);
		p.setTexturas(texturas);
		pontos.clear();
		normais.clear();
		texturas.clear();

		p.setTransformacao(trans);

		cout << "Translacao: " << trans.getTranslacao().getTime() << endl;
		cout << "Rotacao   : " << trans.getRotacao().getTime() << " - " << trans.getRotacao().geteixoX() << " - " << trans.getRotacao().geteixoY() << " - " << trans.getRotacao().geteixoZ() << endl;
		cout << "Escala    : " << trans.getEscala().getX() << " - " << trans.getEscala().getY() << " - " << trans.getEscala().getZ() << endl;
		cout << "Cor    : " << trans.getCor_Orbita().getR() << " - " << trans.getCor_Orbita().getG() << " - " << trans.getCor_Orbita().getB() << endl;

		if (parent == 'F'){
			int q = aplicacoes.size() - 1;
			aplicacoes[q].setFilho(p);
		}
		else if (parent == 'P'){
			int q = aplicacoes.size() - 1;
			aplicacoes[q].setFilho(p);
		}
		else aplicacoes.push_back(p);
	}

	//Se for filho e tiver irmaos:
	if (grupo->NextSiblingElement("grupo") && (parent == 'F' || parent == 'P')){
		parseGrupo(grupo->NextSiblingElement("grupo"), transf, 'P');
	}

	//Se tiver elementos "filhos":
	if (grupo->FirstChildElement("grupo")){
		cout << "Filho:" << endl;
		parseGrupo(grupo->FirstChildElement("grupo"), trans, 'F');
	}

	//Elementos "irmãos"
	if (grupo->NextSiblingElement("grupo") && parent != 'F' && parent != 'P'){
		parseGrupo(grupo->NextSiblingElement("grupo"), transf, 'I');
	}
}

// Função de leitura do ficheiro XML:
void readXML(string filename){

	XMLDocument doc;
	doc.LoadFile(filename.c_str());
	
	XMLElement* cena = doc.FirstChildElement("cena");
	XMLElement* luzes = cena->FirstChildElement("luzes");
	XMLElement* grupo = cena->FirstChildElement("grupo");
	XMLElement* luz = luzes->FirstChildElement("luz");
	tipo = luz->Attribute("tipo");
	posX = atof(luz->Attribute("posX")); 
	posY = atof(luz->Attribute("posY")); 
	posZ = atof(luz->Attribute("posZ"));
	
	
	Transformacao t = Transformacao::Transformacao();
	Escala e = Escala::Escala(1, 1, 1);
	Translacao trans = Translacao::Translacao();
	t.setTranslacao(trans);
	t.setEscala(e);
	parseGrupo(grupo, t, 'I');
}




void initGL(){

	// alguns settings para OpenGL
	glPolygonMode(GL_FRONT, GL_FILL);
	glEnable(GL_NORMALIZE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHT0);
	glEnable(GL_TEXTURE_2D);
	glShadeModel (GL_SMOOTH);
	
	// init para VBOs
	for (size_t j = 0; j < aplicacoes.size(); j++){
		aplicacoes[j].prep();

		if (aplicacoes[j].getFilhos().size() != 0){
			vector<Aplicacao> filhos = aplicacoes[j].getFilhos();
			for (size_t w = 0; w < filhos.size(); w++){
				filhos[w].prep();
			}
			aplicacoes[j].setFilhos(filhos);
		}
	}
}

int main(int argc, char **argv) {
	if (argc>1) {
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
		glutInitWindowPosition(580,150);
		glutInitWindowSize(800,800);
		glutCreateWindow("TP@CG");
		glutFullScreen();

		//Leitura do ficheiro XML:
		readXML(argv[1]);

		glutDisplayFunc(renderScene);
		glutIdleFunc(renderScene);
		glutReshapeFunc(changeSize);

		//Teclado
		glutKeyboardFunc(normalkeyboard);
		glutSpecialFunc(specialKeys);

		//Rato
		glutMouseFunc(processMouseButtons);
		glutMotionFunc(processMouseMotion);

		ilInit();
		ilEnable(IL_ORIGIN_SET);
		ilOriginFunc(IL_ORIGIN_LOWER_LEFT);

		#ifndef __APPLE__	
		glewInit();
		#endif	
		initGL();

		glutMainLoop();
	}
	return 1;
}