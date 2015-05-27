GameObject: game_object.h game_object.cpp
		g++ game_object.cpp -c

Tanque: tanque.h tanque.cpp
	g++ tanque.cpp -c

Teste: teste.cpp GameObject Tanque
	g++ teste.cpp game_object.o tanque.o -o teste -lallegro -lallegro_primitives -lallegro_image
	./teste