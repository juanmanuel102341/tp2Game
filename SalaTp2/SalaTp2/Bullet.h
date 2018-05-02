#ifndef BULLET_H
#define BULLET_H
#include"Entity.h"

class Bullet: public Entity 
{
public:
	Bullet();
//	~Bullet: public ();
	virtual void Initialize();
	virtual void Position(float x, float y);
	virtual void Draw();
	virtual void Move();
	virtual void Destroy();
private:

};
#endif // !BULLET_H

