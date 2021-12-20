#include "Jugador.h"

string toString(tJugador jugador) {
	string nombrePuntos;
	nombrePuntos = jugador.nombre;
	nombrePuntos += " ";
	nombrePuntos += to_string(jugador.puntos);

	return nombrePuntos;
}

void modificarJugador(tJugador & jugador, int puntos) {
	jugador.puntos += puntos;
}

bool operator<(const tJugador & opIzq, const tJugador & opDer) {
  return opIzq.nombre > opDer.nombre;
} 

bool menor(const tJugador & j1, const tJugador & j2) {
	bool menor = false;

	if (j1.puntos < j2.puntos)
	{
		menor = true;
	}
	else if (j1.puntos == j2.puntos && j1 < j2)
	{
		menor = true;
	}
	return menor;
}