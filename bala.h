#ifndef _BALA_H_
#define _BALA_H_

#include <iostream>
#include "game_object.h"

using namespace std;

class Bala : public GameObject {
private:
	int tipo;
public:
	Bala(float origem_x, float origem_y, float destino_x, float destino_y, int tipo);
	void Render();
};

#endif