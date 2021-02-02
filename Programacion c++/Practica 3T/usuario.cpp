#include <iostream>
#include<string>
#include <stdlib.h>
#include "usuario.h"
#define NORMAL "\033[1;0m"
#define CYAN "\033[1;36m"
#define DEBUG "\033[1;31m"
#define YELLOW "\033[1;33m"
#define SOLUCION "\033[1;32m"
using namespace std;


Usuario::Usuario(){

	if (debug){
		cout<<"DEBUG: inicio del constuctor de usuario"<<endl;
	}
	this->setLogin( " ");
	this->setNombre(" ");
	this->setApellido(" " );
	this->setPerfil (" " );
	this->setDebug(false);
	if (debug){
		cout<<"DEBUG: final del constuctor de usuario"<<endl;
	}
}


Usuario::Usuario(string login, string nombre, string apellidos, string perfil_usuario){
	if (debug){
		cout<<"DEBUG: inicio del constuctor por parámetros de usuario"<<endl;
	}
	this->setLogin(login);
	this->setNombre(nombre);
	this->setApellido(apellidos);
	this->setPerfil(perfil_usuario);
	if (debug){
		cout<<"DEBUG: final del constuctor por parámetros de usuario"<<endl;
	}
}
Usuario::~Usuario(){
	if (debug){
		cout<<"DEBUG: inicio del destructor de Usuario"<<endl;
	}

	this->setLogin( " ");
	this->setNombre(" ");
	this->setApellido(" " );
	this->setPerfil(" ");
	this->setDebug(false);

	if (debug){
		cout<<"DEBUG: final del destructor de Usuario"<<endl;
	}
}
void Usuario::setLogin ( string login){

	this->login=login;
}
void Usuario::setPerfil ( string p){

	this->perfil=p;
}
void Usuario::setDebug ( bool debug){

	this->debug=debug;
}
void Usuario::setNombre ( string nombre){

	this->nombre=nombre;
}
void Usuario::setApellido ( string apellido){

	this->apellido=apellido;
}


string Usuario::getLogin(){

	return this->login;
}
string Usuario::getNombre(){

	return this->nombre;
}
string Usuario::getApellido(){

	return this->apellido;
}
string Usuario::getPerfil_usuario(){

	return this->perfil;
}

bool Usuario::getDebug(){

	return this->debug;
}
void Usuario::print(){
	
	
	cout<<CYAN<<"Login: "<<NORMAL<<this->getLogin()<<endl;
	cout<<CYAN<<"Nombre: "<<NORMAL<<this->getNombre()<<endl;
	cout<<CYAN<< "apellidos: "<<NORMAL<< this-> getApellido()<<endl;
	cout<<CYAN<<"Perfil de usuario: " <<NORMAL<< this->getPerfil_usuario()<<endl;
	
}

Admin::Admin() :Usuario(){
	if (debug){
		cout<<"DEBUG: inicio del constructor de Admin"<<endl;
	}

	this->setTotal_consultas(0);	
	if (debug){
		cout<<"DEBUG: final del constructor de Admin"<<endl;
	}
}
Admin::Admin(string login, string nombre, string apellidos, string perfil_usuario, int consultas) : Usuario(){
	
	if (debug){
		cout<<"DEBUG: inicio del constructor por parámetros de Admin"<<endl;
	}

	this->setLogin(login);
	this->setNombre(nombre);
	this->setApellido(apellidos);
	this->setPerfil(perfil_usuario);
	this->setTotal_consultas(consultas);

	if (debug){
		cout<<"DEBUG: final del constructor por parámetros de Admin"<<endl;
	}
}
Admin::~Admin(){
	if(this->getDebug()==true){
		cout<<"DEBUG: ENTRANDO AL DESTRUCTOR DE UN USUAARIO ADMIN"<<endl;
	}
	setTotal_consultas (0);
	if(this->getDebug()==true){
		cout<<"DEBUG: FINALIZANDO EL DESTRUCTOR DE UN USUAARIO ADMIN"<<endl;
	}
}
void Admin:: setTotal_consultas (int numero){

	this->total_consultas=numero;
}
int Admin::getTotal_consultas(){

	return this-> total_consultas;
}
void Admin::print(){

	cout<<SOLUCION;
	cout<<" Administrador: "<<endl;
	this->Usuario::print();
	cout<< " consultas realizadas: "<<getTotal_consultas()<<endl;
	cout<<NORMAL;
}


void Admin::BusquedaFragmento (string fragmento, Usuario *u){//EJERCICIO EXTRA

	int encontrado=0;// variable que utilizaremos para ver si se encuentra la foto bien
	int i=0;
	string buscar;

		if(Normal *h = dynamic_cast<Normal*>(u)){
  	
		for(i=0; i<h->getTotalFotosUsuario ();i++){// este bucle lo utilizaremos para comprobar todas las fotos del usuario, una vez acabado de comprobar, en el anterior int se cambiará
			buscar=h->DevolverFotoVector(i).getRuta();

			encontrado=buscar.find(fragmento, 0); // funcion para ver si se encuentra el fragmento en la ruta de la foto.
			
			if (encontrado != -1){ // si encontrado devuelve algo distinto a menos uno es porque si se encuentra.
			
				cout<<SOLUCION<< buscar<<NORMAL<<endl;
			}
			encontrado=0;// reseteamos encontrado
		}
	}				
}
void Normal::resize(int dim_nueva){


    	Foto *aux=new Foto [dim_nueva];

	 if (this->getTotalFotosUsuario() < dim_nueva){ // caso de que la dimension nueva sea mayor que la dimension actual.
		if(this->getDebug()==true){
			cout << "su vector nuevo es mayor que el anterior, con lo cual no hay problema."<<endl;
		}

		for (int i=0; i<this->getTotalFotosUsuario();i++){ // copiamos todo el contenido del vector en el auxiliar
			aux[i]=this->v_fotos[i];
   		}
		if(this->getDebug()==true){
			cout << "cambio realizado"<<endl;
		}
	}  

	delete []v_fotos;// borramos el vector dinámico antiguo 
	this->v_fotos=0;// hacemos que el vector dinamico apunte a null
	this->v_fotos=aux;

}
Normal::Normal(string login, string nombre, string apellidos, string perfil_usuario, double salario, int util, int dim) : Usuario(){
	
	if (debug){
		cout<<"DEBUG: inicio del constructor por parámetros de Normal"<<endl;
	}

	this->setLogin(login);
	this->setNombre(nombre);
	this->setApellido(apellidos);
	this->setPerfil(perfil_usuario);
	this->setSaldo(salario);
	this->setTotalFotosUsuario(util);
	this->setDimFotos(dim);
	v_fotos= new Foto[DimFotos];
	if (v_fotos==0){

		cout<< " lo siento, no puede continuar la ejecutación del programa"<<endl;
		exit(-1);
	}

	if (debug){
		cout<<"DEBUG: final del constructor por parámetros de Normal"<<endl;
	}
}
Normal::Normal() : Usuario(){

	if (debug){
		cout<<"DEBUG: inicio del constructor de Normal"<<endl;
	}

	TotalFotosUsuario=0;
	saldo=0.0;
	DimFotos=5;
	v_fotos= new Foto[DimFotos];// declaramos un vector dinámico
	if (v_fotos==0){//si no hay espacio en el heap, abortamos.

		cout<< " lo siento, no puede continuar la ejecutación del programa"<<endl;
		exit(-1);
	}

	if (debug){
		cout<<"DEBUG: final del constructor de Normal"<<endl;
	}
}


Normal::~Normal(){
	if(this->getDebug()==true){
		cout<<DEBUG<<"DEBUG: ENTRANDO AL DESTRUCTOR DE UN USUAARIO NORMAL"<<NORMAL<<endl;
	}

	for(int i=0;i<this->getTotalFotosUsuario();i++){// recorremos el vector eliminando el vector

		eliminarFotoVector(i);
	}
	delete [] v_fotos; // eliminamos memoria dinamica
	v_fotos=0;//apuntamos a null
	TotalFotosUsuario=0;
	saldo=0.0;
	DimFotos=0;
	if(this->getDebug()==true){	
		cout<<SOLUCION<<"DEBUG: FINALIZANDO DESTRUCTOR DE UN USUAARIO NORMAL"<<NORMAL<<endl;
	}
}

void Normal::setTotalFotosUsuario (int numero){

	this->TotalFotosUsuario=numero;
}

void Normal:: setSaldo (double numero){

	if (numero > 0){

		this->saldo=numero;
	}

	else{

		cerr<<"Lo siento, no se admite un salario negativo..."<<endl;
	}
}
void Normal:: setDimFotos (int numero){

	this->DimFotos=numero;
}



int Normal::getTotalFotosUsuario (){

	return this->TotalFotosUsuario;
}


double Normal::getSaldo (){

	return this->saldo;
}


int Normal::getDimFotos (){

	return this->DimFotos;
}

void Normal::print(){

	char opcion;

	cout<<YELLOW<<"usuario sin privilegios: "<<NORMAL<<endl;

	this->Usuario::print();

	cout<<YELLOW<<"Saldo:"<<this->getSaldo()<<NORMAL<<endl;

	cout<<YELLOW<<"Numero de fotos"<<this->getTotalFotosUsuario()<<NORMAL<<endl;
	do{
		cout << " desea ver las fotos del Usuario? S(si), N(no)"<<endl;
		cin>>opcion;
	}while( (opcion !='S') && (opcion !='N') );
	if (opcion=='S'){

		this->imprimirVectorFotos();
	}
	if (opcion=='N'){
		cout <<"okey"<<endl;
	}
	

}


void Normal::InsertarFotoVector (const Foto &f){

	if (this->getTotalFotosUsuario() < this->getDimFotos()){ // si la util es menor que la dimension, insertamos sin problema

		if(this->getDebug()==true){
			cout<<"insertando foto en vector.."<<endl;
		}

		this->InsertarFotoVector(getTotalFotosUsuario(),f);//insertamos la foto en el vector
		this->setTotalFotosUsuario(this->getTotalFotosUsuario()+1);
		if(this->getDebug()==true){
			cout<<getTotalFotosUsuario()<<endl;
		}	
	}
	else{ // si la dimension es menor que la util, aumentamos el tamaño

		resize(getDimFotos () +5);//hacemos hueco para las fotos
		this->InsertarFotoVector(getTotalFotosUsuario(),f);//insertamos la posicion en el vector
		this->setTotalFotosUsuario(this->getTotalFotosUsuario()+1);
		setDimFotos (getDimFotos()+5);
	}
}

void Normal::eliminarFotoVector(int i){


	if (this->getTotalFotosUsuario()>0){// si la util es mayor que 0 significa que hay espacio
		v_fotos[i]=v_fotos[getTotalFotosUsuario()-1];//intercambiamos la posicion que queremos eliminar con la ultima
		this->InsertarFotoVector(getTotalFotosUsuario(),DevolverFotoVector(this->getTotalFotosUsuario()-1));// insertamos la foto en el vector
		this->setTotalFotosUsuario(this->getTotalFotosUsuario()-1); // disminuimos la util

	}else{
		cerr<<DEBUG<<"Lo siento, no tienes nada que eliminar.."<<NORMAL<<endl;
	}
}

void Normal::imprimirVectorFotos(){
	if(this->getTotalFotosUsuario()==0){ // si la util es igual a 0 significa que no hay fotos en el vector

		cout<<"No hay fotos que imprimir..."<<endl;
	}
	else{
		for (int i=0;i<this->getTotalFotosUsuario();i++){//bucle que recorrerá todas las fotos de un vector de usuarios
			cout<<YELLOW<<"Foto: "<<i<<NORMAL<<endl;
			 v_fotos[i].print();
		}
	}
}

Foto Normal::DevolverFotoVector(int posicion){

	return this->v_fotos[posicion];
}

void Normal::InsertarFotoVector(int posicion, const Foto &f){

	this->v_fotos[posicion]=f;
}
