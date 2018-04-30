#ifndef GAME_MANAGER_H

#define GAME_MANAGER_H
#include<SFML/Graphics.hpp>
#include<iostream>
#include<SFML/Window.hpp>
#include"Entity.h"
#include"Player.h"
class GameManager
{
public:
	GameManager();
	void Init();
	void UpdateDraw();
	void DestroyEntity();
	sf::RenderWindow* window;
	Entity*basePlayer;
private:
	

};




#endif // !GAME_MANAGER_H

