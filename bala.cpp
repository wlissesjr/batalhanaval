#include <iostream>
#include <string>
#include <sstream>
#include "bala.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <cmath>

using namespace std;

Bala::Bala(float origem_x, float origem_y, float destino_x, float destino_y, int forca){
	this->forca = forca;
	int num = rand()%1000;
	ostringstream convert;
	convert << num;
	this->nome = convert.str();

	this->posicao_x = origem_x+16;
	this->posicao_y = origem_y;

	float cateto_x = destino_x - origem_x;
	float cateto_y = destino_y - origem_y;

	this->velocidade_x = cateto_x/10;
	this->velocidade_y = cateto_y/10;
	this->atrito = 0;
}

void Bala::Render(){
	if (this->inimigo == 0 || (this-> inimigo == 1 && this->atingido == 1)) {
		ALLEGRO_COLOR cor = al_map_rgb(255,0,0);
		
		al_draw_filled_circle(this->posicao_x, this->posicao_y, 3, cor);
	}
}

string Bala::Tipo(){
	return "bala";
}