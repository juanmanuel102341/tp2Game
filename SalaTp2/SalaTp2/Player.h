#ifndef PLAYER_H
#define PLAYER_H
#include"Entity.h"
class Player: public Entity 
{
public:
	Player ();
	virtual void Initialize(float posx,float posy);
	virtual void Draw();
	virtual void Move();
	virtual void Destroy();
	
private:
	
	

};
#endif // !PLAYER_H