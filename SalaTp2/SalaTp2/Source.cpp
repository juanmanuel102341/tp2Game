//#include"Window.hpp"
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
#include"Player.h"
#include"GameManager.h"
using namespace std;
int main() {
	
	
	
	
	GameManager*gameManager = new GameManager();
	sf::RenderWindow window(sf::VideoMode(gameManager->screenWidth, gameManager->screenHeight), "My window");
	gameManager->window = &window;
	
	gameManager->Init();
	
	sf::Texture textureBack;
	if (!textureBack.loadFromFile("assets/space.png")) {
		std::cout << "error";
	};
    sf::Sprite spriteBack;
	spriteBack.setTexture(textureBack);
	while (window.isOpen())
	{
		sf::Event event;


		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				break;
			default:
				break;
			}
		
		}
		
		window.clear(sf::Color::Black);
		window.draw(spriteBack);
		gameManager->UpdateDraw();
		
		window.display();

	}
	
	return 0;
}
