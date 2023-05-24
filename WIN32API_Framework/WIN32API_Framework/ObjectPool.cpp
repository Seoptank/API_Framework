#include "ObjectPool.h"
#include "GameObject.h"

ObjectPool::ObjectPool()
{
}
ObjectPool::~ObjectPool()
{
}
void ObjectPool::ReturnObject(GameObject* _object)
{
	map<string, list<GameObject*>>::iterator iter = PoolList.find(_object->GetKey());

	if (iter == PoolList.end())
	{
		// ** map에 포함시킬 list를 생성한후...
		list<GameObject*> tempList;

		// ** 리스트에 오브젝트를 추가.
		tempList.push_back(_object);

		// ** 오브젝트가 추가된 리스트를 map에 추가.
		PoolList.insert(make_pair(_object->GetKey(), tempList));
	}
	// ** 이미 키가 존재 한다면....
	else
		// ** 해당 리스트에 오브젝트를 추가.
		iter->second.push_back(_object);
}


// Enemy와 불렛이 충돌 되었을때 충돌을 확인하고 
// 불렛이 자기 디스트로이
// 리턴 오브젝트 함수 호출
// PoolList에 추가될 수 있게끔
