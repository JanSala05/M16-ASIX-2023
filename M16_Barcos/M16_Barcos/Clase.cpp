#pragma once
#include "Clase.h"



int Barcos::getVel()
{
	return velocidad;
}

int Barcos::getDis()
{
	return distancia;
}

bool Barcos::getBoost()
{
	return boost;
}

string Barcos::getName()
{
	return name;
}





void Barcos::setVel(int pVel)
{
	velocidad = pVel;
}

void Barcos::setDis(int pDis)
{
	distancia = pDis;
}

void Barcos::setBoost(bool pBoost)
{
	boost = pBoost;
}

void Barcos::setName(string pName)
{
	name = pName;
}



Barcos::Barcos(int pVel, int pDis, bool pBoost, string pName)
{
	velocidad = pVel;
	distancia = pDis;
	boost = pBoost;
	name = pName;
}

Barcos::Barcos()
{}


void Barcos::printParam()
{
	//Print de todas las variables
	cout << "Velocidad: " << velocidad << ", Distancia: " << distancia << ", Nitro: ";

	//If boost activo
	if (boost)
	{
		cout << "Sí ";
	}
	else cout << "No ";
	cout << "Nombre: " << name;
}

void Barcos::printVelDis()
{
	cout << name << ":\n" << "Velocidad: " << velocidad << ", Distancia: " << distancia << "\n";
}




