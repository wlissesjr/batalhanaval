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
	void Remove(GameObject *elemento);
	void Render();
	void Update();
	bool Busca(GameObject *elemento);
	GameObject* Mouse_Down(float x, float y);

	void Colisao(GameObject *bala);

};

#endif