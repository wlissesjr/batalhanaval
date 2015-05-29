#include <iostream>
#include "bala.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <cmath>

using namespace std;

Bala::Bala(float origem_x, float origem_y, float destino_x, float destino_y, int tipo){
	this->posicao_x = origem_x+16;
	this->posicao_y = origem_y;
	float cateto_x = destino_x - origem_x;
	float cateto_y = destino_y - origem_y;
	float hipotenuza = sqrt((cateto_x*cateto_x)+(cateto_y*cateto_y));
	if(tipo == 1){
		this->velocidade_x = 0;
		this->velocidade_y = -(hipotenuza/60);
		this->atrito = 0;
	}
}

void Bala::Render(){
	ALLEGRO_COLOR cor = al_map_rgb(255,0,0);
	al_draw_filled_circle(this->posicao_x, this->posicao_y, 3, cor);
}