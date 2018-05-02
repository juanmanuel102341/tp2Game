#ifndef PLAYER_H
#define PLAYER_H
#include"Entity.h"
#include<list>
#include"Bullet.h"
using namespace std;
class Player: public Entity 
{
public:
	Player ();
	virtual void Initialize();
	virtual void Position(float x, float y);
	virtual void Draw();
	virtual void Move();
	virtual void Destroy();
	
private:
	void Atack();
	void CreationBullets();
	Entity*GetBullet();
	void TakeOutBullet();
	sf::Clock clock;
	sf::Time elapsed;
	float fireRate;
	list<Entity*>listBulletDeads;
	list<Entity*>listBulletLives;
};
#endif // !PLAYER_H