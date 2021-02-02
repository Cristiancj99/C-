#include <iostream>
#include "foto.h"
#define NORMAL "\033[1;0m"
#define CYAN "\033[1;36m"
#define DEBUG "\033[1;31m"
#define YELLOW "\033[1;33m"
#define SOLUCION "\033[1;32m"
using namespace std;

Foto::Foto(){

	this->setRuta(" ");
	this->setTipo(" ");
	this->setTamanio(0);
}		

Foto::Foto(string ruta, string tipo, unsigned long int size){

	this->setRuta(ruta);
	this->setTipo(tipo);
	this->setTamanio(size);
}

void Foto::setRuta(string direccion){

	this->ruta=direccion;
}

void Foto:: setTipo (string tipo){

	this->tipo=tipo;
}
void Foto:: setTamanio (unsigned long int size){

	this->tamanio=tamanio;
}

string Foto::getRuta(){

	return this->ruta;
}

string Foto::getTipo(){

	return this->tipo;
}

unsigned long int Foto::getTamanio(){

	return this-> tamanio;
}

void  Foto::print(){ //sobrecarga del operador <<

	cout<<YELLOW<<"ruta: "<<this->getRuta()<<NORMAL;
	cout<<CYAN<<this->getTipo()<<NORMAL<<endl;
	cout<<SOLUCION<<"Tamanio: "<<NORMAL<<this->getTamanio()<< endl;

}

