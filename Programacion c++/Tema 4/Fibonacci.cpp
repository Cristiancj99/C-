#include <iostream>
#define NORMAL "\033[1;0m"
#define CYAN "\033[1;36m"
#define DEBUG "\033[1;31m"
#define YELLOW "\033[1;33m"
#define SOLUCION "\033[1;32m"


using namespace std;
/**
@brief modulo que sirve para pedir un número a un usuario y lo filtra para que sea mayor que 0 
@param int n (por referencia) variable que utilizaremos para asignar el valor al usuario.
@RETURN Nada. Es un procedimiento
@post  n deberá de ser > que 0.
*/

void PedirNumero (int &n){

	do {
		cout << " Por favori, digame hasta que número deseas calcular el factorial: "<<endl;
		cin >> n;
	}while (n<0);
}

/**
@brief módulo que sirve para calcular fibonacci sobre un número
@pre numero > 0
@param int numero . Tendrá el número sobre el que calcularemos fibonacci
@RETURN devolverá una variable de tipo int que contendrá el resultado de fibonacci
@post fibonacci deberá de ser > 0 
*/
int FibonacciIterativo (int numero){

	int f1=0, f2=0, suma=0;

	for ( int i=0;i<=numero;i++){

		if (i==1){ // caso base de que i sea =1

			suma=1;
		}
		if (i==0){ // caso base de que i sea igual a 0

			suma=0;
		}
		if (i>1){ // caso general

			f2=f1;
			f1=suma;
			suma=f1+f2;
		}
	}
	return suma;
}

/**
@brief módulo que sirve para calcular fibonacci sobre un número
@pre numero > 0
@param int numero . Tendrá el número sobre el que calcularemos fibonacci
@RETURN devolverá una variable de tipo int que contendrá el resultado de fibonacci
@post fibonacci deberá de ser > 0 
*/
int FibonacciRecursivo (int numero){

	int f1=0, f2=0, suma=0;

	if (numero==1){ // caso base de que numero=1
		suma=1;
	}
	if (numero==0){// caso base de que numero=0
		suma=0;
	}
	if (numero>1){ // caso general
		suma=FibonacciRecursivo(numero-1) + FibonacciRecursivo(numero-2);
	}

	
	return suma;
}
	





int main () {
	int n=0;
	int fibonacci=0;

	PedirNumero (n);
	fibonacci=FibonacciIterativo (n);
		cout << " El valor para fibonacci "  <<DEBUG  << "RECURSIVO"<<NORMAL << " es: " << fibonacci<<endl;
	fibonacci = FibonacciRecursivo (n);
	cout << " El valor para fibonacci "  <<CYAN  << "RECURSIVO"<<NORMAL << " es: " << fibonacci<<endl;
}