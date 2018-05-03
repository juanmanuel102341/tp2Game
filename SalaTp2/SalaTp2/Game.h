#ifndef GAME_H
#define GAME_H
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#
#include"Player.h"
class Game
{
public:
	Game();
	void Run();
	

private:
	void ProcessEvents();
	void Update(sf::Time deltaTime);
	void Render();
	sf::RenderWindow window;
	Player* newPlayer;
	
	sf::Time timePerFrame;
	
};
#endif // !GAME_H
