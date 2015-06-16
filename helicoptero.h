#ifndef _HELICOPTERO_H_
#define _HELICOPTERO_H_

#include <iostream>
#include "game_object.h"

using namespace std;

class Helicoptero : public GameObject {

private:
	float forca_tiro;
	float alcance_tiro;

public:
	Helicoptero();
	void Render();
	string Tipo();
	GameObject* Atirar(float x, float y);
};

#endif