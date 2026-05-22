#include "PlayScene.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Player.h"
#include "Enemy.h"
#include "Engine/SceneManager.h"

namespace
{
	float xmova = 10.0f;
	float zmova = 7.0f;
	float yrot = 2.0f;
}

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene"),hModel_(-1),counter_(0)
{
}

void PlayScene::Initialize()
{
	Instantiate<Player>(this);
	Instantiate<Enemy>(this);
}

void PlayScene::Update()
{
	if (FindObject("Enemy") == nullptr)
	{
		SceneManager* sceneManager = (SceneManager*)(this->GetParent());
		sceneManager->ChangeScene(SCENE_ID_CLEAR);
	}
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
