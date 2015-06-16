#ifndef _SUPER_TANQUE_H_
#define _SUPER_TANQUE_H_

#include <iostream>
#include "game_object.h"

using namespace std;

class Super_Tanque : public GameObject {

private:
	float forca_tiro;
	float alcance_tiro;

public:
	Super_Tanque();
	void Render();
	string Tipo();
	GameObject* Atirar(float x, float y);
};

#endif