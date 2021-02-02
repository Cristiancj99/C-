#include <iostream>

#define NORMAL "\033[1;0m"
#define CYAN "\033[1;36m"
#define DEBUG "\033[1;31m"
#define YELLOW "\033[1;33m"
#define SOLUCION "\033[1;32m"
using namespace std;
const int DIM_FILAS=3, DIM_COLUMNAS=3;
/**
@brief modulo que sirve para incluir las lineas de filtro sin necesidad de repetirlas
@pre introducir una variable de un tipo distinto 
@param 
@RETURN nada. (es un procesamiento, con lo cual no devolverá nada)
@post  el buffer se borrará y volverá a pedir valor al usuario
*/
void filtrado(){
	cin.clear();//borra el indicador de error en el cin.
	cin.ignore(256,'\n');//ignora 256 caracteres y el salto de linea
}
/**
@brief módulo que sirve para imprimir una matriz
@pre util_columnas > 0 y util_filas>0 y la matriz debe de estar rellena
@param const int matriz [] [COLUMNAS] SOLO LECTURA.matriz la cual imprimiremos por pantalla

@return Nada. Es un procedimiento
@post La matriz se imprimirá correctamente.
*/

void ImprimeMatriz ( const char matriz [] [DIM_COLUMNAS]){
	
	for (int f=0; f<DIM_FILAS; f++){

		for ( int c=0; c<DIM_COLUMNAS;c++){

			cout << "|" << matriz [f] [c];
		}
	cout << endl;
	}
}
/**
@brief Modulo que sirve para dar mensajes de error dependiendo de los casos
@pre f > 0, c >0
@param  char matriz [] [DIM_COLUMNAS] matriz que utilizaremos para comprobar 
@RETURN Nada. es un procedimiento
@post  Dará las salidas correctamente
*/

void MensajesError (char matriz [] [DIM_COLUMNAS],int &f, int &c){
	if ( (f<0) || (c<0) || (f>3) || ( c>3) ) {

		cout << DEBUG << "NO PUEDES PONER UNA FICHA FUERA DEL TABLERO!!!"<<NORMAL<<endl;
	}
	if ( ( matriz [f][c] =='X') || (matriz [f][c] == 'O') ){

		cout << DEBUG << "RESPETA AL OTRO USUARIO !!!!" <<NORMAL << endl;
	}
}
/**
@brief  modulo que sirve para introducir una ficha en el tablero
@param char matriz [] [DIM_COLUMNAS] matriz que simulará al tablero y la comprobaremos para ver si hay una posición ocupada 
@param int f (por referencia) Variable que sirve para asignar la fila donde se ingresará la ficha
@param int c (por referencia) Variable que sirve para asignar la columna donde se ingresará la ficha
@RETURNNada. Es un procedimiento
@post   La ficha se ingresará en dentro de tablero y en una posicion libre. es decir, f>0 && f<3, c>0 && c<3.
*/
void IntroduceFicha (char matriz [] [DIM_COLUMNAS],int &f, int &c){
	

	do{
		cout << "Posición que va a ingresar: "<< endl;
		while( (!(cin >> f) ) || (!( cin >> c)) ){
			cout << DEBUG<< "CUIDADO CON LO QUE INGRESAS " << NORMAL << endl;
			filtrado();
			
		}
	MensajesError (matriz, f, c);
	}while ( (f>3) || (c>3) || (f<0) || (c<0) || (matriz [f][c] == 'X' ) || (matriz [f][c] == 'O') );

}
/**
@brief Módulo que sirve para comprobar La matriz y ver si hay 3 en ralla
@pre la matriz deberá de ir actualizandose a tiempo real, es decir, se deberá de hacer cada vez que el usuario introduzca un valor
@param matriz [] [DIM_COLUMNAS] matriz que sutilizaremos como tablero para comprobar 
@RETURN Devolvera un bool true o false dependiendo si hay alguna linea
@post  en bool deberá de estar con true si se cumple alguna condición, si no se mantendrá rn true
*/
bool CondicionVictoria (const char matriz [] [DIM_COLUMNAS]){
	bool victoria=false;

	if( ( (matriz[0] [0] == 'X')&&(matriz [0] [1] == 'X') && (matriz [0] [2] == 'X') ) || ( (matriz[0] [0] == 'O')&&(matriz [0] [1] == 'O') && (matriz [0] [2] == 'O') ) ){ // condición de ralla en fila 0

		victoria=true;
	}
	if( ( (matriz[1] [0] == 'X')&&(matriz [1] [1] == 'X') && (matriz [1] [2] == 'X') ) || ( (matriz[1] [0] == 'O')&&(matriz [1] [1] == 'O') && (matriz [1] [2] == 'O') ) ) { // condición de ralla en fila 1

		victoria=true;
	}

	if ( ( (matriz[2] [0] == 'X')&&(matriz [2] [1] == 'X') && (matriz [2] [2] == 'X') ) || ( (matriz[2] [0] == 'O')&&(matriz [2] [1] == 'O') && (matriz [2] [2] == 'O') ) ){ // condicion de ralla en fila 2

		victoria=true;
	}

	if ( ( (matriz[0] [0] == 'X')&&(matriz [1] [0] == 'X') && (matriz [2] [0] == 'X') ) || ( (matriz[0] [0] == 'O')&&(matriz [1] [0] == 'O') && (matriz [2] [0] == 'O') ) ){ // condicion de ralla en columna 2

		victoria=true;
	}

	if( ( (matriz[0] [1] == 'X')&&(matriz [1] [1] == 'X') && (matriz [2] [1] == 'X') ) || ( (matriz[0] [1] == 'O')&&(matriz [1] [1] == 'O') && (matriz [2] [1] == 'O') ) ){ // condicion de ralla en columna 2

		victoria=true;
	}

	if ( ( (matriz[0] [2] == 'X')&&(matriz [1] [2] == 'X') && (matriz [2] [2] == 'X') ) || ( (matriz[0] [2] == 'O')&&(matriz [1] [2] == 'O') && (matriz [2] [2] == 'O') ) ){ // condicion de ralla en columna 3

		victoria=true;
	}

	if ( ( (matriz[0] [0] == 'X')&&(matriz [1] [1] == 'X') && (matriz [2] [2] == 'X') ) || ( (matriz[0] [0] == 'O')&&(matriz [1] [1] == 'O') && (matriz [2] [2] == 'O') ) ){ // condicion de ralla en diagonal 1 ( arriba a abajo)

		victoria=true;
	}

	if ( ( (matriz[2] [0] == 'X')&&(matriz [1] [1] == 'X') && (matriz [0] [2] == 'X') ) || ( (matriz[2] [0] == 'O')&&(matriz [1] [1] == 'O') && (matriz [0] [2] == 'O') ) ){ // condicion de ralla en diagonal 1 ( arriba a abajo)

		victoria=true;
	}


	return victoria;
}
/**
@brief modulo para dar las salidaas del programa.
@pre turno > 0  
@param int turno. variable que llevará asignado el turno con el que determinaremos que jugadpr ha ganado
@param bool victoria. Nos dirá si algún jugador ha ganado o no
@RETURN Nada. es un procedimiento
@post  Las salidas se imprimirán correctamente por pantalla
*/
void salidas (char matriz [] [DIM_FILAS], int turno, bool victoria){

	if ( ( turno%2==0) && (victoria) ) {
		cout << YELLOW;
		cout<<"Enhorabuena jugador 2, has ganado!!"  << endl;
		ImprimeMatriz (matriz);
	
	}
	if ( ( turno%2!=0) && (victoria) ) {
		cout << CYAN;
		cout <<"Enhorabuena jugador 1, has ganado!!" << endl;
		ImprimeMatriz (matriz);
	
	}
	if (!victoria) {

		cout << DEBUG << "Lo siento, no ha habido ningún ganador..."<< endl;
		ImprimeMatriz (matriz);
	}
	cout << NORMAL;
}
int main () {

	char matriz [DIM_FILAS] [DIM_COLUMNAS]= {' '};
	int f=0, c=0;
	int turno=0;
	bool victoria=false;
	

	while ( (turno <9) && ( victoria == false) ){	

		ImprimeMatriz (matriz); 
		if (turno %2==0){
			cout << YELLOW << "Tu turno, JUGADOR1: "<< NORMAL << endl;
			IntroduceFicha (matriz, f, c);
			matriz [f] [c]= 'X';
		}
		else{
			cout << CYAN << " Adelante, JUGADOR 2: "<< NORMAL << endl;
			IntroduceFicha (matriz, f, c);
			matriz [f] [c]= 'O';
		}
		turno ++;

		victoria=CondicionVictoria ( matriz);
	}
	salidas ( matriz , turno,  victoria);
}

