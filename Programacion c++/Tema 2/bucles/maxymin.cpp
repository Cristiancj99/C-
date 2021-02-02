
/* Programa para coger 100 números y
decir cual es mayor y cual número.*/




#include <iostream>
using namespace std;
int main () {

	int numero = 0.0;
	int maximo = 0.0;// no hace falta inicializarla a algo porque con que sea mayor a 0 se actualizará
	int minimo = 2147483647;// inicializada así porque si se inicializa a 0 para ver el minimo tendría que ser un número negativo


	cout << "Bienvendo a un programaque acepta 100 números y te dice el menor y el mayor.";

	for (int progresion = 1; progresion <= 100; progresion = progresion + 1) { //Bucle para que coja 100 números

		cout << "Introduce un número: ";
		cin >> numero;

		if ( numero > maximo) { // para que cada vez que vea un número mayor lo guarde
			maximo= numero;
		}

		if ( numero < minimo) { // para que cada vez que vea un número menor lo guarde
			minimo = numero;
		}
	}

	cout << "El mínimo es "<< minimo << " Y el máximo es "<< maximo << endl;

}