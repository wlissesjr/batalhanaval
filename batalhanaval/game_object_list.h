#ifndef _LISTA_H_
#define _LISTA_H_

#include <iostram>
#include <game_object.h>

using namespace std;

class No {
public:
	GameObject *elemento;
	GameObject *proximo;
};

class GameObjectList {

private:
	No cabeca;
	No ultimo;
	int tamanho;

public:
	GameObjectList();
	void Render();

};

#endif