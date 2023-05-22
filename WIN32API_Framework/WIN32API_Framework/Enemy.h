#pragma once
#include "GameObject.h"

class Enemy : public GameObject
{
public:
	virtual GameObject* Start()override;
	virtual int Update()override;
	virtual void Render(HDC hdc)override;
	virtual void Destroy()override;
public:
	//** 인라인 함수
	virtual GameObject* Clone()override
	{
		return new Enemy(*this);
		// 기본 복사 생성자 중
		// 나 자신을 복사하는 복사 생성자가 있다.
		// ↑처럼 하면 나 자신을 복사하는 복사 생성자가 만들어짐
	}
public:
	Enemy();
	Enemy(Transform _transform) : GameObject(_transform) {};
	virtual ~Enemy();
};

