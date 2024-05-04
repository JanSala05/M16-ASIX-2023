#include "Clase.h"

using namespace std;


//Declaracion variables Main
int velocidad;
int distancia;
bool boost;
string name;



int main()
{
	cout << "Bienvenido!\n";

	//Definimos nombre de nuestro barco
	cout << "Nombra tu barco:\n";
	cin >> name;

	Barcos barcoMio(0, 0, true, name);

	//Definimos nombre de barco contrario

	cout << "Nombra el barco rival:\n";
	cin >> name;

	Barcos barcoTuyo(0, 0, true, name);

	//For para iniciar los 5 turnos
	for (size_t i = 0; i < 5; i++)
	{


		//Inicializamos random
		srand(time(NULL));

		//If para comprobar si quieres boost
		if (barcoMio.getBoost() == true) {
			string askBoost = "";
			//While preguntar boost

			while (askBoost != "s" && askBoost != "n")
			{
				cout << "Quieres utilizar el boost? s/n\n";
				cin >> askBoost;

				if (askBoost == "s")
				{

					//Boost false al usarse
					barcoMio.setBoost(false);
					//Nuestro barco cuenta con un 50% de probabilidades de utilizar el nitro
					int number = rand() % 2;
					//Si velocidad = 0 se duplica sino se divide
					if (number == 0)
					{

						barcoMio.setVel(barcoMio.getVel() * 2);
					}
					else
					{

						barcoMio.setVel(barcoMio.getVel() / 2);
					}
				}

			}
		}

		//Generamos un numero random entre 1 y 6 para los dos barcos
		int dado1 = rand() % 6 + 1;
		int dado2 = rand() % 6 + 1;


		cout << "Press enter para tirar el dado\n";
		system("pause");


		cout << "Tu tiro: " << dado1 << " Tiro del rival: " << dado2 << "\n";

		system("pause");


		//Asignamos la velocidad a cada barco mas la velocidad anterior
		barcoMio.setVel(dado1 + barcoMio.getVel());
		barcoTuyo.setVel(dado2 + barcoMio.getVel());

		//Ajustamos la distancia actual del barco que es la distancia actual mas la velocidad actual
		barcoMio.setDis(barcoMio.getDis() + barcoMio.getVel());
		barcoTuyo.setDis(barcoTuyo.getDis() + barcoTuyo.getVel());

		//Print results
		barcoMio.printVelDis();
		barcoTuyo.printVelDis();
	}

	if (barcoMio.getDis() < barcoTuyo.getDis())
	{
		cout << "Has perdido :[\n";
	}
	else if (barcoMio.getDis() > barcoTuyo.getDis()) {
		cout << "Felicidades, has ganado!\n";
	}
	else
	{
		cout << "Empate.";
	}
}

