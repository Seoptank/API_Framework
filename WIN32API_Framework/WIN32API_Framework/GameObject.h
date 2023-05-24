#pragma once
#include "Include.h"

class Bridge;
class GameObject
{
protected:
	Transform transform;
	float Speed;

	string Key;

	Bridge* bulletBridge;
public:
	virtual GameObject* Start()PURE;
	virtual int Update()PURE;
	virtual void Render(HDC hdc)PURE;
	virtual void Destroy()PURE;
public:
	virtual GameObject* Clone()PURE;
	//overrride: 부모 함수를 재정의
public:
	string GetKey()const { return Key; }
	GameObject* SetKey(const string& _key)
	{
		Key = _key;
		return  this;
	}

	Transform GetTransform()const { return transform; }

	Vector3 GetPosition()const { return transform.position; }
	void SetPosition(const Vector3& _position) { transform.position = _position; }

	Vector3 GetScale()const { return transform.scale; }
	void SetScale(const Vector3& _scale) { transform.scale = _scale; }

	void SetBridge(Bridge* _bridge) { bulletBridge = _bridge; }
public:
	GameObject();
	GameObject(Transform _transform) :transform(_transform), Speed(0.0f) {};
	virtual ~GameObject();
};