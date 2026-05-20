#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Bullet.h"

Player::Player(GameObject* parent)
	:GameObject(parent,"Player"),hModel_(-1)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("Oden.fbx");
	assert(hModel_ >= 0);
	ot_.rotate_.x = 90;
	ot_.position_.y = -4.0f;
}

void Player::Update()
{
	if (Input::IsKey(DIK_A))
	{
		ot_.position_.x -= 0.5f;
	}
	if (Input::IsKey(DIK_D))
	{
		ot_.position_.x += 0.5f;
	}
	if (Input::IsKey(DIK_SPACE))
	{
		Instantiate<Bullet>(this);
	}
	SetPosition(ot_.position_);
}

void Player::Draw()
{
	Model::SetTransform(hModel_,ot_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}
