#include <iostream>
using namespace std;

class Polinomio{

	private:
		float *coeficiente;
		int grado;
		int max_grado;
		bool debug;
		/**
		@brief modulo que sirve para redimensionar el vector de coeficientes. por ahora,  solo aumentará.
		@param int dim_nueva dimensión nueva que le otorgaremos al vector
		@pre el vector de coeficientes debe de tener su espacio agotado
		@return devolvera un puntero float dinamico
		@post el vector aumentara su dimension 1 posición más
		*/
		void resize(int dim_nueva);
	public:
		/**
		@brief modulo que sirve para hacer el vector de coeficiente dinámico e inicializar el polinomio
		@pre. el objeto debe de estar creado previamente .
		@return devolverá un objeto de tipo polinomio.
		@post el objeto polinomio estará listo para usarse .
		*/
		Polinomio();// equivale al crear que usabamos en los struc
		/**
		@brief módulo que sirve para eliminar una variable de tipo polunomio. Es el destructor
		@pre. el objeto deberá de estar creado previamente
		@return nada. es  un procedimiento
		@post la variable será eliminada correctamente liberando así memoria en el heap
		*/
		~Polinomio();//eliminar usuario, se llama automáticamente
		/**
		@brief módulo que sirve para hacer un constructor por copia 
		@param const polinomio &p. Variable que utilizaremos para copiar en el constructor
		@pre const polinomio &p deberá de estar creado previamente
		@return devolverá una variable de tipo polinomio identica a la variable pasada por parámetros
		@post la variable de tipo polinomio nueva será identica a p
		*/
		Polinomio& operator= (const Polinomio &p);
		/**
		@brief módulo que sirve para asignar un valor al bool debug del objeto
		@param bool d. llevará el resultado qque le asignaremos a debug.
		@pre el objeto debe de estar creado previamente
		@return nada. es un procedimiento 
		@post el valor debug del polinomio llamante pasará a tener el valor de d
		*/
		void setDebug(bool d);
		/**
		@brief módulo que sirve para asignar una posicion del vector coeficientes
		@param int i. variable que llevará asignada la posicion donde ingresaremos el contenido de coeficiente
		@param int coeficiente. contenido que le asignaremos a la posicion i de vector coeficiente
		@pre i>0 
		@return nada. es un procedimiento
		@post la posicion i del vector coeficiente tendrá el valor de coeficiente
		*/

		void setCoeficiente (int i/*posiciob dobde lo introduciremos*/, float c/*contenido posicion*/);
		/**
		@brief módulo que sirve para asignar una posicion del vector coeficientes
		@param int i. variable que llevará asignada la posicion donde ingresaremos el contenido de coeficiente
		@param int coeficiente. contenido que le asignaremos a la posicion i de vector coeficiente
		@pre i>0 
		@return nada. es un procedimiento
		@post la posicion i del vector coeficiente tendrá el valor de coeficiente
		*/
		
		
		void setCoeficientev2(int i, float c);
		/**
		@brief módulo que sirve para asignar una posicion del vector coeficientes (añadido el caso de disminuir respecto al v2)
		@param int i. variable que llevará asignada la posicion donde ingresaremos el contenido de coeficiente
		@param int coeficiente. contenido que le asignaremos a la posicion i de vector coeficiente
		@pre i>0 
		@return nada. es un procedimiento
		@post la posicion i del vector coeficiente tendrá el valor de coeficiente
		*/
		void setCoeficientev3(int i, float c);
		/**
		@brief módulo que sirve para devolver una posicion de coeficiente de un objeto polinomio
		@pre La posicion del vector coeficientes debe de estar rellena
		@return devolverá una variable de tipo int que llevará asignada el valor de la posicion deseada de coeficiente
		@post la posicion será devuelta correctamente
		*/
		float getCoeficiente (int i) const;
		/**
		@brief módulo que sirve para rellenar el grado de un objeto polinnomio
		@param int grado. variable que llevará asignada el grado del que será el polinomio
		@return nada. es un procedimiento
		@post el grado del objeto tendrá asignado el valor de grado
		*/
		void setGrado(int i);
		/**
		@brief modulo que sirve para devolder el valor de bool de un polinomio
		@pre el debug de polinomio deberá de estar relleno
		@return. devolverá un bool que tendrá el valor de debug
		@post. el polinomio devuelto tendrá el valor de debug
		*/
		bool getDebug();
		/**
		@brief módulo que sirve para devolver el grado de un objeto de tipo polinomio
		@pre el grado del objeto debe de estar relleno
		@return devolverá una variable de tipo int que llevará asignada el vvalor de grado
		@post el grado será devuelto correctamente
		*/
		
		int getGrado() const;
		/**
		@brief módulo que sirve para rellenar el max_grado de un objeto polinnomio
		@param int grado. variable que llevará asignada el maximo de grados del que será el polinomio
		@return nada. es un procedimiento
		@post el max_grado del objeto tendrá asignado el valor de grado
		*/
		void setMaxGrado(int grado);
		/**
		@brief módulo que sirve para devolver el max_grado de un objeto de tipo polinomio
		@pre el max_grado del objeto debe de estar relleno
		@return devolverá una variable de tipo int que llevará asignada el vvalor de max_grado
		@post el max_grado será devuelto correctamente
		*/
		int getMaxGrado()const;
		/**
		@modulo que sirve para imprimir un objeto de tipo polinomio
		@pre el objeto debe de estar relleno
		@return nada. es un procedimiento
		@post el objeto será imprimidso correctamente
		*/
		friend ostream& operator<<(ostream &flujo, const Polinomio &p);
		/**
		@modulo que sirve para rellenar un objeto de tipo polinomio
		@pre el objeto debe de estar vacio
		@return nada. es un procedimiento
		@post el objeto será rellenado correctamente
		*/
		friend istream& operator >>(std::istream &flujo, Polinomio &p);
		/**
		@brief módulo que sirve para acumular la suma de dos polinomios en el polinomio que llama a la funcion
		@pre. al menos uno de los dos polinomios debeŕa de tener max_grado>0. 
		@param const Polinomio &suma. Polinomio que utilizaremos para sumar
		@return nada. es un procedimiento
		@post el polinomio que llama a la funcion pasará a ser la suma de los dos polinomios.
		*/
		void sumaV1(const Polinomio &suma);
		/**
		@brief módulo que sirve para acumular la suma de dos polinomios en el polinomio que llama a la función (aqui no se perderá informacion)
		@pre. al menos uno de los dos polinomios debeŕa de tener max_grado>0. 
		@param const Polinomio &suma1. Polinomio que utilizaremos para sumar
		@param const Polinomio &suma2. Polinomio que utilizaremos para sumar
		@return nada. es un procedimiento
		@post el polinomio que llama a la funcion pasará a ser la suma de los dos polinomios.
		*/
		void sumaV2(const Polinomio &suma1, const Polinomio &suma2);
		/**
		@brief módulo que sirve para acumular la suma de dos polinomios en el polinomio que llama a la función (aqui no se perderá informacion)
		@pre. al menos uno de los dos polinomios debeŕa de tener max_grado>0. 
		@param const Polinomio &suma. Polinomio que utilizaremos para sumar
		@return nada. es un procedimiento
		@post el polinomio que llama a la funcion pasará a ser la suma de los dos polinomios.
		*/
		Polinomio operator+( Polinomio &suma);
		/**
		@brief módulo que sirve para acumular la suma de dos polinomios en el polinomio que llama a la función (aqui no se perderá informacion). se hara mediante punteros
		@pre. al menos uno de los dos polinomios debeŕa de tener max_grado>0. 
		@param const Polinomio *p2. puntero que apunta al Polinomio que utilizaremos para sumar
		@return devolverá un polinomio con la suma 
		@post el polinomio que llama a la funcion pasará a ser la suma de los dos polinomios.
		*/
		Polinomio *sumav4 (const Polinomio *p2);
};
