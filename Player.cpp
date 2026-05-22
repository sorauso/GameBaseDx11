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
	hModel_ = Model::Load("fiter.fbx");
	assert(hModel_ >= 0);
	transform_.position_.y = -2.0f;
}

void Player::Update()
{
	if (Input::IsKey(DIK_A))
	{
		transform_.position_.x -= 0.1f;
		transform_.rotate_.z += 2;
		if (transform_.rotate_.z > 45)
		{
			transform_.rotate_.z = 45;
		}
	}
	else if (Input::IsKey(DIK_D))
	{
		transform_.position_.x += 0.1f;
		transform_.rotate_.z -= 2;
		if (transform_.rotate_.z < -45)
		{
			transform_.rotate_.z = -45;
		}
	}
	else
	{
		if (transform_.rotate_.z < -2)
		{
			transform_.rotate_.z += 2;
		}
		else if (transform_.rotate_.z > 2)
		{
			transform_.rotate_.z -= 2;
		}
		else
		{
			transform_.rotate_.z = 0;
		}
	}
	if (Input::IsKey(DIK_W))
	{
		transform_.rotate_.x += 2;
		if (transform_.rotate_.x > 45)
		{
			transform_.rotate_.x = 45;
		}
	}
	else if (Input::IsKey(DIK_S))
	{
		transform_.rotate_.x -= 2;
		if (transform_.rotate_.x < -45)
		{
			transform_.rotate_.x = -45;
		}
	}
	else
	{
		if (transform_.rotate_.x < -2)
		{
			transform_.rotate_.x += 2;
		}
		else if (transform_.rotate_.x > 2)
		{
			transform_.rotate_.x -= 2;
		}
		else
		{
			transform_.rotate_.x = 0;
		}
	}
	if (Input::IsKey(DIK_RIGHT))
	{
		transform_.rotate_.y += 2;
		if (transform_.rotate_.y > 45)
		{
			transform_.rotate_.y = 45;
		}
	}
	else if (Input::IsKey(DIK_LEFT))
	{
		transform_.rotate_.y -= 2;
		if (transform_.rotate_.y < -45)
		{
			transform_.rotate_.y = -45;
		}
	}
	else
	{
		if (transform_.rotate_.y < -2)
		{
			transform_.rotate_.y += 2;
		}
		else if (transform_.rotate_.y > 2)
		{
			transform_.rotate_.y -= 2;
		}
		else
		{
			transform_.rotate_.y = 0;
		}
	}
	if (Input::IsKey(DIK_SPACE))
	{
		Bullet* b = Instantiate<Bullet>(GetParent());
		b->SetPosition(transform_.position_);
		b->SetRotate(transform_.rotate_);
	}
	SetPosition(transform_.position_);
}

void Player::Draw()
{
	Model::SetTransform(hModel_,transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}
