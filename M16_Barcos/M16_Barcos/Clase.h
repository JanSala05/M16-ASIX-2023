#pragma once
#include <iostream>
#include <time.h>
using namespace std;


class Barcos {

private:
	//Variables
	int velocidad;
	int distancia;
	bool boost;
	string name;

public:

	//Getters
	int getVel();
	int getDis();
	bool getBoost();
	string getName();

	//Stetters
	void setVel(int pVel);
	void setDis(int pDis);
	void setBoost(bool pNitro);
	void setName(string pNom);

	//Constructor main
	Barcos(int pVel, int pDis, bool pNitro, string pNom);

	//Constructor Vacio
	Barcos();

	//Metodos propios
	void printParam();
	void printVelDis();


};