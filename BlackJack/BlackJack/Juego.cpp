#include <iostream>
#include <time.h>
using namespace std;


int paloCorazones[] = { 1,1,1,1,1,1,1,1,1,1,1,1,1 };//1
int paloDiamantes[] = { 1,1,1,1,1,1,1,1,1,1,1,1,1 };//2
int paloTreboles[] = { 1,1,1,1,1,1,1,1,1,1,1,1,1 };//3
int paloPicas[] = { 1,1,1,1,1,1,1,1,1,1,1,1,1 };//4
int cartaJugador;
int cartaBanca;
int num;
bool banca21 = false;
char jugar = 's';
bool esLaCarta = false;
string palo;
void numeroDeCarta(int& repCartas, string& palo, int& num, char jugar, int& cartaBanca) {

	if (repCartas < 10 && repCartas>0)
	{
		num = repCartas + 1;
		cout << num << " de " << palo << "\n";
	}
	else if (repCartas >= 10)
	{

		num = 10;
		if (repCartas == 10)
		{
			cout << "J de " << palo << "\n";
		}
		else if (repCartas == 11)
		{
			cout << "Q de " << palo << "\n";
		}
		else if (repCartas == 12)
		{
			cout << "K de " << palo << "\n";
		}
	}

	if (repCartas == 0 && jugar == 's')
	{
		do
		{


			cout << "tu AS de " << palo << " es un 1 o un 11\n";
			cin >> num;
			repCartas = num;
			cout << repCartas << " de " << palo << "\n";
		} while (num != 1 && num != 11);
	}
	if (repCartas == 0 && jugar == 'n')
	{
		if (cartaBanca <= 10)
		{
			num = 11;
			repCartas = 11;
		}
		else if (cartaBanca > 10)
		{
			num = 1;
			repCartas = 1;
		}
		cout << "As de " << palo << "\n";
		cout << repCartas << " de " << palo << "\n";
	}


}
void repartirCartas(int& num) {
	int repPalo;
	int repCartas;
	esLaCarta = false;
	do
	{
		repPalo = rand() % 4 + 1;
		repCartas = rand() % 13;

		if (repPalo == 1 && paloCorazones[repCartas] == 1)
		{
			paloCorazones[repCartas] = 0;
			esLaCarta = true;
			palo = "Corazones ";

		}
		if (repPalo == 1 && paloDiamantes[repCartas] == 1)
		{
			paloDiamantes[repCartas] = 0;
			esLaCarta = true;
			palo = "Diamantes ";

		}
		if (repPalo == 1 && paloTreboles[repCartas] == 1)
		{
			paloTreboles[repCartas] = 0;
			esLaCarta = true;
			palo = "Treboles ";

		}
		if (repPalo == 1 && paloPicas[repCartas] == 1)
		{
			paloPicas[repCartas] = 0;
			esLaCarta = true;
			palo = "Picas ";

		}




	} while (esLaCarta = false);
	
	numeroDeCarta(repCartas, palo, num, jugar, cartaBanca);


}


int main() {
	srand(time(NULL));

	cout << "El Blackjack, se juega en base a un sistema de puntos que hace corresponder cada carta de la baraja con un valor numerico determinado 21 es el mejor valor numérico posible que puede obtenerse, y los jugadores deben afanarse para aproximarse lo mas que puedan a dicha cifra, sin pasarse, ya que entonces perderian.\n";

		
		system("pause");
		system("cls");
		
			


			for (size_t i = 0; i < 2; i++)
			{
				repartirCartas(num);
				cartaJugador += num;


			}
			cout << "Tu tienes " << cartaJugador << " puntos\n";
			repartirCartas(num);
			cartaBanca += num;
			cout << "La banca tiene " << cartaBanca << " puntos\n";
			system("pause");
			do
			{
				cout << "Tu tienes " << cartaJugador << " puntos\n";
				cout << "Quieres otra carta?\ns/n\n";
				cin >> jugar;
			} while (jugar != 's' && jugar != 'n');
			while (jugar == 's')
			{
				repartirCartas(num);
				cartaJugador += num;
				if (cartaJugador > 21)
				{

					jugar = 'n';
					cout << "Tu tienes " << cartaJugador << " puntos\n";
					system("pause");
					system("cls");
				}
				else if (cartaJugador < 21)
				{
					do
					{
						cout << "Tu tienes " << cartaJugador << " puntos\n";
						cout << "Quieres otra carta?\ns/n\n";
						cin >> jugar;
					} while (jugar != 's' && jugar != 'n');

				}
			}

			system("cls");
			if (cartaJugador <= 21)
			{
				do
				{
					repartirCartas(num);
					cartaBanca += num;
					cout << "La banca tiene " << cartaBanca << " puntos\n";
					system("pause");
				} while (cartaBanca < cartaJugador && cartaBanca <= 21);
			}
			if (cartaBanca > 21)
			{
				system("cls");
				cout << "Has ganado\n\n";

				system("pause");
				system("cls");
			}
			else {
				system("cls");
				cout << "Has perdido\n\n";

				system("pause");
				system("cls");
			}


		
		
}


