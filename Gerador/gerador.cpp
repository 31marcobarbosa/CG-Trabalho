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



void cubo(double a, double b, double c, , int camadas, int camadas, int camadas , string nome){

	ofstream file(nome);
	double x, y, z;
	double espX = a / camadas;
	double espY = b / camadas;
	double espZ = c / camadas;
  double xx, yy, zz;


	int i,j;


	if ((a % 2) == 0) x = a/2;
	else x = a/2 + 0.5;

	if ((b % 2) == 0) y = b/2;
	else y = b/2 + 0.5;

	if ((c % 2) == 0) z = c/2;
	else z = c/2 + 0.5;


// FRONTAL E TRASEIRA
  for (i = 0 ; i < camadas; i ++) {
    yy = y + espH * i;

	   for (j = 0 ; j < camadas , j++) {
      zz = z + espZ * j;

          	// PARTE DA FRENTE
          	printf("%f %f %f\n", x, yy, zz);
          		file << x << "," << yy << "," << zz << endl;
          	printf("%f %f %f\n", x, yy + espY, zz + espZ);
          		file << x << "," << yy + espY << "," << zz + espZ << endl;
          	printf("%f %f %f\n", x, yy + espY, zz);
          		file << x << "," << y << "," << z << endl;

          	printf("%f %f %f\n", x, yy, zz);
          		file << x << "," << yy << "," << zz << endl;
          	printf("%f %f %f\n", x, yy, zz + espZ);
          		file << x << "," << yy << "," << zz + espZ << endl;
          	printf("%f %f %f\n", x, yy + espY, zz + espZ);
          		file << x << "," << yy + espY << "," << zz + espZ << endl;


          	//PARTE DE TRÁS
          	printf("%f %f %f\n", -x, yy, zz);
          		file << -x << "," << yy << "," << zz << endl;
          	printf("%f %f %f\n", -x, yy + espY, zz);
          		file << -x << "," << yy + espY << "," << zz << endl;
          	printf("%f %f %f\n", -x, yy + espY, zz + espZ);
          		file << -x << "," << yy + espY << "," << zz + espZ << endl;

          	printf("%f %f %f\n", -x, yy, zz);
          		file << -x << "," << yy << "," << zz << endl;
          	printf("%f %f %f\n", x, y, -z);
          		file << -x << "," << yy + espY << "," << zz + espZ << endl;
          	printf("%f %f %f\n", x, -y, -z);
          		file << -x << "," << yy << "," << zz + espZ << endl;

          }
  }



//PARTE DE CIMA E BAIXO
  for (i = 0; i < camadas; i++) {
    xx = x + espX * i;

    for (j=0; j < camadas ; j ++){
      zz = z + espZ * i;

            // PARTE DE CIMA
          	printf("%f %f %f\n", xx, y, zz);
          		file << xx << "," << y << "," << zz << endl;
          	printf("%f %f %f\n", xx + espX, y, zz);
          		file << xx + espX << "," << y << "," << zz << endl;
          	printf("%f %f %f\n", xx , y, zz + espZ);
          		file << xx << "," << y << "," << zz + espZ << endl;

          	printf("%f %f %f\n", xx, y, zz + espZ);
          		file << xx << "," << y << "," << zz + espZ << endl;
          	printf("%f %f %f\n", xx + espX, y, zz);
          		file << xx + espX << "," << y << "," << zz << endl;
          	printf("%f %f %f\n", -x, y, z);
          		file << xx + espX << "," << y << "," << zz + espZ << endl;


          	//PARTE DE BAIXO
          	printf("%f %f %f\n", xx, -y, zz);
          		file << xx << "," << -y << "," << zz << endl;
          	printf("%f %f %f\n", xx, -y, z + espZ);
          		file << xx << "," << -y << "," << zz + espZ << endl;
          	printf("%f %f %f\n", xx + espX, -y, zz);
          		file << xx + espX << "," << -y << "," << zz << endl;

          	printf("%f %f %f\n", xx, -y, zz + espZ);
          		file << xx << "," << -y << "," << zz + espZ << endl;
          	printf("%f %f %f\n", xx + espX, -y, zz + espZ);
          		file << xx + espX << "," << -y << "," << zz + espZ << endl;
          	printf("%f %f %f\n", xx + espX, -y, zz);
          		file << xx + espX << "," << -y << "," << zz << endl;


// LADO DIREITO E ESQUERDO

		 for (i = 0 ; i < camadas ; i++) {
			 yy = y + espY * i;

			 	for (j = 0 ; j < camadas ; j++) {
					xx = x + espX * j;

	// LADO DIREITO
	printf("%f %f %f\n", xx, yy, z);
		file << xx << "," << yy << "," << z << endl;
	printf("%f %f %f\n", xx, yy + espY, z);
		file << xx << "," << yy + espY << "," << z << endl;
	printf("%f %f %f\n", xx + espX, yy, z);
		file << xx + espX << "," << yy << "," << z << endl;

	printf("%f %f %f\n", xx, yy + espY, z);
		file << xx << "," << yy + espY << "," << z << endl;
	printf("%f %f %f\n", xx + espX, yy + espY, z);
		file << xx + espX << "," << yy + espY << "," << z << endl;
	printf("%f %f %f\n", -x, y, z);
		file << xx + espX << "," << yy << "," << z << endl;


	//LADO ESQUERDO
	printf("%f %f %f\n", xx, yy, -z);
		file << xx << "," << yy << "," << -z << endl;
	printf("%f %f %f\n", xx + espX, yy, -z);
		file << xx + espX << "," << yy << "," << -z << endl;
	printf("%f %f %f\n", xx, yy + espY, -z);
		file << xx << "," << yy + espY << "," << z << endl;

	printf("%f %f %f\n", xx, yy + espY, -z);
		file << xx << "," << yy + espY << "," << z << endl;
	printf("%f %f %f\n", xx + espX, yy, -z);
		file << xx + espX << "," << yy << "," << z << endl;
	printf("%f %f %f\n", xx + espX, yy + espY, -z);
		file << xx + espX << "," << yy + espX << "," << -z << endl;
	}
}


}


void cone(double raio, double altura, int camadasV, int camadasH, string nome){

	ofstream file(nome);
	double espV = (2 * M_PI) / camadasV;
	double espH = altura / camadasH;
	double alt = - altura / 2; //faz o cone ficar centrado no referêncial



	file << (camadasH) << endl;
	file << (camadasH) << endl;
	file << (camadasV) << endl;


	// a base (desenhado em y = alt = -altura/2)
	for (double a = 0; a < 2 * M_PI; a += espV){

		double x1 = 0;
		double y1 = alt;
		double z1 = 0;

		double x2 = raio * sin(a + espV);
		double y2 = alt;
		double z2 = raio * cos(a + espV);

		double x3 = raio * sin(a);
		double y3 = alt;
		double z3 = raio * cos(a);

		printf("%f, %f, %f\n", x1, y1, z1);
			file << x1 << "," << y1 << "," << z1 << endl;
		printf("%f, %f, %f\n", x2, y2, z2);
			file << x2 << "," << y2 << "," << z2 << endl;
		printf("%f, %f, %f\n", x3, y3, z3);
			file << x3 << "," << y3 << "," << z3 << endl;
	}


	// as várias camadas de altura
	for (int i = 0; i<camadasH; i++){

		for (double a = 0; a < camadasV; a += espV){

			double camada = alt + i * espH;
			double camadaAux = alt + (i + 1) * espH;

			double raio1 = raio - (raio * i) / camadasH;
			double raio2 = raio - (raio * (i + 1)) / camadasH;

			double x4 = raio2 * sin(a);
			double y4 = camadaAux;
			double z4 = raio2 * cos(a);

			double x5 = raio1 * sin(a);
			double y5 = camada;
			double z5 = raio1 * cos(a);

			double x6 = raio2 * sin(a + espV);
			double y6 = camadaAux;
			double z6 = raio2 * cos(a + espV);

			printf("%f, %f, %f\n", x4, y4, z4);
				file << x4 << "," << y4 << "," << z4 << endl;
			printf("%f, %f, %f\n", x5, y5, z5);
				file << x5 << "," << y5 << "," << z5 << endl;
			printf("%f, %f, %f\n", x6, y6, z6);
				file << x6 << "," << y6 << "," << z6 << endl;

			double x7 = raio1 * sin(a);
			double y7 = camada;
			double z7 = raio1 * cos(a);

			double x8 = raio1 * sin(a + espV);
			double y8 = camada;
			double z8 = raio1 * cos(a + espV);

			double x9 = raio2 * sin(a + espV);
			double y9 = camadaAux;
			double z9 = raio2 * cos(a + espV);

			printf("%f, %f, %f\n", x7, y7, z7); file << x7 << "," << y7 << "," << z7 << endl;
			printf("%f, %f, %f\n", x8, y8, z8); file << x8 << "," << y8 << "," << z8 << endl;
			printf("%f, %f, %f\n", x9, y9, z9); file << x9 << "," << y9 << "," << z9 << endl;
		}
	}
}


void esfera(double raio, int camadasV, int camadasH, string nome) {

		double espV = 2 * M_PI / camadasV;
		double espH = M_PI / camadasH;

		ofstream file(nome):

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
				cubo(atof(argv[2]),atof(argv[3]),atof(argv[4]),atoi(argv[5]),atoi(argv[6]),atoi(argv[7]),argv[8]);
			}
			else if (strcmp(argv[1],"Esfera") == 0) {
				esfera(atoi(argv[2]), atoi(argv[3]), atoi(argv[4]),(argv[5]);
			}
			else if (strcmp(argv[1],"Cone") == 0) {
				cone(atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5]), argv[6]);
			}
			else {
				printf("FIGURA IMPOSSÍVEL\n");
			}

	}
	else {
		printf("ARGUMENTOS INSUFICIENTES\n", );
	}

	return 0;
}
