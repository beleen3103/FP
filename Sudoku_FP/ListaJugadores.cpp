#include "ListaJugadores.h"

void creaListaVacia(tListaJugadores & lista) {

	lista.cont = 0;
	lista.tam = TAM_INI;
	lista.jugador = new tJugadorPtr[lista.tam];

}

bool cargar(tListaJugadores & lista)
{
	ifstream fich;
	bool carga = false;

	fich.open("listaJugadores.txt");
	if (fich.is_open()) {
		carga = true;
		do {
			if (lista.cont == lista.tam) {
				ampliar(lista);
			}
			lista.jugador[lista.cont] = new tJugador();
			fich >> lista.jugador[lista.cont]->nombre >> lista.jugador[lista.cont]->puntos;
			lista.cont++;

		} while (!fich.eof());
	
	}

	fich.close();
	return carga;
}

void mostrar(const tListaJugadores & lista) 
{
	for (int i = 0; i < lista.cont; i++)
	{
		cout <<lista.jugador[i]->nombre << " " << lista.jugador[i]->puntos << endl;
	}
}

bool guardar(const tListaJugadores & lista) {

	ofstream fich;
	int aux;
	bool posible = false;

	fich.open("ListaJugadores.txt");
	if (fich.is_open()) {
		for (int i = 0; i < lista.cont-1; i++) {
			fich << toString(*lista.jugador[i]) << endl;
			aux = i;
		}
		fich << lista.jugador[aux + 1]->nombre << " " << lista.jugador[aux + 1]->puntos;
		posible = true;
	}

	return posible;
}

void puntuarJugador(tListaJugadores & lista, int puntos)
{
	string id;
	tJugador aux;
	int pos = 0;

	cout << "Introduce el identificador: ";
	cin >> id;
	
	if (buscar(lista, id, pos))
	{
		modificarJugador(*lista.jugador[pos], puntos);
	}
	else 
	{
		if(lista.cont == lista.tam)
		{
			ampliar(lista);
		}
		aux.nombre = id;
		aux.puntos = puntos;

		lista.jugador[lista.cont] = new tJugador();
		for (int i = lista.cont; i > pos; i--) {
			*lista.jugador[i] = *lista.jugador[i - 1];
		}
		*lista.jugador[pos] = aux;
		lista.cont++;
	}
}	

bool buscar(const tListaJugadores & lista, string id, int ini, int fin, int& pos) {
	int mitad = (ini + fin) / 2;
	bool existe;

	if (ini > fin) {
		pos = ini;
		existe = false;
	}
	else {
		if (lista.jugador[mitad]->nombre < id) {
			existe = buscar(lista, id, mitad + 1, fin, pos);
		}
		else if (lista.jugador[mitad]->nombre > id) {
			existe = buscar(lista, id, ini, mitad - 1, pos);
		}
		else {
			pos = mitad;
			existe = true;
		}
	}
	return existe;
}
bool buscar(tListaJugadores & lista, string id, int & pos)
{
	bool enc;
	ordenarPorId(lista);
	enc= buscar(lista, id, 0, lista.cont-1, pos);
	
	return enc;
} 

void ordenarPorId(tListaJugadores& lista) {
	tJugador aux;

	for (int i = 0; i < lista.cont - 1; i++) {
		for (int j = i + 1; j < lista.cont; j++) {
			if (lista.jugador[j]->nombre < lista.jugador[i]->nombre) {
				aux = *lista.jugador[i];
				*lista.jugador[i] = *lista.jugador[j];
				*lista.jugador[j] = aux;
			}
		}
	}
}

void crearListaAux(tListaJugadores& lista, const tListaJugadores& listaAux) {

	lista = listaAux;
	for (int i = 0; i < listaAux.cont; i++) {
		
		*lista.jugador[i] = *listaAux.jugador[i];
	}
}



tListaJugadores ordenarPorRanking(const tListaJugadores & listaAux)
{
	tJugadorPtr aux;
	tListaJugadores lista;
	int j;

	crearListaAux(lista, listaAux);

	for (int i = 1; i < lista.cont; i++) {
		aux = lista.jugador[i];
		j = i;
		while (j > 0 && !menor(*aux, *lista.jugador[j - 1])) {
			lista.jugador[j] = lista.jugador[j - 1];
			j--;
		}
		lista.jugador[j] = aux;
	}

	
	return lista;
}

void ampliar(tListaJugadores & lista) {
		
	tJugadorPtr * aux = lista.jugador;
	lista.tam *= 2;
	lista.jugador = new tJugadorPtr[lista.tam];
	for (int i = 0; i < lista.cont; i++) {
		lista.jugador[i] = aux[i];
	}
	delete [] aux;
	//aux = nullptr;		NO ES NECESARIO YA QUE AL ACABARLA FUNCION AUX SE ELIMINA
}


void borrarListaJugadores(tListaJugadores & lista) {
	for (int i = 0; i < lista.cont; i++) {
		delete lista.jugador[i];
		lista.jugador[i] = nullptr;
		
	}
	
	delete[] lista.jugador;
	lista.jugador = nullptr;

	lista.cont = 0;
	lista.tam = 0;
}