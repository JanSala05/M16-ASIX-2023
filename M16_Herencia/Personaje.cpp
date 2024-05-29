#pragma once
#include "Personaje.h"
#include  <iostream>
	//constructor
Personaje::Personaje(int pHp, std::string pName, int pAtaque, int pPosicionX, int pPosicionY) {
	hp = pHp;
	name = pName;
	ataque = pAtaque;
	posicionX = pPosicionX;
	posicionY = pPosicionY;
	}

Personaje::Personaje()
{
}

	//Getters
	int Personaje::getHp() {
		return hp;
	}

	std::string Personaje::getName() {
		return name;
	}

	int Personaje::getAtaque() {
		return ataque;
	}

	int Personaje::getPosicionX()
	{
		return posicionX;
	}

	int Personaje::getPosicionY()
	{
		return posicionY;
	}

	



	//Setters

	void Personaje::setHp(int php) {
		hp = php;
	}

	void Personaje::setName(std::string pname) {
		name = pname;
	}

	void Personaje::setAtaque(int pataque) {
		ataque = pataque;
	}

	void Personaje::setPosicionX(int pPosicionX)
	{
		posicionX = pPosicionX;
	}

	void Personaje::setPosicionY(int pPosicionY)
	{
		posicionY = pPosicionY;

	}

	


	//Metodos propios

	void Personaje::printStatus() {
		std::cout << "El enemigo se llama " << getName() << " con una vida de " << getHp() << std::endl;
 	}