#include"GameManager.h"

void GameManager::Init() {
	basePlayer = new Player();
	basePlayer->window = window;
	basePlayer->Initialize();

}
void GameManager::UpdateDraw(){
	basePlayer->Draw();
}
void GameManager::DestroyEntity() {
	basePlayer->Destroy();
}
GameManager::GameManager() {
	
	
}
