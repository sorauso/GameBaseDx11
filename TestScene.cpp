#include "TestScene.h"
#include "Engine/Image.h"

//コンストラクタ
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene"),hTitlePict_(-1)
{
}

//初期化
void TestScene::Initialize()
{
	hTitlePict_ = Image::Load("TITLE.png");
	assert(hTitlePict_ >= 0);
}

//更新
void TestScene::Update()
{
	
}

//描画
void TestScene::Draw()
{
	Image::SetTransform(hTitlePict_, transform_);
	Image::Draw(hTitlePict_);
}

//開放
void TestScene::Release()
{
}
