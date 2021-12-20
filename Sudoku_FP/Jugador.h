#ifndef Jugador_h
#define Jugador_h 

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

typedef struct {
	int puntos;
	string nombre;
}tJugador;

typedef tJugador *tJugadorPtr;

string toString(tJugador jugador);
void modificarJugador(tJugador & jugador, int puntos);
bool operator<(const tJugador & opIzq, const tJugador & opDer);
bool menor(const tJugador & j1, const tJugador & j2);

#endif