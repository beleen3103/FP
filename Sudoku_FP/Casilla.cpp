#include "Casilla.h"


void iniciaCasilla(tCasilla & casilla) {

	casilla.estado = VACIA;
	cjto_lleno(casilla.c);
	casilla.num = 0;
}
void rellenaCasilla(tCasilla & casilla, char c, bool fija) {
	if (c == ' ')
	{
		casilla.estado = VACIA;
	}
	else {
		if (fija == true)
		{
			cjto_vacio(casilla.c);
			casilla.num = c - 48;
			casilla.estado = FIJA;
		}
		else
		{
			casilla.estado = RELLENADA;
			//borraElemento(casilla.c, c);
			cjto_vacio(casilla.c);
			casilla.num = c;
		}
	}

}
void dibujaCasilla(const tCasilla & casilla) {

	if (casilla.estado == FIJA) {
		colorFondo(1);
	}
	else if (casilla.estado == RELLENADA) {
		colorFondo(4);
	}
	else {
		colorFondo(0);
	}
	
	if (casilla.estado == VACIA) {
		cout << "   ";
	}
	else { cout << " " << casilla.num << " "; }
	

	colorFondo(0);
}
void colorFondo(int color) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, 15 | (color << 4));
}
bool esSimple(const tCasilla & casilla, int & numero) {
	bool simple = false;

	if (casilla.estado == VACIA && simple == false) {
		if (esUnitario(casilla.c, numero)) {
			simple = true;

		}
	}
	return simple;
}

void annadeElemento(tCasilla& casilla, int e) {
	annadeElemento(casilla.c, e);
}

void mostrar(const tCasilla& casilla) {
	mostrar(casilla.c);
}

void borraElemento(tCasilla& casilla, int e) {
	borraElemento(casilla.c, e);
}

bool pertenece(const tCasilla& casilla, int e) {
	return pertenece(casilla.c, e);	
}