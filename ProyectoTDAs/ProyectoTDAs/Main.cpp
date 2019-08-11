#include <iostream>
using namespace std;
int entrada();
void Listas();
void Colas();
void Pilas();
int main(){
    int opcion=0;
    bool MenuP=false; // bool de menu principal;
    while(opcion!=4){
        while (MenuP==false){// while del menu principal
            cout << "Menu Principal"<< endl;
            cout <<"    1. Trabajar con Listas"<< endl;
            cout <<"    2. Trabajar con Pilas"<< endl;
            cout <<"    3. Trabajar con Colas"<< endl;
            cout <<"    4. salir"<< endl;
            opcion=entrada();
            if (opcion >0 && opcion <5){
            /*
            revisa si el primer caracter es un numero 
            entre los que se ocupan
            */        
                MenuP=true;
            }//fin if
            else{
                cout << "vuelva a intentar: "<< endl;
            }
        if (opcion==1){// se va a meter al menu de listas alv compa
            Listas();
        }else if (opcion==2){// se va a meter en pilas
            Pilas();
        }else if(opcion ==3){// se va a meter a colas
            Colas();
        }
        
        }// fin del while del menu principal;
    }//while del programa si opcion esigaul a 4 se sale
return 0;
}
int entrada(){
    int numero=0;
    cout<< "ingrese opcion: "<< endl;
    string entrada="";
    cin>> entrada;
    numero=(int)entrada[0];
    numero=numero-48;        
    return numero;
}
void Listas(){
    cout << "Menu Tipo de Lista"<< endl;
    cout << "   1. Trabajar con ArrayList"<< endl;
    cout << "   2. Trabajar con Linked List" << endl;
    cout << "   3. Regresar al Menu Principal"<< endl;
    int opcion=0;
    opcion=entrada();
}

