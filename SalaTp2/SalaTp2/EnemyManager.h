#ifndef ENEMY_MANAGER_H
#define ENEMY_MANAGER_H
#include<vector>
#include"EnemyA.h"
#include"Entity.h"
#include<SFML/Window.hpp>
using namespace std;
class EnemyManager
{
public:
	EnemyManager();
	void Init();
	void Draw();
//	~EnemyManager();
	void SpawnA();
	sf::RenderWindow* window;
	Entity* enemiesA;
private:

};

#endif // !ENEMY_MANAGER_H

