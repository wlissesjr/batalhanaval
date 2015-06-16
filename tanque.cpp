#include <iostream>
#include "tanque.h"
#include "bala.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

Tanque::Tanque(){
	this->forca_tiro = 30;
	this->alcance_tiro = 80;
}

void Tanque::Render(){
	ALLEGRO_BITMAP *image = al_load_bitmap("tanque.png");
	if(this->inimigo == 0 || this->atingido == 1){
		al_draw_bitmap(image,this->posicao_x,this->posicao_y,0);
	}
	al_destroy_bitmap(image);
}

string Tanque::Tipo(){
	return "tanque";
}

GameObject* Tanque::Atirar(float x, float y){
	GameObject *bala = new Bala(this->posicao_x,this->posicao_y, x, y, 50);
	return bala;
}