#pragma once
#include "GameObject.h"

class Player : public GameObject
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
		return new Player(*this);
		// 기본 복사 생성자 중
		// 나 자신을 복사하는 복사 생성자가 있다.
		// ↑처럼 하면 나 자신을 복사하는 복사 생성자가 만들어짐
	}
public:
	GameObject* CreateBullet();
public:
	Player();
	//생성자의 초기화에서는 class내부에 있는 요소들로만 초기화 가능
	// 복사 생성자를 들고와 조기화
	Player(Transform _transform) : GameObject(_transform) {};
	virtual ~Player();
};

