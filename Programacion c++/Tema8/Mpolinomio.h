#include <iostream>
#include <stdlib.h>
#include "Opolinomio.h"
#define NORMAL "\033[1;0m"
#define CYAN "\033[1;36m"
#define DEBUG "\033[1;31m"
#define YELLOW "\033[1;33m"
#define SOLUCION "\033[1;32m"
using namespace std;



/***********  declaracion objeto *************/
void Polinomio::resize(int dim_nueva){

	float *aux=new float [dim_nueva+1];

	//cout<<"vamos a entrar en el resize"<<endl;
	
	if (dim_nueva>max_grado){

		for (int i=0;i<=max_grado;i++){

			aux[i]=coeficiente[i];
		}
		/*for (int i=max_grado;i<=dim_nueva;i++){

			aux[i]=0;
		}*/
	}

	if (dim_nueva<max_grado){
		
	//	cout <<"copiando el vector hasta la dimension nueva"<<endl;
	
		for (int i=0;i<dim_nueva;i++){

			aux[i]=coeficiente[i];
		}
	//	cout<< "despues de copiar"<<endl;
		coeficiente[max_grado]=0;
	}


	
	//cout<<"vamos a eliminar la memoria dinámica"<<endl;
	delete [] coeficiente;
	setMaxGrado(dim_nueva);
	//cout<<CYAN<<max_grado<<NORMAL<<endl;
	//cout<<"memoria borrada"<<endl;
	coeficiente=aux;
}	


Polinomio::Polinomio (){

	cout << SOLUCION<<"he entrado en el constructor"<<NORMAL<<endl;
	setGrado(0); // inicializamos el grado a 0
	setMaxGrado(0);// inicializamos el max_grado a 0

	coeficiente= new float [max_grado+1];// reservamos memoria dinámica ( estilo simple)
	
	if (coeficiente==0){

		cout <<"lo siento, no hay memoria"<<endl;
		exit(-1);
	}
	
	for (int i=0;i<=getMaxGrado();i++){

		coeficiente[i]=0;
		cout <<CYAN << coeficiente[i];
	}

	cout << " constructor finalizado"<<endl;
	
}

Polinomio::~Polinomio(){


	cout << DEBUG<<"he entrado en el destructor"<<NORMAL<<endl;
	for(int i=0;i<max_grado;i++){
		//cout <<YELLOW<<i<<endl;
		coeficiente[i]=0;
	}
	delete [] coeficiente;// eliminamos el espacio en el heap que teniamos
	coeficiente=0;// apuntamos el puntero a null

	setGrado(0); // inicializamos el grado a 0
	setMaxGrado(0);// inicializamos el max_grado a 0

}
Polinomio& Polinomio::operator= (const Polinomio &p){ 
/*será como clonar una variable*/
	cout<<"constuctor por copia"<<endl;
	if (&p!= this){
		delete [] this->coeficiente;
		this->max_grado=p.max_grado;
		this->grado=p.grado;
		this->coeficiente=new float [max_grado+1];
	
		if (coeficiente==0){ // si coeficiente apunta a una direccion de memoria nula, debemos de abortar el programa porque significa que no hay espacio en el heap

			cout<< "lo siento, no hay suficiente memoria en el constructor por copia"<<endl;
			exit(-1);
		}
		for(int i=0;i<=max_grado;i++){ // bucle para copiar todos los componentes de coeficiente de la variable p a la variable nueva

			this->coeficiente[i]=p.coeficiente[i];
		}
	}
	return *this;
}

void Polinomio::setDebug(bool d){

	debug=d;
}
void Polinomio::setCoeficiente(int i, float c){

	if (i<getMaxGrado()){
		coeficiente[i]=c;
	}

}

void Polinomio::setCoeficientev2(int i, float c){

	if ( (i<=max_grado)&& (i>=0) ){
		this->coeficiente[i]=c;
	}
		else if (i>max_grado){// caso de que el grado sea mayor que el maximo grado admitidoo
			setGrado(i);
			for (int j=0;getMaxGrado()<i;j++){

				resize(getMaxGrado()+1);
			}
			this->coeficiente[i]=c;
		}
		/*else if (i < 0){// caso de grados negativos

			cout << DEBUG<< "Lo siento, no se admite grados negativos..."<<NORMAL<<endl; 
	
		}*/

	if(c==0){ // caso de cuando el coeficientee es 0
		cout<<CYAN<<" Cieficiente 0"<<endl;
		this->coeficiente[i]=c;
		for(int i=getMaxGrado(); coeficiente[i]==0;i--){
			setGrado(i-1);

		}
	}
}
void Polinomio::setCoeficientev3(int i, float c){


	if ( (i<=getMaxGrado()) && (i>=0) && (c!=0)){
		//cout<<"DEBUG:posicion menor que grado acrual, se puede introducir sin problema"<<endl;
		this->coeficiente[i]=c;
		cout<<coeficiente[i]<<endl;
	}
		else if (i>getMaxGrado()){// caso de que el grado sea mayor que el maximo grado admitidoo
			setGrado(i);
			for (int j=0;getMaxGrado()<i;j++){
				//cout<<SOLUCION<<"he entrado aqui"<<endl;
				resize(getMaxGrado()+1);
			}
			this->coeficiente[i]=c;
		}
		/*else if (i < -1){// caso de grados negativos(-1 será utilizado para eliminar un coef)

			cout << DEBUG<< "Lo siento, no se admite grados negativos..."<<NORMAL<<endl; 
	
		}*/

	if(c==0){ // caso de cuando el coeficientee es 0
		//cout<<CYAN<<" Cieficiente 0"<<endl;
		this->coeficiente[i]=c;
		for(int i=getMaxGrado(); coeficiente[i]==0;i--){// bucle que realizaremos para disminuir la dimension hasta que encontremos el grado del polinomio

			resize(getMaxGrado()-1);
			
		}
		setGrado(max_grado);//aal mantener la memoria exacta, max grado será igual que grado
	}
	
	if(i==-1){

		cout<<YELLOW<<"vamos a disminuir su tamaño"<<endl;
		resize(getMaxGrado()-1);
		cout<<"max_grado despues del resize: "<<max_grado<<endl;
		//grado=max_grado;
		cout<<"grado despues del resize: "<<grado<<endl;
		
		for(int i=getMaxGrado(); coeficiente[i]==0;i--){// bucle que realizaremos para disminuir la dimension hasta que encontremos el grado del polinomio

			resize(getMaxGrado()-1);
			
		}
		setGrado(getMaxGrado());//aal mantener la memoria exacta, max grado será igual que grado
		
				
	//cout<<DEBUG<<grado<<NORMAL<<endl;
	}
	setGrado(getMaxGrado());
	
}

void Polinomio::setGrado(int i){

	if (i<0){

		cerr<<DEBUG<<"Lo siento, no puede existir un polinomio de grado negativo en este programa.."<<NORMAL<<endl;
	}
	else{
		this->grado=i;
	}
}

void Polinomio::setMaxGrado(int grado){

	this->max_grado=grado;
}


bool Polinomio::getDebug(){

	return debug;
}

int Polinomio::getGrado() const{

	return grado;

}

int Polinomio::getMaxGrado()const{

	return max_grado;

}


float Polinomio::getCoeficiente(int i) const{

	//cout<<CYAN<<coeficiente[i]<<NORMAL;

	return coeficiente[i];

}

void Polinomio::sumaV1( const Polinomio &suma){

	cout<<DEBUG<<"DEBUG: comenzando la sumaV1"<<endl;


	if (this->getMaxGrado()>= suma.getMaxGrado()){ // caso de que el grado del objeto llamante sea mayor o igual que el objeto por parámetros

		for (int i=0; i<=this->getMaxGrado();i++){

			setCoeficientev3(i, this->coeficiente[i] + suma.coeficiente[i]);
			//cout<<"DEBUG:coeficiente despues de sumar: "<<coeficiente[i]<<endl;
		}
	}
	if (this->getMaxGrado() < suma.getMaxGrado()){// caso de que el grado del objeto llamante sea menor que el objeto por parámetros

		for (int i=0; i<=suma.getMaxGrado();i++){

			setCoeficientev3(i, this->coeficiente[i] + suma.coeficiente[i]);
			//cout<<"DEBUG:coeficiente despues de sumar: "<<coeficiente[i]<<"en el grado: "<<i<<endl;
		}
	}


}

void Polinomio::sumaV2(const Polinomio &suma1, const Polinomio &suma2){

	cout<<DEBUG<<"DEBUG: comenzando la sumaV2"<<endl;


	if (suma1.getMaxGrado()>= suma2.getMaxGrado()){// caso de que suma 1 sea de mayor grado o igual que suma2

		for (int i=0; i<=suma1.getMaxGrado();i++){

			this->setCoeficientev3(i, suma1.coeficiente[i] + suma2.coeficiente[i]);
			cout<<"DEBUG:coeficiente despues de sumar: "<<coeficiente[i]<<endl;
		}
	}
	if (suma1.getMaxGrado() < suma2.getMaxGrado()){// caso de que suma 1 sea de menor grado que suma 2

		for (int i=0; i<=suma2.getMaxGrado();i++){

			this->setCoeficientev3(i, suma1.coeficiente[i] + suma2.coeficiente[i]);
			cout<<"DEBUG:coeficiente despues de sumar: "<<coeficiente[i]<<"en el grado: "<<i<<endl;
		}
	}

}
Polinomio Polinomio::operator+( Polinomio &suma){

	Polinomio aux;
	cout<<"despues de entrar en el constructor de aux"<<endl;

	cout<<DEBUG<<"DEBUG: comenzando la suma"<<endl;


	if (this->getMaxGrado()>= suma.getMaxGrado()){ // caso de que el grado del objeto llamante sea mayor o igual que el objeto por parámetros

		for (int i=0; i<=getMaxGrado();i++){

			aux.setCoeficientev3(i, coeficiente[i] + suma.coeficiente[i]);
			//cout<<"DEBUG:coeficiente despues de sumar: "<<coeficiente[i]<<endl;
		}
	}
	if (this->getMaxGrado() < suma.getMaxGrado()){// caso de que el grado del objeto llamante sea menor que el objeto por parámetros

		for (int i=0; i<=suma.getMaxGrado();i++){

			aux.setCoeficientev3(i, coeficiente[i] + suma.coeficiente[i]);
			//cout<<"DEBUG:coeficiente despues de sumar: "<<coeficiente[i]<<"en el grado: "<<i<<endl;
		}
	}

	return aux;

}

Polinomio *Polinomio::sumav4 (const Polinomio *p2){

	Polinomio *aux;
	aux=new Polinomio();

	cout<<"despues de entrar en el constructor de aux mediante punteros"<<endl;

	cout<<DEBUG<<"DEBUG: comenzando la suma"<<endl;


	if (this->getMaxGrado()>= p2->getMaxGrado()){// caso de que el grado del objeto llamante sea mayor o igual que el objeto por parámetros

		for (int i=0; i<=getMaxGrado();i++){

			aux->setCoeficientev3(i, coeficiente[i] + p2->coeficiente[i]);
			//cout<<"DEBUG:coeficiente despues de sumar: "<<coeficiente[i]<<endl;
		}
	}
	if (this->getMaxGrado() < p2->getMaxGrado()){// caso de que el grado del objeto llamante sea menor que el objeto por parámetros

		for (int i=0; i<=p2->getMaxGrado();i++){

			aux->setCoeficientev3(i, coeficiente[i] + p2->coeficiente[i]);
			//cout<<"DEBUG:coeficiente despues de sumar: "<<coeficiente[i]<<"en el grado: "<<i<<endl;
		}
	}

	return aux;


}

ostream& operator<<(ostream &flujo, const Polinomio &p) {

	flujo<<"P(x): ";
	for (int i=0;i<=p.getGrado();i++) {// bucle para imprimir el objeto, suponiendo que por ahora el grado es como la util

		if (i==0){
		
			flujo<<SOLUCION<<p.coeficiente[i]<<" ";
		}
		else{
			flujo << SOLUCION<<p.coeficiente[i]<<"x"<<"^"<<i<<" "<<NORMAL;
		}
	}
	flujo <<endl<<DEBUG<<"Grado del polinomio: "<<p.getGrado()<<NORMAL<<endl;
	flujo<<DEBUG<<"Grado máximo admitido: "<<p.getMaxGrado()<<NORMAL<<endl;
	return flujo;
}

istream& operator>>(std::istream &flujo, Polinomio &p) {
	int mg;
	int g;
	int c;

	cout << "insete el numero de monomios que infresará"<<endl;
	flujo >> mg;
	
	for (int i=0;i<mg;i++){

		cout<< " introduzca el grado del monomio : "<<endl;
		flujo>> g;
		cout<< "introduzca su coeficiente"<<endl;
		flujo>>c;
		p.setCoeficientev3 (g, c);
	}
	return flujo;
}
/**
@brief modulo que sirve para hacer el testing 0.
@param *polinomio objeto sobre el que realizaremos el testing
@pre el onjeto debe estar creado previamente
@return nada. es un procedimiento
@post. el testing se ejecutará correctamente
*/

void testing_cero ( Polinomio *p){

	cout<<SOLUCION<<"realizando el testing 0 (imprimir polinomio)"<<NORMAL<<endl;
	cout<<p;
	cout<<p->getGrado();
	cout<<SOLUCION<<"terminado el testing 0 (imprimir polinomio)"<<NORMAL<<endl;
}
/**
@brief modulo que sirve para hacer el testing 1.
@param *polinomio objeto sobre el que realizaremos el testing
@pre el onjeto debe estar creado previamente
@return nada. es un procedimiento
@post. el testing se ejecutará correctamente
*/

void testing_uno ( Polinomio *p){

	cout<<SOLUCION<<"realizando el testing 1 (insertar monomio de grado menor al actual)"<<NORMAL<<endl;
	p->setCoeficientev2(6,-2);
	cout<<p;
	cout<<SOLUCION<<"terminado el testing 1 (insertar monomio de grado menor al actual)"<<NORMAL<<endl;
}
/**
@brief modulo que sirve para hacer el testing 2.
@param *polinomio objeto sobre el que realizaremos el testing
@pre el onjeto debe estar creado previamente
@return nada. es un procedimiento
@post. el testing se ejecutará correctamente
*/

void testing_dos ( Polinomio *p){

	cout<<SOLUCION<<"realizando el testing 2 (insertar monomio de grado negativo)"<<NORMAL<<endl;
	p->setCoeficientev2(-1,3);
	cout<<p;
	cout<<SOLUCION<<"terminado el testing 2 (insertar monomio de grado negativo)"<<NORMAL<<endl;
}
/**
@brief modulo que sirve para hacer el testing 2.
@param *polinomio objeto sobre el que realizaremos el testing
@pre el onjeto debe estar creado previamente
@return nada. es un procedimiento
@post. el testing se ejecutará correctamente
*/

void testing_tres ( Polinomio *p){

	cout<<SOLUCION<<"realizando el testing 3 (insertar monomio de grado mayor al grado actual y grado menor al max_Grado)"<<NORMAL<<endl;
	p->setCoeficientev2(8,5);
	cout<<p;
	cout<<SOLUCION<<"terminadoel testing 3 (insertar monomio de grado mayor al grado actual y grado menor al max_Grado)"<<NORMAL<<endl;
}
/**
@brief modulo que sirve para hacer el testing 2.
@param *polinomio objeto sobre el que realizaremos el testing
@pre el onjeto debe estar creado previamente
@return nada. es un procedimiento
@post. el testing se ejecutará correctamente
*/

void testing_cuatro ( Polinomio *p){

	cout<<SOLUCION<<"realizando el testing 4 (insertar monomio de grado mayor al grado actual y grado mayor al max_Grado)"<<NORMAL<<endl;
	p->setCoeficientev2(13,5);
	cout<<p;
	cout<<SOLUCION<<"terminado el testing 4 (insertar monomio de grado mayor al grado actual y grado mayor al max_Grado)"<<NORMAL<<endl;
}
/**
@brief modulo que sirve para hacer el testing 2.
@param *polinomio objeto sobre el que realizaremos el testing
@pre el onjeto debe estar creado previamente
@return nada. es un procedimiento
@post. el testing se ejecutará correctamente
*/

void testing_cinco ( Polinomio *p){

	cout<<SOLUCION<<"realizando el testing 5 ( insertar un monomio de grado igual que el grado actual, y cuyo coeficiente sea cero )"<<NORMAL<<endl;
	p->setCoeficientev3(13,0);
	cout<<p;
	cout<<SOLUCION<<"terminado el testing 5 ( insertar un monomio de grado igual que el grado actual, y cuyo coeficiente sea cero )"<<NORMAL<<endl;
}
/**
@brief modulo que sirve para realizar todos los testing llamando a una función
@param *polinomio objeto sobre el que realizaremos el testing
@pre el onjeto debe estar creado previamente
@return nada. es un procedimiento
@post. el testing se ejecutará correctamente
*/

void testing_general ( Polinomio *p){

	testing_cero (p);
	testing_uno (p);
	testing_dos (p);
	testing_tres (p);
	testing_cuatro (p);
	testing_cinco(p);
	//p->setCoeficientev3(-1,-2);	
	//p->setCoeficientev3(-1,-2);
	//p->setCoeficientev3(-1,-2);		
}



