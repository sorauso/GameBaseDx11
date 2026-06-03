#include "Bullet.h"
#include "Engine/Model.h"
namespace
{
	XMVECTOR xM;
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
	XMVECTOR Vt = XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);
	xM = XMVector3TransformNormal(Vt, Mr);
	xM;
}

void Bullet::Update()
{
	float speed = 0.5f;

	XMVECTOR pos = XMLoadFloat3(&transform_.position_);
	pos = XMVectorAdd(pos, XMVectorScale(xM, speed));
	XMStoreFloat3(&transform_.position_, pos);
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
