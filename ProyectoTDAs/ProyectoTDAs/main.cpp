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
void menuListas(TDALista*,TDALista*);
//Menú principal de selección de Colas
void menuColas(TDACola*,TDACola*);
//Menú principal de selección de Pilas
void menuPilas(TDAPila*,TDAPila*);

//Menú de operaciones de Listas
void operacionesLista(TDALista*);
//Menú de operaciones de Pila
void operacionesPila(TDAPila*);
//Menú de operaciones de Cola
void operacionesCola(TDACola*);

int main(){
    TDALista* arrayList = new ArrayList();
    TDALista* linkedList = new LinkedList();
    
    TDAPila* arraypila = new ArrayStack();
    TDAPila* linkedPila = new LinkedStack();
    
    TDACola* arrayCola = new ArrayQueue();
    TDACola* linkedCola = new LinkedQueue();
    
    
    //test
    Alumno* alumno = new Alumno("1001","Nombre");
    Simbolo* simbolo = new Simbolo('%');
    arraypila->push(alumno);
    linkedPila->push(alumno);
    
    cout << "Array" << arraypila->toString()<<endl;
    cout << "Linkd" << linkedPila->toString()<<endl;
    //fin test
    
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
                menuListas(arrayList,linkedList);
                MenuP = false;//volver a ingresar el menú principal al salir del menú de listas
            }else if (opcion == 2){// se va a meter en pilas
                menuPilas(arraypila,linkedPila);
                MenuP = false;//volver a ingresar el menú principal al salir del menú de pilas
            }else if(opcion == 3){// se va a meter a colas
                menuColas(arrayCola,linkedCola);
                MenuP = false;//volver a ingresar el menú principal al salir del menú de colas
            }
            

        }// fin del while del menu principal;
    }//while del programa si opcion esigaul a 4 se sale
    
    delete arraypila;
    delete linkedPila;
    delete arrayCola;
    delete linkedCola;
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
void menuListas(TDALista* arrayList, TDALista* linkedList){
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
                operacionesLista(arrayList);
                MenuP=false;
            }else if (opcion==2){
                operacionesLista(linkedList);
                MenuP=false;
            }
        }
    }
}

//Menú principal de selección de Pilas
void menuPilas(TDAPila* arrayPila, TDAPila* linkedPila){
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
                //Trabajar con ArrayStack
                operacionesPila(arrayPila);
                MenuP=false;
            }else if (opcion==2){
                //Trabajar con LinkedStack
                operacionesPila(linkedPila);
                MenuP=false;
            }
        }
    }
}

//Menú principal de selección de Colas
void menuColas(TDACola* arrayCola,TDACola* linkedCola){
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
                operacionesCola(arrayCola);
                MenuP=false;
            }else if (opcion==2){
                operacionesCola(linkedCola);
                MenuP=false;
            }
        }
    }
}

//Menú de operaciones de Listas
void operacionesLista(TDALista* lista){
    
    Alumno* alumno = NULL;
    string cuenta;
    string nombre;
    int pos = 0;
    
    int opcion = -1;
    bool MenuP = false; // bool de menu principal;
    
    while(opcion != 0){
        while (MenuP == false){// while del menu principal
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
            << "\t0 Regresar al Menú Principal\n";
            opcion = entrada();
            
            if (opcion >= 0 && opcion <11)
                MenuP = true;
            else
                cout << "¡Opción no válida! Vuelva a intentar.\n"<< endl;
            
            if (opcion == 1){
                //Insertar Elemento
                alumno = new Alumno();
                cout << "Ingrese el nombre: ";
                cin >> nombre;
                cout << "Ingrese el # cuenta: ";
                cin >> cuenta;
                cout << "Ingrese la posición: ";
                cin >> pos;
                alumno->setNombre(nombre);
                alumno->setCuenta(cuenta);
                lista->insertar(alumno,pos);
                MenuP = false;
            }else if (opcion == 2){
                //Imprimir Elementos
                //lista->imprimir();
                cout << lista->toString();
                MenuP = false;
            }
            else if (opcion == 3){
                //Buscar Elemento
                MenuP = false;
            }
            else if (opcion == 4){
                //Borrar Elemento
                MenuP = false;
            }
            else if (opcion == 5){
                //Ver si está vacía
                MenuP = false;
            }
            else if (opcion == 6){
                //Obtener Elemento por Posición
                MenuP = false;
            }
            else if (opcion == 7){
                //Obtener Siguiente
                cout << "Ingrese la posición: ";
                cin >> pos;
                cout << lista->siguiente(pos)->toString();
                MenuP = false;
            }
            else if (opcion == 8){
                cout << "Ingrese la posición: ";
                cin >> pos;
                cout << lista->anterior(pos)->toString();
                //Obtener Anterior
                MenuP = false;
            }
            else if (opcion == 9){
                //Borrar todos los elementos (anula)
                MenuP = false;
            }
        }
    }
}

//Menú de operaciones de Pila
void operacionesPila(TDAPila* pila){
    Simbolo* simbolo = NULL;
    char symbol;
    int opcion = 0;
    bool MenuP = false; // bool de menu principal;
    while(opcion != 6){
        while (MenuP == false){// while del menu principal
            cout << "\nOperaciones de Pilas\n"
                << "\t1. Empujar\n"
                << "\t2. Sacar\n"
                << "\t3. Ver Tope\n"
                << "\t4. Verificar si está vacía\n"
                << "\t5. Imprimir Elementos\n"
                << "\t6 Regresar al Menú Principal\n";
            opcion = entrada();
            if (opcion > 0 && opcion <7)
                MenuP = true;
            else
                cout << "¡Opción no válida! Vuelva a intentar.\n"<< endl;
            
            if (opcion == 1){
                //Push
                simbolo = new Simbolo();
                cout << "Ingrese un símbolo: ";
                cin >> symbol;
                simbolo->setSimbolo(symbol);
                pila->push(simbolo);
                MenuP = false;
            }else if (opcion == 2){
                //Pop
                cout << pila->pop()->toString();
                MenuP = false;
            }
            else if (opcion == 3){
                //Top
                cout << pila->top()->toString();
                MenuP = false;
            }
            else if (opcion == 4){
                //Verificar si está vacía
                pila->isEmpty();
                MenuP = false;
            }
            else if (opcion == 5){
                //Imprimir Elementos
                cout << pila->toString();
                MenuP = false;
            }
        }
    }
}

//Menú de operaciones de Cola
void operacionesCola(TDACola* cola){
    
    Alumno* alumno = NULL;
    string cuenta;
    string nombre;
    
    int opcion = 0;
    bool MenuP = false; // bool de menu principal;
    
    while(opcion != 6){
        while (MenuP == false){// while del menu principal
            cout << "\nOperaciones de Pilas\n"
                << "\t1. Encolar\n"
                << "\t2. Desencolar\n"
                << "\t3. Ver Tope\n"
                << "\t4. Verificar si está vacía\n"
                << "\t5. Imprimir Elementos\n"
                << "\t6 Regresar al Menú Principal\n";
            opcion = entrada();
            
            if (opcion > 0 && opcion <7)
                MenuP = true;
            else
                cout << "¡Opción no válida! Vuelva a intentar.\n"<< endl;
            
            if (opcion == 1){
                //Queue
                alumno = new Alumno();
                cout << "Ingrese el nombre: ";
                cin >> nombre;
                cout << "Ingrese el # cuenta: ";
                cin >> cuenta;
                alumno->setNombre(nombre);
                alumno->setCuenta(cuenta);
                cola->queue(alumno);
                MenuP = false;
            }else if (opcion == 2){
                //deQueue
                cout << cola->deQueue()->toString();
                MenuP = false;
            }
            else if (opcion == 3){
                //Top
                cout << cola->front()->toString();
                MenuP = false;
            }
            else if (opcion == 4){
                //Verificar si está vacía
                cola->isEmpty();
                MenuP = false;
            }
            else if (opcion == 5){
                //Imprimir Elementos
                cout << cola->toString();
                MenuP = false;
            }
        }
    }
}
