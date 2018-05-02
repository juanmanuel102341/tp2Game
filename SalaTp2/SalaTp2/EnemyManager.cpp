#include"EnemyManager.h"
void EnemyManager::Init(){
	for (int i = 0; i < 30; i++) {
		Entity*e;
		e = new EnemyA();
		e->window = window;
		e->Initialize();
		listDead.push_back(e);
	}
	std::list<Entity*>::iterator it=listDead.begin();
	Entity*e = *it;
	float y = 50 + rand() % 580;
	e->Position(800, y);
	e->live = true;
	listLive.push_back(e);
	/*enemiesA = new EnemyA();
	enemiesA->window = window;
	enemiesA->Initialize();
	enemiesA->Position(300, 300);
	vecA.push_back(enemiesA);
	*/
	}
void EnemyManager::Draw() {
	elapsed= clock.getElapsedTime();
	for(std::list<Entity*>::iterator it = listLive.begin(); it != listLive.end(); ++it) {	
	
		Entity*e=*it;
		e->Draw();
	
	}
	//std::cout<<"tiempo "<<timing
	if (elapsed.asSeconds() > 2) {
		
		listLive.push_back(GetEnemy());
		elapsed = clock.restart();
	}
	TakeOut();
}
Entity* EnemyManager::GetEnemy() {
	for (std::list<Entity*>::iterator it = listDead.begin(); it != listDead.end(); ++it) {
		Entity*e = *it;
		if (!e->live) {
			float y =50+ rand() %   600;
			std::cout << "y " << y<<endl;
			e->Position(800, y);
			e->live = true;
			return e;
		}
	}
}
void EnemyManager::TakeOut() {
	for (std::list<Entity*>::iterator it = listLive.begin(); it != listLive.end(); ++it) {
		Entity*e = *it;
		if (e->sprite.getPosition().x < 0) {
			e->live = false;
			listLive.erase(it);
			break;
		}
	}
	
}

void EnemyManager::SpawnA(){

}
EnemyManager::EnemyManager() {
	srand(time(NULL));
}