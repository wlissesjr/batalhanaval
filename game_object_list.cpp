#include <iostream>
#include "game_object.h"
#include "game_object_list.h"

using namespace std;

GameObjectList::GameObjectList(){
	this->cabeca = NULL;
	this->ultimo = NULL;
	this->tamanho = 0;
}

void GameObjectList::Render(){
	if(this->tamanho <= 0){
		return 0;
	}else{
		No atual = new No;
		atual = this->cabeca->proximo;
		atual->Render();
	}
}