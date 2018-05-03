#include"Game.h"


void Game::Render(){
	window.clear();
	newPlayer->Draw();
	window.display();

}
void Game::Update(sf::Time deltaTime){
	newPlayer->Move(deltaTime);
}
void Game::ProcessEvents(){
	sf::Event event;
	
	while (window.pollEvent(event)) {
		switch (event.type)
		{

		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::KeyPressed:
			newPlayer->HandlePlayerInputs(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			newPlayer->HandlePlayerInputs(event.key.code, false);
			break;
		default:
			break;
		}
	}
}
void Game::Run(){
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (window.isOpen())
	{
				
		sf::Time elapsed = clock.restart();
		std::cout << elapsed.asSeconds() << endl;
		ProcessEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{//[ara garantizarme q corra con la misma cantidad de frames y no haya problemas en colisiones 
			timeSinceLastUpdate -= timePerFrame;
			ProcessEvents();
			Update(timePerFrame);
		
		}
		Update(elapsed);
		Render();
		//clock.restart();
	}
	
}




Game::Game() : window(sf::VideoMode(800, 600), "My window"){
	std::cout << "inicio juego" << endl;

	newPlayer = new Player(&window);
	timePerFrame = sf::seconds(1.f / 60.f);
	

}