#include <iostream>
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include "game_object.h"
#include "game_object_list.h"
#include "tanque.h"
#include "soldado.h"
#include "super_tanque.h"
#include "helicoptero.h"
#include "mapa.h"

using namespace std;

int main(){

	Mapa *mapa = new Mapa(); // Iniciliza o mapa

	ALLEGRO_DISPLAY *display;

	al_init();//Inicializa allegro
	al_init_image_addon();//Inicializa o uso de imagens
	al_init_primitives_addon();//Inicializa o uso de primitivas
	al_install_mouse();//Inicializa o uso do mouse

	al_set_new_display_flags(ALLEGRO_WINDOWED);
	display = al_create_display(mapa->getLargura(), mapa->getAltura());

	

	GameObjectList *lista = new GameObjectList();

	GameObject *tanque1 = new Tanque();
	GameObject *tanque2 = new Tanque();
	GameObject *tanque3 = new Soldado();
	GameObject *tanque4 = new Super_Tanque();
	GameObject *tanque5 = new Helicoptero();

	GameObject *inimigo1 = new Tanque();
	GameObject *inimigo2 = new Tanque();
	GameObject *inimigo3 = new Soldado();
	GameObject *inimigo4 = new Super_Tanque();
	GameObject *inimigo5 = new Helicoptero();

	inimigo1->setNome("inimigo1");
	inimigo1->setPosicao_x(rand()%600);
	inimigo1->setPosicao_y(rand()%300);
	inimigo1->set_isInimigo(true);

	inimigo2->setNome("inimigo2");
	inimigo2->setPosicao_x(rand()%600);
	inimigo2->setPosicao_y(rand()%300);
	inimigo2->set_isInimigo(true);

	inimigo3->setNome("inimigo3");
	inimigo3->setPosicao_x(rand()%600);
	inimigo3->setPosicao_y(rand()%300);
	inimigo3->set_isInimigo(true);

	inimigo4->setNome("inimigo4");
	inimigo4->setPosicao_x(rand()%600);
	inimigo4->setPosicao_y(rand()%300);
	inimigo4->set_isInimigo(true);

	inimigo5->setNome("inimigo5");
	inimigo5->setPosicao_x(rand()%600);
	inimigo5->setPosicao_y(rand()%300);
	inimigo5->set_isInimigo(true);

	GameObject *objetoselecionado = new GameObject();
	GameObject *objetoauxiliar = new GameObject();

	tanque1->setNome("tanque1");
	tanque1->setPosicao_x(80);
	tanque1->setPosicao_y(320);

	tanque2->setNome("tanque2");
	tanque2->setPosicao_x(190);
	tanque2->setPosicao_y(400);

	tanque3->setNome("soldado");
	tanque3->setPosicao_x(270);
	tanque3->setPosicao_y(380);

	tanque4->setNome("supertanque");
	tanque4->setPosicao_x(320);
	tanque4->setPosicao_y(430);

	tanque5->setNome("helicoptero");
	tanque5->setPosicao_x(550);
	tanque5->setPosicao_y(400);

	lista->Add(tanque1);
	lista->Add(tanque2);
	lista->Add(tanque3);
	lista->Add(tanque4);
	lista->Add(tanque5);

	lista->Add(inimigo1);
	lista->Add(inimigo2);
	lista->Add(inimigo3);
	lista->Add(inimigo4);
	lista->Add(inimigo5);

	ALLEGRO_EVENT events;

	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	float fps = 60;
	ALLEGRO_TIMER *timer = al_create_timer(1 / fps);

	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_mouse_event_source());

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
				mapa->Render();
				lista->Render();
				al_flip_display();
				al_clear_to_color(al_map_rgb(0,0,0));
			}else{
				lista->Update();
				draw = true;
			}
		}
		if(events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
			objetoauxiliar = lista->Mouse_Down(events.mouse.x,events.mouse.y);
			if(objetoauxiliar != NULL){
				objetoselecionado = objetoauxiliar;
			}else{
				if(objetoselecionado->Tipo() == "tanque"){
					objetoselecionado = (Tanque*)objetoselecionado;
					objetoauxiliar = objetoselecionado->Atirar(events.mouse.x,events.mouse.y);
				} else if(objetoselecionado->Tipo() == "soldado"){
					objetoselecionado = (Tanque*)objetoselecionado;
					objetoauxiliar = objetoselecionado->Atirar(events.mouse.x,events.mouse.y);
				} else if(objetoselecionado->Tipo() == "super_tanque"){
					objetoselecionado = (Tanque*)objetoselecionado;
					objetoauxiliar = objetoselecionado->Atirar(events.mouse.x,events.mouse.y);
				} else if(objetoselecionado->Tipo() == "helicoptero"){
					objetoselecionado = (Tanque*)objetoselecionado;
					objetoauxiliar = objetoselecionado->Atirar(events.mouse.x,events.mouse.y);
				}
				lista->Add(objetoauxiliar);
			}
		}
	}

	al_destroy_display(display);

	return 0;
}