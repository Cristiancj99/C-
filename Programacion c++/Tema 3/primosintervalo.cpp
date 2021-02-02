/* Programa ue te dice los números
primos en un inervalo*/

#include <iostream>
using namespace std;
// declaración de funciones


void pedirintervalo (int &n1, int &n2){

	do {
		
		cout << "Por favor, introduzca el intervalo: ";

		cin >> n1 >> n2;

	}while ( ( n1 < 0 ) || (n2 < 0) );

}



bool esprimo ( int n){ // función para calcular un primo

	bool primo = true;

	for (int i = 2; ( (i<n) && (primo==true) ); i++) {

		if (n % i == 0){ // si el resto es 0, significárá que el número es divisible.
			
			primo =false;
		}
	}
	
	return primo;
}

int main (){

	int n1= 0;
	int n2= 0;
	bool suprimo = false;

	cout << "Bienvenido al programa para ver los números primos en un intervalo."<<endl;
	
	pedirintervalo (n1, n2);

	for (int i =n1; i<=n2; i++){

		suprimo=esprimo (i);

		if (suprimo== true) {
			cout << i << "es primo"<< endl;
		}
	}
	cout << "Hasta luego lucas "<<endl;
}
	 