#include "Player.h"

Player::Player() {
	timer = sf::seconds(0.01f);
	velocity = 50;
}
void Player::Draw() {
	
	window->draw(sprite);
	Move();

}
void Player::Move() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		sprite.move(velocity*timer.asSeconds(), 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		sprite.move(-velocity*timer.asSeconds(), 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		sprite.move(0, velocity*timer.asSeconds());
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		sprite.move(0, -velocity*timer.asSeconds());
	}
		
	
}


void Player::Initialize() {
	if (!texture.loadFromFile("assets/_h.png")) {
		std::cout << "error";
	};
	sprite.setTexture(texture);
	sprite.setPosition(100, 100);
	
}
void Player::Destroy() {

}