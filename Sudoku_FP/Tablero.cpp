#include "Tablero.h"

void actualiza(tTablero tablero, int fila, int col);

void iniciaTablero(tTablero tablero) {
	for (int fila = 0; fila < MAX_TAM; fila++) {
		for (int col = 0; col < MAX_TAM; col++) {
			iniciaCasilla(tablero[fila][col]);
		}
	}
}

bool cargarTablero(string nombreFichero, tTablero tablero) {
	ifstream fich;
	bool carga;
	string str;

	fich.open(nombreFichero);
	if (!fich.is_open()) {
		carga = false;
		cout << "Archivo no cargado" << endl;
	}
	else {
		carga = true;
		for (int i = 0; i < MAX_TAM; i++) {
			getline(fich, str);

			for (int j = 0; j < str.length(); j++) {

				rellenaCasilla(tablero[i][j], str[j], true);
				actualiza(tablero, i, j);
			}
		}
	}
	fich.close();
	return carga;
}

void dibujarTablero(const tTablero tablero) {
	cout << "  1  2  3   4  5  6   7  8  9  \n";
	cout << " -----------------------------\n";
	for (int i = 0; i < 9; i++)
	{
		cout << "|";
		for (int j = 0; j < 9; j++)
		{
			dibujaCasilla(tablero[i][j]);
			if (j == 2 || j == 5) {
				cout << "|";
			}
		}
		cout << "|  " << i + 1 << "\n";
		if (i == 2 || i == 5) {
			cout << "|-----------------------------|\n";
		}

	}
	cout << " -----------------------------\n";

}

bool ponerNum(tTablero tablero, int fila, int col, int c) {
	bool posible = false;

	if (tablero[fila][col].estado == VACIA && pertenece(tablero[fila][col], c)) {
		posible = true;
		rellenaCasilla(tablero[fila][col], c, false);
		tablero[fila][col].estado = RELLENADA;
		actualiza(tablero, fila, col);
	}

	return posible;

}

bool borrarNum(tTablero tablero, int fila, int col) {
	bool posible = false;
	int x, y;

	if (tablero[fila][col].estado == RELLENADA) {
		posible = true;
		annadeElemento(tablero[fila][col], tablero[fila][col].num);
		rellenaCasilla(tablero[fila][col], ' ', false);
		for (int i = 0; i < MAX_TAM; i++) {
			annadeElemento(tablero[fila][i], tablero[fila][col].num);
		}
		for (int i = 0; i < MAX_TAM; i++) {
			annadeElemento(tablero[i][col], tablero[fila][col].num);
		}
		x = (col / 3) * 3;
		y = (fila / 3) * 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				annadeElemento(tablero[x + i][y + j], tablero[fila][col].num);
			}
		}
		for (int i = 0; i < MAX_TAM; i++)
		{
			for (int j = 0; j < MAX_TAM; j++)
			{
				if (tablero[i][j].estado == VACIA)
				{
					cjto_lleno(tablero[i][j].c);
				}
			}
		}
		for (int i = 0; i < MAX_TAM; i++)
		{
			for (int j = 0; j < MAX_TAM; j++)
			{
				if (tablero[i][j].estado != VACIA)
				{
					actualiza(tablero, i, j);
				}
			}
		}
	}
	


	return posible;
}

bool tableroLleno(const tTablero tablero) {
	int fila = 0, columna = 0;
	bool lleno = true;

	while (fila < MAX_TAM && lleno) {
		while (columna < MAX_TAM && lleno) {
			if (tablero[fila][columna].estado == VACIA) {
				lleno = false;
			}
			columna++;
		}
		columna = 0;
		fila++;
	}

	return lleno;
}

void mostrarPosibles(const tTablero tablero, int fila, int col) {
	if (tablero[fila][col].estado == VACIA) {
		cout << "Numeros posibles: ";
		mostrar(tablero[fila][col]);
	}
	else
	{
		cout << "\nNo es una casilla vacia" << endl;
	}
}

void rellenarSimples(tTablero tablero) {
	int numero, fila, col;
	bool valorUnico;

	for (int i = 0; i < MAX_TAM; i++) {
		for (int j = 0; j < MAX_TAM; j++) {
			valorUnico = esSimple(tablero[i][j], numero);
			if (valorUnico == true) {
				tablero[i][j].num = numero;
				tablero[i][j].estado = RELLENADA;
				fila = i;
				col = j;
				
				actualiza(tablero, fila, col);

			}
		}
	}

}

void actualiza(tTablero tablero, int fila, int col) {
	int x, y;

	for (int i = 0; i < MAX_TAM; i++) {
		borraElemento(tablero[fila][i], tablero[fila][col].num);
	}
	for (int i = 0; i < MAX_TAM; i++) {
		borraElemento(tablero[i][col], tablero[fila][col].num);
	}
	y = (col / 3) * 3;
	x = (fila / 3) * 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			borraElemento(tablero[x + i][y + j], tablero[fila][col].num);
		}
	}

}