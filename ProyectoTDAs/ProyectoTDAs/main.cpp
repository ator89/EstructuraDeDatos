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
    //Instancias de las listas, pilas y colas
    TDALista* arrayList = new ArrayList();
    TDALista* linkedList = new LinkedList();
    
    TDAPila* arraypila = new ArrayStack();
    TDAPila* linkedPila = new LinkedStack();
    
    TDACola* arrayCola = new ArrayQueue();
    TDACola* linkedCola = new LinkedQueue();
    
    
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
            
            if (opcion == 1){// se va a meter al menu de listas
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
                //Insertar Alumno
                int pos = 0;
                alumno = new Alumno();
                cout << "Ingrese la posición: ";
                cin >> pos;
                
                while(1)
                {
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        cout << "\nSólo se permiten valores numéricos, intente otra vez.\n"<<endl;
                        cout << "Ingrese posición para borrar elemento: ";
                        cin >> pos;
                    }
                    if(!cin.fail())
                        break;
                }
                
                if(pos < 1 ){
                    cout << "Fuera de rango, no puede ingresar valores menores a 1 o negativos.\n";
                }
                else if(pos > 1 && lista->isEmpty()){
                    cout << "La lista está vacía, sólo se puede agregar en la primera posición.\n";
                }
                else if(pos < 1 || pos > lista->getSize()+1){
                    cout << "Posición inválida, sólo se puede agregar al final de la lista.\n";
                }
                else{
                    cout << "Ingrese el nombre: ";
                    cin >> nombre;
                    cout << "Ingrese el # cuenta: ";
                    cin >> cuenta;
                    alumno->setNombre(nombre);
                    alumno->setCuenta(cuenta);
                    lista->insertar(alumno,pos);
                    cout << "Alumno " << nombre << " agregado con éxito a la lista.\n";
                }
                
                //PEDIR AL USUARIO SEGUIR INGRESANDO DATOS <<-------------------------
                
                MenuP = false;
            }
            //Imprimir Elementos
            else if (opcion == 2){
                
                
                if(lista->isEmpty())
                    cout << "La Lista está vacía, nada que imprimir.\n";
                else
                    cout << "\nElementos de la Lista: \n";
                    lista->imprimir();
                MenuP = false;
            }
            else if (opcion == 3){
                //Buscar Elemento por #cuenta
                string cuenta = "";
                if(lista->isEmpty())
                    cout << "La lista está vacía, nada que buscar.\n";
                else{
                    cout << "Ingrese el número de cuenta a buscar: ";
                    cin >> cuenta;
                    if(lista->buscar(cuenta)== nullptr)
                        cout << "No existe.\n";
                    else
                        cout << "Encontrado en posición: " << lista->getPosBusqueda() << " - " << lista->buscar(cuenta)->toString() << "\n";
                }
                MenuP = false;
            }
            //Borrar Elemento
            else if (opcion == 4){
                int pos = 0;
                if(lista->isEmpty())
                    cout << "La lista está vacía, nada que borrar.\n";
                else{
                    
                    lista->imprimir();
                    cout << "Ingrese posición para borrar elemento: ";
                    cin >> pos;
                    
                    while(1)
                    {
                        if(cin.fail())
                        {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                            cout << "\nSólo se permiten valores numéricos, intente otra vez.\n"<<endl;
                            cout << "Ingrese posición para borrar elemento: ";
                            cin >> pos;
                        }
                        if(!cin.fail())
                            break;
                    }
                    
                    if(pos > lista->getSize() || pos <1){
                        cout << "Fuera de rango, elija un elemento dentro de la lista.\n";
                    }else{
                        cout << "Elemento <" << lista->borrar(pos)->toString() << "> borrado con éxito\n";
                    }
                }
                
                MenuP = false;
            }//#4 fin borrar elemento #4
            
            //Verificar si la lista está vacía
            else if (opcion == 5){
                
                if(lista->isEmpty())
                    cout << "La lista está vacía.\n";
                else
                    cout << "La lista tiene " << lista->getSize() << " elementos.\n";
                MenuP = false;
            }
            //Obtener Elemento por Posición
            else if (opcion == 6){
                
                int pos = 0;
                cout << "Ingrese posición a obtener: ";
                cin >> pos;
                
                while(1)
                {
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        cout << "\nSólo se permiten valores numéricos, intente otra vez.\n"<<endl;
                        cout << "Ingrese posición a obtener: ";
                        cin >> pos;
                    }
                    if(!cin.fail())
                        break;
                }
                
                if(lista->isEmpty())
                    cout << "La lista está vacía, nada que buscar.\n";
                else if(pos <= 0 || pos > lista->getSize()){
                    cout << "Posicón inválida, intente otra.\n";
                }else
                    cout << lista->posicion(pos)->toString();
                MenuP = false;
            }
            //Obtener Siguiente
            else if (opcion == 7){
                
                int pos = 0;
                cout << "Ingrese la posición para obtener su valor siguiente: ";
                cin >> pos;
                
                while(1)
                {
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        cout << "\nSólo se permiten valores numéricos, intente otra vez.\n"<<endl;
                        cout << "Ingrese la posición para obtener su valor siguiente: ";
                        cin >> pos;
                    }
                    if(!cin.fail())
                        break;
                }
                
                if(lista->isEmpty())
                    cout << "La lista está vacía, nada que buscar.\n";
                else if(pos == lista->getSize())
                    cout << "No hay más valores siguientes\n";
                else if(pos <= 0 || pos > lista->getSize()){
                    cout << "Posicón inválida, intente otra.\n";
                }else
                    cout << lista->siguiente(pos)->toString();
                MenuP = false;
            }
            //Obtener Anterior
            else if (opcion == 8){
                
                int pos = 0;
                cout << "Ingrese la posición para obtener su valor anterior: ";
                cin >> pos;
                
                while(1)
                {
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        cout << "\nSólo se permiten valores numéricos, intente otra vez.\n"<<endl;
                        cout << "Ingrese la posición para obtener su valor anterior: ";
                        cin >> pos;
                    }
                    if(!cin.fail())
                        break;
                }
                if(lista->isEmpty())
                    cout << "La lista está vacía, nada que buscar.\n";
                else if(pos <= 1)
                    cout << "No hay valores anteriores.\n";
                else if(pos <= 0 || pos > lista->getSize()){
                    cout << "Posición inválida, intente otra.\n";
                }else
                    cout << lista->anterior(pos)->toString();
                MenuP = false;
            }
            //Borrar todos los elementos (anula)
            else if (opcion == 9){
                if(lista->isEmpty())
                   cout << "La lista está vacía, nada que vaciar.\n";
                else{
                    lista->vaciar();
                    cout << "La lista se vació exitosamente.\n";
                }
                MenuP = false;
            }
        }
    }
    //delete alumno;
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
                
                //VALIDAR POSICIÓN QUE SEA SOLAMENTE UN CARACTER <<-------------------------
                
                simbolo->setSimbolo(symbol);
                pila->push(simbolo);
                cout << "Símbolo " << symbol << " agregado con éxito a la pila.\n";
                MenuP = false;
            }else if (opcion == 2){
                //Pop
                if(pila->isEmpty())
                    cout << "La Pila está vacía, nada que sacar.\n";
                else
                    cout << "Elemento sacado de la Pila con éxito: \n" << pila->pop()->toString() << "\n";
                MenuP = false;
            }
            else if (opcion == 3){
                //Top
                if(pila->isEmpty())
                    cout << "La Pila está vacía, nada que ver.\n";
                else
                    cout << "Top de la Pila: \n" << pila->top()->toString() << "\n";
                MenuP = false;
            }
            else if (opcion == 4){
                //Verificar si está vacía
                if(pila->isEmpty())
                    cout << "La Pila está vacía.\n";
                else
                    cout << "La Pila NO está vacía.\n";
                MenuP = false;
            }
            else if (opcion == 5){
                //Imprimir Elementos
                if(pila->isEmpty())
                    cout << "La Pila está vacía, nada que imprimir.\n";
                else
                    cout << "Elementos de la Pila: \n" <<  pila->toString() << "\n";
                MenuP = false;
            }
        }
    }
    delete simbolo;
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
            cout << "\nOperaciones de Colas\n"
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
                cout << "Alumno " << nombre << " agregado con éxito a la cola.\n";
                MenuP = false;
            }else if (opcion == 2){
                //deQueue
                if(cola->isEmpty())
                    cout << "La Cola está vacía.\n";
                else
                    cout << "Elemento sacado de la cola con éxito: \n" << cola->deQueue()->toString() << "\n";
                MenuP = false;
            }
            else if (opcion == 3){
                //Top
                if(cola->isEmpty())
                    cout << "La Cola está vacía.\n";
                else
                    cout << "Top de la cola: \n" << cola->front()->toString() << "\n";
                MenuP = false;
            }
            else if (opcion == 4){
                //Verificar si está vacía
                if(cola->isEmpty())
                    cout << "La Cola está vacía.\n";
                else
                    cout << "La Cola NO está vacía.\n";
                MenuP = false;
            }
            else if (opcion == 5){
                //Imprimir Elementos
                if(cola->isEmpty())
                    cout << "La Cola está vacían nada que mostrar.\n";
                else
                    cout << "Elementos de la cola: \n" << cola->toString() << "\n";
                MenuP = false;
            }
        }
    }
    delete alumno;
}
