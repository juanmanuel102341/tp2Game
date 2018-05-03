#include "Player.h"

Player::Player(sf::RenderWindow* _window) {
	//timer = sf::seconds(0.01f);
	//velocity = 350;
	//fireRate = 0.3f;
	window = _window;
	Initialize();
}
void Player::HandlePlayerInputs(sf::Keyboard::Key key, bool isPressed) {
	if (key == sf::Keyboard::Up)
		moveUp = isPressed;
	else if (key == sf::Keyboard::Down)
		moveDown = isPressed;
	else if (key == sf::Keyboard::Left)
		 moveLeft= isPressed;
	else if (key == sf::Keyboard::Right)
		moveRight = isPressed;
}
void Player::Draw() {
	
	window->draw(sprite);
	//for (std::list<Entity*>::iterator it = listBulletLives.begin(); it != listBulletLives.end(); ++it) {
		//Entity*e = *it;
		//e->Draw();
	//}
	//Move();

}
void Player::Move(sf::Time deltaTime) {
	sf::Vector2f movement(0.f, 0.f);
	if (moveUp)
		movement.y -= 1.f;
	if (moveDown)
		movement.y += 1.f;
	if (moveLeft)
		movement.x -= 1.f;
	if (moveRight)
		movement.x += 1.f;
	sprite.move(movement*deltaTime.asSeconds());

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
	//CreationBullets();
	//std::cout << "scale x" << sprite.getScale().x <<std::endl;
}
void Player::Position(float x, float y) {
	sprite.setPosition(x, y);
}
void Player::Destroy() {

}