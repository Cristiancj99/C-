#include <iostream>

#include<cmath>

using namespace std;



int main() {

	int cantidad_notas=0, i=0, util_notas=0;

	const int DIMENSION_BOLSA=10;

	int notas[DIMENSION_BOLSA];

	double media=0.0, desviacion=0.0, varianza=0.0;

	do{ // bucle para filtrar el numero de notas a introducir.

		cout <<"introduzca la cantidad de numeros que va a introducir= ";

		cin >> cantidad_notas;



	}while((cantidad_notas < 1) || (cantidad_notas > DIMENSION_BOLSA));



	for (i=0;i<cantidad_notas;i++){ // bucle para que el usuario introduzca las notas.

		cout << "Introduzca las notas del alumno " << i + 1 <<endl;

		cin >> notas [i];

		util_notas++;

	}

	

	for (i=0;i<util_notas;i++){ // bucle para calcular la media

		media+= notas[i];

	}

	media/= util_notas;

	cout << "Usted ha introducido "<< util_notas <<" , ha dejado un espacio de "<< DIMENSION_BOLSA - util_notas << " En la bolsa. La media es de: " << media << endl;


	for (i=0;i<util_notas;i++){ // bucle para calcular la desviación



		desviacion += (pow(notas [i] - media, 2.0)/util_notas);

	}

	varianza= sqrt( desviacion); // calculo necesarios para la varianza

//Salidas del programa


	cout << "media = "<< media << endl;

	cout << "deviación = "<< desviacion << endl;

	cout << "varianza = "<< varianza << endl;

}



