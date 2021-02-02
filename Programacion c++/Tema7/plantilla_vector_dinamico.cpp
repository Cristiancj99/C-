#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
// declaracion de struct
struct Persona{
    string nombre;
    int edad;
};
/**
@brief modulo que sirve para introducir el nombre a un puntero que apunta a una variable estructurada
@param Persona *p. puntero que apunta a la variable dinamica que queremos rellenar
@param string nombre. string que llevará asignado el nombre que le asignaremos al alumno
@pre el espacio de memoria reservado para el nombre de la persona debe de estar libre
@return Nada. es un procedimiento
@post al al nombre de la variable estructurada se le asignara el contenido de nombre.
*/
void setNombre(Persona *p, string nombre){
    //(*p).nombre = nombre  //tb vale
    p->nombre = nombre;    //cuando tenemos punteros nos gusta más usar el operador flecha
}
/**
@brief modulo que sirve para introducir la edad a un puntero que apunta a una variable estructurada
@param Persona *p. puntero que apunta a la variable dinamica que queremos rellenar
@param int edad. int que llevará asignado la edad que le asignaremos a la persona
@pre el espacio de memoria reservado para la edad de la persona debe de estar libre
@return Nada. es un procedimiento
@post a la edad de la variable estructurada se le asignara el contenido de nombre.
*/
void setEdad (Persona *p, int edad){
    p->edad = edad;
}
/**
@brief modulo que devuelve el nombre de una persona
@param Persona *p. puntero que apunta a la variable de la cual queremos extraer los datos
@pre p-> nombre deberá de estar relleno
@return devolverá un string con el nombre de la persona
@post el nombre será devuelto correctamente
*/
string getNombre(Persona *p){
    return p->nombre;
}
/**
@brief modulo que devuelve la edad de una persona
@param Persona *p. puntero que apunta a la variable de la cual queremos extraer los datos
@pre p-> edad deberá de estar relleno
@return devolverá un int con la edad de la persona a la que señala el puntero
@post la edad  será devuelta correctamente
*/
int getEdad (Persona *p){
    return p->edad;
}
/**
@brief modulo que sirve para imprimir una variable estructurada mediante un puntero que la apunte
@param Persona *p. puntero que apunta a la variable de tipo Persona que queremos imprimir
@pre la Variable estructurada deberá de estar correctamente rellena
@return Nada. es un procedimiento
@post el alumno se imprimirá por pantalla correctamente
*/
void printPersona(Persona *p){
    cout << "Persona: " << getNombre(p) << " tiene " << getEdad(p) << " años." << endl;
}
/**
@brief modulo que sirve para imprimir un vector de personas 
@param Persona *v. puntero que apunta hacia la posicion 0 del vector de personas
@param int util_v varianle de tipo int que nos dirá cuantas posiciones ocupadas hay en nuestro vector
@pre util_v deberá de ser mayor que 0, si no, no hay personas en el vector
@return nada. es un procedimiento
@post el vector será imprimido correctamente
*/
void printVectorPersonas(Persona *v, int util_v){
    for(int i=0; i < util_v; i++)
        printPersona(&v[i]);
}
/**
@brief modulo que sirve paraa crear un puntero a persona dinamico.
@pre tendremos que haber creado un puntero a personas previamente.
@return en el caso de que haya espacio libre en el heap, se devolverá una direccion de memoria dinámica
@post si hay espacio en el heap se devolverá un puntero a personas dinamico, si no , se mostrará un mensaje de error por la pantalla y se acabará el programa
*/
Persona* crearPersona(){
    Persona *p = new Persona;
    if (p == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }
    return p;
}
/**
@brief modulo que sirve para eliminar una variable estructurada de tipo persona mediante un puntero  que la apunte
@param Persona *p variable de tipo puntero que apunta al espacio de memoria donde se encuentra la variable estructurada Persona
@pre La variabla estructurada deberá de estar rellena
@return Nada. es un procedimiento
@post la persona será eliminada y su espacio en el heap quedará libre
*/
void borrarPersona(Persona *p){
    //formateo a cero/nulo todos los datos que tiene una persona
    p->nombre = "";
    p->edad = -1;
    //borro el fragmento de memoria
    delete p;
    //elimino la dirección que referenciaba al fragmento de memoria
    p = 0;
}

/**
 * @brief Cambia la dimensión del vector a una nueva dim_nueva
 *  1) Creo un vector nuevo con la nueva dimension
 *  2) Copio el contenido del vector que me pasan, en el nuevo vector (OJO SI ES MÁS GRANDE O MÁS CHICO)
 *  3) Libero la memoria del vector que me pasan
 *  4) Devuelvo el puntero del nuevo vector
 */
Persona* resize(Persona *v, int &util_actual, int dim_actual,  int dim_nueva){

    Persona *dinamico_aux = new Persona[dim_nueva]; 


    if (dim_actual==dim_nueva){

        dinamico_aux=
    }

    else if (util_actual > dim_nueva){ // caso en el que el nuevo vector es menor que el vector actual

        for (int i =0; i < dim_nueva ; i++){
        
            dinamico_aux[i]=v[i];
        }
    util_actual=dim_nueva;
    }
    else if (util_actual < dim_nueva){ // caso en el que el vector actual es menor que el vector nuevo

        for (int i =0; i < util_actual ; i++){
        
            dinamico_aux[i]=v[i];
        }
    }   

    return dinamico_aux;
}
        

        

/**
 * @brief Módulo que inserta la Persona p, en el Vector Dinámico de Personas v.
 *  En los escenarios necesarios realiza una llamada al módulo resize para que la nueva persona p pueda introducirse sin problemas y sea transparente para el programado que utilice este módulo
 *
 */
Persona* insertarPersonaenVector(Persona* v, int &util_actual, int &dim_actual, Persona *p){
    //aquí dentro se usa la llamada al resize!!!
    Persona *dinamico_aux = new Persona[dim_actual];

    cout << "insertando persona..."<<endl;

    dinamico_aux=resize(v, util_actual, dim_actual, dim_actual+1);// primero aumentamos en uno el tamaño de nuestro vector
    dinamico_aux[util_actual]=*p; //en el espapcio nuevo creado, le insertamos el contenido de la variable a la que apunta el puntero p
    util_actual++; // por ultimo, actualizamos la util

    return dinamico_aux;

}

/**
@brief modulo que sirve para eliminar una posicion del vector
@pre i< util, i >0
@param persona *v vector de personas que utilizaremos para borrar el elemento
@param int util_persona vriable que nos dira la posicion ocupada del vector
@RETURN devolvera un puntero a de tipo persona
@post  El vector tendrá una util menos y la posicion estará eliminada correctamente
*/
void EliminarPersonaVector (Persona *v, int &util_actual, int i){

    v[i]=v[util_actual-1]; // copiamos la ultima posicion del vector en la posicion que queremos eliminar.
    resize(v, util_actual, util_actual, util_actual-1);// hacemos un resize restandole uno y eliminando la ultima posicion del vector. OJO, SE PIERDEN DATOS

}
int main(){
    
    Persona pepe_estatico; //memoria estática
    
    //1º) Declaro los punteros
    Persona *pepe = 0, *carlos = 0, *jose = 0, *antonio=0;; //memoria dinámica
    
    //2º) Pedir memoria al SO
    pepe = crearPersona();
    carlos = crearPersona();
    jose = crearPersona();
    antonio=crearPersona();

    //3º) METEMOS DATOS
    //Uso estático de los módulos que emplean punteros
    setNombre(&pepe_estatico, "Pepe_Estático");
    setEdad(&pepe_estatico, 31);
    //Uso dinámico de los módulos que emplean punteros
    setNombre(pepe,"Pepe");
    setEdad(pepe, 20);
    setNombre(jose,"Jose");
    setEdad(jose, 5);
    setNombre(carlos,"Carlos");
    setEdad(carlos, 47);
    setNombre(antonio,"Antonio");
    setEdad(antonio, 12);
    
    
    //AHORA VAMOS A USAR UN VECTOR DINÁMICO
    const int DIM_V = 20;
    Persona v_estatico[DIM_V]; //memoria estática: ME HA CREADO 20 PERSONAS ESTÁTICAS!!!!!
    int util_v_estatico = 0;
    
    //1ª ALTERNATIVA: UN VECTOR DINÁMICO DE PERSONAS
    int tamanio = 3;
    int util_v_dinamico = 0;
    Persona *v_dinamico = new Persona[tamanio]; //memoria dinámica: ME HE CREADO "tamanio" PERSONAS DINÁMICAS
    if (v_dinamico == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }
    
    v_estatico[0] = *carlos;
    v_estatico[1] = pepe_estatico;
    util_v_estatico = 2;
    printVectorPersonas(v_estatico, util_v_estatico);
    
    v_dinamico[0] = pepe_estatico; //TIPOS COMPATIBLES!!!
    //v[0] = pepe; //TIPOS INCOMPATIBLES!!!
    v_dinamico[0] = *pepe; //UNA COPIA!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    v_dinamico[1] = *jose;
    v_dinamico[2] = pepe_estatico;
    util_v_dinamico = 3;
    //v contiene la dirección de la primera Persona
    printVectorPersonas(v_dinamico, util_v_dinamico);
    
    cout << " INSERTANDO PERSONA...."<<endl;
    v_dinamico=insertarPersonaenVector(v_dinamico,util_v_dinamico, tamanio,antonio);
       printVectorPersonas(v_dinamico, util_v_dinamico);
    
    
   //Uso y testing del resize
    cout << "Cambiando tamaño aumentando... "<<endl;
    int nuevo_tam = tamanio+2; // CRECER
    v_dinamico = resize(v_dinamico,util_v_dinamico,tamanio,nuevo_tam);
    
    printVectorPersonas(v_dinamico,util_v_dinamico);
    
    /*cout<<"borrando numero..."<<endl;
    EliminarPersonaVector (v_dinamico, util_v_dinamico,1);
     printVectorPersonas(v_dinamico,util_v_dinamico);
    
    cout<<"cambiando tamaño disminuyendo..."<<endl;
    nuevo_tam = tamanio-2; //DECRECER
    v_dinamico = resize(v_dinamico,util_v_dinamico,tamanio, nuevo_tam);
    printVectorPersonas(v_dinamico,nuevo_tam);
 
    */
    
      //BORRO LAS COPIAS DE LAS PERSONAS GUARDADAS EN EL VECTOR DINÁMICO DE PERSONAS!!!!
    //Borro las personas que tenía creadas antes
    borrarPersona(pepe);
    borrarPersona(carlos);
    borrarPersona(jose);
    
    //Borrar las direcciones donde estaba la memoria reservada
    v_dinamico = pepe = carlos = jose = 0;
}