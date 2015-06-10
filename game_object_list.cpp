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

void GameObjectList::Update(){
	No *atual = this->cabeca;
	while(atual != NULL){
		atual->elemento->Update();
		atual = atual->proximo;
	}
}

void GameObjectList::Colision(){
	No *atual = this->cabeca;
	while (atual->proximo != NULL) {
		atual = atual->proximo;
		if (atual.Tipo() == "bala") {
			No *atual2 = this->cabeca;
			while (atual2->proximo != NULL) {
				atual2 = atual2->proximo;
				if ((atual.getPosicao_x() >= atual2.getPosicao_x() && atual.getPosicao_x() <= atual2.getPosicao_x()+32)
					&& (atual.getPosicao_y() >= atual2.getPosicao_y() && atual.getPosicao_y() <= atual2.getPosicao_y()){
						atual.Colidiu(atual2);
				}
			}
		}
	}
}

void GameObjectList::Remover(GameObject objeto_remover){
	if (objeto_remover.Tipo() != "bala"){
		//só remove
	}
	else{

	}

}

GameObject* GameObjectList::Mouse_Down(float x, float y){
	No *atual = this->cabeca;
	while(atual != NULL){
		if((atual->elemento->getPosicao_x() < x && x < (atual->elemento->getPosicao_x()+32)) && (atual->elemento->getPosicao_y() < y && y < (atual->elemento->getPosicao_y()+32))){
			return atual->elemento;
		}
		atual = atual->proximo;
	}
	return NULL;
}