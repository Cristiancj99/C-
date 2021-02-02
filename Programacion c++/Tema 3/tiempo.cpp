#include <iostream>
using namespace std;

//declaración de funciones.

/**
@brief módulo que te pide un numero hasta que es mayor que 0 
@pre no tiene 
@param int ValorInicial( variable por REFERENCIA)
@return nada. es un procedimiento, con lo cual la salida se realiza mediante el parámetro formal
@post ValorInicial>0 
*/

void entrada (int &ValorInicial){ // funció de entrada

	do {
		cout << "introduce un número de segundos";
		cin >> ValorInicial;
	} while (ValorInicial < 0 );
}
/**
@brief módulo que hará los procedimientos necesarios para transformar los segundos en dias, horas, minutos y segundos.
@pre n>0 
@param int ValorInicial( variable filtrada anteriormente)
@param int dias( variable por REFERENCIA)
@param int horas( variable por REFERENCIA)
@param int minutos( variable por REFERENCIA)
@param int segundos( variable por REFERENCIA)
@return nada. es un procedimiento, con lo cual la salida se realiza mediante el parámetro formal
@post dias > 0, horas >0 y <24, minutos >0 y < 60, y segundos >0 y < 60
*/
void transformacion (int ValorInicial, int &dias, int &horas, int &minutos, int &segundos){
	dias = ValorInicial/ 86400; //proeso para calcular los dias
	horas = ( ValorInicial % 86400) / 3600; // proceso para calcular las horas
	minutos = (( ValorInicial % 86400) % 3600) / 60;//proceso para calcular los minutos
	segundos= (( ValorInicial % 86400) % 3600) % 60; // proceso para calcular los segundos
}

/**
@brief módulo que realizará la salida del programa
@pre dias > 0, horas >0 y <24, minutos >0 y < 60, y segundos >0 y < 60
@param int dias( variable calculada anteriormente)
@param int horas( variable calculada anteriormente)
@param int minutos( variable calculada anteriormente)
@param int segundos( variable calculada anteriormente
@return nada. es un procedimiento, con lo cual la salida se realiza mediante el parámetro formal
@post 
*/
void salida  (int ValorInicial, int dias, int horas, int minutos, int segundos){

	cout << ValorInicial << " Son " <<dias << " días " << horas << " horas " << minutos << " minutos " << " y " << segundos << " Segundos " << endl; 
}

int main ()  {

	int dias=0, horas=0, minutos=0, segundos=0;
	int ValorInicial=0;

	cout << "Bienvenidos al programa que transforma segundos!!"<<endl;
//invocación de las funciones
	entrada(ValorInicial);
	transformacion ( ValorInicial,dias, horas, minutos, segundos);
	salida ( ValorInicial,dias, horas, minutos, segundos);
}