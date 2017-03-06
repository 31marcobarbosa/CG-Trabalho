#include "gerador.h"


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
	y = alt / 2; yy = -y; //y é usado para indicar a altura da face de cima e yy é a altura a que a base de baixo se encontrará
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


	/*
	file << (camadasH) << endl;
	file << (camadasH) << endl;
	file << (camadasV) << endl;
*/

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


int main (int argc , char **argv){


	if( argc > 1) {
			if (strcmp(argv[1],"Plano") == 0) {
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
			else {
				printf("FIGURA IMPOSSÍVEL\n");
			}

	}
	else {
		printf("ARGUMENTOS INSUFICIENTES\n");
	}

	return 0;
}
