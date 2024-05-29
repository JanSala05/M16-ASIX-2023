#pragma once
#include  <iostream>
class Personaje
{

private:
	int hp;
	std::string name;
	int ataque;
	int posicionX;
	int posicionY;

public:
	//Constructor
	Personaje(int pHp, std::string pName, int pAtaque, int pPosicionX, int pPosicionY);
	Personaje();
	//Getters
	int getHp();

	std::string getName();

	int getAtaque();

	int getPosicionX();
	int getPosicionY();

	//Setters

	void setHp(int php);

	void setName(std::string pname);

	void setAtaque(int pattack);

	void setPosicionX(int pPosicionX);
	void setPosicionY(int pPosicionY);

	//Metodos propios

	void printStatus();

};

