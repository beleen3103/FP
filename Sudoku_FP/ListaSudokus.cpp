#include "listaSudokus.h"

void creaListaVacia(tListaSudokus & lista) {
	lista.cont = 0;
}

bool cargar(tListaSudokus & lista)
{
	bool carga = false;
	ifstream fich;

	fich.open("listaSudokus.txt");
	
	if (fich.is_open()) {

		carga = true;
		do {
			fich >> lista.sudoku[lista.cont].nombre >> lista.sudoku[lista.cont].puntos;
			lista.cont++;
		} while (!fich.eof());
	}

	fich.close();
	return carga;
}

void mostrar(const tListaSudokus & lista)
{
	for  (int i = 0; i < lista.cont; i++)
	{
		cout << lista.sudoku[i].nombre << " " << lista.sudoku[i].puntos << endl;
	}

}

bool guardar(const tListaSudokus & lista)
{
	ofstream fich;
	bool posible = false;
	int aux;

	fich.open("ListaSudokus.txt");
	if (fich.is_open()) {
		for (int i = 0; i < lista.cont - 1; i++) {
			fich << lista.sudoku[i].nombre << " " << lista.sudoku[i].puntos <<"\n";
			aux = i;
		}
		fich << lista.sudoku[aux + 1].nombre << " " << lista.sudoku[aux + 1].puntos;
		posible = true;
	}

	fich.close();
	return posible;
}

bool registrarSudoku(tListaSudokus & lista)
{
	string nombreFich;
	int puntos, pos, n = 0;
	bool posible = false, existe = false;
	tSudoku sdk, aux;

	cout << "Inserte nombre del sudoku: ";
	cin >> nombreFich;
	cout << endl << "Inserte puntos del sudoku: ";
	cin >> puntos;

	existe = buscarFichero(lista, nombreFich);
	if (!existe && lista.cont < MAX_SUDOKUS) {
		posible = true;
		sdk.nombre = nombreFich;
		sdk.puntos = puntos;

		pos = buscarPos(lista, sdk);

		
		for (int i = lista.cont; i > pos; i--) {
			lista.sudoku[i] = lista.sudoku[i - 1];
		}
		lista.sudoku[pos] = sdk;
		lista.cont++;

		
		guardar(lista);
	}
	else {
		cout << "\nNo es posible registrar el sudoku\n" << endl;
	}
	
	return posible;
}

bool buscarFichero(const tListaSudokus & lista, string nombreFich)
{
	bool encontrado = false;
	int pos = 0;
	while (pos < lista.cont && !encontrado) 
	{
		if (nombreFich == lista.sudoku[pos].nombre) 
		{
			encontrado = true;
		}
		pos++;
	}

	return encontrado;
}

int buscarPos(const tListaSudokus & lista, const tSudoku & sudoku)
{

	int ini = 0, fin = lista.cont - 1, mitad, pos;
	bool encontrado = false;

	while ((ini <= fin) && !encontrado)
	{
		mitad = (ini + fin) / 2;
		if (sudoku.puntos < lista.sudoku[mitad].puntos)
		{
			fin = mitad - 1;
		}
		else if (lista.sudoku[mitad].puntos < sudoku.puntos)
		{
			ini = mitad + 1;
		}
		else
		{
			if (sudoku.nombre < lista.sudoku[mitad].nombre)
			{
				fin = mitad - 1;
			}
			else if (lista.sudoku[mitad].nombre < sudoku.nombre)
			{
				ini = mitad + 1;
			}
			else
			{
				encontrado = true;
			}
		}
	}
	if (encontrado)
	{
		pos = mitad;
	}
	else
	{
		pos = ini;
	}
	return pos;
}
