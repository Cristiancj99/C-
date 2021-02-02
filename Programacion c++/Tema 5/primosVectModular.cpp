#include <iostream>

#define NORMAL "\033[1;0m"

#define CYAN "\033[1;36m"

#define DEBUG "\033[1;31m"

#define YELLOW "\033[1;33m"

#define SOLUCION "\033[1;32m"





using namespace std;



/**
@brief modulo para pedir el numero de numeros que introducirá el usuario
@pre el valor que introduzca el usuario tendrá que ser de tipo int.
@param int n. (por referencia) variable de tipo int donde asignaremos el valor introducido
@RETURN devolverá una variable int que llevará asignada el numero ntroducido por el usuario
@post  m tendrá que ser mayor a 0 y menor a la DIM
*/

void PedirEntrada (int &n){



	cout << "Por favor, introduzca hasta que numero desea introducir los primos: ";

	cin >> n;

}



/**

@brief módulo que sirve para ver si un número es primo o no

@pre j > 0

@param int j. variable a la que le asignaremos el número a comprobar si es primo
@RETURN devolverá bool que sirve para ver si es primo. será true si es primo o false si no
@post bool deberá de ser true o falso, dependiendo de si el número es primo o no

*/

bool Primo (int j ){

	 bool primo=true;

	for (int i = 2; ( (i<j) && (primo==true) ); i++) {



		if (j % i == 0){ // si el resto es 0, significárá que el número es divisible.

			

			primo =false;

		}

	

	}



}



/**

@brief modulo que pide a las entradas y te dice si un numero es primo o no
@pre util deberá de ser igual que 0
@param int primos[] vector donde almacenaremos los números que despues comprobaremos
@param int util_primos (por referencia) Variable de tipo int que utilizaremos para ver los espacios ocupados de nuestro vector a tiempo real y la siguiente posición libre
@RETURN Nada. es un procedimiento
@post util_primos deberá de ser mayor que 0 y menor que DIM_VECTOR. 

*/

void PedirEntradaComprobarPrimo (int primos[], int &util_primos, bool primo, int n){



	int i=0;

	PedirEntrada(n); //invocación de la funcion

	for (int j=3; j<=n;j++){ // bucle para repetir n veces el proceso de comprobar si es primo

		primo=true;



		primo=ComprobarPrimo( j);



		if (primo == true){ // si primo es true significará que es primo, con lo cual lo ingresamos en el vector

			primos [i]= j;

			util_primos++;

			i++;

		}

	}

}


/**
@brief Módulo que sirve para imprimir un vector.
@pre util > 0.
@param const int primos [] vector constante del que leeremos sus espacios
@param int util_primos. variable de tipo int que utilizaremos para manejar el contenido del vector y saber hasta cuando leer.
@return Nada. es un procedimiento.
@post  El programa imprimirá el vector correctamente.
*/

void imprimevector (const int primos [], int util_primos){



	for (int i =0; i<util_primos;i++){

		cout << SOLUCION << primos [i] << " Es primo."<< NORMAL << endl;

	}

}

		

int main () {

	const int DIM_PRIMOS= 100; // dimension del vector

	int primos [DIM_PRIMOS];// vector donde guardaremos los primos

	int util_primos=0;// util para manejar el vector

	bool primo=true;

	int n=0;



	PedirEntradaComprobarPrimo (primos, util_primos, primo, n);

	imprimevector(primos, util_primos);



}