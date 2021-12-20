#ifndef listaSudokus_h
#define listaSudokus_h	

#include "Juego.h"

const int MAX_SUDOKUS = 20;

typedef tSudoku aSudoku[MAX_SUDOKUS];

typedef struct {
	aSudoku sudoku;
	int cont;
}tListaSudokus;

void creaListaVacia(tListaSudokus & lista);
bool cargar(tListaSudokus & lista);
void mostrar(const tListaSudokus & lista);
bool guardar(const tListaSudokus & lista);
bool registrarSudoku(tListaSudokus & lista);
bool buscarFichero(const tListaSudokus & lista, string nombreFich);
int buscarPos(const tListaSudokus & lista, const tSudoku & sudoku);


#endif