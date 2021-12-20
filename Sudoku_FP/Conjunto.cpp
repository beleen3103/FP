#include "Conjunto.h"

void cjto_vacio(tConjunto& c) {
	c.cont = 0;
	for (int i = 0; i < MAX; i++) {
		c.valor[i] = false;
	}
}
void cjto_lleno(tConjunto& c) {
	c.cont = MAX;
	for (int i = 0; i < MAX; i++) {
		c.valor[i] = true;
	}
}
bool pertenece(const tConjunto & c, int e) {
	bool pertenece = false;

	if (c.valor[e - 1] == true) {
		pertenece = true;
	}

	return pertenece;
}
void annadeElemento(tConjunto & c, int e) {
	if (c.valor[e - 1] == false)
	{
		c.valor[e - 1] = true;
		c.cont = 0;
		for (int i = 0;i < MAX; i++) {
			if (c.valor[i] == true) {
				c.cont++;
			}
		}
	}
}
void borraElemento(tConjunto & c, int e) {
	c.valor[e - 1] = false;

	c.cont = 0;
	for (int i = 0;i < MAX; i++) {
		if (c.valor[i] == true) {
			c.cont++;
		}
	}
}
int numElems(const tConjunto & c) {
	return c.cont;
}
bool esUnitario(const tConjunto & c, int & e) {
	bool unico = false;
	int n = 0;

	if (c.cont == 1) {
		unico = true;
		while (n < MAX && c.valor[n] == false) {
			n++;
		}
		e = n + 1;
	}

	return unico;
}
void mostrar(const tConjunto & c) {
	for (int i = 0; i < MAX; i++) {
		if (c.valor[i] == true) {
			cout << i + 1 << " ";
		}
	}
}