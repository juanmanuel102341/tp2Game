#ifndef ENTITY_H
#define ENTITY_H
#include<SFML/Graphics.hpp>
#include<iostream>
#include<SFML/Window.hpp>
class Entity
{
public:
	Entity();
	virtual void Initialize()=0;
	virtual void Draw()=0;
	virtual void Position(float x, float y)=0;
	virtual void Move()=0;
	virtual void Destroy()=0;
	sf::RenderWindow* window;
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Time timer;
	float velocity;
	bool live = false;
private:

};

#endif // !ENTITY_H
