#pragma once
#include "Include.h"

class GameObject;
class Prototype
{
public:
	Single(Prototype);
private:
	//원본만 필요하기 때문에 list를 사용하지 않음
	map<string, GameObject*> PrototypeObject;
public:
	void Start();

	GameObject* GetGameObject(string _key);

private:
	Prototype();
public:
	~Prototype();
};

