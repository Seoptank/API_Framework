#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include "ObjectManager.h"
#include "Prototype.h"

Stage::Stage() : m_pPlayer(nullptr), EnemyList(nullptr), BulletList(nullptr)
{

}

Stage::~Stage()
{
	Destroy();
}

void Stage::Start()
{

	GetSingle(Prototype)->Start();

	{
		//** 유니티로 따지면 프리팹을 들고온 것임
		GameObject* protoObj = GetSingle(Prototype)->GetGameObject("Player");
		

		//** 스크립트 상에서 예외처리 필요
		if (protoObj != nullptr)
		{
			m_pPlayer = protoObj->Clone();
			m_pPlayer->Start();
		}
	}

	{
		GameObject* protoObj = GetSingle(Prototype)->GetGameObject("Enemy");
		
		if (protoObj != nullptr)
		{
			GameObject* Object = protoObj->Clone();
			ObjectManager::GetInstance()->AddObject(Object->Start());
		}
	}
		EnemyList = ObjectManager::GetInstance()->GetObjectList("Enemy");
}

int Stage::Update()
{


	if (m_pPlayer)
		m_pPlayer->Update();

	if (EnemyList != nullptr && !EnemyList->empty())
	{
		for (list<GameObject*>::iterator iter = EnemyList->begin(); iter != EnemyList->end(); ++iter)
			(*iter)->Update();
	}

	if (BulletList != nullptr && !BulletList->empty())
	{
		for (list<GameObject*>::iterator iter = BulletList->begin(); iter != BulletList->end(); ++iter)
			(*iter)->Update();
	}
	else
		BulletList = ObjectManager::GetInstance()->GetObjectList("Bullet");

	return 0;
}

void Stage::Render(HDC hdc)
{
	if (m_pPlayer)
		m_pPlayer->Render(hdc);

	if (EnemyList != nullptr && !EnemyList->empty())
	{
		for (list<GameObject*>::iterator iter = EnemyList->begin(); iter != EnemyList->end(); ++iter)
			(*iter)->Render(hdc);
	}

	if (BulletList != nullptr && !BulletList->empty())
	{
		for (list<GameObject*>::iterator iter = BulletList->begin(); iter != BulletList->end(); ++iter)
			(*iter)->Render(hdc);
	}
}

void Stage::Destroy()
{
	if (m_pPlayer)
	{
		delete m_pPlayer;
		m_pPlayer = NULL;
	}

	if (EnemyList != nullptr && !EnemyList->empty())
	{
		for (list<GameObject*>::iterator iter = EnemyList->begin(); iter != EnemyList->end(); ++iter)
		{
			delete (*iter);
			(*iter) = nullptr;
		}
		EnemyList->clear();
	}

	if (BulletList != nullptr && !BulletList->empty())
	{
		for (list<GameObject*>::iterator iter = BulletList->begin(); iter != BulletList->end(); ++iter)
		{
			delete (*iter);
			(*iter) = nullptr;
		}
		BulletList->clear();
	}
}
