#include <iostream>
using namespace std;

class Foto{

	private:

		string ruta;
		string tipo;
		unsigned long int tamanio;
	public:

		/**
		@brief constructor  de Foto
		@return nada. es un procedimiento
		@post se construirá un objeto de tipo Usuario.
		*/		
		Foto();
		/*@brief constructor por parametros de Foto
		@param string ruta valor que le asignaemos al atributo ruta
		@string tipo valor que le asignaremos al atributo tipo
		@unsigned long int size valor que le asignaremos al tamanio 
		@post se construirá un objeto que con los parámetros mencionados anteriormente
		*/
		Foto(string ruta, string tipo,unsigned long int size);
		/**
		@brief método que sirve para rellenar la ruta de un objeto  de tipo foto
		@param string direccion. ruta que introduciremos en el atributo ruta.
		@pre. el objeto debe de estar creado previamente
		@return nada. es un procedimiento
		@post el valor de ruta será igual que el de direccion.
		*/
		void setRuta (string direccion);
		/**
		@brief método que sirve para rellenar el tipo de un objeto  de tipo foto
		@param string tipo. tipo que introduciremos en el atributo tipo.
		@pre. el objeto debe de estar creado previamente
		@return nada. es un procedimiento
		@post el valor de tipo será igual que el de tipo.
		*/
		void setTipo (string tipo);
		/**
		@brief método que sirve para rellenar el tamanio de un objeto  de tipo foto
		@param unsigned long int size. tamanio que introduciremos en el atributo tamanio.
		@pre. el objeto debe de estar creado previamente
		@return nada. es un procedimiento
		@post el valor de tamanio será igual que el de size.
		*/
		void setTamanio (unsigned long int size);		
		/**
		@brief método que sirve para devolver la ruta de un objeto.
		@pre. la ruta del objeto deberá de estar rellena
		@return devolverá un string que llevará asignado el contenido de ruta
		@post ruta será devuelta correctamente.
		*/
		string getRuta ();
		/**
		@brief método que sirve para devolver el tipo de un objeto.
		@pre. el tipo del objeto deberá de estar rellena
		@return devolverá un string que llevará asignado el contenido de tipo
		@post tipo será devuelta correctamente.
		*/
		string getTipo ();
		/**
		@brief método que sirve para devolver el tamanio de un objeto.
		@pre. el tamanio del objeto deberá de estar rellena
		@return devolverá un unsigned long int que llevará asignado el contenido de tamanio
		@post tamanio será devuelta correctamente.
		*/
		unsigned long int getTamanio ();
		/**
		@brief método que sobrecargaremos para imprimir un objeto de tipo foto
		@pre. el objeto debe de estar creado y relleno
		@param
		@param
		@return 
		@post la variable será imprimida correctamente
		*/
		void print();

		

};

