#include "Bullet.h"
#include "Engine/Model.h"

Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet"), hModel_(-1)
{
	ot_.position_ = parent->GetPosition();
}

Bullet::~Bullet()
{
}

void Bullet::Initialize()
{
	hModel_ = Model::Load("Oden.fbx");
	assert(hModel_ >= 0);
	ot_.rotate_.x = 90;
	ot_.scale_ = { 0.2f,0.2f,0.2f };
}

void Bullet::Update()
{
	ot_.position_.z += 0.4f;
}

void Bullet::Draw()
{
	Model::SetTransform(hModel_, ot_);
	Model::Draw(hModel_);
}

void Bullet::Release()
{
}
