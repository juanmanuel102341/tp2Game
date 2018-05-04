#ifndef BULLET_H
#define BULLET_H
#include"Entity.h"

class Bullet: public Entity 
{
public:
	Bullet(int directionx);
//	~Bullet: public ();
	virtual void Initialize();
	virtual void Position(float x, float y);
	virtual void Draw();
	virtual void Move(sf::Time deltaTime);
	virtual void Destroy();
	void Persuit(sf::Vector2f posPlayer);
private:
	int directionx;
};
#endif // !BULLET_H

