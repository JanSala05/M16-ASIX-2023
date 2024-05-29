#pragma once
#include "Personaje.h"
#include <iostream>

using namespace std;

class EnemigoFinal : public Personaje
{
private:
	int megaAtaque;
	int hiperAtaque;
	

public:

	//Constructor con elementos propios y de clase padre
	EnemigoFinal(int pHp, std::string pName, int pAtaque, int pPosicionX, int pPosicionY, int pMegaAtaque, int pHiperAtaque);

	EnemigoFinal();
	//Getters y setters
	int getMegaAtaque();
	int getHiperAtaque();
	

	void setMegaAtaque(int pMegaAtaque);
	void setHiperAtaque(int pHiperAtaque);
	

	//Metodos propios
	void printAllStats();


};

