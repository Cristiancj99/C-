/* Programa que te muetra un menú
y hace 3 funciones diferentes.*/


#include <iostream>
using namespace std;
// Declaración de funciones


int factorial ( int n) { // Función para calcular el factorial
	int acumulacion =1;

	for (int i=2; i<=n; i++){ // bucle acumulativo para el factorial

		acumulacion= (acumulacion * i);
	}
	return acumulacion;
}

float MediaTresN ( int a, int b, int c){ // función para calcular la media

	float media= (a + b + c) / 3;
	
	return media;
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


void Menu (char opcion){ // función para enseñar nuestro menú

	int resFact=0;
	int n=0,n1=0, n2=0;
	float media= 0.0;
	bool suprimo = false;


	cout << "         MENU                "<<endl;

	cout << "Pulsa 'a' para realizar  la función factorial."<< endl;
	cout << "Pulsa 'b' para realizar la media de 3 n"<<endl;
	cout << "Pulsa 'c' para realizar la comprobación de un número primo."<<endl;
	cin >> opcion;

	 switch (opcion) { // switch utilizado para el menú
        	case 'a':

			cout << "Introduzca un número para realizar su factorial: ";
			cin >> n;

			resFact = factorial (n); // Llamamiento a la función

			cout << "El factorial de "<<n<< "Es: " << resFact << endl;
			break;
		
		case 'b':
		
			cout << "Introduzca tres numeros para hacer la media : ";
			cin >> n >> n1>> n2;

			media= MediaTresN ( n,n1,n2); // Llamamiento a la función

			cout << "La media Es: " <<media << endl;
		
			break;
		
		case 'c': 

			cout << "Introduzca un número para ver si es primo o no: ";
			cin >> n;

			suprimo=esprimo (n); // Llamamiento a la función

			if (suprimo == true){
				cout << n << "Es primo" << endl;
			}
			else {
				cout << "Es compuesto"<<endl;
			}
			
			break;

			default: 
		
				cout << "Ha ocurrido un error. CUIDADO CON MAYÚSCULAS"<< endl;
			break;
	}
}

int main () {

  char tecla;

       cout << "                    MENÚ                   " << endl;
        cout << "Pulse la tecla para realizar la función deseada: " << endl;
 
       Menu(tecla); // Llamamiento a la función

}


	 
