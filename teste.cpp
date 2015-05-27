#include <iostream>
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include "game_object.h"
#include "game_object_list.h"
#include "tanque.h"

using namespace std;

int main(){

	ALLEGRO_DISPLAY *display;

	al_init();
	al_init_image_addon();
	al_init_primitives_addon();
	al_set_new_display_flags(ALLEGRO_WINDOWED);
	display = al_create_display(600, 600);

	GameObjectList *lista = new GameObjectList();

	GameObject *tanque = new Tanque();
	GameObject *basico = new GameObject();

	tanque->setNome("Wlisses");
	tanque->setPosicao_x(20);
	tanque->setPosicao_y(20);
	tanque->setVelocidade_x(0);
	tanque->setVelocidade_y(10);
	tanque->setAtrito(0.09);

	lista->Add(tanque);

	basico->setNome("Wendell");
	basico->setPosicao_x(20);
	basico->setPosicao_y(300);
	basico->setVelocidade_x(0);
	basico->setVelocidade_y(-10);
	basico->setAtrito(0.19);

	lista->Add(basico);

	ALLEGRO_EVENT events;

	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	float fps = 60;
	ALLEGRO_TIMER *timer = al_create_timer(1 / fps);

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_start_timer(timer);

	bool finalizado = false;
	bool draw = false;

	ALLEGRO_COLOR cor = al_map_rgb(0,0,139);

	lista->Render();

	while(!finalizado){
		al_wait_for_event(event_queue, &events);
		if(events.type == ALLEGRO_EVENT_TIMER){
			if(draw){
				draw = false;
				lista->Render();
				al_flip_display();
				al_clear_to_color(al_map_rgb(0,0,0));
			}else{
				tanque->Update();
				basico->Update();
				draw = true;
			}
		}
	}

	al_destroy_display(display);

	return 0;
}