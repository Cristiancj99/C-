#include <iostream>
#include <cmath>
using namespace std;


bool analizarMovimientoCaballo(int y1, int x1, int y2, int x2){`// función que analiza el movimiento del caballo
    bool esvalido = false;
  if ( ( (y2 == y1 + 2) && ( (x2 == x1 -1) || ( x2 == x1+1) ) ) || ( (y2 == y1 - 2) && ( (x2 == x1 -1) || ( x2 == x1+1) ) ) || ( (x2 == x1 + 2) && ( (y2 == y1 -1) || ( y2 == y1+1) ) ) || ( (x2 == x1 - 2) && ( (y2 == y1 -1) || ( y2 == y1+1) ) ) ) // todas las condiciones del caballo
	esvalido=true;
    return esvalido;
}

bool analizarMovimientoReina(int fil_y1, int x1, int y2, int x2){ // función que analiza el movimiento de la reina
    bool esvalido = false;
    if ( ( ( (y2 +y1 <= 7) && (y2-y1 >=1) && ( x2 == x1) ) || ( (x2 +x1 <= 7) && (x2-y1 >=1) && ( y2 == y1) ) )  ||  (abs ( x1-x2) ) ==  ( abs ( y1-y2) ) ){ // utilizamos el absoluto para los movimientos en diagonal.
	esvalido=true;
    return esvalido;
}

bool analizarMovimientoTorre(int fil_y1, int x1, int y2, int x2){ // función que analiza el movimiento de la torre
    bool esvalido = false;
    if ( ( (y2 +y1 <= 7) && (y2-y1 >=1) && ( x2 == x1) ) || ( (x2 +x1 <= 7) && (x2-y1 >=1) && ( y2 == y1) ) ) { // movimientos podibles en vertical y en horizontal para la torre
	esvalido=true;
    return esvalido;
}

bool analizarMovimientoPieza(int int fil_y1, int x1, int y2, int x2, char pieza){ // función que analiza cualquier movimiento de cualquier pieza
    
    bool esvalido = false;
    if (pieza == 'C')
        esvalido = analizarMovimientoCaballo(fil_orig, col_orig, fil_dest, col_dest);
    else if (pieza == 'R')
        esvalido = analizarMovimientoReina(fil_orig, col_orig, fil_dest, col_dest);
    else
        esvalido = analizarMovimientoTorre(fil_orig, col_orig, fil_dest, col_dest);
    
    return esvalido;
}

int main(){
    int y1 = 0;
    int x1 = 0;
    int y2 = 0;
    int x2 = 0;
    char pieza = '\0'; //varible me permite identificar la pieza
    bool validez = false;
    
    cout << "Bienvenido al programa KASPAROV. Le ayudaremos a saber si su movimiento para una pieza es válido..." << endl;
    //entradas filtradas
	do{
    		cout << "Introduzca la fila donde se encuentra originalmente su pieza [1-8]: ";
    		cin >> y1;
	}while(y1>7) && (y1< 0);
	do{
	    cout << "Introduzca la columna donde se encuentra originalmente su pieza [1-8]: ";
	    cin >> x1;
	}while(x1 >7) && (x1 < 0);
	do{
		cout << "Introduzca la fila donde pretende mover su pieza [1-8]:";
    		cin >> y2;
	}while(y2 >7) && (y2 < 0);
	do{
		cout << "Introduzca la columna donde pretende mover su pieza :";
		cin >> x2;
	}while(x2>7) && (x2 < 0);
    
    cout << "Introduzca la pieza que pretende mover [(C)aballo,(R)eina,(T)orre]:";
    cin >> pieza;
    
    validez = analizarMovimientoPieza(y1, x1, y2, x2);//invocación de la función
    
    if (validez == true)
        cout << "Movimiento de la pieza SÍ es válido!!" << endl;
    else
        cout << "Movimiento de la pieza NO es válido!!" << endl;
}