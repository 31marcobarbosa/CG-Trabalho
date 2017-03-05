#include "gerador.h"


 // meter as variaveis em ING

void plano(int lado, string nome) {

	ofstream file(nome);
	double x,y,z;
	y=0;

	//posicionamento do plano centrado com o eixo
	if ((lado % 2) == 0) {
		x = lado / 2;
		z = lado / 2;
	}
	else {
		x = lado / 2 + 0.5;
		z = lado / 2 + 0.5;
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



void cone(double raio, double altura, int camadasV, int camadasH, string nome){

	ofstream file(nome);
	double espV = (2 * M_PI) / camadasV;
	double espH = altura / camadasH;
	double alt = - altura / 2; //faz o cone ficar centrado no referêncial

	int a,b;

	double x,y,z;
	double xx,yy,zz;
	double xxx,yyy,zzz;
	double x1, x2, x3, y1, y2, y3, z1, z2, z3, x4, z4;
	double beta, betaprox;
	double dif;
	double raioNovo;


	// a base (desenhado em y = alt = -altura/2)
	for (a = 0; a < camadasV; a ++){

		beta = espV*a; //angulo da camada;
		betaprox = espV * (a+1); //angulo da prox camada

		//coordenadas da camada atual e da próxima
		xx = raio*sin(beta);
		zz = raio*cos(beta);
		xxx = raio*sin(betaprox);
		zzz = raio*cos(betaprox);

		printf("%f, %f, %f\n", xx, yy, zz);
			file << xx << "," << y << "," << zz << endl;
		printf("%f, %f, %f\n", x2, y2, z2);
			file << x << "," << y << "," << z << endl;
		printf("%f, %f, %f\n", x3, y3, z3);
			file << xxx << "," << yyy << "," << zzz << endl;
	}

	//valor retirada por cada novo raio;
	dif = raio / camadasH;

	// as várias camadas de altura
	for (int i = 0; i<camadasH - 1; i++){

		for (b = 0; b <= camadasV; b++){

			beta = espV*b;
			betaprox = espV*(b+1);

			raioNovo = raio - dif;

			x1 = raio*sin(beta);
			y1 = y;
			z1 = raio*cos(beta);

			x2 = raio * sin(betaprox);
			y1 = y;
			z2 = raio * cos(betaprox);

			x3 = raioNovo *sin(beta);
			y2 = y + espH;
			z3 = raioNovo * cos(beta);

			x4 = raioNovo * sin(betaprox);
			y2 = y + espH;
			z4 = raioNovo * cos(betaprox);

			printf("%f, %f, %f\n", x1, y1, z1); file << x1 << "," << y1 << "," << z1 << endl;
			printf("%f, %f, %f\n", x2, y1, z2);	file << x2 << "," << y1 << "," << z2 << endl;
			printf("%f, %f, %f\n", x3, y2, z3);	file << x3 << "," << y2 << "," << z3 << endl;

			printf("%f, %f, %f\n", x2, y1, z2); file << x2 << "," << y1 << "," << z2 << endl;
			printf("%f, %f, %f\n", x4, y2, z4); file << x4 << "," << y2 << "," << z4 << endl;
			printf("%f, %f, %f\n", x3, y2, z3); file << x3 << "," << y2 << "," << z2 << endl;
		}

		raio = raio - dif;//atualiza o raio
		y = y + espH; //passa para a proxima camada
	}
		y = alt / 2; // a altura maxima da coordenada do y

		for (a = 0; a <= camadasV; a++){
		beta = espV*a;//angulo atual
		betaprox = espV * (b + 1);//angulo na proxima camada

		x1 = raioNovo *sin(beta);
		z1 = raioNovo * cos(beta);

		x2 = raioNovo * sin(betaprox);
		z2 = raioNovo * cos(betaprox);

		printf("%f %f %f\n", 0, y, 0); file << 0 << "," << y1 << "," << 0 << endl;
		printf("%f %f %f\n", x1, y2, z1); file << x1 << "," << y2 << "," << z1 << endl;
		printf("%f %f %f\n", x2, y2, z2); file << x2 << "," << y2 << "," << z2 << endl;
	}


	file.close();
}


void esfera(double raio, int camadasV, int camadasH, string nome) {

		double espV = 2 * M_PI / camadasV;
		double espH = M_PI / camadasH;

		ofstream file(nome);

		float x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4;
		int a, aux = 0;

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
