#include <iostream>
#include <time.h>
#include "Personaje.h"
#include "EnemigoFinal.h"


//Con creacionTablero cojemos los parametros de mapa y moves para poder printear por pantalla el tablero dependiendo los numeros puestos en el mapa se printeara un tablero u otro.
void creacionTablero(string moves[3], int mapa[5][5]) {
	
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			if (mapa[i][j] == 0 || mapa[i][j] == 2 || mapa[i][j] == 1)
			{
				cout << moves[0];
			}
			
			else if (mapa[i][j] == 3)
			{
				cout << moves[1];
			}
			else 
			{
				cout << moves[2];
			}
		}
		cout << "\n";
	}
}


int main() {
	srand(time(NULL));
	//Variables
	int num;

	int mapa[5][5];
	//Creacion de lo necesario para el tablero
	//Espacio sin ver o vacio: "?" espacio del jugador "-" espacio con enemigo "!".
	string moves[3] = { " ? "," - "," ! "};


	//Creamos 4 enemigos basicos y un enemigo final esperandonos al final del tablero
	Personaje heroe(1500,"Jan",150,4,0);
	Personaje enemigo1(150,"Martillo",50,1,0);
	Personaje enemigo2(150,"Pildora",30,2,0);
	Personaje enemigo3(160,"Bola",20,3,0);
	Personaje enemigo4(305,"Clavo",15,4,0);
	EnemigoFinal boss(1000, "Malo", 150, 0, 0,300,400);
	//Los espacios sin explorar son 0, los enemigos son 1 y el enemigo final es 2
	//Primero de todo se rellena la array de 0 para printear el tablero y despues se añaden los enemigos
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			mapa[i][j] = 0;
			
		}
	}
	//Ahora ponemos un enemigo en cada fila y en columnas aleatorias y les iremos dando valor a todos los personajes
	
	//Enemigo 1
		num = rand() % 5;
		mapa[1][num] = 1;
		enemigo1.setPosicionY(num);
	//Enemigo 2
		num = rand() % 5;
		mapa[2][num] = 1;
		enemigo2.setPosicionY(num);
	//Enemigo 3
		num = rand() % 5;
		mapa[3][num] = 1;
		enemigo3.setPosicionY(num);
	//Enemigo 4
		num = rand() % 5;
		mapa[4][num] = 1;
		enemigo4.setPosicionY(num);
	
	//Al enemigo final lo vamos a poner en la ultima fila que es el 0 en el array
		num = rand() % 5;
		mapa[0][num] = 2;
		boss.setPosicionY(num);
	
	//Colocamos al jugador en la primera fila del tablero y usaremos el 3 como posicion inicial.
	do
	{
		
		if (true)
		{
			num = rand() % 5;
			if (mapa[4][num] ==0)
			{
				mapa[4][num] = 3;
				heroe.setPosicionY(num);
			}
		}
	} while (mapa[4][num] !=3);

	
	bool final = false;
	while (!final)
	{

		for (size_t i = 0; i < 5; i++)
		{
			
			cout << "\n";
		}

		//Creamos el tablero mediante la funcion
		creacionTablero(moves, mapa);
		//Seleccionamos a donde movernos mediante wasd
		cout << "Te mueves con wasd\n";
		char letra;
		cin >>  letra;
		int x = heroe.getPosicionX();
		int y = heroe.getPosicionY();
		
		int antX = x;
		int antY = y;
		//Creamos una segunda condicion para que no se salga de la pantalla al movernos
		
		if (letra == 's' && x !=4 )
		{
			x += 1;
		}
		else if (letra == 'w' && x!=0  )
		{
			x -= 1;
		}
		else if (letra == 'd'  && y !=4 )
		{
			y += 1;
		}
		else if (letra == 'a' && y!=0  )
		{
			y -= 1;
		}
		else
		{
			cout << "movimiento no posible";
		}
		
		
		
		//Comprovamos si hay enemigos en la casilla
		if (mapa[x][y]==0)
		{
			mapa[x][y] = 3;
			mapa[antX][antY] = 0;
		
		}
		else if (mapa[x][y] == 1 || mapa[x][y] == 2)
		{
			if (mapa[x][y] == 2) {

				final = true;
			}

			mapa[x][y] = 4;
			mapa[antX][antY] = 0;

		}
		
			
		heroe.setPosicionX(x);
		heroe.setPosicionY(y);



		system("cls");
	}







	

}