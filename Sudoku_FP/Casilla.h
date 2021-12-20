#ifndef Casilla_h
#define Casilla_h
#include "Conjunto.h"
#include <Windows.h>

typedef enum tEstado { VACIA, FIJA, RELLENADA };

typedef struct {
	tEstado estado;
	int num;
	tConjunto c;
}tCasilla;


void iniciaCasilla(tCasilla & casilla);
void rellenaCasilla(tCasilla & casilla, char c, bool fija = false);
void dibujaCasilla(const tCasilla & casilla);
bool esSimple(const tCasilla & casilla, int & numero);
void colorFondo(int color);
void annadeElemento(tCasilla& casilla, int e);
void mostrar(const tCasilla& casilla);
void borraElemento(tCasilla& casilla, int e);
bool pertenece(const tCasilla& casilla, int e);


#endif
