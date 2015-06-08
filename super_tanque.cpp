#include <iostream>
#include "super_tanque.h"
#include "bala.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

Super_Tanque::Super_Tanque(){
	this->forca_tiro = 50;
	this->alcance_tiro = 80;
}

void Super_Tanque::Render(){
	ALLEGRO_BITMAP *image = al_load_bitmap("super_tanque.png");
	if(this->velocidade_y>0){
		al_draw_bitmap(image,this->posicao_x,this->posicao_y,0);
	}else{
		al_draw_bitmap(image,this->posicao_x,this->posicao_y,0);
	}
	al_destroy_bitmap(image);
}

string Super_Tanque::Tipo(){
	return "super_tanque";
}

GameObject* Super_Tanque::Atirar(float x, float y){
	GameObject *bala = new Bala(this->posicao_x,this->posicao_y, x, y, 1);
	return bala;
}