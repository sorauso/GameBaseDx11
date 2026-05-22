#include "ClearScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

ClearScene::ClearScene(GameObject* parent)
	:GameObject(parent, "ClearScene"), hImage_(-1)
{
}

void ClearScene::Initialize()
{
	hImage_ = Image::Load("CLEAR.png");
	assert(hImage_ >= 0);
}

void ClearScene::Update()
{
	if (Input::IsKey(DIK_N))
	{
		SceneManager* sceneManager = (SceneManager*)(this->GetParent());
		sceneManager->ChangeScene(SCENE_ID_TEST);
	}
}

void ClearScene::Draw()
{
	Image::SetTransform(hImage_,transform_);
	Image::Draw(hImage_);
}

void ClearScene::Release()
{
}
