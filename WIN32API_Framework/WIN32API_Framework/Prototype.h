#pragma once
#include "Include.h"

class GameObject;
class Prototype
{
public:
	Single(Prototype);
private:
	//������ �ʿ��ϱ� ������ list�� ������� ����
	map<string, GameObject*> PrototypeObject;
public:
	void Start();

	GameObject* GetGameObject(string _key);

private:
	Prototype();
public:
	~Prototype();
};

