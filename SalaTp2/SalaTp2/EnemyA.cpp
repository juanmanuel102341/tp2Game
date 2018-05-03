#include"EnemyA.h"

void EnemyA::Initialize() {
	if (!texture.loadFromFile("assets/_rept_1.png")) {
		std::cout << "error";
	};
	sprite.setTexture(texture);
}
void EnemyA::Position(float x, float y) {
	sprite.setPosition(x, y);

}
void EnemyA::Draw(){
	window->draw(sprite);
	Move();
}
void EnemyA::Move(){
	sprite.move(-velocity*timer.asSeconds(),0);
}
void EnemyA::Destroy(){

}
EnemyA::EnemyA() {
	timer= sf::seconds(0.01f);
	velocity = 250;
}