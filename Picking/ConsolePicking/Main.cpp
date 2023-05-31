#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>

using namespace std;

//** Ÿ�� ����,������ �ִ� ���� 
#define COUNT_X 7
#define COUNT_Y 4

// enum���� �����ص� ��
#define BLACK       0 
#define	DARKBLUE    1
#define	DARKGREEN   2
#define	DARKSKYBLUE 3
#define	DARKRED		4
#define	DARKPURPULE 5
#define	DARKYELLOW	6
#define	GRAY		7
#define	DARKGRAY    8

typedef struct tagVector3
{
	float x, y;

	tagVector3() : x(0.0f),y(0.0f){}
	tagVector3(float _x,float _y) : x(_x), y(_y){}

}Vector3;

void SetCorsorPosition(const float& _x, const float& _y);
void SetColor(int color);
void Text(const float& _x, const float& _y, const string& _str);

int main(void)
{
	Vector3 position;
	position.x = 3;
	position.y = 2;

	Vector3 scale;
	scale.x = 6;
	scale.y = 3;
	
	Vector3 myPosition = x,y;

	ULONGLONG time = GetTickCount64();

	while (true)
	{
		if (GetAsyncKeyState(VK_UP))
		{

		}
		if (GetAsyncKeyState(VK_DOWN))
		{

		}
		if (GetAsyncKeyState(VK_LEFT))
		{

		}
		if (GetAsyncKeyState(VK_RIGHT))
		{

		}

		if (time + 150 < GetTickCount64())
		{

			time = GetTickCount64();

			//** ȭ��û��
			system("cls");

			for (int y = 0; y < COUNT_Y; ++y)
			{
				for (int x = 0; x < COUNT_X; ++x)
				{

					//** Ÿ�� ���
					Text(position.x - (scale.x * 0.5f) + scale.x * x,
						position.y - (scale.y * 0.5f) + scale.y * y,
						"������");
					Text(position.x - (scale.x * 0.5f) + scale.x * x,
						position.y - (scale.y * 0.5f) + scale.y * y + 1,
						"������");;
					Text(position.x - (scale.x * 0.5f) + scale.x * x,
						position.y - (scale.y * 0.5f) + scale.y * y + 2,
						"������");

					//** index Ȯ��
					int index = y * COUNT_X + x;

					// _itoa: ������ ���ڷ� �����ϴ� �ڵ�
					char* buffer = new char[4];
					_itoa(index, buffer, 10);


					Text(position.x - 1 + scale.x * x,
						position.y - (scale.y * 0.5f) + scale.y * y + 1,
						string(buffer));

					
				}

			}

			//** CPU�� �������� �ʴ� ����
			Sleep(50);
		}
	}


	SetColor(7);
	


	return 0;
}

void SetCorsorPosition(const float& _x, const float& _y)
{
	COORD pos = { _x, _y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void SetColor(int color)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(
		handle, color);
}

void Text(const float& _x, const float& _y, const string& _str)
{
	SetCorsorPosition(_x, _y);
	cout << _str << endl;
}


//** ����: �ܼ�â���� Ű �Է¹޾� ĭĭ�� �����̱�