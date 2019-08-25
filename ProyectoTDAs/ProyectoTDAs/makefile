main: main.o Pieza.o Partida.o Tablero.o Reina.o Torre.o Alfil.o Caballo.o Rey.o Peon.o
	g++ main.o Pieza.o Partida.o Tablero.o Reina.o Torre.o Alfil.o Caballo.o Rey.o Peon.o -o main 

Tablero.o: Tablero.cpp
	g++ -c Tablero.cpp

Partida.o: Partida.cpp
	g++ -c Partida.cpp

Pieza.o: Pieza.cpp Reina.cpp Torre.cpp Alfil.cpp Caballo.cpp Rey.cpp Peon.cpp
	g++ -c Pieza.cpp Reina.cpp Torre.cpp Alfil.cpp Caballo.cpp Rey.cpp Peon.cpp

main.o: main.cpp
	g++ -c main.cpp