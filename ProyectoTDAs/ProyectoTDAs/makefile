main: main.o Object.o TDALista.o TDACola.o TDAPila.o Alumno.o Simbolo.o LinkedList.o ArrayList.o LinkedStack.o ArrayStack.o LinkedQueue.o ArrayQueue.o Nodo.o
	g++ main.o Object.o TDALista.o TDACola.o TDAPila.o Alumno.o Simbolo.o LinkedList.o ArrayList.o LinkedStack.o ArrayStack.o LinkedQueue.o ArrayQueue.o Nodo.o -o main

Nodo.o: Nodo.cpp
	g++ -c Nodo.cpp

Object.o: Object.cpp TDALista.cpp TDACola.cpp TDAPila.cpp Alumno.cpp Simbolo.cpp LinkedList.cpp ArrayList.cpp LinkedStack.cpp ArrayStack.cpp LinkedQueue.cpp ArrayQueue.cpp
	g++ -c Object.cpp TDALista.cpp TDACola.cpp TDAPila.cpp Alumno.cpp Simbolo.cpp LinkedList.cpp ArrayList.cpp LinkedStack.cpp ArrayStack.cpp LinkedQueue.cpp ArrayQueue.cpp

main.o: main.cpp
	g++ -c main.cpp
