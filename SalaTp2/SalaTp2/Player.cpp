#include "Player.h"

Player::Player() {
	timer = sf::seconds(0.01f);
	velocity = 350;
}
void Player::Draw() {
	
	window->draw(sprite);
	Move();

}
void Player::Move() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&sprite.getPosition().x<750) {
		sprite.move(velocity*timer.asSeconds(), 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&sprite.getPosition().x>0) {
		sprite.move(-velocity*timer.asSeconds(), 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&sprite.getPosition().y<550) {
		sprite.move(0, velocity*timer.asSeconds());
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&sprite.getPosition().y>0) {
		sprite.move(0, -velocity*timer.asSeconds());
	}
		
	
}


void Player::Initialize() {
	if (!texture.loadFromFile("assets/_h.png")) {
		std::cout << "error";
	};
	sprite.setTexture(texture);
	
	//std::cout << "scale x" << sprite.getScale().x <<std::endl;
}
void Player::Position(float x, float y) {
	sprite.setPosition(x, y);
}
void Player::Destroy() {

}