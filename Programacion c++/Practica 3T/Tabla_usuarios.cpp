#include <iostream>
#include <stdlib.h>
#include "Tabla_usuarios.h"
#define NORMAL "\033[1;0m"
#define CYAN "\033[1;36m"
#define DEBUG "\033[1;31m"
#define YELLOW "\033[1;33m"
#define SOLUCION "\033[1;32m"
using namespace std;


void Tabla_usuarios::resize(int dim_nueva){

	Usuario** aux= new Usuario*[dim_nueva];

	if(this->getDebug()==true){
		cout<< "dinamico creado"<<endl;
	}
	
	if(this->getTotal_usuarios() >dim_nueva){ // caso de que la dimension actual sea mayor que la dim nueva. NUNCA DEBERÁ DE SER IGUAL, y ppuesto a que la util actual y la dim son iguales, solo hay un caso.

		for (int i=0;i<dim_nueva;i++){// copiamos el vector hasta la dim nueva.

			aux[i]=this->puntero_a_puntero[i];
		}
		if(this->getDebug()==true){
			cout<< "despues de copiar el vector"<<endl;
		}
	}


	if (this->getTotal_usuarios() < dim_nueva){// caso de aumentar la dimensión

		for (int i=0;i<this->getTotal_usuarios();i++){ // copiamos hasta la dimension

			aux[i]=this->puntero_a_puntero[i];
		}
	}

	

	delete [] this->puntero_a_puntero; // eliminamos la memoria del antiguo puntero
	this->puntero_a_puntero=0;//apuntamos a null
	this->puntero_a_puntero=aux;	

	
}

Tabla_usuarios::Tabla_usuarios(){

	setDebug(false);
	if(this->getDebug()==true){
		cout<<DEBUG<<" DEBUG:constructor Tabla_usuarios ha comenzado"<<NORMAL<<endl;
	}
	setTotal_usuarios(0);
	puntero_a_puntero=new Usuario*[total_usuarios];/// reservamos memoria dinámica

	if (puntero_a_puntero==0){ // si no hay espacio en el heap abortamos el programa
		cout << DEBUG<< "Lo siento, no hay espacio..."<<NORMAL<<endl;
		exit(-1);
	}
	if(this->getDebug()==true){
		cout<<SOLUCION<<"DEBUG: constructor Tabla_usuarios ha finalizado"<<NORMAL<<endl;
	}
}

Tabla_usuarios::~Tabla_usuarios(){

	if(this->getDebug()==true){
		cout<<DEBUG<<"DEBUG: destructor Tabla_usuarios ha comenzado"<<NORMAL<<endl;
	}

	for (int i=0;i<getTotal_usuarios();i++){
		delete puntero_a_puntero[i];// eliminamos todas las posiciones del vector
	}
	delete []puntero_a_puntero;//eliminamos el vector
	puntero_a_puntero=0;//apuntamos a null
	setTotal_usuarios(0);//reseteamos
	if(this->getDebug()==true){
		cout<<SOLUCION<<"DEBUG: destructor Tabla_usuarios ha finalizado"<<NORMAL<<endl;
	}
}

void Tabla_usuarios::setTotal_usuarios(int numero){

	this->total_usuarios=numero;
}
void Tabla_usuarios::setDebug ( bool debug){

	this->debug=debug;
}
int Tabla_usuarios::getTotal_usuarios (){

	return this->total_usuarios;
}
bool Tabla_usuarios::getDebug(){

	return this->debug;
}
Usuario* Tabla_usuarios::DevolverPosicion(int numero){

	return this-> puntero_a_puntero[numero];

}
void Tabla_usuarios::print(){

	for (int i=0; i<getTotal_usuarios();i++){//bucle que recorrerá todo el vector
		if(this->getDebug()){
			cout << "he entrado"<<endl;
		}
		DevolverPosicion(i)->print();
	}
}
void Tabla_usuarios::InsertarUsuarioenVector(Usuario *u){

	// creamos hueco para el usuario
	resize (getTotal_usuarios() +1);
	//insertamos el usuario
	if(this->getDebug()==true){
		cout <<DEBUG<<"DEBUG: insertando usuario..."<<NORMAL<<endl;
	}
	InsertarUsuarioVector(this->getTotal_usuarios(), u);//insertamos la posicion en el vector

	if(this->getDebug()==true){
		cout <<DEBUG<<"DEBUG:usuario insertado correctamente"<<NORMAL<<	endl;
	}
	setTotal_usuarios(getTotal_usuarios() + 1);

}
bool Tabla_usuarios::BuscarLogin(string u, int &posicion, bool imprimir){

	bool encontrado=false;


	for (int i=0;( (i<this->getTotal_usuarios() ) && (!encontrado) );i++){// buscaremos hasta que lleguemos al final del vector o hasta que lo encontremos.

		if (u==puntero_a_puntero[i]->getLogin() ){ // si el login es igual que el de 
			if(imprimir==true){
				DevolverPosicion(i)->print();
			}
			encontrado=true;
			posicion=i;
		}
	}
	return encontrado;
}

void Tabla_usuarios::InsertarFotoUsuarioTabla(Foto &f, int i){

	if(Normal *h = dynamic_cast<Normal*>(puntero_a_puntero[i])){ // comprobamos si la vaariable es de tipo Normal.

		if(this->getDebug()==true){  	
			cout <<" DEBUG:dentro de normal en el casting de tipos"<<endl;
			cout<< "DEBUG:insertando fotos"<<endl;
		}
		h->InsertarFotoVector(f);
		this->InsertarUsuarioVector(i,h);
		
        }
	if(Admin *h = dynamic_cast<Admin*>(puntero_a_puntero[i])){ //si la variable es de tipo admin no podremos utilizar este metodo.
  	
		cout<<DEBUG<<"lo siento, este usuario no tiene esa opcion"<<NORMAL<<endl;
        }
	
}
void Tabla_usuarios::EliminarFotoUsuarioTabla(int i, int posicion_foto){


	if(Normal *h = dynamic_cast<Normal*>(puntero_a_puntero[i])){// comprobamos si la vaariable es de tipo Normal.
  		if(this->getDebug()==true){ 
			cout <<"DEBUG: dentro de normal en el casting de tipos eliminando foto"<<endl;
			cout<< "DEBUG: Eliminando foto"<<endl;
		}
		h->eliminarFotoVector(posicion_foto);
		this->InsertarUsuarioVector(i,h);//insertar usuario en vector
        }
	if(Admin *h = dynamic_cast<Admin*>(puntero_a_puntero[i])){//si la variable es de tipo admin no podremos utilizar este metodo.
  	
		cout<<DEBUG<<"lo siento, este usuario no tiene esa opcion"<<NORMAL<<endl;
        }







}
void Tabla_usuarios::ImprimirFotosUsuarioTabla(int i){
	if(Normal *h = dynamic_cast<Normal*>(puntero_a_puntero[i])){// comprobamos si la vaariable es de tipo Normal.
  	
		h->imprimirVectorFotos();

        }
	if(Admin *h = dynamic_cast<Admin*>(puntero_a_puntero[i])){//si la variable es de tipo admin no podremos utilizar este metodo.
  	
		cout<<DEBUG<<"lo siento, este usuario no tiene esa opcion"<<NORMAL<<endl;
        }
	
}

void Tabla_usuarios::EliminarUsuarioVector(int eliminar){

	if(this->getDebug()==true){ 
		cout <<DEBUG<<"DEBUG:Eliminando usuario en tabla puntero.... "<<NORMAL<<endl;
	}
	delete this->puntero_a_puntero[eliminar];//primero eliminamos la posicion que deseamos eliminar

	if (eliminar < this->getTotal_usuarios()){ // si la posicion no es la ultima, podremos sobreescribir. si es la ultima simplemente haremos el resize
		for (int i=eliminar; i<this->getTotal_usuarios();i++){// despues sobreescribimos
		
			this->InsertarUsuarioVector(i,this->DevolverPosicion(i+1));// sobreescribimos la posicion hasta llegar a final del vector
	
		}
	}

	this->resize(getTotal_usuarios()-1);// por ultimo disminuimos la dimension
	setTotal_usuarios(getTotal_usuarios() - 1);// actualizamos utiles
	if(this->getDebug()==true){ 
		cout<<SOLUCION<<"DEBUG: Posicion eliminada correctamente"<<endl;
	}
}
void Tabla_usuarios::OrdenarPorLogin(){

	bool cambio=true;
	string auxiliar;
	Usuario *aux=new Usuario();
	for (int izqda=0;izqda<this->getTotal_usuarios() && cambio;izqda++){ // METODO burbuja

		cambio=false;
		auxiliar=this->puntero_a_puntero[getTotal_usuarios()-1]->getLogin();// copiamos el login en una posicion auxiliar
		for (int i=this->getTotal_usuarios()-1;i>izqda;i--){ // comparamos desde el final hasta llegar a izqda
			auxiliar=this->puntero_a_puntero[i]->getLogin();
			if(auxiliar <this->DevolverPosicion(i-1)->getLogin()){ // comparamos los login
				// realizamos el cambio
				cambio=true;				
				aux=puntero_a_puntero[i];
				this->InsertarUsuarioVector(i,this->puntero_a_puntero[i-1]);
				this->InsertarUsuarioVector(i-1,aux);	
			}
		}	
	}
}

void Tabla_usuarios::OrdenarPorTotalFotos(){

	Normal *auxiliar1=new Normal();
	Normal *auxiliar2=new Normal();
	int posicion=0;

	for (int i=0;i<this->getTotal_usuarios();i++){

		if(Normal *h = dynamic_cast<Normal*>(DevolverPosicion(i))){// primero comprobamos que la variable que hay en posicion i sea una variable de tipo normal
			posicion=i;
	
			for (int j= i + 1;j<this->getTotal_usuarios();j++){

				if(Normal *aux = dynamic_cast<Normal*>(DevolverPosicion(posicion))){// volvemos a comprobar que la variable que hay en la posicion i sea de tipo normal
			
					auxiliar1=aux;
				}
				if(Normal *aux2 = dynamic_cast<Normal*>(DevolverPosicion(j))){// comprobamos que la variable de la posicion j sea de tipo Normal
			
					auxiliar2=aux2;
				}

				if(auxiliar1->getTotalFotosUsuario() < auxiliar2->getTotalFotosUsuario()){ // una vez que lo tenemos comprobado, comparamos
			
					posicion=j;
				}
			}
			//realizamos el intercambio
			this->InsertarUsuarioVector(i,auxiliar2);
			this->InsertarUsuarioVector(posicion,auxiliar1);

		}
	}
	
}
void Tabla_usuarios::printNormal(){


	for (int i=0;i<this->getTotal_usuarios();i++){

		if(Normal *h = dynamic_cast<Normal*>(DevolverPosicion(i))){// si la variable es normal, no tiene permiso.

			h->print();

		}
	}
}
		
void Tabla_usuarios::ExtraFragmento (string fragmento, int posicion){

	if(Admin *h = dynamic_cast<Admin*>(DevolverPosicion(posicion))){// primero comprobamos que el usuario dado sea un Admin
		h->setTotal_consultas (h->getTotal_consultas()+1);
		puntero_a_puntero[posicion]=h;
		for (int i=0;i<this->getTotal_usuarios();i++){// vamos pasandole todos los usuarios al metodo, donde se comprobará si es admin o no.

				h->BusquedaFragmento (fragmento, DevolverPosicion(i));
		}
	}
	if(Normal *h = dynamic_cast<Normal*>(DevolverPosicion(posicion))){// si la variable es normal, no tiene permiso.

		cout<<DEBUG<<"Lo siento, no tiene permiso para hacer esto"<<NORMAL<<endl;
	}
}

void Tabla_usuarios::CambiarDebugTabla(bool debug){

	this->setDebug(debug);
	for( int i=0; i<this->getTotal_usuarios();i++){

		this->puntero_a_puntero[i]->setDebug(debug);
	}
}

void Tabla_usuarios::InsertarUsuarioVector(int i, Usuario *u){

	this->puntero_a_puntero[i]=u;
}

void Tabla_usuarios::EliminarMinimoFotosTabla(int fotos_min){

	for (int i=0;i<this->getTotal_usuarios();i++){// vamos recorriendo todo el vector

		if(Normal *n = dynamic_cast<Normal*>(DevolverPosicion(i))){// si la variable es normal, pasamos a la comprobacion

			if(n->getTotalFotosUsuario() < fotos_min){//si fotos usuario es menor que las fotos minimas, serán eliminados
		
				EliminarUsuarioVector(i);
				i=0;// reseteamos la i paraa que no haya problema con la condición
			}
		}
	}

}		
