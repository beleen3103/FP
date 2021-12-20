#ifndef Tablero_h
#define Tablero_h
#include "Casilla.h"

const int MAX_TAM = 9;
typedef tCasilla tTablero[MAX_TAM][MAX_TAM];

void iniciaTablero(tTablero tablero);
bool cargarTablero(string nombreFichero, tTablero tablero);
void dibujarTablero(const tTablero tablero);
bool ponerNum(tTablero tablero, int fila, int col, int c);
bool borrarNum(tTablero tablero, int fila, int col);
bool tableroLleno(const tTablero tablero);
void mostrarPosibles(const tTablero tablero, int fila, int col);
void rellenarSimples(tTablero tablero);


#endif