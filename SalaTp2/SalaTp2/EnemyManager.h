#ifndef ENEMY_MANAGER_H
#define ENEMY_MANAGER_H
#include<vector>
#include<list>
#include"EnemyA.h"
#include"Entity.h"
#include<SFML/Window.hpp>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;
class EnemyManager
{
public:
	EnemyManager();
	void Init();
	void Draw();
//	~EnemyManager();
	void SpawnA();
	Entity* GetEnemy();
	void TakeOut();
	sf::RenderWindow* window;
	sf::Time elapsed;
	sf::Clock clock;
	Entity* enemiesA;
	std::vector<Entity*>vecA;
	std::list<Entity*>listA;
	
private:

};

#endif // !ENEMY_MANAGER_H

