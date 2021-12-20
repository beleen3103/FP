//Belen Garcia Puente
//Silvia Egido Diaz

#include"listaSudokus.h"
#include "listaJugadores.h"
#include "checkML.h"

int menu1();
void title();
void salir();

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	tSudoku sudoku;
	tListaSudokus lista;
	tListaJugadores listaJ;
	int opcion, pos = 0, puntos;
	bool encontrado = false;


	title();
	
	creaListaVacia(listaJ);

	if (!cargar(listaJ)) {
		cout << "No se ha cargado el fichero de jugadores" << endl;
	}

	creaListaVacia(lista);
	if (!cargar(lista)) {
		cout << "No se ha cargado el archivo de sudokus" << endl;
	}

	do
	{
		opcion = menu1();
		if (opcion == 1) {
			mostrar(lista);

			cout << "Elige un sudoku: ";
			cin >> sudoku.nombre;
			if (!buscarFichero(lista, sudoku.nombre)) {
				cout << "\nError. Fichero no encontrado\n" << endl;
				system("pause");
				system("cls");
			}
			else {
				while (!encontrado && sudoku.nombre != lista.sudoku[pos].nombre) {
					pos++;
				}
				sudoku.puntos = lista.sudoku[pos].puntos;
				puntos = jugarUnSudoku(sudoku);
				if (puntos != 0) {
					puntuarJugador(listaJ, puntos);
				}
				if (guardar(listaJ)) {
					cout << "Datos guardados con exito" << endl;
				}
				system("cls");
			}
		}
		else if (opcion == 2)
		{
			ordenarPorId(listaJ);
			mostrar(listaJ);
			
			system("pause");
			system("cls");
		}
		else if (opcion == 3) 
		{
			mostrar(ordenarPorRanking(listaJ));
		
			borrarListaJugadores(listaJ);
			creaListaVacia(listaJ);
			cargar(listaJ);
			system("pause");
			system("cls");
		}
		else if(opcion == 4)
		{
			if (registrarSudoku(lista)) {
				cout << "\nEl sudoku fue registrado\n" << endl;
			}
			system("pause");
			system("cls");
		}
	} while (opcion > 0 && opcion < 5);

	if (opcion == 0) {

		salir();
	}

	borrarListaJugadores(listaJ);
	
	
	system("pause");
	return 0;
}

void title() {
	string title = R"(				 _______           ______   _______  _                
				(  ____ \|\     /|(  __  \ (  ___  )| \    /\|\     /|
				| (    \/| )   ( || (  \  )| (   ) ||  \  / /| )   ( |
				| (_____ | |   | || |   ) || |   | ||  (_/ / | |   | |
				(_____  )| |   | || |   | || |   | ||   _ (  | |   | |
				      ) || |   | || |   ) || |   | ||  ( \ \ | |   | |
				/\____) || (___) || (__/  )| (___) ||  /  \ \| (___) |
				\_______)(_______)(______/ (_______)|_/    \/(_______)
)";

	string authors = R"(                                                                                                                      
 _____        _    _____     _            _____             _               _____ _ _     _        _____     _   _     
| __  |_ _   |_|  | __  |___| |___ ___   |   __|___ ___ ___|_|___    _ _   |   __|_| |_ _|_|___   |   __|___|_|_| |___ 
| __ -| | |   _   | __ -| -_| | -_|   |  |  |  | .'|  _|  _| | .'|  | | |  |__   | | | | | | .'|  |   __| . | | . | . |
|_____|_  |  |_|  |_____|___|_|___|_|_|  |_____|__,|_| |___|_|__,|  |_  |  |_____|_|_|\_/|_|__,|  |_____|_  |_|___|___|
      |___|                                                         |___|                               |___|          

)";
	system("color D");
	cout << title << "\n" << authors << "\n";
	cout << "Presiona Enter para acceder al sudoku: ";
	cin.get();

	system("color 07");
	system("cls");

}

void salir() {
	string str = R"(                                                  __ 
 _____         _                          _      |  |
|  |  |___ ___| |_ ___    ___ ___ ___ ___| |_ ___|  |
|     | .'|_ -|  _| .'|  | . |  _| . |   |  _| . |__|
|__|__|__,|___|_| |__,|  |  _|_| |___|_|_|_| |___|__|
                         |_|                        
)";
	cout << str;
}

int menu1() {
	int opcion;

	cout << "1.- Jugar\n2.- Ver jugadores ordenados por identificador\n3.- Ver jugadores ordenados por puntos\n4.- Incorporar sudoku\n0.- Salir" << endl;
	cin >> opcion;
	while (opcion < 0 || opcion > 4) {
		cout << "Opcion no valida. Seleccione otra: ";
		cin >> opcion;
	}

	return opcion;
}