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






int main (int argc , int **argv){


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