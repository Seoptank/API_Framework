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
	m_hdc = GetDC(g_hWnd); // m_�� �پ� ������ namespace�� ���� ����. namespace����

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
	SceneManager::GetInstance()->Render(m_hdc);//<-DC�� �޾ƿ´�.
}

void MainUpdate::Destroy()
{
	
}
