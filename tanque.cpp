#include <iostream>
#include "tanque.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

Tanque::Tanque(){
	this->forca_tiro = 30;
	this->alcance_tiro = 80;
}

void Tanque::Render(){
	ALLEGRO_BITMAP *image = al_load_bitmap("tanque.png");
	if(this->velocidade_y>0){
		al_draw_bitmap(image,this->posicao_x,this->posicao_y,90);
	}else{
		al_draw_bitmap(image,this->posicao_x,this->posicao_y,0);
	}
	al_destroy_bitmap(image);
}

string Tanque::Tipo(){
	return "tanque";
}