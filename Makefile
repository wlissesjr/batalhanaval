GameObject: game_object.h game_object.cpp
	g++ game_object.cpp -c

GameObjectList: game_object_list.h game_object_list.cpp
	g++ game_object_list.cpp -c

Tanque: tanque.h tanque.cpp
	g++ tanque.cpp -c

Teste: teste.cpp GameObject GameObjectList Tanque
	g++ teste.cpp game_object.o tanque.o game_object_list.o -o teste -lallegro -lallegro_primitives -lallegro_image
	./teste