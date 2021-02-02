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
@brief Módulo que sirve para calcular el factorial de forma iterativa
@pre n deberá de ser mayor que 0
@param int n. variable que tiene asignada el factorial que quiere calcular el usuario.
@param int factorial (por referencia) variable que utilizaremos para poder calcular el factorial
@RETURN Nada. Es un procedimiento
@post  n se mantendrá igual que al inicio y factorial deberá de ser > 0.
*/
void FactorialIterativo (int n, int &factorial){

	for (int i=2; i<=n;i++){
	
		factorial *=i;
	}
}
/**
@brief Módulo que sirve para calcular el factorial de forma factorial
@pre n deberá de ser mayor que 0
@param int n. variable que tiene asignada el factorial que quiere calcular el usuario.
@RETURN devolverá un int con el resultado del factorial
@post  n se mantendrá igual que al inicio y factorial deberá de ser > 0.
*/
int FactorialRecursivo (int n){
	int f=0;

	if  (n==0){ //caso base de que n=0
		f=1;
	}
	else{
		f = n * FactorialRecursivo (n-1);
	}
	return f;
	
}
int main () {

	int n=0;
	int factorial=1;

	PedirNumero(n);
	FactorialIterativo(n, factorial);
	cout << "El valor factorial "<<DEBUG<<"iterativo " << NORMAL<< "es: "<< factorial<< endl;
	factorial=FactorialRecursivo( n);
		cout << "El valor factorial "<<CYAN <<"recursivo " << NORMAL<< "es: "<< factorial<< endl;

}