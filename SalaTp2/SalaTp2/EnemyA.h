#ifndef ENEMY_A_H
#define ENEMY_A_H
#include"Entity.h"
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
	
private:

};


#endif // !ENEMY_A_H
