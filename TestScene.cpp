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
	
}

//更新
void TestScene::Update()
{
	if (1)
	{
		//SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");//シーンマネージャーを探してくる//見つからない場合もある
		SceneManager* pSceneManager = (SceneManager*)(this->GetParent());
		pSceneManager->ChangeScene(SCENE_ID_TITLE);//シーンマネージャーに切り替えたいシーンを伝える
	}
}

//描画
void TestScene::Draw()
{
	
}

//開放
void TestScene::Release()
{
}
