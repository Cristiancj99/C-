#include <iostream>

#define NORMAL "\033[1;0m"
#define CYAN "\033[1;36m"
#define DEBUG "\033[1;31m"
#define YELLOW "\033[1;33m"
#define SOLUCION "\033[1;32m"
using namespace std;
const int DIM_FILAS=3, DIM_COLUMNAS=3; // variables locales
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
@brief modulo que sirve para determinar una matriz a unos valores en concreto
@param matriz [] [DIM_COLUMNAS] matriz la cual inicializaremos
@RETURN nada. es un procedimiento
@post la matriz se verá incializada con los valores disponibles.

*/
void InicializarMatriz ( char matriz [] [DIM_COLUMNAS]){

	for (int f=0; f<DIM_FILAS; f++){

		for ( int c=0; c<DIM_COLUMNAS;c++){

			matriz[f] [c] = ' ';
		}
	}
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
	cout << "------------"<< endl;

		for ( int c=0; c<DIM_COLUMNAS;c++){

			cout << "|" << matriz [f] [c] << " |";
			
		}
	cout << endl;
	}
}
/**
@brief Modulo que sirve para dar mensajes de error dependiendo de los casos
@pre f > 0, c >0
@param  char matriz [] [DIM_COLUMNAS] matriz que utilizaremos para comprobar
@param int f (por referencia) variable que llevará asignada la fila de la posición a comprobar
@param int c (por referencia) variable que llevará asignada la columna de la posición a comprobar 
@RETURN Nada. es un procedimiento
@post  Dará las salidas correctamente
*/

void MensajesError (char matriz [] [DIM_COLUMNAS],int &f, int &c){
	if ( (f<0) || (c<0) || (f>3) || ( c>3) ) { // caso de que una ficha esté en el tablero

		cout << DEBUG << "NO PUEDES PONER UNA FICHA FUERA DEL TABLERO!!!"<<NORMAL<<endl;
	}
	if ( ( matriz [f][c] =='X') || (matriz [f][c] == 'O') ){ // caso de que una ficha esté ocupada

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
		while( (!(cin >> f) ) || (!( cin >> c)) ){ // cuando f y c tengan un contenido que no corresponde a su tipo de variable entrará en el bucle
			cout << DEBUG<< "CUIDADO CON LO QUE INGRESAS " << NORMAL << endl;
			filtrado();
			
		}
	MensajesError (matriz, f, c);
	}while ( (f>3) || (c>3) || (f<0) || (c<0) || (matriz [f][c] == 'X' ) || (matriz [f][c] == 'O') );

}
/**
@brief Módulo que sirve para comprobar La matriz y ver si hay 3 en ralla
@pre la matriz deberá de ir actualizandose a tiempo real, es decir, se deberá de hacer cada vez que el usuario introduzca un valor
@param const char matriz [] [DIM_COLUMNAS] matriz que sutilizaremos como tablero para comprobar 
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

	if ( ( (matriz[2] [0] == 'X')&&(matriz [1] [1] == 'X') && (matriz [0] [2] == 'X') ) || ( (matriz[2] [0] == 'O')&&(matriz [1] [1] == 'O') && (matriz [0] [2] == 'O') ) ){ // condicion de ralla en diagonal 1 ( abajo a arriba)

		victoria=true;
	}


	return victoria;
}
/**
@brief modulo para dar las salidaas del programa.
@pre turno > 0  
@param char matriz [] [DIM_FILAS] matriz con la cual llamaremos a la funcion de imprime matriz para ver el resultado fnal.
@param int turno. variable que llevará asignado el turno con el que determinaremos que jugadpr ha ganado
@param bool victoria. Nos dirá si algún jugador ha ganado o no
@param const char jugador1 [] vector que tendrá asignado el nombre del jugador 1
@param const char jugador2 [] vector que tendrá asignado el nombre del jugador 2
@RETURN Nada. es un procedimiento
@post  Las salidas se imprimirán correctamente por pantalla
*/
void salidas (char matriz [] [DIM_FILAS], int turno, bool victoria, const char jugador1 [], const char jugador2 [] ){

	if ( ( turno%2==0) && (victoria) ) { // caso de la victoria del jugador 1
		cout << YELLOW;
		cout<<"Enhorabuena " << jugador2<<" , has ganado!!"  << endl;
		ImprimeMatriz (matriz);
	
	}
	if ( ( turno%2!=0) && (victoria) ) { // caso de victoria del jugador 2
		cout << CYAN;
		cout <<"Enhorabuena "<<jugador1<<" , has ganado!!" << endl;
		ImprimeMatriz (matriz);
	
	}
	if (!victoria) { // caso de empate

		cout << DEBUG << "Lo siento, no ha habido ningún ganador..."<< endl;
		ImprimeMatriz (matriz);
	}
	cout << NORMAL;
}

/**
@brief modulo que sirve para enseñar un menu y que el usuario pueda elegir sus opciones 
@pre char != e
@param  char &opcion(por referencia) parametro que sirve para ver que opción cogemos.
@param char matriz [] [DIM_COLUMNAS] matriz de tipo char que utiizaremos como tablero.
@param const char jugador1 [] vector que tendrá asignado el nombre del jugador 1
@param const char jugador2 [] vector que tendrá asignado el nombre del jugador 2
@RETURN Nada. es un procedimiento
@post  Mostrará por pantalla el menú correctamente
*/

void menu ( char &opcion, char matriz[] [DIM_COLUMNAS], const char jugador1[], const char jugador2[]){
	int f=0, c=0;
	int turno=0;
	bool victoria=false;

	cout << "---------------------------MENU--------------------------"<<endl;
	cout << "Para jugar, pulse j"<<endl;
	cout << "Para finalizar el programa, pulse [e]xit"<<endl;
	cin >> opcion;

	switch (opcion) { // switch utilizado para el menú
        	case 'j':
		
		InicializarMatriz (matriz);
			
			while ( (turno <9) && ( victoria == false) ){	// bucle que se repetiá hasta que se agoten los turnos o hasta que haya un ganador

				ImprimeMatriz (matriz); 
				if (turno %2==0){ // si turno es par, significa que le toca al jugador 1
					cout << YELLOW << "Tu turno, " << jugador1 <<" : "<< NORMAL << endl;
					IntroduceFicha (matriz, f, c);
					matriz [f] [c]= 'X';
				}
				else{// si es impar significa que le toca al jugador 2
					cout << CYAN << " Adelante, " << jugador2 << " : "<< NORMAL << endl;
					IntroduceFicha (matriz, f, c);
					matriz [f] [c]= 'O';
				}
				turno ++;
				victoria=CondicionVictoria ( matriz);
			}
			
			salidas ( matriz , turno,  victoria, jugador1, jugador2);

			break;

		default:
			break;

	}
}


int main () {

	char matriz [DIM_FILAS] [DIM_COLUMNAS]= {' '};
	char opcion='\0';
	const int DIM_VECTOR=30;
	char usuario1[DIM_VECTOR];
	char usuario2 [DIM_VECTOR];

	cout << "Por favor, indtroduza su usuario, jugador 1..."; // pedimos el nombre al usuario1
	cin.getline(usuario1, DIM_VECTOR);

	cout << "Por favor, indtroduza su usuario, jugador 2..."; // pedimos el nombre al usuario2
	cin.getline(usuario2, DIM_VECTOR);

	cout << CYAN << "Bienvenidos al fabuloso Tres en ralla " << usuario1 << " y " << usuario2 << NORMAL << endl;
	do{
		menu( opcion, matriz, usuario1, usuario2);

	}while (opcion != 's');
}


