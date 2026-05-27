#include "PlayScene.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Image.h"
#include "Player.h"
#include "EnemyMather.h"
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
	hModel_ = Image::Load("PLAY.png");
	assert(hModel_ >= 0);
	Instantiate<Player>(this);
	Instantiate<EnemyMather>(this);
}

void PlayScene::Update()
{

	if (FindObject("EnemyMather") == nullptr)
	{
		SceneManager* sceneManager = (SceneManager*)(this->GetParent());
		sceneManager->ChangeScene(SCENE_ID_CLEAR);
	}
}

void PlayScene::Draw()
{
	transform_.position_ = { 0,0,0, };
	transform_.scale_ = { 1.0f,1.0f,1.0f };//画像の大きさの設定
	Image::SetTransform(hModel_, transform_);//画像の位置や向きの設定
	Image::Draw(hModel_);//画像の描画
}

void PlayScene::Release()
{
}
