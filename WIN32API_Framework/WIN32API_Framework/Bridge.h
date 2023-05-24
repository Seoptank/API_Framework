#pragma once
#include "Include.h"
// ObjectPool의 GameObject와
// Beidge의 GameObject는 같고
// BulletBridge는 
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

//** Bridge Pattern(연결되는 과정)
//   연결시켜주는 패턴이다
//   ex) Enemy중에서도 a,b,c가 있을 수 있다.
//       Update와 Render을 실행할 때 a,b,c를 구분을 어떻게 지을까?
//	 =>Bridge가 이걸 해결해 줄 수 있다.
//	 자신이 가지고 있는 Update와 Render을 실행해서 a,b,c를 들고와서 사용할 수 있다.
//   