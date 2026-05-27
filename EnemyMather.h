#pragma once
#include "Engine/GameObject.h"
class EnemyMather :
    public GameObject
{
public:
    EnemyMather(GameObject* parent);
    ~EnemyMather();
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
};

