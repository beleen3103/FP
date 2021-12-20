#ifndef ListaJugadores_h
#define ListaJugadres_h
#include "Jugador.h"

const int TAM_INI = 6;

typedef struct 
{
	tJugadorPtr * jugador;
	int cont;
	int tam;

}tListaJugadores;

void creaListaVacia(tListaJugadores & lista);
bool cargar(tListaJugadores & lista);
void mostrar(const tListaJugadores & lista);
bool guardar(const tListaJugadores & lista);
void puntuarJugador(tListaJugadores & lista, int puntos);
void ordenarPorId(tListaJugadores & lista);
bool buscar(tListaJugadores & lista, string id, int & pos);
tListaJugadores ordenarPorRanking(const tListaJugadores & lista);
void ampliar(tListaJugadores & lista);
void borrarListaJugadores(tListaJugadores & lista);
void crearListaAux(tListaJugadores& lista, const tListaJugadores& listaAux);

#endif
