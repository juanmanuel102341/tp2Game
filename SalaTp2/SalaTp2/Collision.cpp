#include"Collision.h"


Collision::Collision(EnemyManager* _enemyManager, Player* _player){
	enemyManager = _enemyManager;
	player = _player;

}
void Collision::CollideBulletEnemy() {

	for (std::list<Entity*>::iterator it = player->listBulletLives.begin(); it != player->listBulletLives.end(); ++it) {
		Entity*eBullet = *it;
		for (std::list<Entity*>::iterator it2 = enemyManager->listLive.begin(); it2 != enemyManager->listLive.end(); ++it2) {
			
			Entity*eEnemy = *it2;
		if(eBullet->sprite.getGlobalBounds().intersects(eEnemy->sprite.getGlobalBounds())){
		
			std::cout << "contacto" << endl;
			eBullet->live = false;
			player->listBulletLives.erase(it);
			eEnemy->live = false;
			enemyManager->listLive.erase(it2);
	
			return;
		}
	}
}

}
void Collision::CollideEnemyPlayer() {
	for (std::list<Entity*>::iterator it =enemyManager->listLive.begin(); it != enemyManager->listLive.end(); ++it) {
		Entity*enemy=*it;
		if (enemy->sprite.getGlobalBounds().intersects(player->sprite.getGlobalBounds())) {
			std::cout << "contacto " << endl;
			player->dead = true;
			enemy->live = false;
			enemyManager->listLive.erase(it);
			return;
		}
	}
}
/*
void Collision::CollideBulletPlayer() {
	for (std::list<Entity*>::iterator it = enemyManager->listLive(); it != enemyManager->listLive.end(); ++it) {
		Entity*enemy = *it;
		if (enemy->sprite.getGlobalBounds().intersects(player->sprite.getGlobalBounds())) {
			std::cout << "contacto " << endl;
			player->dead = true;
			enemy->live = false;
			enemyManager->listLive.erase(it);
			return;
		}
	}
}
*/