#include <iostream>
#define NORMAL "\033[1;0m"
#define CYAN "\033[1;36m"
#define DEBUG "\033[1;31m"
#define YELLOW "\033[1;33m"
#define SOLUCION "\033[1;32m"


using namespace std;

/**
@brief modulo que sirve para decir cuantos números quieres introducir y filtrarlo para que sea menor que DIM_VECTOR
@param int num1 para guardar el valor
@param const int DIM_VECTOR Nos marcará el valor máximo que podrá tener num1
@RETURN Nada, es un procedimiento
@post  n>0  n< DIM_VECTOR
*/
void PedirNumero (int &num1, const int DIM_VECTOR){

	do{
		cout << "Por favor, Introduzca cuantos números quieres ingresar en el vector. Primero en el uno y despues en el dos.";
		cin >> num1;
	}while ( num1 > DIM_VECTOR);

}
/**
@brief módulo para pedir cuantos numeros van a tener los dos vectores 
@pre utiles=0
@param int num1 (por referencia) variable que sirve para ver la cantidad de numeros que ingresará el usuario en el vector 1
@param int num2 (por referencia) variable que sirve para ver la cantidad de numeros que ingresará el usuario en el vector 2
@param const int DIM_VECTOR Nos marcará el valor máximo que podrá tener num1
@RETURN Nada. Es un procedimiento
@post  num1 y num2 < DIM_VECTOR && > 0
*/
void Entradas (int &num1, int &num2, const int DIM_VECTOR){

	PedirNumero (num1, DIM_VECTOR);
	PedirNumero (num2, DIM_VECTOR);


}

/**
@brief Módulo que sirve para rellenar un vector
@pre  util_uno=0
@param  int vector [] vector que rellenaremos con los datos del usuario
@param int num. variable a la que asignaremos la cantidad de numeros que ingresará el usuario
@param util_vector (por referencia) variable que sirve para llevar el estado en tiempo real de nuestro vector
@RETURN no devuelve nada, es un procedimiento
@post util_uno =< DIM_VECTOR y == num
*/
void rellenarvector ( int num, int vector [], int &util_vector){
	for (int i=0; i<num; i++){ // bucle que sirve para rellenar un vector
		
		cout << "Por favor, diganos los numeros que desea (primero vector 1 y después vector 2";
		cin >> vector[i];
		util_vector++;
	}
}


/**
@brief Modulo que copia un vector en otro y da salida a todos los componentes del vector
@pre util_uno > 0 y < DIM_VECT, util_dos será menor o igual que util_uno
@param int dos[] vector de tipo int donde copiaremos el otro vector
@param const int uno [] (L)vector que llevará los valores a copiar en dos
@param int util_dos (por referencia). variable que servirá para seguir el estado de dos[]
@param int util_uno nos dirá la cantidad de espacios que están ocupados en uno[]
@RETURNNada. Es un procedimiento
@post  util_dos = util_uno
*/


void CopiaVector (int uno [], const int &util_uno, int dos [], int &util_dos){

	util_dos=0;

	for (int i =0; i < util_uno; i++){  // bucle para copiar un vector

		dos[i] = uno [i];
		util_dos++;
	}
}
	
/**
@brief copia el vector uno en un vector aux y de ahi al vector_dos 
@pre util_uno > 0 y < DIM_VECT, util_dos será menor o igual que util_uno
@param int dos[] vector de tipo int donde copiaremos el otro vector
@param const int uno [] (L)vector que llevará los valores a copiar en dos
@param int util_dos (por referencia). variable que servirá para seguir el estado de dos[]
@param int util_uno nos dirá la cantidad de espacios que están ocupados en uno[]
@RETURNNada. Es un procedimiento
@post  util_dos = util_uno
*/
void Copia (int uno [], int &util_uno, int dos [], int &util_dos, const int DIM_VECTOR){

	int vector_Auxiliar [DIM_VECTOR]; // vector auxiliar 
	int util_vector_auxiliar=0;

	CopiaVector (uno, util_uno, vector_Auxiliar, util_vector_auxiliar);
	CopiaVector (dos, util_dos, uno, util_uno);
	CopiaVector (vector_Auxiliar, util_vector_auxiliar, dos, util_dos);
}

/**
@brief Módulo que sirve para dar las salidas del programa.
@pre util > 0.
@param const int VECTOR [] vector constante del que leeremos sus espacios
@param int util. variable de tipo int que utilizaremos para manejar el contenido del vector y saber hasta cuando leer.
@return Las salidas.
@post  El programa imprimirá el vector correctamente.
*/
void salidas ( int dos [], int util_dos, int uno [], int util_uno){

	for (int i=0; i< util_uno; i++){
		cout << SOLUCION<< " el valor " << i << " es " << uno [i] << NORMAL<<  endl;

	}
	for (int i=0; i< util_dos; i++){
		cout << CYAN<< " el valor en el vector 2 de  " << i << " es " << dos [i] << NORMAL<<  endl;

	}
}


int main () {
	const int DIM_VECTOR=20;
	int uno [DIM_VECTOR];
	int util_uno=0;
	int dos [DIM_VECTOR];
	int util_dos=0;
	int numuno=0;
	int numdos=0;


	//  invocación de las funciones
	Entradas (numuno, numdos, DIM_VECTOR);
	rellenarvector (  numuno, uno , util_uno);
	rellenarvector ( numdos, dos,util_dos);
	Copia (uno, util_uno, dos , util_dos, DIM_VECTOR);
	salidas ( dos,util_dos, uno, util_uno);

}