#include <iostream>

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

int main () {

	int matriz [DIM_FILAS] [DIM_COLUMNAS];
	int util_filas=0;
	int util_columnas=0;

	PedirFilas (util_filas);
	PedirColumnas(util_columnas);
	RellenaMatriz (matriz, util_filas, util_columnas);
	ImprimeMatriz (matriz, util_filas, util_columnas);

}