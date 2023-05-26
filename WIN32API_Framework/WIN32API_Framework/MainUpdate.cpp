#include "MainUpdate.h"
#include "SceneManager.h"
#include "InputManager.h"


MainUpdate::MainUpdate()
{

}

MainUpdate::~MainUpdate()
{
	Destroy();
}


void MainUpdate::Start()
{
	m_hdc = GetDC(g_hWnd); // m_이 붙어 있으면 namespace를 먼저 본다. namespace꺼임

	SceneManager::GetInstance()->SetScene(LOGO);
}

void MainUpdate::Update()
{
	GetSingle(InputManager)->CheckKey();
	//InputManager::GetInstance()->CheckKey();

	SceneManager::GetInstance()->Update();
}

void MainUpdate::Render()
{
	SceneManager::GetInstance()->Render(m_hdc);//<-DC를 받아온다.
}

void MainUpdate::Destroy()
{
	
}
