#pragma once
#include "Include.h"

class Bitmap;
class ImageManager // ->보관을 위해 만듬
{
public:
	Single(ImageManager)
private:
	map<string, Bitmap*> m_mapImageList;
public:
	map<string, Bitmap*>* GetImageList() { return &m_mapImageList; }
private:
	ImageManager();
public:
	~ImageManager();
};

