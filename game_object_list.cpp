#include <iostream>
#include "game_object.h"
#include "game_object_list.h"

using namespace std;

GameObjectList::GameObjectList(){
	this->cabeca = NULL;
}

void GameObjectList::Add(GameObject *elemento){
	No *novo = new No();
	novo->elemento = elemento;
	novo->proximo = NULL;

	if(this->cabeca == NULL){
		this->cabeca = novo;
	}else{
		No *atual = this->cabeca;
		while (atual->proximo != NULL) {
			atual = atual->proximo;
		}
		atual->proximo = novo;
	}
}

void GameObjectList::Render(){
	No *atual = this->cabeca;
	while(atual != NULL){
		atual->elemento->Render();
		atual = atual->proximo;
	}
}