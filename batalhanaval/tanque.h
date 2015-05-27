#ifndef _TANQUE_H_
#define _TANQUE_H_

#include <iostream>
#include "game_object.h"

using namespace std;

class Tanque : public GameObject {

private:
	float forca_tiro;
	float alcance_tiro;

public:
	Tanque();
	void Render();
	string Tipo();
};

#endif