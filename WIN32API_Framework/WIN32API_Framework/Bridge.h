#pragma once
#include "Include.h"
// ObjectPool�� GameObject��
// Beidge�� GameObject�� ����
// BulletBridge�� 
class GameObject;
class Bridge
{
protected:
	GameObject* Object;
public:
	virtual void Start()PURE;
	virtual void Update(Transform& transform)PURE;
	virtual void Render(HDC hdc)PURE;
	virtual void Destroy()PURE;

public:
	void SetObject(GameObject* _Object) { Object = _Object; }

public:
	Bridge():Object(nullptr){}
	virtual ~Bridge(){}
};

//** Bridge Pattern(����Ǵ� ����)
//   ��������ִ� �����̴�
//   ex) Enemy�߿����� a,b,c�� ���� �� �ִ�.
//       Update�� Render�� ������ �� a,b,c�� ������ ��� ������?
//	 =>Bridge�� �̰� �ذ��� �� �� �ִ�.
//	 �ڽ��� ������ �ִ� Update�� Render�� �����ؼ� a,b,c�� ���ͼ� ����� �� �ִ�.
//   