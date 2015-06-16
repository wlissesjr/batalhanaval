Mapa: mapa.h mapa.cpp
	g++ mapa.cpp -c

Bala: bala.h bala.cpp
	g++ bala.cpp -c

GameObject: game_object.h game_object.cpp
	g++ game_object.cpp -c

GameObjectList: game_object_list.h game_object_list.cpp
	g++ game_object_list.cpp -c

Tanque: tanque.h tanque.cpp
	g++ tanque.cpp -c

Soldado: soldado.h soldado.cpp
	g++ soldado.cpp -c

Super_Tanque: super_tanque.h super_tanque.cpp
	g++ super_tanque.cpp -c

Helicoptero: helicoptero.h helicoptero.cpp
	g++ helicoptero.cpp -c

Teste: teste.cpp Mapa GameObject GameObjectList Bala Tanque Soldado Super_Tanque Helicoptero
	g++ teste.cpp mapa.o game_object.o tanque.o soldado.o super_tanque.o helicoptero.o bala.o game_object_list.o -o teste -lallegro -lallegro_primitives -lallegro_image
	./teste