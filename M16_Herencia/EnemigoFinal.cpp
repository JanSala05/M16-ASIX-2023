#include "EnemigoFinal.h"


//Para hacer la herencia cojemos los valores definidos en la clase EnemigoFinal y añadimos los ataques especiales.

//Constructor de EnemigoFinal
EnemigoFinal::EnemigoFinal(int pHp, std::string pName, int pAtaque, int pPosicionX, int pPosicionY, int pMegaAtaque, int pHiperAtaque) : 
Personaje(pHp, pName, pAtaque, pPosicionX, pPosicionY) { megaAtaque = pMegaAtaque; hiperAtaque = pHiperAtaque;
}

EnemigoFinal::EnemigoFinal()
{
}


//Getters y setters
int EnemigoFinal::getMegaAtaque() {
	return megaAtaque;
}

int EnemigoFinal::getHiperAtaque()
{
	return hiperAtaque;
}

void EnemigoFinal::setMegaAtaque(int pMegaAttack)
{
	megaAtaque = pMegaAttack;
}

void EnemigoFinal::setHiperAtaque(int pHiperAttack)
{
	hiperAtaque = pHiperAttack;
}



//Metodos propios
void EnemigoFinal::printAllStats() {
	cout << "El enemigo final se llama " << getName() << endl;
	cout << "El enemigo final esta a " << getHp() << endl;
	cout << "El ataque basico del enemigo es " << getAtaque() << endl;
	cout << "Su posicion es " << getPosicionX()<<","<<getPosicionY() << endl;
	cout << "El ataque final del enemigo es " << getMegaAtaque() << endl;
	
}