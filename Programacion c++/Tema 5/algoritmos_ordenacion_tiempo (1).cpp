//
//  algoritmos_ordenacion_tiempos.cpp
//
//
//  Created by Jaime Matas Bustos on 24/01/16.
//
//

#define BLACK_COLOR "\033[1;30m"
#define RED_COLOR "\033[1;31m"
#define GREEN_COLOR "\033[1;32m"
#define YELLOW_COLOR "\033[1;33m"
#define BLUE_COLOR "\033[1;34m"
#define PURPLE_COLOR "\033[1;35m"
#define CYAN_COLOR "\033[1;36m"
#define WHITE_COLOR "\033[1;39m"

#define RESTORE_DEFAULT_COLOR "\033[0m"

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <iomanip>
#include <time.h>

using namespace std;
/**
@brief módulo que sirve para copiar y pegar un vector en otro que esté vacio.
@pre util_v deberá de ser mayor a o y menor que DIM, y util_v_copia deberá de ser 0.
@param const int v[], vector que copiaremos en otro. parámeto simplemente de lectura.
@param int util_v variable de tipo int que sirve para saber cuand tenemos que parar decopias. nos dice los esacios ocupados del vector y la siguiente posición.
@param int v_copia [] veector donde copiaremos v[].
@uti_V_copia (pasada por referencia) variable de tipo int que sirve para ver el estado de nuestor vector. marcará los espacios de memoria ocupados y la siguiente posición libre.
@return. Nada. es un PROCEDIMIENTO
@post util_copia deberá de ser igual a util_v.
*/
void copiarVector( const int v[], int util_v, int v_copia[], int &util_copia ){
    for (int i=0; i < util_v; i++){
        v_copia[i] = v[i];
    }
    util_copia = util v;
}
/**
@brief módulo que sirve para rellenar un vector hasta su dimensión con valores random
@pre util_v deberá de ser igual a 0.
@param int v[], vector que utilizaremos para almacenar todos los valores aleatorios
@param int util_v variable de tipo int que sirve para saber el estado de nuestro vector en todo momento. nos dice los esacios ocupados del vector y la siguiente posición.
@param const DIM_V. dimensión máxima del vector
@return. Nada. es un PROCEDIMIENTO
@post util_v deberá de ser mayor que o e igual que DIM_V.
*/
void generarVector( int v[], int &util_v,const int DIM_V){
    for (int i=0; i < DIM_V; i++){
        v[i] = rand();
        util_v++;
    }
}
/**
@brief módulo que sirve para imprimir un vector
@pre util_v deberá de ser mayor que 0 y menor que DIM_V
@param const int v[], (L): vector del cual leeremos su contenido 
@param int util_v variable de tipo int que sirve para saber el estado de nuestro vector en todo momento. En esta ocasión nos dirá hasta cuando tenemos que leer del vector.
@return. Nada. es un PROCEDIMIENTO
@post el vector se deberá de mprimir por pantalla correctamente y la util se deberá de mantene igual.
*/
void imprimeVector(const int v[], int util_v){
    cout << RED_COLOR << "V = { ";
    for (int i=0; i < util_v; i++)
        cout << v[i] << " ";
    cout << "}" << endl;
    cout << RESTORE_DEFAULT_COLOR;
}



/**
@brief módulo que sirve para ordenar un vector de menor a mayor por el método de la inserción
@pre util deberá de ser mayor a o y menor que DIM.
@param  int vector[] vector que ordenaremos por el método de inserción
@param int util variable de tipo int que sirve para saber cuand tenemos que parar de ordenar. nos dice los esacios ocupados del vector y la siguiente posición.
@return. Nada. es un PROCEDIMIENTO
@post El vector deberá de estar ordenado de menor a mayor y la util se deberá de mantener igual..
*/
void algoritmoInsercion(int Vector[],int util){
    int izq=1,i,valor; // izqda es la primera parte del vector desordenada
    
    for(izq=1;izq<util;izq++){
        
        valor=Vector[izq]; // cogemos el valor que tenemos que nsertar en la parte ordenada
        
        for(i=izq;i>0 && valor<Vector[i-1];i--){
            Vector[i]=Vector[i-1]; 
        }
        Vector[i]=valor;
    }
}

/**
@brief módulo que sirve para buscar el número más pequeñño del vector y guardar su contenido y su posición  ej v{ 3, 4, 1} resultado = posicion_mimnimo= 2 y contenido=1
@pre util deberá de ser mayor a o y menor que DIM, e i deberá de ser menor que util-1.
@param  int vector[] vector en el cual buscaremos la posición minima.
@param int izqda. nos marcará a partir de que espacio de memoria deberemos de empezar a buscar. digamos que separa la parte ordenada de la desordenada
@param int derecha. variable que marca el tamaño del vector hasta donde tenemos que buscar
@return. devolverá una variable de tipo int con la posición del espacio del vector que contenga el numero más pequeño
@post posición numero deberá de contener una posición ue exista en el vector. es decir, si el vector tiene 5 posiciones no puede devolver la 7. además, tendrá que tener la posición del numero más pequeño
*/
int Posminimo(const int Vector[],int izq,int dcha){
    
    double minimo=Vector[izq];
    int posicion_minimo=izq;
    for(int i=izq+1;i<=dcha;i++){
        if(Vector[i]<minimo){
            minimo=Vector[i];
            posicion_minimo=i; // almacenaremos donde se encuentra posición del menor valor
        }
        
    }
    return posicion_minimo;
}
/**
@brief módulo que sirve para ordenar un vector de menor a mayor por el método de selección
@pre util deberá de ser mayor a o y menor que DIM.
@param  int vector[] vector que ordenaremos por el método de inserción
@param int util variable de tipo int que sirve para saber cuand tenemos que parar de ordenar. nos dice los esacios ocupados del vector y la siguiente posición.
@return. Nada. es un PROCEDIMIENTO
@post El vector deberá de estar ordenado de menor a mayor y la util se deberá de mantener igual..
*/
void algoritmoSeleccion(int Vector[],int util){
    
    int pos_min,intercambiar;
    
    for(int i=0;i<util-1;i++){// la i nos indica la 1 parte del vector desordenado
        pos_min = Posminimo(Vector,i,util-1);
        
        intercambiar=Vector[i];
        Vector[i]=Vector[pos_min];     // intercambio del elemento más pequeño con la primera posición del vector desordenado.
        Vector[pos_min]=intercambiar;
    }
    
}

/**
@brief módulo que sirve para ordenar un vector de menor a mayor por el método de la burbbuja
@pre util deberá de ser mayor a o y menor que DIM.
@param  int vector[] vector que ordenaremos por el método de inserción
@param int util_v variable de tipo int que sirve para saber cuand tenemos que parar de ordenar. nos dice los esacios ocupados del vector y la siguiente posición.
@return. Nada. es un PROCEDIMIENTO
@post El vector deberá de estar ordenado de menor a mayor y la util se deberá de mantener igual..
*/
void algoritmoOrdenacionBurbuja(int v[], int util_v){
    bool cambio = true; //para detectar una pasada sin cambios
    int aux;
    for (int izda = 0; izda < util_v && cambio; izda++){
        cambio = false;
        for (int i = util_v-1; i > izda; i--){
            if (v[i] < v[i-1]){
                cambio = true;
                //Intercambiamos
                aux = v[i];
                v[i] = v[i-1];
                v[i-1] = aux;
            }
        }
        //cout << "Iteración (" << izda << "): ";
        //imprimeVector(v, util_v);
    }
}

int main(){
    //VARIABLES PARA MEDIR TIEMPOS
    clock_t t_iniSelec, t_finSelec,t_iniInser,t_finInser,t_finBurbu,t_iniBurbu;
    double secsSelec,secsInser,secsBurbu;
    
    //VECTORES
    const int DIM_V = 100000;
    int v[DIM_V] = {0};
    int util_v = 0;
    
    const int DIM_VCOPIA = 100000;
    int v_copia[DIM_VCOPIA] = {0};
    int util_v_copia = 0;
    
    //Generamos el Vector Aleatorio
    generarVector( v_copia, util_v_copia, DIM_VCOPIA);
    
    //Algoritmo de Selección
    cout << endl << "********** ALGORITMO DE ORDENACIÓN POR SELECCIÓN *************" << endl;
    copiarVector( v_copia, util_v_copia, v, util_v );
    //cout << "Mi Vector Inicial es: ";
    //cout << RED_COLOR;
    //imprimeVector(v, util_v);
    //cout << RESTORE_DEFAULT_COLOR;
    
    t_iniSelec = clock();
    algoritmoSeleccion(v, util_v);
    t_finSelec = clock();
    
    //cout << "Mi Vector Final es: ";
    //cout << GREEN_COLOR;
     //imprimeVector(v, util_v);
    //cout << RESTORE_DEFAULT_COLOR;
    
    //Algoritmo de Inserción
    cout << endl << "********** ALGORITMO DE ORDENACIÓN POR INSERCIÓN *************" << endl;
    copiarVector( v_copia, util_v_copia, v, util_v );
    // cout << "Mi Vector Inicial es: ";
    //cout << RED_COLOR;
    //imprimeVector(v, util_v);
    //cout << RESTORE_DEFAULT_COLOR;    
    t_iniInser = clock();
    algoritmoInsercion(v, util_v);
    t_finInser = clock();
    
   // cout << "Mi Vector Final es: ";
    //cout << GREEN_COLOR;
    //imprimeVector(v, util_v);
    //cout << RESTORE_DEFAULT_COLOR;    
    //Algoritmo de la Burbuja
    cout << endl << "********** ALGORITMO DE ORDENACIÓN POR BURBUJA *************" << endl;
    copiarVector( v_copia, util_v_copia, v, util_v );
  //  cout << "Mi Vector Inicial es: ";
   //cout << RED_COLOR;
    //imprimeVector(v, util_v);
    //cout << RESTORE_DEFAULT_COLOR;
    
    t_iniBurbu = clock();
    algoritmoOrdenacionBurbuja(v, util_v);
    t_finBurbu = clock();
    
    // cout << "Mi Vector Final es: ";
    //cout << GREEN_COLOR;
    //imprimeVector(v, util_v);
    //cout << RESTORE_DEFAULT_COLOR;    
    cout << endl << "/************** MEDICIÓN DE TIEMPOS Y DIMENSIÓN ***********/" << endl;
    cout << "La Dimensión del Vector era de: " << BLUE_COLOR <<  DIM_V << endl;
    //Operación de conversión a mili segundos
    secsSelec = (double)(t_finSelec - t_iniSelec) / CLOCKS_PER_SEC;
    cout << RESTORE_DEFAULT_COLOR << "Tiempo de Selección:\t" << fixed << setprecision(16) << CYAN_COLOR << secsSelec << endl;
    
    //Operación de conversión a mili segundos
    secsInser = (double)(t_finInser - t_iniInser) / CLOCKS_PER_SEC;
    cout  << RESTORE_DEFAULT_COLOR << "Tiempo de Inserción:\t" << fixed << setprecision(16) << YELLOW_COLOR <<  secsInser  << endl;
    
    //Operación de conversión a mili segundos
    secsBurbu = (double)(t_finBurbu - t_iniBurbu) / CLOCKS_PER_SEC;
    cout << RESTORE_DEFAULT_COLOR << "Tiempo de Burbuja:\t" << fixed << setprecision(16) << PURPLE_COLOR << secsBurbu  << endl;
    
    cout << RESTORE_DEFAULT_COLOR << endl;
    
    return 0;
}
