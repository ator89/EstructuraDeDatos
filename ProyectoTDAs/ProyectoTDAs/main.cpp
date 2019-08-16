#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;

//Importar header de TDAs
#include "TDALista.h"
#include "TDACola.h"
#include "TDAPila.h"
#include "ArrayStack.h"
#include "ArrayQueue.h"
#include "ArrayList.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"
#include "LinkedList.h"
//importar objetos
#include "Alumno.h"
#include "Simbolo.h"

//Validación de entrada de usuario
int entrada();
//Menú principal de selección de Listas
void menuListas();
//Menú principal de selección de Colas
void menuColas();
//Menú principal de selección de Pilas
void menuPilas();

//Menú de operaciones de Listas
void operacionesLista();
//Menú de operaciones de Pila
void operacionesPila();
//Menú de operaciones de Cola
void operacionesCola();

int main(){
    TDALista* arrayList = new ArrayList();
    TDALista* linkedList = new LinkedList();
    TDAPila* arraypila = new ArrayStack();
    TDAPila* linkedPila = new LinkedStack();
    TDACola* arraycola = new ArrayQueue();
    TDACola* linkedcola = new LinkedQueue();
    
    
    Alumno* alumno = new Alumno("1001","Nombre");
    Simbolo* simbolo = new Simbolo('%');
    arraypila->push(alumno);
    linkedPila->push(alumno);
    
    cout << "Array" << arraypila->toString()<<endl;
    cout << "Linkd" << linkedPila->toString()<<endl;
    
    
    int opcion = 0;
    bool MenuP = false; // bool de menu principal;
    while(opcion != 4){
        while (MenuP == false){// while del menu principal
            cout << "\nMenu Principal" << endl;
            cout << "\t1. Trabajar con Listas" << endl;
            cout << "\t2. Trabajar con Pilas" << endl;
            cout << "\t3. Trabajar con Colas" << endl;
            cout << "\t4. Salir" << endl;
            opcion = entrada();
            
            //revisa si el primer caracter es un numero entre los que se ocupan
            if (opcion > 0 && opcion < 5){
                MenuP = true;
            }//fin if
            else{
                cout << "¡Opción no válida! Vuelva a intentar.\n"<< endl;
            }
            
            if (opcion == 1){// se va a meter al menu de listas alv compa
                menuListas();
                MenuP = false;//volver a ingresar el menú principal al salir del menú de listas
            }else if (opcion == 2){// se va a meter en pilas
                menuPilas();
                MenuP = false;//volver a ingresar el menú principal al salir del menú de pilas
            }else if(opcion == 3){// se va a meter a colas
                menuColas();
                MenuP = false;//volver a ingresar el menú principal al salir del menú de colas
            }
            
            
        }// fin del while del menu principal;
    }//while del programa si opcion esigaul a 4 se sale
    
    delete arraypila;
    delete linkedPila;
    delete arraycola;
    delete linkedcola;
    delete arrayList;
    delete linkedList;
    delete alumno;
    delete simbolo;
    
    return 0;
}

//Validación de entrada de usuario
int entrada(){
    int numero = 0;
    string entrada = "";
    cout << "Ingrese una opción: "<< endl;
    cin >> entrada;
    numero = (int)entrada[0];
    numero = numero-48;
    return numero;
}

//Menú principal de selección de Listas
void menuListas(){
    int opcion = 0;
    bool MenuP = false; // bool de menu principal;
    while(opcion != 3){
        while (MenuP == false){// while del menu principal
            cout << "\nMenu Tipo de Lista"<< endl;
            cout << "\t1. Trabajar con ArrayList"<< endl;
            cout << "\t2. Trabajar con Linked List" << endl;
            cout << "\t3. Regresar al Menu Principal"<< endl;
            opcion = entrada();
            if (opcion > 0 && opcion <4)
                MenuP = true;
            else
                cout << "¡Opción no válida! Vuelva a intentar.\n"<< endl;
            
            if (opcion==1){
                operacionesLista();
                MenuP=false;
            }else if (opcion==2){
                operacionesLista();
                MenuP=false;
            }
        }
    }
}

//Menú principal de selección de Pilas
void menuPilas(){
    int opcion = 0;
    bool MenuP = false; // bool de menu principal;
    while(opcion != 3){
        while (MenuP == false){// while del menu principal
            cout << "\nMenu Tipo de Pila"<< endl;
            cout << "\t1. Trabajar con ArrayStack"<< endl;
            cout << "\t2. Trabajar con LinkedStack" << endl;
            cout << "\t3. Regresar al Menu Principal"<< endl;
            opcion = entrada();
            if (opcion > 0 && opcion <4)
                MenuP = true;
            else
                cout << "¡Opción no válida! Vuelva a intentar.\n"<< endl;
            
            if (opcion==1){
                operacionesPila();
                MenuP=false;
            }else if (opcion==2){
                operacionesPila();
                MenuP=false;
            }
        }
    }
}

//Menú principal de selección de Colas
void menuColas(){
    int opcion = 0;
    bool MenuP = false; // bool de menu principal;
    while(opcion != 3){
        while (MenuP == false){// while del menu principal
            cout << "\nMenu Tipo de Cola"<< endl;
            cout << "\t1. Trabajar con ArrayQueue"<< endl;
            cout << "\t2. Trabajar con LinkedQueue" << endl;
            cout << "\t3. Regresar al Menu Principal"<< endl;
            opcion = entrada();
            if (opcion > 0 && opcion <4)
                MenuP = true;
            else
                cout << "¡Opción no válida! Vuelva a intentar.\n"<< endl;
            
            if (opcion==1){
                operacionesCola();
                MenuP=false;
            }else if (opcion==2){
                operacionesCola();
                MenuP=false;
            }
        }
    }
}

//Menú de operaciones de Listas
void operacionesLista(){
    cout << "\nOperaciones de Listas\n"
    << "\t1. Insertar Elemento\n"
    << "\t2. Imprimir Elementos\n"
    << "\t3. Buscar Elemento\n"
    << "\t4. Borrar Elemento\n"
    << "\t5. Ver si está vacía\n"
    << "\t6. Obtener Elemento por Posición\n"
    << "\t7. Obtener Siguiente\n"
    << "\t8. Obtener Anterior\n"
    << "\t9. Borrar todos los elementos (anula)\n"
    << "\t10 Regresar al Menú Principal\n";
    int opcion = 0;
    opcion = entrada();
}

//Menú de operaciones de Pila
void operacionesPila(){
    cout << "\nOperaciones de Pilas\n"
    << "\t1. Empujar\n"
    << "\t2. Sacar\n"
    << "\t3. Ver Tope\n"
    << "\t4. Verificar si está vacía\n"
    << "\t5. Imprimir Elementos\n"
    << "\t6 Regresar al Menú Principal\n";
}

//Menú de operaciones de Cola
void operacionesCola(){
    cout << "\nOperaciones de Pilas\n"
    << "\t1. Encolar\n"
    << "\t2. Desencolar\n"
    << "\t3. Ver Tope\n"
    << "\t4. Verificar si está vacía\n"
    << "\t5. Imprimir Elementos\n"
    << "\t6 Regresar al Menú Principal\n";
}
