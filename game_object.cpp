#include <iostream>
#include <string>
#include "game_object.h"

using namespace std;

GameObject::GameObject(){
	this->vida = 100;
}

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

float GameObject::getVida(){
	return this->vida;
}
void GameObject::setVida(float vida){
	this->vida = vida;
}

float GameObject::getForca(){
	return this->forca;
}
void GameObject::setForca(float forca){
	this->forca = forca;
}

bool GameObject::isInimigo(){
	return this->inimigo;
}
void GameObject::set_isInimigo(bool is){
	this->inimigo = is;
}

bool GameObject::isAtingido(){
	return this->atingido;
}
void GameObject::set_isAtingido(bool is){
	this->atingido = is;
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

string GameObject::Tipo(){
	return "basico";
}

GameObject* GameObject::Atirar(float x, float y){
	return this;
}