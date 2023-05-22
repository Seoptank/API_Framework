#include "Player.h"
#include "Bullet.h"
#include "ObjectManager.h"
#include "InputManager.h"
#include "Prototype.h"


Player::Player()
{

}

Player::~Player()
{

}

GameObject* Player::Start()
{
	transform.position = Vector3(WIDTH * 0.5f, HEIGHT * 0.5f, 0.0f);
	transform.direction = Vector3(0.0f, 0.0f, 0.0f);
	transform.scale = Vector3(100.0f, 100.0f, 0.0f);

	Speed = 5.0f;

	Key = "Player";

	return this;
}

int Player::Update()
{
	//DWORD dwKey = InputManager::GetInstance()->GetKey(); 
	DWORD dwKey = GetSingle(InputManager)->GetKey();

	if (dwKey & KEYID_UP)
		transform.position.y -= Speed;

	if (dwKey & KEYID_DOWN)
		transform.position.y += Speed;

	if (dwKey & KEYID_LEFT)
		transform.position.x -= Speed;

	if (dwKey & KEYID_RIGHT)
		transform.position.x += Speed;

	if (dwKey & KEYID_SPACE)
		ObjectManager::GetInstance()->AddObject( CreateBullet() );

	return 0;
}

void Player::Render(HDC hdc)
{
	Rectangle(hdc,
		int(transform.position.x - (transform.scale.x * 0.5f)),
		int(transform.position.y - (transform.scale.y * 0.5f)),
		int(transform.position.x + (transform.scale.x * 0.5f)),
		int(transform.position.y + (transform.scale.y * 0.5f)));
}

void Player::Destroy()
{

}

GameObject* Player::CreateBullet()
{
	//** ProtoType CreateBullet 함수 구성
	GameObject*protoObj = GetSingle(Prototype)->GetGameObject("Bullet");


	if (protoObj != nullptr)
	{
		GameObject* Object = protoObj->Clone();
		Object->Start();
		Object->SetPosition(transform.position);
		return Object;
	}
	else
		return nullptr;

	//** 이전 CreateBullet 함수 구성
	/*
	GameObject* bullet = new Bullet;
	
	bullet->Start();
	bullet->SetPosition(transform.position);
	
	return bullet;
	*/
}


	
	//★ 오류 로그를 풀력할 수 있는 try chatch문 
	/*
	try 
	{
		if (true)
			throw "zzzzzz";
	}
	catch(string str)
	{
		
	}
	catch(...)   ←다 잡는 놈
	{

	}
	*/