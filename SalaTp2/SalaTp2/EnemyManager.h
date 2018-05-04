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
#include"Player.h"
class EnemyManager
{
public:
	EnemyManager(Player* _player);
	void Init();
	void Draw();
	void Move(sf::Time deltaTime);
//	~EnemyManager();
	void SpawnA();
	Entity* GetEnemy();
	void TakeOut();
	sf::RenderWindow* window;


	Entity* enemiesA;
	std::list<Entity*>listDead;
	std::list<Entity*>listLive;
	
private:
	sf::Clock clock;
	sf::Time elapsed;
	Player*player;
};

#endif // !ENEMY_MANAGER_H

