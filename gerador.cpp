#include "gerador.h"


 // meter as variaveis em ING

void plane(int lado, string nome) {

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


void box(int a, int b, int c, string nome){

	ofstream(nome);
	double x, y, z;

	if ((a % 2) == 0) x = a/2;
	else x = a/2 + 0.5;

	if ((b % 2) == 0) y = b/2;
	else y = b/2 + 0.5;

	if ((c % 2) == 0) z = c/2;
	else z = c/2 + 0.5;


	// PARTE DA FRENTE
	//Triangulo 1
	printf("%f %f %f\n", x, -y, z);
		file << x << "," << -y << "," << z << endl;
	printf("%f %f %f\n", x, y, z);
		file << x << "," << y << "," << z << endl;
	printf("%f %f %f\n", -x, y, z);
		file << -x << "," << y << "," << z << endl;

	//Triangulo 2
	printf("%f %f %f\n", -x, y, z);
		file << -x << "," << y << "," << z << endl;
	printf("%f %f %f\n", -x, -y, z);
		file << -x << "," << -y << "," << z << endl;
	printf("%f %f %f\n", x, -y, z);
		file << x << "," << -y << "," << z << endl;


	//PARTE DE TRÁS
	//Triangulo 1
	printf("%f %f %f\n", x, -y, -z);
		file << x << "," << -y << "," << -z << endl;
	printf("%f %f %f\n", -x, -y, -z);
		file << -x << "," << -y << "," << -z << endl;
	printf("%f %f %f\n", -x, y, -z);
		file << -x << "," << y << "," << -z << endl;

	//Triangulo 2
	printf("%f %f %f\n", -x, y, -z);
		file << -x << "," << y << "," << -z << endl;
	printf("%f %f %f\n", x, y, -z);
		file << x << "," << y << "," << -z << endl;
	printf("%f %f %f\n", x, -y, -z);
		file << x << "," << -y << "," << -z << endl;


	//PARTE DE CIMA
	//Triangulo 1
	printf("%f %f %f\n", x, y, -z);
		file << x << "," << y << "," << -z << endl;
	printf("%f %f %f\n", -x, y, z);
		file << -x << "," << y << "," << z << endl;
	printf("%f %f %f\n", x, y, z);
		file << x << "," << y << "," << z << endl;

	//Triangulo 2
	printf("%f %f %f\n", x, y, -z);
		file << x << "," << y << "," << -z << endl;
	printf("%f %f %f\n", -x, y, -z);
		file << -x << "," << y << "," << -z << endl;
	printf("%f %f %f\n", -x, y, z);
		file << -x << "," << y << "," << z << endl;

	//PARTE DE BAIXO
	//Triangulo 1
	printf("%f %f %f\n", x, -y, -z);
		file << x << "," << -y << "," << -z << endl;
	printf("%f %f %f\n", x, -y, z);
		file << x << "," << -y << "," << z << endl;
	printf("%f %f %f\n", -x, -y, z);
		file << -x << "," << -y << "," << z << endl;

	//Triangulo 2
	printf("%f %f %f\n", x, -y, -z);
		file << x << "," << -y << "," << -z << endl;
	printf("%f %f %f\n", -x, -y, z);
		file << -x << "," << -y << "," << z << endl;
	printf("%f %f %f\n", -x, -y, -z);
		file << -x << "," << -y << "," << -z << endl;

	//LADO DIREITO
	//Triangulo 1
	printf("%f %f %f\n", -x, -y, -z);
		file << -x << "," << -y << "," << -z << endl;
	printf("%f %f %f\n", -x, -y, z);
		file << -x << "," << -y << "," << z << endl;
	printf("%f %f %f\n", -x, y, -z);
		file << -x << "," << y << "," << -z << endl;

	//Triangulo 2
	printf("%f %f %f\n", -x, -y, z);
		file << -x << "," << -y << "," << z << endl;
	printf("%f %f %f\n", -x, y, z);
		file << -x << "," << y << "," << z << endl;
	printf("%f %f %f\n", -x, y, -z);
		file << -x << "," << y << "," << -z << endl;

	//LADO ESQUERDO
	//Triangulo 1
	printf("%f %f %f\n", x, -y, -z);
		file << x << "," << -y << "," << -z << endl;
	printf("%f %f %f\n", x, y, -z);
		file << x << "," << y << "," << -z << endl;
	printf("%f %f %f\n", x, y, z);
		file << x << "," << y << "," << z << endl;

	//Triangulo 2
	printf("%f %f %f\n", x, y, z);
		file << x << "," << y << "," << z << endl;
	printf("%f %f %f\n", x, -y, z);
		file << x << "," << -y << "," << z << endl;
	printf("%f %f %f\n", x, -y, -z);
		file << x << "," << -y << "," << -z << endl;

}


void cone(float raio, float altura, float camadasV, float camadasH, string nome){


	double espV = (2 * M_PI) / camadasV;
	double espH = altura / camadasH;
	double alt = - altura / 2; //faz o cone ficar centrado no referêncial


	ofstream(nome);
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

		printf("%f, %f, %f\n", x1, y1, z1); file << x1 << "," << y1 << "," << z1 << endl;
		printf("%f, %f, %f\n", x2, y2, z2); file << x2 << "," << y2 << "," << z2 << endl;
		printf("%f, %f, %f\n", x3, y3, z3); file << x3 << "," << y3 << "," << z3 << endl;
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

			printf("%f, %f, %f\n", x4, y4, z4); file << x4 << "," << y4 << "," << z4 << endl;
			printf("%f, %f, %f\n", x5, y5, z5); file << x5 << "," << y5 << "," << z5 << endl;
			printf("%f, %f, %f\n", x6, y6, z6); file << x6 << "," << y6 << "," << z6 << endl;

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


int main (int argc , char **argv){


	if( argc > 1) {
			if (strcmp(argv[1],"Plane") == 0) {
				plane(atoi(argv[2]),argv[3]);
			}
			else if (strcmp(argv[1],"Box") == 0) {
				box(atoi(argv[2]),atoi(argv[3]),atoi(argv[4]),argv[5]);
			}
			else if (strcmp(argv[1],"Sphere") == 0) {

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
