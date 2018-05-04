#ifndef ENEMY_A_H
#define ENEMY_A_H
#include"Entity.h"
#include<stdio.h>
#include<math.h>
#include<list>
#include"Bullet.h"
class EnemyA: public Entity
{
public:
	EnemyA();
	//~EnemyA();
	virtual void Initialize();
	virtual void Position(float x, float y);
	virtual void Draw();
	virtual void Move(sf::Time deltaTime);
	virtual void Destroy();
	void Persuit(sf::Vector2f posPlayer);
	list<Entity*>listBulletLives;
	
private:
	sf::Vector2f vecPersuit;
	float propx;
	float propy;
	float distance;
	int directiony = 1;
	list<Entity*>listBulletDeads;
	void CreationBullet();
	Entity*GetBullet();
	void TakeOutBullet();
	void MoveBullets(sf::Time deltaTime);
	float fireRate;
	//sf::Vector2f vecPLayer;
};


#endif // !ENEMY_A_H
