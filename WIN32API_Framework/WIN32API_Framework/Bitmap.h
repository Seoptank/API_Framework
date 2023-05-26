#pragma once
#include "Include.h"

class Bitmap
{
private:
	HDC			m_hdc, m_MemDC;
	HBITMAP		m_bitmap, m_Oldbitmap; // HBITMAP: 그리기 도구
	//m_bitmap	 : 새로운 그리기 도구 
	//m_Oldbitmap: 기존 그리기 도구 보관할 변수
public:
	Bitmap* LoadBmp(LPCWSTR _FileName); 
	void Release();

public:
	HDC GetMemDC() { return m_MemDC; }
public:
	Bitmap();
	~Bitmap();
};

