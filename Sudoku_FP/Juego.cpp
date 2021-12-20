#include "Juego.h"
#include "ListaJugadores.h"

int menu();

void iniciaJuego(tJuego & juego, const tSudoku & sudoku) {
	juego.lleno = false;
	juego.sudoku.puntos = sudoku.puntos;
	iniciaTablero(juego.tablero);
}
//Inicializar a 0 los puntos del sudoku justo antes de llamar a la funcion

void mostrarJuego(const tJuego & juego) {
	cout << "Nombre: " << juego.sudoku.nombre << endl;
	cout << "Puntos: " << juego.sudoku.puntos << endl;
	dibujarTablero(juego.tablero);
}

bool cargaJuego(tJuego & juego, const tSudoku & sudoku) {
	return cargarTablero(sudoku.nombre, juego.tablero);
}

int jugarUnSudoku(const tSudoku & sudoku) {
	int opcion, fila, col, num, pos = 0, puntos;
	bool existe;
	string id;
	tJuego juego;
	tListaJugadores jugadores;

	iniciaJuego(juego, sudoku);

	if (!cargaJuego(juego, sudoku)) {
		puntos = 0;
		system("pause");
	}
	else {	
		do {
			system("cls");
			cout << sudoku.nombre << "      Puntos: " << sudoku.puntos << "\n\n";
			dibujarTablero(juego.tablero);
			juego.lleno = tableroLleno(juego.tablero);
			if(juego.lleno==false){
				opcion = menu();
			}

			if (opcion == 1) {
				cout << "Introduzca la fila de la casilla: ";
				cin >> fila;
				cout << "Introduzca la columna de la casilla: ";
				cin >> col;
				mostrarPosibles(juego.tablero, fila-1, col-1);
				cout << endl;
				system("pause");
			}
			else if (opcion == 2) {
				cout << "Introduce fila: ";
				cin >> fila;
				cout << endl << "Introduce columna: ";
				cin >> col;
				if (fila <= 9 && fila > 0 && col <= 9 && col > 0) {
					cout << endl << "Introduce numero: ";
					cin >> num;
					if (!ponerNum(juego.tablero, fila - 1, col - 1, num)) {
						cout << "No se puede escribir el numero en esa casilla" << endl;
						system("pause");
					}
				}
				else {
					cout << "Error. Esa posicion no esta en el tablero" << endl;
					system("pause");
				}
			
			}
			else if (opcion == 3) {
				cout << "Introduce fila: ";
				cin >> fila;
				cout << endl << "Introduce columna: ";
				cin >> col;
				if (fila <= 9 && fila > 0 && col <= 9 && col > 0) {
					if (!borrarNum(juego.tablero, fila - 1, col - 1)) {
						cout << "No se puede borrar un numero de esta casilla" << endl;
						system("pause");
					}
				}
				else {
					cout << "Error. Esa posicion no esta en el tablero" << endl;
					system("pause");
				}
			}
			
			else if (opcion == 4) {
				iniciaJuego(juego, sudoku);
				cargaJuego(juego, sudoku);

			}
			else if (opcion == 5) {
				rellenarSimples(juego.tablero);
			}
		
		} while (opcion < 6 && opcion>0 && juego.lleno == false);

		if (opcion == 0) {
			puntos = 0;
		}

		if (juego.lleno == true) {
			cout << "Enhorabuena, has completado el sudoku." << endl;
			puntos = juego.sudoku.puntos;
			cout << "Has conseguido " << puntos << " punto(s)." << endl;
		}
	}

	return puntos;
}

int menu()
{
	int opcion;

	cout << "\n1.- Ver posibles valores de una casilla vacia\n2. - Colocar valor en una casilla\n3. - Borrar valor de una casilla\n4. - Reiniciar el tablero\n5. - Autocompletar celdas simples\n0. - Abortar la resolucion y volver al menu principal " << endl;
	cin >> opcion;
	while (opcion < 0 || opcion>5) {
		cout << "Opcion no valida.Seleccione otra: ";
		cin >> opcion;
	}
	return opcion;
}