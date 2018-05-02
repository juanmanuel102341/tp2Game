#include "Player.h"

Player::Player() {
	timer = sf::seconds(0.01f);
	velocity = 350;
	fireRate = 0.3f;

}
void Player::Draw() {
	
	window->draw(sprite);
	for (std::list<Entity*>::iterator it = listBulletLives.begin(); it != listBulletLives.end(); ++it) {
		Entity*e = *it;
		e->Draw();
	}
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
	Atack();
}
void Player::Atack(){
	elapsed = clock.getElapsedTime();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&&elapsed.asSeconds()>fireRate) {
		listBulletLives.push_back(GetBullet());
		elapsed = clock.restart();
	}
	TakeOutBullet();
}

void Player::CreationBullets(){
	for (int i = 0; i < 40;i++) {
		Entity*e;
		e = new Bullet();
		e->window = window;
		e->Initialize();
		listBulletDeads.push_back(e);
	}

}
Entity* Player::GetBullet() {
	for (list<Entity*>::iterator it = listBulletDeads.begin(); it != listBulletDeads.end(); ++it) {
		Entity*e = *it;
		if (!e->live) {
			cout << "position x" << sprite.getPosition().x << endl;
			cout << "position y" << sprite.getPosition().y << endl;
			e->Position(sprite.getPosition().x, sprite.getPosition().y);
			e->live = true;
			return e;

		}
	}
}
void Player::TakeOutBullet(){
	for (std::list<Entity*>::iterator it = listBulletLives.begin(); it != listBulletLives.end(); ++it) {
		Entity*e = *it;
		if (e->sprite.getPosition().x > 800) {
			e->live = false;
			listBulletLives.erase(it);
			break;
		}
	}
}
void Player::Initialize() {
	if (!texture.loadFromFile("assets/_h.png")) {
		std::cout << "error";
	};
	sprite.setTexture(texture);
	CreationBullets();
	//std::cout << "scale x" << sprite.getScale().x <<std::endl;
}
void Player::Position(float x, float y) {
	sprite.setPosition(x, y);
}
void Player::Destroy() {

}