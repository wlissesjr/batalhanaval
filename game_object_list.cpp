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

void GameObjectList::Remove(GameObject *elemento){
	No *atual = this->cabeca;
	No *auxiliar;
	if(this->cabeca->elemento->getNome() == elemento->getNome()){
		this->cabeca = this->cabeca->proximo;
	}else{
		while (atual->proximo != NULL) {
			if(atual->proximo->elemento->getNome() == elemento->getNome()){
				auxiliar = atual->proximo;
				if(auxiliar->proximo != NULL){
					atual->proximo = auxiliar->proximo;
					break;
				}else{
					atual->proximo = NULL;
					break;
				}
			}
			atual = atual->proximo;
		}
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
		if(atual->elemento->Tipo()=="bala"){
			this->Colisao(atual->elemento);
		}
		if(atual->elemento->getVida() <= 0){
			this->Remove(atual->elemento);
		}
		if(atual->elemento->getPosicao_x() > 600 || atual->elemento->getPosicao_x() < 0 || atual->elemento->getPosicao_y() > 600 || atual->elemento->getPosicao_y() < 0){
			this->Remove(atual->elemento);
		}
		atual = atual->proximo;
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

void GameObjectList::Colisao(GameObject *bala){
	No *veiculo = this->cabeca;
	while(veiculo->proximo != NULL){
		if((bala->getPosicao_x() >= veiculo->elemento->getPosicao_x() && bala->getPosicao_x() <= veiculo->elemento->getPosicao_x()+32)
			&& (bala->getPosicao_y() >= veiculo->elemento->getPosicao_y() && bala->getPosicao_y() <= veiculo->elemento->getPosicao_y()+32)
			&& bala->getNome() != veiculo->elemento->getNome()){
			float vida = veiculo->elemento->getVida() - bala->getForca();
			this->Remove(bala);
			veiculo->elemento->setVida(vida);
			veiculo->elemento->set_isAtingido(true);
		}
		veiculo = veiculo->proximo;
	}
}