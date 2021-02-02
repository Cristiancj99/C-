#include <iostream>
#define NORMAL "\033[1;0m"
#define CYAN "\033[1;36m"
#define DEBUG "\033[1;31m"
#define YELLOW "\033[1;33m"
#define SOLUCION "\033[1;32m"

using namespace std;

	const int DIM_FILAS=20;
	const int DIM_COLUMNAS=30;

/**
@brief módulo que te pide el numero de filas que vas a introducir
@pre util_filas=0;
@param int util filas (por referencia) nos indica cuantas filas ocupará el usuario
@return nada. Es un procedimiento
@post util_filas deberá de ser mayor que 0 y menor que DIM_FILAS
*/
void PedirFilas (int &util_filas){

	cout << "Por favor, indiquenos cuantas filas va a ingresar: ";
	cin >> util_filas;

}


/**
@brief módulo que te pide el numero de columnas que vas a introducir
@pre util_columnas=0;
@param int util columnas(por referencia) nos indica cuantas columnas ocupará el usuario
@return nada. Es un procedimiento
@post util_columnas deberá de ser mayor que 0 y menor que DIM_COLUMNAS
*/
void PedirColumnas ( int &util_columnas){

	cout << "Por favor, indiquenos cuantas columnas va a ingresar: ";
	cin >> util_columnas;


}

/**
@brief módulo que sirve para rellenar una matriz
@pre util_columnas > 0 y util_filas>0
@param int matriz [] [COLUMNAS] matriz la cual rellenaremos
@param int util_filas variable de tipo int para ver cuantas filas tenemos que rellenar
@param int util_columnas variable de tipo int para ver cuantas columnas tenemos que rellenar
@return Nada. Es un procedimiento
@post las utiles deberán de mantenerse igual y la matriz debe de estar rellena.
*/

void RellenaMatriz (int matriz [] [DIM_COLUMNAS], int util_filas, int util_columnas){

	
	for (int f=0; f<util_filas; f++){
		for (int c=0; c< util_columnas;c++){
	
			cout << "Ingrese la posición ( "<< f << " , " << c << " ) ";
			cin >> matriz [f] [c];
		}
	}

}

/**
@brief módulo que sirve para imprimir una matriz
@pre util_columnas > 0 y util_filas>0 y la matriz debe de estar rellena
@param const int matriz [] [COLUMNAS] SOLO LECTURA.matriz la cual imprimiremos por pantalla
@param int util_filas variable de tipo int para ver el número de filas que tenemos que imprimir
@param int util_columnas variable de tipo int para ver el numero de columnas que tenemos que imprimir
@return Nada. Es un procedimiento
@post La matriz se imprimirá correctamente.
*/

void ImprimeMatriz (const int matriz [] [DIM_COLUMNAS], int util_filas, int util_columnas){

	
	for (int f=0; f<util_filas; f++){
		for (int c=0; c< util_columnas;c++){
	
			cout << matriz [f] [c] ;
		}
	cout<<endl;
	}
			
}
/**
@brief modulo que sirve para comprobar si un número está en el vector.
@pre util_vector tendrá que ser mayor que 0.
@param const int VECTOR []. (L) vector en el que comprobaremos si está un número
@param util_vector variable con la que tendremos el estado de nuestro vector.
@param int NumeroBuscar. variable que tendrá asignada el número que queremos buscar.
@param int n. variable para asignar el valor de la posición donde se encuentra el número
@RETURN Nada. Es un PROCEDIMIENTO
@post si el numero se repite n tendrá que tener su valor, si no la salida correcta del programa 
*/
int BusquedaSimple (const int VECTOR[], int util_vector, int NumeroBuscar,bool &encontrado){

	int i=0;

	for (i=0 ;( (i<util_vector) && (encontrado==false) );i++){ // bucle para comprobar si el numero está en el vector
		cout << DEBUG<< i << NORMAL<<endl;

		if (VECTOR[i] == NumeroBuscar){ // si el contenido de vector [i] es igual al numero que buscmos, asignamos la posición a una variable y finalizamos el bucle
			encontrado= true;
		}
	}
	if (encontrado ==true){
		return i;
	}
}
/**
@brief módulo que sirve para realizar una busqueda secuencial simple
@pre util_columnas > 0 y util_filas>0 y la matriz debe de estar rellena
@param const int matriz [] [COLUMNAS] SOLO LECTURA.matriz en la cual buscaremos el numero
@param int util_filas variable de tipo int para ver el número de filas que tenemos que buscar
@param int util_columnas variable de tipo int para ver el numero de columnas que tenemos que buscar
@param int numero. variable de tipo int que tendrá asignado el numero deseado por el usuario
@param int &fila. Variable por referencia que va a servir para guardar la fila donde estará el elemento 
@param int &columna. Variable por referencia que va a servir para guardar la columna donde estará el elemento 
@param bool encontrado. bool que servirá para una vez encontrado el numero salir del bucle.
@return Nada. Es un procedimiento 
@post El bool tendrá que ser true en cado de estar el número o false en caso de que no. 
@post Si está en la matriz. fila y columna tendrán que ser mayor que 0 y menor que sus respectivas utiles.
*/


bool BusquedaMatriz (const int matriz [] [DIM_COLUMNAS], int util_filas, int util_columnas, int &fila, int &columna, int numero){
	columna=0;
	bool encontrado=false;
	
	for (fila=0; (fila<util_filas && !encontrado); fila++){
			cout << DEBUG<< fila<<NORMAL<< endl;

		columna= BusquedaSimple (matriz[fila], util_columnas, numero, encontrado); // llamamos a la función BusquedaSimple. y le pasamos las filas. ahí encontraremos la columna donde está  el bucle de la función nos dará la fila.
	
		}
	

	return encontrado;			
}
/**
@brief  modulo que sirve para ordenar una matriz por filas por ejemplo: ( 3, 2) --> (1, 2)
																		( 1, 4)     (3, 4) 
@pre La matriz deberá de estar rellena tantas filas como indique util_filas y tantas columnas como indique util_columnas
@param int matriz [] [DIM_COLUMNAS] matriz la cual ordenaremos.
@param int util_filas. variable de tipo int que utilizaremos para ver la cantidad de filas que tenemos escritas.
@param int util_columnas. variable de tipo int que utilizaremos para ver la cantidad de columnas que tenemos escritas.
@RETURN Nada.es un procedimiento
@post  la matriz deberá de estar ordenada y las utiles no deberán de ser modificadas
*/
void OrdenarFilas ( int matriz [] [DIM_COLUMNAS], int util_filas, int util_columnas ){
	int c=0;
	int f=0;
	int f2=0, c2=0;  // variables que utilizaremos para ir cambiando de posicion y comparar
	int aux=0;
	
	for ( f=0; f<util_filas; f++){

		for ( c=0; c< util_columnas;c++){ // este for y el anterior seleccionarán el primer número para scomprobar, una vez comprobado irán pasando de posición

			for (f2=0; f2<util_filas;f2++){
	
				for (c2=0; c2<util_columnas ;c2++){ // recorrerá la matriz comparando los numeros.
	
					if (matriz [f] [c] < matriz [f2] [c2]){// si el contenido de matriz [f] [c] es menor que matriz [f_Ant] [c_ant] se realizará un cambio

						aux = matriz [f] [c];
						matriz [f] [c] = matriz [f2] [c2];
						matriz [f2] [c2]= aux;
					}
				}
			}
		}
	}			


}
/**
@brief  modulo que sirve para ordenar una matriz por columnas por ejemplo (1, 3) --> (1, 3)
									  (4, 2)     (2, 4)
@pre La matriz deberá de estar rellena tantas filas como indique util_filas y tantas columnas como indique util_columnas
@param int matriz [] [DIM_COLUMNAS] matriz la cual ordenaremos.
@param int util_filas. variable de tipo int que utilizaremos para ver la cantidad de filas que tenemos escritas.
@param int util_columnas. variable de tipo int que utilizaremos para ver la cantidad de columnas que tenemos escritas.
@RETURN Nada.es un procedimiento
@post  la matriz deberá de estar ordenada por columnas y las utiles no deberán de ser modificadas
*/
void Ordenarcolumnas ( int matriz [] [DIM_COLUMNAS], int util_filas, int util_columnas ){
	int c=0;
	int f=0;
	int f2=0, c2=0; // variables que utilizaremos para ir cambiando de posicion y comparar
	int aux=0;
	
	for ( c=0; c<util_columnas; c++){

		for ( f=0; f< util_filas;f++){ // este for y el anterior seleccionarán el primer número para scomprobar, una vez comprobado irán pasando de posición

			for (c2=0; c2<util_columnas;c2++){
	
				for (f2=0; f2<util_filas ;f2++){ // recorrerá la matriz comparando los numeros.
	
					if (matriz [f] [c] < matriz [f2] [c2]){ // si el contenido de matriz [f] [c] es menor que matriz [f_Ant] [c_ant] se realizará un cambio

						aux = matriz [f] [c];
						matriz [f] [c] = matriz [f2] [c2];
						matriz [f2] [c2]= aux;
					}
				}
			}
		}
	}			


}

/**
@brief Módulo que sirve para elegir si ordenar una matriz por filas, or columnas o encontrar un numero en ella.
@param una variable char (por REFERENCIA) La utilizaremos para ver en que opcion nos metenmos
@param int matriz [] [DIM_COLUMNAS] matriz con la cual trabajaremos en las opciones.
@param int util_filas. variable de tipo int que utilizaremos para ver la cantidad de filas que tenemos escritas.
@param int util_columnas. variable de tipo int que utilizaremos para ver la cantidad de columnas que tenemos escritas.
@pre deberemos de tener una matriz rellena, las utiles deberán de ser >o y menor que sus DIM.
@return nada. es un PROCEDIMIENTO
@post El menú deberá de llamar bien a la función deseada y mostrar los resultados por pantalla.
*/
void Menu (char &opcion, int matriz [] [DIM_COLUMNAS], int util_filas, int util_columnas){ 

	int numero=0,fila=0,columna=0; // variables que necesitaremos para encontrar el número
	bool encontrado=false;// variables que necesitaremos para encontrar el número
	
	cout << YELLOW<<"         MENU                "<<NORMAL<<endl;
	cout << "Pulse la tecla para realizar la función deseada: " << endl;

	cout  << "Pulsa 'f' ordenar la matriz por filas." <<endl;
	cout  << "Pulsa 'c' para ordenar la matriz por columnas" <<endl;
	cout  << "Pulsa 'e' para encontrar un número en el vector." <<endl;
	cout  << "Pulsa 's' para finalizar el programa." <<endl;
	cin >> opcion;

	switch (opcion) { // switch utilizado para el menú
        	case 'f':

			OrdenarFilas (  matriz ,  util_filas,  util_columnas );
			ImprimeMatriz (matriz, util_filas, util_columnas);;
			break;
		
		case 'c': // caso de ordenar por columnas

			Ordenarcolumnas (  matriz ,  util_filas,  util_columnas );
			ImprimeMatriz (matriz, util_filas, util_columnas);
			break;
		
		case 'e': // caso de encontrar un numero
		
			cout << "Diganos el número que desea buscar";
			cin >> numero;
			encontrado=BusquedaMatriz ( matriz , util_filas,util_columnas, fila, columna, numero);

			if (encontrado==true){

				cout << "El numero " << numero << " Está en la posición (  " << fila -1 << " , " << columna -1 << " )."<<endl;
			}

			else{
				cout << "ERROOOOOOR!!!. Número no encontrado" << endl;
			};
			
			break;


		default:
			break;

	}
}
int main () {

	int matriz [DIM_FILAS] [DIM_COLUMNAS];
	int util_filas=0;
	int util_columnas=0;
	char opcion;
	

	PedirFilas (util_filas);
	PedirColumnas(util_columnas);
	RellenaMatriz (matriz, util_filas, util_columnas);
	ImprimeMatriz (matriz, util_filas, util_columnas);
	do{
		Menu (opcion,matriz, util_filas, util_columnas);
	}while(opcion != 's' );
	


}
