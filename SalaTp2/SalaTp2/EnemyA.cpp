#include"EnemyA.h"

void EnemyA::Initialize(float posx,float posy) {
	if (!texture.loadFromFile("assets/_rept_1.png")) {
		std::cout << "error";
	};
	sprite.setTexture(texture);
	sprite.setPosition(posx, posy);
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
	velocity = 25;
}