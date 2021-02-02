/* version mejorada de los numeros
primos.*/



#include <iostream>
using namespace std;
int main (){

	int n = 0.0; // variable que asignará el usuario.
	bool primo = true; // booleano que utilizaremos para averiguar si es primo o no 

	cout << "Bienvenidos a la version ejorada de los numeros primos"<<endl;
	
	cout << "Para comenzar este programa introduzca un número ";
	cin >> n;

	for (int i = 2; ( (i<n) && (primo==true) ); i++) {

		if (n % i == 0){ // si el resto es 0, significárá que el número es divisible.
			
			primo =false;
		}
	}

	if (primo == true){

		cout << "El número es primo" << endl;
	}

	else {
		cout << "El número es divisible." << endl;
	}
}