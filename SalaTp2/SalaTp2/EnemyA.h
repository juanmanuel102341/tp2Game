#ifndef ENEMY_A_H
#define ENEMY_A_H
#include"Entity.h"
class EnemyA: public Entity
{
public:
	EnemyA();
	//~EnemyA();
	virtual void Initialize(float posx,float posy);
	virtual void Draw();
	virtual void Move();
	virtual void Destroy();
private:

};


#endif // !ENEMY_A_H
