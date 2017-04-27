#include "aplicacao.h"

Aplicacao::Aplicacao( ){
	transformacao = Transformacao::Transformacao();
	nome = "";
	filhos = vector<Aplicacao>();
	pontos = vector<Ponto>();
}

Aplicacao::Aplicacao(string n, vector<Aplicacao> a, vector<Ponto> p, Transformacao t){
	nome = n;
	filhos = a;
	pontos = p;
	transformacao = t;
}

void Aplicacao::construir() {
	int i;
	int totalpts = pontos.size();

	glBegin(GL_TRIANGLES);

	for(i=0; i< totalpts ; i++) {

		glVertex3f(pontos.at(i).getX() , pontos.at(i).getY(), pontos.at(i).getZ());
	}

	glEnd();
}


void Aplicacao::prep() {

	int n , pptam;
	size_t i;
	n = i = 0;
	pptam = pontos.size();

	glEnableClientState(GL_VERTEX_ARRAY);

	v = (float *)malloc(sizeof(float)* pptam*3);

	for(; i < pptam; i++) {
		v[n] = pontos[i].getX();
		v[n + 1] = pontos[i].getY();
		v[n + 2] = pontos[i].getZ();
		n += 3; 
	}

	nvertices = n;

	glGenBuffers(1,buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * nvertices, v, GL_STATIC_DRAW);

	free(v);
}
	

void Aplicacao::draw() {

	
	glBindBuffer(GL_ARRAY_BUFFER, buffer[0]);
	glVertexPointer(3 , GL_FLOAT, 0 , 0);
	glDrawArrays(GL_TRIANGLES,0, nvertices);
}



