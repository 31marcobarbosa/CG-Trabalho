//#include "gerador.h"



#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <GL/glut.h>
#include <stdlib.h>

using namespace std;


 // meter as variaveis em ING

void plano(int lado, string nome) {

	ofstream file(nome);
	float x,y,z;
	y=0;

	//posicionamento do plano centrado com o eixo
	if ((lado % 2) == 0) {
		x = (float)lado / 2;
		z = (float)lado / 2;
	}
	else {
		x = (float)lado / 2 + 0.5;
		z = (float)lado / 2 + 0.5;
	}


	// Triangulo 1
	printf("%f %f %f\n",x,y,z);
		file << x << "," << y << "," << z << endl;
	printf("%f %f %f\n",x,y,-z);
		file << x << "," << y << "," << -z << endl;
	printf("%f %f %f\n",-x,y,-z);
		file << -x << "," << y << "," << -z << endl;


	// Triangulo 2
	printf("%f %f %f\n",-x,y,z);
		file << -x << "," << y << "," << z << endl;
	printf("%f %f %f\n",x,y,z);
		file << x << "," << y << "," << z << endl;
	printf("%f %f %f\n",-x,y,-z);
		file << -x << "," << y << "," << -z << endl;


	file.close();
}



void cubo(double comp, double larg, double alt, int camadas, string nome){
	double x, y, z, xx, yy, zz; //variaveis que variam ao longo dos eixos
	double espc, espl, espal; //espaçamento entre as camadas de comprimento, largura e 
	int i, j; //variáveis que serão usadas nos ciclos
	ofstream file(nome);

	//Espaçamentos
	espc = comp / camadas; 
	espl = larg / camadas; 
	espal = alt / camadas; 

	/*
	 * FACES DE CIMA E DE BAIXO
	 */
	y = alt / 2; 
	yy = -y; //y é usado para indicar a altura da face de cima e yy é a altura a que a base de baixo se encontrará
	z = larg / 2;		 //a variável z assume metade do valor da largura, ficando o poligono centrado no eixo do z

	for (i = 0; i < camadas; i++){
		x = -(comp / 2);  //a variável x assume metade do valor do comprimento, ficando o poligono centrado no eixo do x
		xx = x + espc;   //incrementa também o xx, para andar sempre à frente do x, para fazer o triângulo
 		zz = z - espl;  //decrementa o z, pois temos o z com o seu valor maximo positivo e para o plano ficar centrado temos que ir tirando o espaçamento entre as camadas de largura
		for (j = 0; j < camadas; j++){

			
			printf("%f %f %f\n", x, y, z); file <<  x << "," << y << "," << z << endl;
			printf("%f %f %f\n", xx, y, z); file << xx << "," << y << "," << z << endl;
			printf("%f %f %f\n", x, y, zz); file << x << "," << y << "," << zz << endl;
			
			printf("%f %f %f\n", xx, y, z); file << xx << "," << y << "," << z << endl;
			printf("%f %f %f\n", xx, y, zz); file << xx << "," << y << "," << zz << endl;
			printf("%f %f %f\n", x, y, zz); file << x << "," << y << "," << zz << endl;

			printf("%f %f %f\n", x, yy, z); file << x << "," << yy << "," << z << endl;
			printf("%f %f %f\n", x, yy, zz); file << x << "," << yy << "," << zz << endl;
			printf("%f %f %f\n", xx, yy, z); file << xx << "," << yy << "," << z << endl;
			
			printf("%f %f %f\n", xx, yy, z); file << xx << "," << yy << "," << z << endl;
			printf("%f %f %f\n", x, yy, zz); file << x << "," << yy << "," << zz << endl;
			printf("%f %f %f\n", xx, yy, zz); file << xx << "," << yy << "," << zz << endl;

			x = x + espc;   //incrementa o x, sendo o x assumindo o valor na proxima camada
			xx = xx + espc;//incrementa também o xx, para andar sempre à frente do x, para fazer o triângulo
		}
		z = z - espl;// z vai decrementando sempre o valor do espaçamento lateral, para ficar com as camadas certas na largura
	}


	
	x = -(comp / 2); // face da esqueda
	xx = -x; // face da direita
	y = -(alt / 2);//a altura onde se iniciam as faces laterais

	for (i = 0; i < camadas; i++){
		z = larg / 2;    //a variável z assume metade do valor da largura, ficando o poligono centrado no eixo do z
		zz = z - espl;  //decrementa o z, pois temos o z com o seu valor maximo positivo e para o plano ficar centrado temos que ir tirando o espaçamento entre as camadas de largura
		yy = y + espal;//para o poligono ficar centrado, começamos com y negativo, sendo o seu valor metade da altura

		for (j = 0; j < camadas; j++){
			
			printf("%f %f %f\n", x, y, z); file << x << "," << y << "," << z << endl;
			printf("%f %f %f\n", x, yy, z); file << x << "," << yy << "," << z << endl;
			printf("%f %f %f\n", x, yy, zz); file << x << "," << yy << "," << zz << endl;

			printf("%f %f %f\n", x, y, zz); file << x << "," << y << "," << zz << endl;
			printf("%f %f %f\n", x, y, z); file << x << "," << y << "," << z << endl;
			printf("%f %f %f\n", x, yy, zz); file << x << "," << yy << "," << zz << endl;

			
			printf("%f %f %f\n", xx, y, z); file << xx << "," << y << "," << z << endl;
			printf("%f %f %f\n", xx, y, zz); file << xx << "," << y << "," << zz << endl;
			printf("%f %f %f\n", xx, yy, zz); file << xx << "," << yy << "," << zz << endl;

			printf("%f %f %f\n", xx, y, z); file << xx << "," << y << "," << z << endl;
			printf("%f %f %f\n", xx, yy, zz); file << xx << "," << yy << "," << zz << endl;
			printf("%f %f %f\n", xx, yy, z); file << xx << "," << yy << "," << z << endl;

			z = z - espl;   // z vai decrementando sempre o valor do espaçamento lateral, para ficar com as camadas certas na largura
			zz = zz - espl;//decrementa o z, pois temos o z com o seu valor maximo positivo e para o plano ficar centrado temos que ir tirando o espaçamento entre as camadas de largura
		}
		y = y + espal;//incrementar na altura o valor do espaçamento, para obter nessa altura as camadas indicadas	
	}

	

	z = larg / 2; //Face da frente
	zz = -z; // Face trás
	y = -(alt / 2); //altura que se inicia as camadas frente e trás

	for (i = 0; i < camadas; i++){
		x = -(comp / 2);  //valor da coordenada x, onde se começam a desenhar os triângulos
		xx = x + espc;   //valor do x na proxima camada de comprimento
		yy = y + espal; //valor do y na proxima camada de altura

		for (j = 0; j < camadas; j++){
			
			printf("%f %f %f\n", x, y, z); file << x << "," << y << "," << z << endl;
			printf("%f %f %f\n", xx, y, z); file << xx << "," << y << "," << z << endl;
			printf("%f %f %f\n", x, yy, z); file << x << "," << yy << "," << z << endl;

			printf("%f %f %f\n", xx, y, z); file << xx << "," << y << "," << z << endl;
			printf("%f %f %f\n", xx, yy, z); file << xx << "," << yy << "," << z << endl;
			printf("%f %f %f\n", x, yy, z); file << x << "," << yy << "," << z << endl;

			printf("%f %f %f\n", x, y, zz); file << x << "," << y << "," << zz << endl;
			printf("%f %f %f\n", x, yy, zz); file << x << "," << yy << "," << zz << endl;
			printf("%f %f %f\n", xx, y, zz); file << xx << "," << y << "," << zz << endl;

			printf("%f %f %f\n", xx, y, zz); file << xx << "," << y << "," << zz << endl;
			printf("%f %f %f\n", x, yy, zz); file << x << "," << yy << "," << zz << endl;
			printf("%f %f %f\n", xx, yy, zz); file << xx << "," << yy << "," << zz << endl;

			x = x + espc;    //x vai incrementando o valor do espaçamento do comprimento, para ficar com as camadas indicadas
			xx = xx + espc; //xx também incrementa o valor do espaçamento do comprimento, para ficar sempre na proxima camada no eixo do x	
		}
		y = y + espal; //incrementar na altura o valor do espaçamento, para obter nessa altura as camadas indicadas	
	}
	file.close();
}



void cone(float raio, float altura, int camadasV, int camadasH, string nome){

	ofstream file(nome);
	float espV = (2 * M_PI) / camadasV;
	float espH = altura / camadasH;
	float alt = - altura / 2; //faz o cone ficar centrado no referêncial



	// a base (desenhado em y = alt = -altura/2)
	for (float a = 0; a < 2 * M_PI; a += espV){

		float x1 = 0;
		float y1 = alt;
		float z1 = 0;

		float x2 = raio * sin(a + espV);
		float y2 = alt;
		float z2 = raio * cos(a + espV);

		float x3 = raio * sin(a);
		float y3 = alt;
		float z3 = raio * cos(a);

		printf("%f, %f, %f\n", x1, y1, z1);
			file << x1 << "," << y1 << "," << z1 << endl;
		printf("%f, %f, %f\n", x2, y2, z2);
			file << x2 << "," << y2 << "," << z2 << endl;
		printf("%f, %f, %f\n", x3, y3, z3);
			file << x3 << "," << y3 << "," << z3 << endl;
	}


	// as várias camadas de altura
	for (int i = 0; i<camadasH; i++){

		for (float a = 0; a < camadasV; a += espV){

			float camada = alt + i * espH;
			float camadaAux = alt + (i + 1) * espH;

			float raio1 = raio - (raio * i) / camadasH;
			float raio2 = raio - (raio * (i + 1)) / camadasH;

			float x4 = raio2 * sin(a);
			float y4 = camadaAux;
			float z4 = raio2 * cos(a);

			float x5 = raio1 * sin(a);
			float y5 = camada;
			float z5 = raio1 * cos(a);

			float x6 = raio2 * sin(a + espV);
			float y6 = camadaAux;
			float z6 = raio2 * cos(a + espV);

			printf("%f, %f, %f\n", x4, y4, z4);
				file << x4 << "," << y4 << "," << z4 << endl;
			printf("%f, %f, %f\n", x5, y5, z5);
				file << x5 << "," << y5 << "," << z5 << endl;
			printf("%f, %f, %f\n", x6, y6, z6);
				file << x6 << "," << y6 << "," << z6 << endl;

			float x7 = raio1 * sin(a);
			float y7 = camada;
			float z7 = raio1 * cos(a);

			float x8 = raio1 * sin(a + espV);
			float y8 = camada;
			float z8 = raio1 * cos(a + espV);

			float x9 = raio2 * sin(a + espV);
			float y9 = camadaAux;
			float z9 = raio2 * cos(a + espV);

			printf("%f, %f, %f\n", x7, y7, z7); file << x7 << "," << y7 << "," << z7 << endl;
			printf("%f, %f, %f\n", x8, y8, z8); file << x8 << "," << y8 << "," << z8 << endl;
			printf("%f, %f, %f\n", x9, y9, z9); file << x9 << "," << y9 << "," << z9 << endl;
		}
	}
}


void esfera(float raio, int camadasV, int camadasH, string nome) {

		float espV = 2 * M_PI / camadasV;
		float espH = M_PI / camadasH;

		ofstream file(nome);

		float x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4;
		float a, aux = 0;

		for (int i = 0 ; i < camadasH ; i ++) {

			a = 0;

			for (int j = 0 ; j < camadasV ; j++){

			x1 = raio * sin(aux) * sin(a);
			y1 = raio * cos(aux);
			z1 = raio * sin(aux) * cos(a);

			x2 = raio * sin(aux + espH) * sin(a + espV);
			y2 = raio * cos(aux + espH);
			z2 = raio * sin(aux + espH) * cos(a + espV);

			x3 = raio * sin(aux + espH) * sin(a);
			y3 = raio * cos(aux + espH);
			z3 = raio * sin(aux + espH) * cos(a);

			x4 = raio * sin(aux) * sin(a + espV);
			y4 = raio * cos(aux);
			z4 = raio * sin(aux) * cos(a + espV);


			printf("%f %f %f\n", x1, y1, z1); file << x1 << "," << y1 << "," << z1 << endl;
			printf("%f %f %f\n", x2, y2, z2); file << x2 << "," << y2 << "," << z2 << endl;
			printf("%f %f %f\n", x3, y3, z3); file << x3 << "," << y3 << "," << z3 << endl;

			printf("%f %f %f\n", x1, y1, z1); file << x1 << "," << y1 << "," << z1 << endl;
			printf("%f %f %f\n", x4, y4, z4); file << x4 << "," << y4 << "," << z4 << endl;
			printf("%f %f %f\n", x2, y2, z2); file << x2 << "," << y2 << "," << z2 << endl;

			a += espV;

			}

			aux += espH;
		}

	
}

void cilindro(float raio, float altura, int camadasH, int camadasV,string nome){

	ofstream file(nome);
	float espV = 2 * M_PI / camadasV;
	float espH = altura / camadasH;
	float ang = 0;
	float ang1 = espV;
	altura =  -(altura/2);
	int i,j;
	float x1,x2,z1,z2,x3,z3;



	//BASES
	for(int i=0;i<=camadasV;i++){
		x1 = raio*sin(ang);
		x2 = raio*sin(ang1);
		z1 = raio*cos(ang);
		z2 = raio*cos(ang1);

		printf("%f %f %f\n",x1,altura,z1);
			file << x1 << "," << altura << "," << z1 << endl;
		printf("0 %f 0\n",altura);
			file << 0 << "," << altura << "," << 0 << endl;
		printf("%f %f %f\n",x2,altura,z2);
			file << x2 << "," << altura << "," << z2 << endl;


		printf("%f %f %f\n",x1,-altura,z1);
			file << x1 << "," << -altura << "," << z1 << endl;
		printf("%f %f %f\n",x2,-altura,z2);
			file << x2 << "," << -altura << "," << z2 << endl;
		printf("0 %f 0\n",-altura);
			file << 0 << "," << -altura << "," << 0 << endl;

	
			ang = espV*(i+1);
			ang1 = espV*(i+2);

	}

	for(i=0; i < camadasH ; i++){
		for(j=0; j < camadasV; j++){

		  ang += espV;

		  x1 = raio*sin(ang);
		  x2 = raio*sin(ang1);
		  x3 = raio*sin(ang + ang1);
		  z1 = raio*cos(ang);
		  z2 = raio*cos(ang1);
		  z3 = raio*cos(ang + ang1);

		  printf("%f %f %f\n",x1,altura,z1);
		  	file << x1 << "," << altura << "," << z1 << endl;
		  printf("%f %f %f\n",x3,altura,z3);
		  	file << x3 << "," << altura << "," << z3 << endl;
		  printf("%f %f %f\n",x1,altura+espH,z1);
		  	file << x1 << "," << altura+espH  << "," << z1 << endl;


		  printf("%f %f %f\n",x3,altura,z3);
		  	file << x3 << "," << altura << "," << z3 << endl;
		  printf("%f %f %f\n",x3,altura+espH,z3);
		  	file << x3 << "," << altura+espH << "," << z3 << endl;
		  printf("%f %f %f\n",x1,altura+espH,z1);
		  	file << x1 << "," << altura+espH  << "," << z1 << endl;
		}
		altura = altura + espH;
	}

}

void menu() {

	cout <<" ---------------------> MENU DE AJUDA <---------------------"<< endl;
	cout <<"|                                                           |"<< endl;
	cout <<"|                                                           |"<< endl;
	cout <<"|       GERADOR:                                            |"<< endl;
	cout <<"|                                                           |"<< endl;
	cout <<"|       $ g++ gerador.cpp -o gen                            |"<< endl;
	cout <<"|       $ ./gen Figura [Parâmetros] figura.3d               |"<< endl;
	cout <<"|       $ mv figura.3d diretoria/Motor                      |"<< endl;
	cout <<"|                                                           |"<< endl;
	cout <<"|                                                           |"<< endl;
	cout <<"|       MOTOR:                                              |"<< endl;
	cout <<"|                                                           |"<< endl;
	cout <<"|       [build]$ make                                       |"<< endl;
	cout <<"|       $ ./Projecto_de_CG sistemasolar.xml                 |"<< endl;
	cout <<"|                                                           |"<< endl;
	cout <<"|                                                           |"<< endl;
	cout <<"|------------------------> FIGURA <-------------------------|"<< endl;
	cout <<"|                                                           |"<< endl;
	cout <<"|                                                           |"<< endl;
	cout <<"|       * Plano lado                                        |"<< endl;
	cout <<"|                                                           |"<< endl;
	cout <<"|       * Cubo comp larg alt camadas                        |"<< endl;
	cout <<"|                                                           |"<< endl;
	cout <<"|       * Cone raio altura camadasV camadasH                |"<< endl;
	cout <<"|                                                           |"<< endl;
	cout <<"|       * Esfera raio camadasV camadasH                     |"<< endl;
	cout <<"|                                                           |"<< endl;
	cout <<"|                                                           |"<< endl;
	cout <<"|---------------------> Controlos 3D <----------------------|"<< endl;
	cout <<"|                                                           |"<< endl;
	cout <<"|       * TRANSLAÇÃO: Seta cima, baixo, esquerda, direita   |"<< endl;
	cout <<"|                                                           |"<< endl;
	cout <<"|       * ROTAÇÃO: w, a, s, d  | W, A, S, D                 |"<< endl;
	cout <<"|                                                           |"<< endl;
	cout <<"|       * ZOOM: + | -                                       |"<< endl;
	cout <<"|                                                           |"<< endl;
	cout <<"|                                                           |"<< endl;
	cout <<" ------------------------------><---------------------------"<< endl;
}

float* formulaBezier( float tt, float *p1 , float *p2 , float *p3 , float *p4) {

	float ite = 1.0 - tt;
	float* ptt = new float[3];

	float x0 , x1 , x2 , x3;
	x0 = pow(ite,3);
	x1 = 3 * pow(ite,2);
	x2 = 3 * tt * tt * tt;
	x3 = tt * tt * tt;

	ppt[0] = x0*p1[0] + x1*p2[0] + x2*p3[0] + x3*p4[0];
	ppt[1] = x0*p1[1] + x1*p2[1] + x2*p3[1] + x3*p4[1];
	ppt[2] = x0*p1[2] + x1*p2[2] + x2*p3[2] + x3*p4[2];


	return ppt;
}


float* bezier( float a , float b , int* indice , float** pontos , int ni , int np) {

	float* ponto = new float[3];
	float altp[4][3];
	float res[4][3];
	int i , j = 0 , x = 0;
	float *calculo;


	for( i = 0 ; i < 16 ; i++) {
		altp[j][0] = pontos[indice[i]][0];
		altp[j][0] = pontos[indice[i]][1];
		altp[j][0] = pontos[indice[i]][2];

		j++;

		if( j % 4 == 0 ) {
			ponto = formulaBezier(a,altp[0],altp[1],altp[2],altp[3]);
			res[x][0] = ponto[0];
			res[x][1] = ponto[1];
			res[x][2] = ponto[2];

			k++;

			j = 0;
		}

	}
	calculo = formulaBezier(b,res[0],res[1],res[2],res[3]);

	return calculo;
}


void patch( string file , int tess , string name) {

	ofstream fileo(name);
	string line , aux;
	ifstream filei(file);
	int i;

	if(filei.is_open()) {
		getline(filei,line);
		int npatch = atoi(line.c_str());
		int** indices = new int*[npatch];
		cout << npatch << endl;

		for(int r = 0 ; r < npatch ; r++) {
			getline(filei,line);
			indices[r] = new int[16];

			for(int j = 0 ; j < 16 ; j++) {
				i = line.find(",");
				aux = line.substr(0,i);
				indices[r][j] = atoi(aux.c_str());
				line.erase(0, i + 1);
			} 
		}

		getline(filei,line);
		int npontos = atoi(line.c_str());
		cout << npontos << endl;
		float** pontos = new float*[npontos];

		for( int m = 0 ; m < npontos ; m++){
			getline(filei,line);
			pontos[m] = new float[3];
			for( int l = 0 ; l < 3 ; l++) {
				i = line.find(",");
				aux = line.substr(0,i);
				pontos[m][l] = atof(aux.c_str());
				line.erase(0 , i + 1);
			}
		}

		float incre = 1.0 / tess , u , v , u2 , v2;
		float *** pontoRes = new float**[npatch];

		for(int rr = 0 ; rr < npatch ; rr++) {
			pontoRes[rr] = new float*[4];
		 	
		 	for( int jj = 0 ; jj << tess ; i ++) {

		 		for( int mn = 0 ; mn << tess ; mn++) {

		 			u = jj*incre;
		 			v = mn*incre;
		 			u2 = (jj + 1)* incre;
		 			v2 = (mn + 1)* incre;

		 			pontoRes[rr][0] = bezier(u, v, indices[rr], pontos, npatch, npontos);
					pontoRes[rr][1] = bezier(u, v2, indices[rr], pontos, npatch, npontos);
					pontoRes[rr][2] = bezier(u2, v, indices[rr], pontos, npatch, npontos);
					pontoRes[rr][3] = bezier(u2, v2, indices[rr], pontos, npatch, npontos);


					fileo << pontoRes[rr][0][0] << "," << pontoRes[rr][0][1] << "," << pontoRes[rr][0][2] << endl;
					fileo << pontoRes[rr][2][0] << "," << pontoRes[rr][2][1] << "," << pontoRes[rr][2][2] << endl;
					fileo << pontoRes[rr][3][0] << "," << pontoRes[rr][3][1] << "," << pontoRes[rr][3][2] << endl;

					fileo << pontoRes[rr][0][0] << "," << pontoRes[rr][0][1] << "," << pontoRes[rr][0][2] << endl;
					fileo << pontoRes[rr][3][0] << "," << pontoRes[rr][3][1] << "," << pontoRes[rr][3][2] << endl;
					fileo << pontoRes[rr][1][0] << "," << pontoRes[rr][1][1] << "," << pontoRes[rr][1][2] << endl;
		 		}
		 	}

		 }
	}

	filei.close();
	fileo.close();
}




int main (int argc , char **argv){


	if( argc > 1) {
			if (strcmp(argv[1],"Menu") == 0) {
				menu();

			}
			else if (strcmp(argv[1],"Plano") == 0) {
				plano(atoi(argv[2]),argv[3]);
			}
			else if (strcmp(argv[1],"Cubo") == 0) {
				cubo(atof(argv[2]),atof(argv[3]),atof(argv[4]),atoi(argv[5]),argv[6]);
			}
			else if (strcmp(argv[1],"Esfera") == 0) {
				esfera(atoi(argv[2]), atoi(argv[3]), atoi(argv[4]),argv[5]);
			}
			else if (strcmp(argv[1],"Cone") == 0) {
				cone(atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5]), argv[6]);
			}
			else if (strcmp(argv[1],"Cilindro") == 0) {
				cilindro(atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5]), argv[6]);
			}
			else if(strcmp(argv[1],"Patch") == 0){
				patch(argv[2], atoi(argv[3]) , argv[4]);
			}
			else {
				printf("FIGURA IMPOSSÍVEL\n");
			}

	}
	else {
		printf("ARGUMENTOS INSUFICIENTES\n");
	}

	return 0;
}
