/* Programa para ver si un número es 
par o impar.*/


#include <iostream>
using namespace std;
int main () { 
	int a= 0.0; //número introducido por el usuario.
//entradas
	cout << " Bienvenido al programa para ver si un número es par o impar." << endl;
	cout << "Introduzca un número para ver si es par o impar: ";
	cin >> a;
//Salidas

	if (a%2==0) { // si el resto de un número entre dos es 0, numero par.
		cout << " El número " << a << " es un número par." << endl;
	}

	if (a%2!=0) { // siel resto es distinto de 0, número impar
		cout << " El número " << a << " es un número impar." << endl;
	}

	cout << " Muchas gracias por utilizar el programa!! " << endl;
}