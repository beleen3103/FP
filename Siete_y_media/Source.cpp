#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int HUMANO = 1;
const int MAQUINA = 2;
int generarMaxCartas();
int determinaGanador(double puntosJugador, double puntosMaquina);
void Menu();
double ModoA();
double ModoB();
double modoBhumano(ifstream&fich, int max_cartas);
double modoBmaquina(ifstream& fich, int max_cartas, float puntosJugador);
float puntuacionesA(ifstream& fich, int max_cartas);
int main()
{
	Menu();

	system("pause");
	return 0;
}

void Menu()
{
	int modo;
	double ModoA();
	cout << "Bienvenido al juego de las 7.5. Escoja el modo que desee jugar:\n1. Modo A\n2. Modo B\n3. Salir" << endl;
	cin >> modo;
	if (modo == 1)
	{
		cout << "Bienvenido al modo A" << endl;
		ModoA();
		system("pause");
		main();
	}
	else if (modo == 2)
	{
		cout << "Bienvenido al modo B" << endl;
		ModoB();
		system("pause");
		main();
	}
	else if (modo == 3)
	{
		cout << "Hasta pronto!" << endl;
	}
	else
	{
		cout << "Opcion incorrecta. Por favor, intentelo de nuevo" << endl;

		system("pause");
		Menu();
	}
}

double ModoA()
{
	bool ganador=true;
	int max_cartas;
	float puntosJugador, puntosMaquina;
	max_cartas = generarMaxCartas();
	string arch;
	ifstream fich;
	cout << "Introduce el nombre del archivo que deseas abrir: ";
	cin >> arch;
	fich.open(arch);
	if (!fich.is_open())
	{
		cout << "Archivo no encontrado. Intentelo de nuevo." << endl;
		ModoA();
	}
	else
	{
		cout << "El numero de cartas que puedes robar es " << max_cartas << "\nEs tu turno." << endl;
		puntosJugador = puntuacionesA(fich,max_cartas);
		cout << "Tu puntuacion es: " << puntosJugador << endl;
		if (puntosJugador > 7.5)
		{
			cout << "Te has pasado. He ganado" << endl;
		}
		else
		{
			cout << "Es mi turno." << endl;
			puntosMaquina = puntuacionesA(fich, max_cartas);
			cout << "Mi puntuacion es " << puntosMaquina << endl;
			ganador = determinaGanador(puntosJugador, puntosMaquina);
			if (ganador == 1)
			{
				cout << "Has ganado" << endl;
			}
			else
			{
				cout << "He ganado" << endl;
			}
		}
	}
	return ganador;
}


double ModoB()
{
	bool ganador=true;
	int max_cartas;
	float puntosJugador, puntosMaquina;
	max_cartas = generarMaxCartas();
	
	string arch;
	ifstream fich;
	cout << "Introduce el nombre del archivo que deseas abrir: ";
	cin >> arch;
	fich.open(arch);
	if (!fich.is_open())
	{
		cout << "Archivo no encontrado. Intentalo de nuevo." << endl;
		system("pause");
		ModoB();
	}
	else
	{
		cout << "El numero de cartas que puedes robar es " << max_cartas << ".\nEs tu turno." << endl;
		puntosJugador = modoBhumano(fich, max_cartas);
		if (puntosJugador > 7.5)
		{
			cout << "Te has pasado. He ganado." << endl;
			ganador = false;
		}
		else
		{
			cout << "Es mi turno." << endl;
			puntosMaquina = modoBmaquina(fich, max_cartas, puntosJugador);
			ganador = determinaGanador(puntosJugador, puntosMaquina);
			if (ganador == 1)
			{
				cout << "Has ganado." << endl;
			}
			else
			{
				cout << "He ganado" << endl;
			}
		}
	}
	return ganador;
}

float puntuacionesA(ifstream& fich, int max_cartas)
{
	double puntuacion = 0;
	for (int i = 0; i < max_cartas; i++)
	{
		int carta;
		fich >> carta;
		cout << "La carta es un " << carta << endl;
		if (carta <= 7)
		{
			puntuacion = puntuacion + carta;
		}
		else
		{
			puntuacion = puntuacion + 0.5;
		}
		cout << "La puntuacion por ahora es de: " << puntuacion << endl;
		system("pause");
	}

	return puntuacion;
}

double modoBhumano(ifstream&fich, int max_cartas)
{
	int i=0;
	float puntuacion=0;
	char n=0;
	while (i<max_cartas&&n!='s')
	{
		int carta;
		fich >> carta;
		cout << "La carta es un " << carta << endl;
		if (carta <= 7)
		{
			puntuacion = puntuacion + carta;
		}
		else
		{
			puntuacion = puntuacion + 0.5;
		}
		cout << "Tu puntuacion por ahora es de: " << puntuacion << ". Quieres plantarte? s/n" << endl;
		cin >> n;
		i++;
	}
	return puntuacion;
}

double modoBmaquina(ifstream&fich, int max_cartas, float puntosJugador)
{
	int i = 0;
	float puntuacion=0;
	while (i < max_cartas && puntuacion < 7.5 && puntuacion < puntosJugador)
	{
		int carta;
		fich >> carta;
		cout << "La carta es un " << carta << endl;
		if (carta <= 7)
		{
			puntuacion = puntuacion + carta;
		}
		else
		{
			puntuacion = puntuacion + 0.5;
		}
		cout << "Mi puntuacion es de " << puntuacion << endl;
		system("pause");
		i++;
	}
	return puntuacion;
}



int determinaGanador(double puntosJugador, double puntosMaquina)
{
	int ganador;
	if (puntosMaquina > 7.5)
	{
		ganador = HUMANO;
	}
	else if (puntosJugador < puntosMaquina)
	{
		ganador = MAQUINA;
	}
	else if (puntosJugador = puntosMaquina)
	{
		cout << "Hemos empatado. Decidiremos aleatoriamente quien gana." << endl;
		srand(NULL);
		ganador = 1+rand()%(3-1);
	}
	else
	{
		ganador = HUMANO;
	}

	return ganador;
}



int generarMaxCartas()
{
	int random;
	srand(time(NULL));
	random = 3 + rand() % (6 - 3);
	return random;
}