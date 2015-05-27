#include <iostream>
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include "game_object.h"
#include "tanque.h"

using namespace std;

int main(){

	ALLEGRO_DISPLAY *display;

	al_init();
	al_init_image_addon();
	al_init_primitives_addon();
	al_set_new_display_flags(ALLEGRO_WINDOWED);
	display = al_create_display(600, 600);

	Tanque *tanque = new Tanque();
	Tanque *tanque2 = new Tanque();

	tanque->setNome("Wlisses");
	tanque->setPosicao_x(20);
	tanque->setPosicao_y(20);
	tanque->setVelocidade_x(0);
	tanque->setVelocidade_y(10);
	tanque->setAtrito(0.1);

	tanque2->setNome("Wlisses");
	tanque2->setPosicao_x(20);
	tanque2->setPosicao_y(300);
	tanque2->setVelocidade_x(0);
	tanque2->setVelocidade_y(-10);
	tanque2->setAtrito(0.2);

	ALLEGRO_EVENT events;

	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	float fps = 60;
	ALLEGRO_TIMER *timer = al_create_timer(1 / fps);

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_start_timer(timer);

	bool finalizado = false;
	bool draw = false;

	ALLEGRO_COLOR cor = al_map_rgb(0,0,139);

	while(!finalizado){
		al_wait_for_event(event_queue, &events);
		if(events.type == ALLEGRO_EVENT_TIMER){

			if(draw){
				draw = false;
				tanque->Render();
				tanque2->Render();
				al_flip_display();
				al_clear_to_color(al_map_rgb(0,0,0));
			}else{
				tanque->Update();
				tanque2->Update();
				draw = true;
			}
		}
	}

	al_destroy_display(display);

	return 0;
}