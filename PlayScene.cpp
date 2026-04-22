#include "PlayScene.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

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
	hModel_ = Model::Load("Oden.fbx");
	assert(hModel_ >= 0);
}

void PlayScene::Update()
{
	counter_ += 1.0f;
	if (Input::IsKey(DIK_A))
	{
		xmova++;
	}
	if (Input::IsKey(DIK_D))
	{
		xmova--;
		if (xmova < 0)
		{
			xmova = 0;
		}
	}
	if (Input::IsKey(DIK_W))
	{
		zmova--;
		if (zmova < 0)
		{
			zmova = 0;
		}
	}
	if (Input::IsKey(DIK_S))
	{
		zmova++;
	}
	if (Input::IsKey(DIK_Q))
	{
		yrot++;
	}
	if (Input::IsKey(DIK_E))
	{
		yrot--;
		if (yrot < 0)
		{
			yrot = 0;
		}
	}



	ot_.position_ = { cosf(counter_ / 50) * xmova,-2,(sinf(counter_ / 50) * zmova) + 10 };
	ot_.scale_ = { 1.0f,sinf(counter_ / 40) + 1.1f,1.0f };
	ot_.rotate_ = { 0,counter_ * yrot,0 };
}

void PlayScene::Draw()
{
	Model::SetTransform(hModel_, ot_);
	Model::Draw(hModel_);
}

void PlayScene::Release()
{
}
