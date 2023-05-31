#pragma once


extern HWND g_hWnd;

const int COUNT = 128;

#define PI 3.141592f

#define WIDTH 740
#define HEIGHT 986

const unsigned char KEYID_UP = 0x00000001;
const unsigned char KEYID_DOWN = 0x00000002;
const unsigned char KEYID_LEFT = 0x00000004;
const unsigned char KEYID_RIGHT = 0x00000008;
const unsigned char KEYID_RETURN = 0x00000010;
const unsigned char KEYID_SPACE = 0x00000020;
const unsigned char KEYID_ESCAPE = 0x00000040;
const unsigned char KEYID_CONTROL = 0x00000080;


const unsigned char STATEID_HIT = 0x00000001;
const unsigned char STATEID_ATTACK = 0x00000002;
const unsigned char STATEID_JUMP = 0x00000004;

//** C에서만 사용하는 Singletone 문법
#define Single(T)					\
public:								\
	static T** GetInstance()		\
	{								\
		static T* instance;			\
		if(instance == nullptr)		\
			instance = new T;		\
		return &instance;			\
	}								\
private:							\
	T(const T&) = delete;			\
	T& operator=(const T&) = delete;

#define GetSingle(T) (*T::GetInstance())



template <typename T> // 안전하게 지울때 사용하는 코드 
inline void Safe_Release(T& _Object) // 인라인 함수 정의 
{
	if (_Object)
	{
		delete _Object;
		_Object = nullptr;
	}
} // 사용은 일반 함수 사용하듯이 사용






