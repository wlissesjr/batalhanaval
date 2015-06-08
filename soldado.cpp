#include <iostream>
#include "soldado.h"
#include "bala.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

Soldado::Soldado(){
	this->forca_tiro = 10;
	this->alcance_tiro = 80;
}

void Soldado::Render(){
	ALLEGRO_BITMAP *image = al_load_bitmap("soldado.png");
	if(this->velocidade_y>0){
		al_draw_bitmap(image,this->posicao_x,this->posicao_y,0);
	}else{
		al_draw_bitmap(image,this->posicao_x,this->posicao_y,0);
	}
	al_destroy_bitmap(image);
}

string Soldado::Tipo(){
	return "soldado";
}

GameObject* Soldado::Atirar(float x, float y){
	GameObject *bala = new Bala(this->posicao_x,this->posicao_y, x, y, 1);
	return bala;
}