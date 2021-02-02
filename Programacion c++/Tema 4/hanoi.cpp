#include <iostream>

#define NORMAL "\033[1;0m"
#define CYAN "\033[1;36m"
#define DEBUG "\033[1;31m"
#define YELLOW "\033[1;33m"
#define SOLUCION "\033[1;32m"

using namespace std;
/**
@brief modulo que sirve para pedir el número de fichas filtrado
@param int fichas (por referencia) variable a la que le asignaremos el numero de fichas
@return nada, es un procedimiento.
@post fichas deberá de ser mayor que 1 y menor que 7
*/
void PedirFichas (int &fichas){

	do{
    	cout << "por favor, indique cuantas fichas vas a ingresar";
        cin>> fichas;
    }while ( (n<1) || (n>7) );
}
/**
@brief modulo que sirve para ver los moviientos que necesitas para resolver las torres de hanoi para n fichas
@pre fichas deberá de ser mayor que 1 y menor que 7
@param int fichas numero de fichas de las que consta la partida
@param int origen. columna de donde saldrán las piezas.
@param int intermedio. columna que podremos utilizar como apoyo para mover las fichas a la columna destino
@param int destino. columna donde irán destinadas las piezas.
@Return nada. es un procedimiento 
@post. se deberán de mostrar los pasos por pantalla
*/
void Mover_Torres (int fichas, int origen, int intermedio, int destino){
	if ( fichas > 1 ){ 
		Mover_Torres( fichas - 1, origen, destino, intermedio); //primero se mueve una torre de n-1 a la torre intermedia para dejar la 3 columna libre para la ficha más grande



		cout <<"Mueve la ficha " <<  fichas  << " de " << Origen << " a " <<  Destino << endl;
		Mover_Torres( fichas - 1, intermedio, origen, destino); // después se deberá de mover la fila donde hemos almacinado la torre de n-1 de la columna de el centro a la 3 columna
} 



	if ( fichas == 1 ){ //caso base de que la ficha sea 1
		cout << "Mueve el disco 1 de " << origen << " a " << destino << endl;

	}

} 


int main () {

	int fichas=0;

    PedirFichas(fichas);
    Mover_Torres( fichas, 1, 2, 3);

}