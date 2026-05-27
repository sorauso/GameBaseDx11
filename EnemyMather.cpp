#include "EnemyMather.h"
#include "Enemy.h"
namespace
{
	int counter;
}

EnemyMather::EnemyMather(GameObject* parent)
	:GameObject(parent, "EnemyMather")
{
}

EnemyMather::~EnemyMather()
{
}

void EnemyMather::Initialize()
{
	counter = 0;
}

void EnemyMather::Update()
{
	if (counter > (rand() % 90)+30)
	{
		Instantiate<Enemy>(this);
		counter = 0;
	}
	else
	{
		counter++;
	}
}

void EnemyMather::Draw()
{
}

void EnemyMather::Release()
{
}
