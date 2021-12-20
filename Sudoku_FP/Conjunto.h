#ifndef Conjunto_h
#define Conjunto_h

#include <iostream>
#include <string>
#include <fstream>
#include "checkML.h"

using namespace std;

const int MAX = 9;

typedef struct {
	int cont;
	bool valor[MAX];
}tConjunto;

void cjto_vacio(tConjunto& c);
void cjto_lleno(tConjunto& c);
bool pertenece(const tConjunto & c, int e);
void annadeElemento(tConjunto & c, int e);
void borraElemento(tConjunto & c, int e);
int numElems(const tConjunto & c);
bool esUnitario(const tConjunto & c, int & e);
void mostrar(const tConjunto & c);

#endif

