#include <iostream>
#include <string>
#include "game_object.h"

using namespace std;

GameObject::GameObject(){}

string GameObject::getNome(){
	return this->nome;
}

void GameObject::setNome(string nome){
	this->nome = nome;
}

float GameObject::getPosicao_x(){
	return this->posicao_x;
}

void GameObject::setPosicao_x(float posicao_x){
	this->posicao_x = posicao_x;
}

float GameObject::getPosicao_y(){
	return this->posicao_y;
}
void GameObject::setPosicao_y(float posicao_y){
	this->posicao_y = posicao_y;
}

float GameObject::getVelocidade_x(){
	return this->velocidade_x;
}
void GameObject::setVelocidade_x(float velocidade_x){
	this->velocidade_x = velocidade_x;
}

float GameObject::getVelocidade_y(){
	return this->velocidade_y;
}
void GameObject::setVelocidade_y(float velocidade_y){
	this->velocidade_y = velocidade_y;
}

float GameObject::getAtrito(){
	return this->atrito;
}
void GameObject::setAtrito(float atrito){
	this->atrito = atrito;
}

void GameObject::Update(){

	this->velocidade_x = this->velocidade_x - (this->velocidade_x*this->atrito);
	this->velocidade_y = this->velocidade_y - (this->velocidade_y*this->atrito);

	this->posicao_x += this->velocidade_x;
	this->posicao_y += this->velocidade_y;

	
}

void GameObject::Render(){
	cout << "Objeto basico!" << endl;
}

GameObject GameObject::Colidiu(GameObject objeto_atingido){
		objeto_atingido.vida -= this->forca;
		objeto_atingido.atingido = true;
		//this->remove();
		return this;
}

string GameObject::Tipo(){
	return "basico";
}

GameObject* GameObject::Atirar(float x, float y){
	return this;
}