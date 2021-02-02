#include <iostream>
#define NORMAL "\033[1;0m"
#define CYAN "\033[1;36m"
#define DEBUG "\033[1;31m"
#define YELLOW "\033[1;33m"
#define SOLUCION "\033[1;32m"


using namespace std;

/**
@brief modulo que pide al usuario los valores para poder realizar ackerman. 
@param int m. variable de tipo int a la que le asignaremos el prier valor del usuario
@param int n. Variable de tipo int a la que le asignaremos el segundo valor del usuario
@RETURN Nada. Es un procedimiento.
@post  n> 0 && m>0.
*/
void PedirEntradas (int &n, int &m){

	do{
	cout << "Introduzca el valor de n: ";
	cin >> m;

	cout << "Introduzca el valor de m: ";
	cin >> n;
	}while ( ( n<0) && ( m<0) );
}

/**
@brief modulo que sirve para calcular ackerman
@pre n > 0  y m >0
@param int n. valor donde llevará asignado el valor de n
@param int m. valor donde llevará asignado el valor de m
@RETURN devolvera un int donde estará el valor de Ackerman
@post  ackerman >0,
*/
int ackerman (int m, int n){
	int ackermann=0;
	if(m==0) // caso base de que m sea 0.
		ackermann = n+1;
	else if(n==0){ // caso base de qye ackermann sea 0
		ackermann= ackerman(m-1, 1);
	}
        else if ( ( m>0)&& (n>0) ){
		ackermann=ackerman(m-1, ackerman(m, n-1));
    }
	return ackermann;
}
		



int main () {
	
	int n=0, m=0;
	int ackermann=0;

	PedirEntradas (m, n);
	ackermann= ackerman(m,n);
	cout << SOLUCION << ackermann << endl;

}