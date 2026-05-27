#include "Bullet.h"
#include "Engine/Model.h"
namespace
{
	XMMATRIX xM;
}
Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet"), hModel_(-1),hp(100)
{

}

Bullet::~Bullet()
{
}

void Bullet::Initialize()
{
	hModel_ = Model::Load("bullet.fbx");
	assert(hModel_ >= 0);
	transform_.scale_ = { 0.4f,0.4f,0.8f };
	SphereCollider* collider = new SphereCollider(XMFLOAT3(0.0f, 0.0f, 0.0f), 0.5f);
	AddCollider(collider);

	XMMATRIX Mr =
		XMMatrixRotationRollPitchYaw(
			transform_.rotate_.x,
			transform_.rotate_.y,
			transform_.rotate_.z
		);
	XMMATRIX Mt =
		XMMatrixTranslation(
			0, 0, 1);
	xM = XMMatrixMultiply(Mr,Mt);
}

void Bullet::Update()
{
	XMVECTOR  v = XMVECTOR(transform_.position_.x, transform_.position_.y, transform_.position_.z, 0.0f);
	//transform_.position_.z += 0.4f;
	if (hp < 0)
	{
		KillMe();
	}
	hp--;
}

void Bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Bullet::Release()
{
}
