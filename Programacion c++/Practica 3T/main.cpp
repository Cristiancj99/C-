#include <iostream>
#include "vista.h"
using namespace std;

int main (){

	Vista mivista;
	char opcion;
	bool creado=false;// variable que utilizaremos para filtrar el menu
	
	do{ // llamada al menu

		mivista.menu(opcion, creado);
	}while(opcion !='s');
}
