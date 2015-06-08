#include <iostream>
#include "helicoptero.h"
#include "bala.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

Helicoptero::Helicoptero(){
	this->forca_tiro = 40;
	this->alcance_tiro = 80;
}

void Helicoptero::Render(){
	ALLEGRO_BITMAP *image = al_load_bitmap("helicoptero.png");
	if(this->velocidade_y>0){
		al_draw_bitmap(image,this->posicao_x,this->posicao_y,0);
	}else{
		al_draw_bitmap(image,this->posicao_x,this->posicao_y,0);
	}
	al_destroy_bitmap(image);
}

string Helicoptero::Tipo(){
	return "helicoptero";
}

GameObject* Helicoptero::Atirar(float x, float y){
	GameObject *bala = new Bala(this->posicao_x,this->posicao_y, x, y, 1);
	return bala;
}