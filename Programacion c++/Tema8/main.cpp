#include <iostream>
#include <stdlib.h>
#include "Mpolinomio.h"
#define NORMAL "\033[1;0m"
#define CYAN "\033[1;36m"
#define DEBUG "\033[1;31m"
#define YELLOW "\033[1;33m"
#define SOLUCION "\033[1;32m"

class Vista{

	private:
		Polinomio* vector;
		int dimutil;
		/**
		@brief modulo que sirve para redimensionar el vector de Polinomios. Aumentará o disminuirá de uno en uno (memoria exacta)
		@param int dim_nueva dimensión nueva que le otorgaremos al vector
		@pre el vector de coeficientes debe de tener su espacio agotado
		@return devolvera un puntero float dinamico
		@post el vector aumentara o disminuirá su dimension 1 posición más
		*/
		void resize(int dim_nueva);
	public:
		/**
		@brief constructor que utilizaremos para el objeto Vista
		return nada. es un procedimiento
		post el objeto estará creado correctamente
		*/
		Vista();
		/**
		@brief destructor que utilizaremos para el objeto Vista
		@pre la variable deberá de estar creada previamente
		return nada. es un procedimiento
		post el objeto se eliminará
		*/
		~Vista();
		/**
		@brief modulo que sirve para insertar una posicion en el vector
		@param Polinomio p. Polinomio que insertaremos en el vector
		@pre. el vector deberña de estar creado previamente. irá aumentando posicion por posicion
		@return nda. es un procedimiento
		@post. dimutil pasara a valer un numero mas y tedremos una posicion del vector ocupada más 
		*/

		void InsertarPolinomioEnVector (Polinomio &Nuevo);
		/**
		@brief modulo que sirve para eliminar una posicion del vector
		@pre. dimutil>0.
		@return nda. es un procedimiento
		@post. dimutil pasara a valer un numero menos y tedremos una posicion del vector menos 
		*/

		void EliminarPolinomioEnVector ();

		/**
		@brief modulo que sirve para insertar un valor en dimutil
		@param unt nuevo. es el nuevo valor que se le asignara a dimutil
		@pre, el objeto que contiene a dimutil debe de estar creado previamente
		@return nada. es un procedimiento
		@post dimutil tendrá el valor de nuevo
		*/
		void setdimutil(int nuevo);
		/**
		@brief modulo que sirve para devolver el valor de dimutil
		@pre, el objeto que contiene a dimutil debe de estar creado previamente y relleno.
		@return devolvera una variable de tipo int con el valor de dimutil.
		@post dimutil tserá devuelto correctamente
		*/
		int getdimutil();

		/**
		@brief metodo que sirve para imprimir un menu con diferentes opciones
		@param &Vista Nueva objeto de tipo vista que utilizaremos para operar en el menu
		@param char c. opcion que cogeremos en el menu
		@return nada. es un procedimiento
		post el menu será mostrado correctamente
		*/
		void menu(char &c, Polinomio &n);

		/**
		@brief método que sirve para imprimir todo el vector de Polinomios
		@return nada.
		@pre. El vector deberá de estar relleno
		@post. el vector será imprimido correctamente
		*/
		void ImprimirPolinomios();
};

void Vista::resize(int dim_nueva){

	Polinomio *aux=new Polinomio [dim_nueva];

	cout<<"vamos a entrar en el resize"<<endl;
	
	if (dim_nueva>this->getdimutil()){
		cout<<"dimension mayor"<<endl;

		for (int i=0;i<getdimutil();i++){

			aux[i]=this->vector[i];
		}

	}

	if (dim_nueva<getdimutil()){
	
	
		cout <<"copiando el vector hasta la dimension nueva"<<endl;
	
		for (int i=0;i<dim_nueva;i++){

			aux[i]=this->vector[i];
		}
		
		cout<< "despues de copiar"<<endl;
		
	}


	
	//cout<<"vamos a eliminar la memoria dinámica"<<endl;
	delete [] vector;
	//cout<<CYAN<<max_grado<<NORMAL<<endl;
	//cout<<"memoria borrada"<<endl;
	this->vector=aux;
	//cout<< vector;
	cout<<"resize finalizado"<<endl;
}
Vista::Vista (){

	cout << SOLUCION<<"he entrado en el constructor de Vista"<<NORMAL<<endl;
	setdimutil(0); // inicializamos la util a 0

	vector= new Polinomio [dimutil];// reservamos memoria dinámica ( estilo simple)
	
	if (vector==0){

		cout <<"lo siento, no hay memoria"<<endl;
		exit(-1);
	}

	cout << " constructor finalizado de vista"<<endl;
	
}
Vista::~Vista(){
	cout << DEBUG<<"he entrado en el destructor de vista"<<NORMAL<<endl;
	Polinomio auxiliar;
	for(int i=0;i<this->getdimutil();i++){
		cout <<YELLOW<<i<<endl;
		this->vector[i]=auxiliar;
	}
	
	delete[]vector;// eliminamos el espacio en el heap que teniamos
	this->vector=0;// apuntamos el puntero a null

	setdimutil(0); // inicializamos la util a 0
}
void Vista::setdimutil( int nuevo){

	this->dimutil=nuevo;
}

int Vista:: getdimutil(){
	
	return this->dimutil;
}

void Vista::InsertarPolinomioEnVector (Polinomio &nuevo){

	cout<< YELLOW<<"insertando posicion en vector" <<endl;
	this->resize(getdimutil()+1);// aumentamos el vector una posicion
	this->vector[getdimutil()]=nuevo;  // insertamos el Polinomio en la posición libre que hemos creado
	cout<< " insertada la posicion en el vector "<<endl;
	this->setdimutil(getdimutil()+1); // actualizamos la util
	//cout <<" util actualizada"<<endl;
}

void Vista::EliminarPolinomioEnVector(){
	cout<<YELLOW<< "eliminando posicion en vector" <<endl;
	this->resize(getdimutil()-1); // disminuimos la posicion del vector
	this->setdimutil(getdimutil()-1); // actualizamos la util
}

void Vista::ImprimirPolinomios(){

	cout<< YELLOW<< "Imprimiendo su vector de polinomios..."<<endl;

	for (int i=0; i<getdimutil();i++){

		cout << vector[i];

	cout<< "----------------------------------------------------------"<<NORMAL<<endl;
	}
}

void Vista::menu(char &c, Polinomio &n){

	

	cout <<"Opición a: rellenar e insertar un polinomio "<<endl;
	cout<<"Opcion b: imprimir vector de polinomios "<<endl;
	cout <<"Opcion c: Eliminar vector de Polinomios"<<endl;
	cout<< "opcion d:salir"<<endl;

	cin>> c;

	switch(c) {

	case 'a':
		cin>>n;
		cout<<n;
		this->InsertarPolinomioEnVector (n);
		cout <<" despues de insertar"<<endl;
		cout << DEBUG<< getdimutil()<<NORMAL<<endl;
		break;

	case 'b':
		
		this->ImprimirPolinomios();		

		break;

	case'c':
		this->EliminarPolinomioEnVector();
		cout << DEBUG<< getdimutil()<<NORMAL<<endl;
		break;

	case 's':

		break;
	}
}


int main(){
 
	Vista nuevo;
	Polinomio n;
	char c;

	do{

		nuevo.menu(c,n);
	} while(c!='d');
	cout<<"finalizando el programa"<<endl;


}	