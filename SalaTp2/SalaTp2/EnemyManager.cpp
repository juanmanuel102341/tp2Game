#include"EnemyManager.h"
void EnemyManager::Init(){
	for (int i = 0; i < 30; i++) {
		Entity*e;
		e = new EnemyA();
		e->window = window;
		e->Initialize();
		vecA.push_back(e);
	}
	std::vector<Entity*>::iterator it=vecA.begin();
	Entity*e = *it;
	float y = 50 + rand() % 580;
	e->Position(800, y);
	e->live = true;
	listA.push_back(e);
	/*enemiesA = new EnemyA();
	enemiesA->window = window;
	enemiesA->Initialize();
	enemiesA->Position(300, 300);
	vecA.push_back(enemiesA);
	*/
	}
void EnemyManager::Draw() {
	elapsed= clock.getElapsedTime();
	for(std::list<Entity*>::iterator it = listA.begin(); it != listA.end(); ++it) {	
	
		Entity*e=*it;
		e->Draw();
	
	}
	//std::cout<<"tiempo "<<timing
	if (elapsed.asSeconds() > 2) {
		
		listA.push_back(GetEnemy());
		elapsed = clock.restart();
	}
	TakeOut();
}
Entity* EnemyManager::GetEnemy() {
	for (std::vector<Entity*>::iterator it = vecA.begin(); it != vecA.end(); ++it) {
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
	for (std::list<Entity*>::iterator it = listA.begin(); it != listA.end(); ++it) {
		Entity*e = *it;
		if (e->sprite.getPosition().x < 0) {
			e->live = false;
			listA.erase(it);
			break;
		}
	}
	
}

void EnemyManager::SpawnA(){

}
EnemyManager::EnemyManager() {
	srand(time(NULL));
}