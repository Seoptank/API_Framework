#include "Player.h"
#include "Bullet.h"
#include "ObjectManager.h"
#include "InputManager.h"
#include "Protptype.h"
#include "ObjectPool.h"

#include "NormalBullet.h"
#include "GuideBullet.h"
#include "Bitmap.h"



Player::Player()
{

}

Player::~Player()
{

}

GameObject* Player::Start()
{
	frame.cntX = 0;
	frame.cntY = 0;
	frame.endFrame = 7;
	frame.frameTime = 150; // 0.05초


	transform.position = Vector3(WIDTH * 0.5f, HEIGHT * 0.5f, 0.0f);
	transform.direction = Vector3(0.0f, 0.0f, 0.0f);
	transform.scale = Vector3(679/7, 639/9, 0.0f);

	Speed = 5.0f;

	Key = "Player";

	

	Time = GetTickCount64();

	return this;
}

void Player::ChangeAnimation(int _cntY, int _end)
{

	if (dirX >= 0)
	{
		Key = "Player";
	}
	else
	{
		Key = "PlayerFlipX";
	}

	frame.cntY = _cntY;
	frame.endFrame = _end;


	if (Time + frame.frameTime < GetTickCount64())
	{
		Time = GetTickCount64();


		while (frame.cntX < _end)
		{
			++frame.cntX;
		}

		if (frame.cntX == frame.endFrame)
		{
			frame.cntX = 0;
			frame.cntY = _cntY;
		}

	}
	
}

int Player::Update()
{
	ChangeAnimation(0, 7);

	DWORD dwKey = GetSingle(InputManager)->GetKey();

	if (dwKey & KEYID_UP)
	{
		transform.position.y -= Speed;
		ChangeAnimation(1, 7);
	}


	if (dwKey & KEYID_DOWN)
	{
		transform.position.y += Speed;
		ChangeAnimation(1, 7);
	}

	if (dwKey & KEYID_LEFT)
	{
		transform.position.x -= Speed;
		dirX = -1;
		ChangeAnimation(1, 7);

	}

	if (dwKey & KEYID_RIGHT)
	{
		transform.position.x += Speed;
		dirX = 0;
		ChangeAnimation(1, 7);

	}

	if (dwKey & KEYID_SPACE)
	{
		ObjectManager::GetInstance()->AddObject(CreateBullet<NormalBullet>("NormalBullet"));
		ChangeAnimation(5,3);
	}

	if (dwKey & KEYID_CONTROL)
	{
		ObjectManager::GetInstance()->AddObject(CreateBullet<GuideBullet>("GuideBullet"));
		ChangeAnimation(5, 4);
	}
	

	return 0;
}

void Player::Render(HDC hdc)
{
	TransparentBlt(hdc,	  // 복사해 넣을 그림판 ?!
		(int)transform.position.x,	// 복사할 영역 시작점 X
		(int)transform.position.y, 	// 복사할 영역 시작점 Y
		(int)transform.scale.x,	// 복사할 영역 끝부분 X
		(int)transform.scale.y, 	// 복사할 영역 끝부분 Y
		(*m_ImageList)[Key]->GetMemDC(),	// 복사할 이미지 (복사대상)
		transform.scale.x *  frame.cntX,  // 복사할 시작점 X
		transform.scale.y *  frame.cntY,  // 복사할 시작점 Y
		(int)transform.scale.x, 			// 출력할 이미지의 크기 만큼 X
		(int)transform.scale.y,			// 출력할 이미지의 크기 만큼 Y
		RGB(255, 0, 255));		// 해당 색상을 제외

	
}

void Player::Destroy()
{

}


template <typename T>
GameObject* Player::CreateBullet(string _Key)
{
	GameObject* Obj = GetSingle(ObjectPool)->GetGameObject(_Key);

	if (Obj == nullptr)
	{
		Bridge* pBridge = new T;
		pBridge->Start();
		((BulletBridge*)pBridge)->SetTarget(this);

		GameObject* ProtoObj = GetSingle(Protptype)->GetGameObject(_Key);

		if (ProtoObj != nullptr)
		{
			GameObject* Object = ProtoObj->Clone();
			Object->Start();
			Object->SetPosition(transform.position);
			Object->SetKey(_Key);

			pBridge->SetObject(Object);
			Object->SetBridge(pBridge);

			return Object;
		}
		else
			return nullptr;
	}

	Obj->Start();
	Obj->SetPosition(transform.position);
	Obj->SetKey(_Key);

	return Obj;
}