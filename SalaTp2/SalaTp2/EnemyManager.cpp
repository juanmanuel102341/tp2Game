#include"EnemyManager.h"
void EnemyManager::Init(){
	enemiesA = new EnemyA();
	enemiesA->window = window;
	enemiesA->Initialize(400,100);
}
void EnemyManager::Draw() {
	enemiesA->Draw();
}
void EnemyManager::SpawnA(){

}
EnemyManager::EnemyManager() {

}