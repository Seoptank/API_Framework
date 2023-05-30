#pragma once
#include "GameObject.h"

class Player : public GameObject
{

private:
	int dirX;
public:
	virtual GameObject* Start()override;
	virtual int Update()override;
	virtual void Render(HDC hdc)override;
	virtual void Destroy()override;
public:
	virtual GameObject* Clone()override { return new Player(*this); }
public:
	template <typename T>
	GameObject* CreateBullet(string _Key);

	void ChangeAnimation(int _cntY,int _end);
public:
	Player();
	Player(Transform _transform) : GameObject(_transform) {}
	virtual ~Player();
};

