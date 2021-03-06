#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_

#include <iostream>
#include <string>

using namespace std;

class GameObject {

protected:
	string nome;
	float posicao_x;
	float posicao_y;
	float velocidade_x;
	float velocidade_y;
	float atrito;
	float vida;
	float forca;
	bool inimigo; //se for 1, é inimigo
	bool atingido;

public:
	GameObject();

	string getNome();
	void setNome(string nome);

	float getPosicao_x();
	void setPosicao_x(float posicao_x);

	float getPosicao_y();
	void setPosicao_y(float posicao_y);

	float getVelocidade_x();
	void setVelocidade_x(float velocidade_x);

	float getVelocidade_y();
	void setVelocidade_y(float velocidade_y);

	float getAtrito();
	void setAtrito(float atrito);

	float getVida();
	void setVida(float vida);

	float getForca();
	void setForca(float forca);

	bool isInimigo();
	void set_isInimigo(bool is);

	bool isAtingido();
	void set_isAtingido(bool is);

	void Update();
	virtual void Render();
	virtual string Tipo();
	virtual GameObject* Atirar(float x, float y);

};

#endif