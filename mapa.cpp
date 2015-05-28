#include <iostream>
#include "mapa.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

using namespace std;

Mapa::Mapa(){
	this->tipo = 1;
	this->largura = 600;
	this->altura = 600;
}

int Mapa::getLargura(){
	return this->largura;
}
int Mapa::getAltura(){
	return this->altura;
}
int Mapa::getTipo(){
	return this->tipo;
}
void Mapa::setLargura(int largura){
	this->largura = largura;
}
void Mapa::setAltura(int altura){
	this->altura = altura;
}
void Mapa::setTipo(int tipo){
	this->tipo = tipo;
}
void Mapa::Render(){
	ALLEGRO_BITMAP *imagemapa = al_load_bitmap("mapa1.png");
	if(this->tipo == 1){
		al_draw_bitmap(imagemapa,0,0,0);
	}
	al_destroy_bitmap(imagemapa);
}