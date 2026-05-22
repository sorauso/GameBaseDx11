#include "Bullet.h"
#include "Engine/Model.h"

Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet"), hModel_(-1),hp(50)
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
}

void Bullet::Update()
{
	XMMATRIX matRot =
		XMMatrixRotationRollPitchYaw(
			transform_.rotate_.x,
			transform_.rotate_.y,
			transform_.rotate_.z
		);
	XMMATRIX matTrans =
		XMMatrixTranslation(
			0,0,1);
	XMMATRIX M =  matTrans * matRot;
	XMVECTOR  mVectoer = XMLoadFloat3(&transform_.position_);
	XMVECTOR mV2 = XMVector3TransformCoord(mVectoer,M);
	XMStoreFloat3(&transform_.position_, mV2);
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
