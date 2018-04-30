#include "Player.h"

Player::Player() {
	
}
void Player::Draw() {
	
	window->draw(sprite);
	Move();

}
void Player::Move() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		sprite.move(1, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		sprite.move(-1, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		sprite.move(0, 1);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		sprite.move(0, -1);
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