#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"), hModel_(-1), hp(50)
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("enemy.fbx");
	assert(hModel_ >= 0);
	transform_.scale_ = { 0.8f,0.8f,0.8f };
	int rx = (rand() % 10) -5;
	int ry = (rand() % 4) - 2;
	transform_.position_ = XMFLOAT3(rx,ry,200);
	SphereCollider* collider = new SphereCollider(XMFLOAT3(0.0f, 0.0f, 0.0f), 0.5f);
	AddCollider(collider);
}

void Enemy::Update()
{
	transform_.position_.z-= 1;
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
	//Instantiate<Enemy>(GetParent());
}

void Enemy::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Bullet")
	{
		pTarget->KillMe();
		KillMe();
	}
}
