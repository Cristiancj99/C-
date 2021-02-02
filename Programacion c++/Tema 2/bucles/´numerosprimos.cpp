/* programa para calcular los numeros
primos mediante un bucle */


#include <iostream>
using namespace std;
int main () {

	int numero= 0; // numero introducido por el usuario
	int contador = 1; // contador para ir probando dividir
	double division = 0.0;
	int contador2 =0.0;// contador pra ver cuantas veces las divisiones son exactas.

	cout << "Programa para calcular si un número es primo o no" << endl;
	
	cout << "Introduce un número: " << endl;
	cin >> numero;

	while( (contador >= 1) && ( contador <= numero ) ){ // bucle para las divisiones
		contador = contador + 1;
		division = numero % contador; 
		if (division == 0) { // para que sume en caso de que la división sea exacta.
			contador2 = contador2 + 1;
		}
	}
	
	if ( (numero % 1 == 0) && (numero % numero == 0 ) && (contador2 > 2) ){// condición para saber si no es primo.
		cout << " El numero  no es primo" << endl;
	}
	else {
		cout << " el número  es primo." <<endl;
	}
}				
