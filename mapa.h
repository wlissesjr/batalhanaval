#ifndef _MAPA_H_
#define _MAPA_H_

#include <iostream>

class Mapa {

private:
	int largura;
	int altura;
	int tipo;

public:
	Mapa();
	int getLargura();
	int getAltura();
	int getTipo();
	void setLargura(int largura);
	void setAltura(int altura);
	void setTipo(int tipo);
	void Render();

};

#endif