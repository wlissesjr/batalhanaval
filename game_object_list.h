#ifndef _LISTA_H_
#define _LISTA_H_

#include <iostream>
#include "game_object.h"

using namespace std;

class No {
public:
	GameObject *elemento;
	No *proximo;
};

class GameObjectList {

private:
	No *cabeca;

public:
	GameObjectList();
	void Add(GameObject *elemento);
	void Render();

};

#endif