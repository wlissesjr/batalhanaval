#ifndef _SOLDADO_H_
#define _SOLDADO_H_

#include <iostream>
#include "game_object.h"

using namespace std;

class Soldado : public GameObject {

private:
	float forca_tiro;
	float alcance_tiro;

public:
	Soldado();
	void Render();
	string Tipo();
	GameObject* Atirar(float x, float y);
};

#endif