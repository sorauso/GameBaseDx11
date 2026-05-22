#include "TestScene.h"
#include "Engine/Image.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"

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
	if (Input::IsKey(DIK_N))
	{
		//SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");//シーンマネージャーを探してくる//見つからない場合もある
		SceneManager* pSceneManager = (SceneManager*)(this->GetParent());
		pSceneManager->ChangeScene(SCENE_ID_PLAY);//シーンマネージャーに切り替えたいシーンを伝える
	}
}

//描画
void TestScene::Draw()
{
	transform_.position_ = {0,0,0,};
	transform_.scale_ = {1.5f,1.5f,1.0f};//画像の大きさの設定
	Image::SetTransform(hTitlePict_, transform_);//画像の位置や向きの設定
	Image::Draw(hTitlePict_);//画像の描画
}

//開放
void TestScene::Release()
{
}
