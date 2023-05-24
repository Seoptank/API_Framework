#include "GuideBullet.h"
#include "GameObject.h"

GuideBullet::GuideBullet()
{
}

GuideBullet::~GuideBullet()
{
}

void GuideBullet::Start()
{
	Speed = 2.5f;
}

void GuideBullet::Update(Transform& transform)
{
	float Horiaontal = Target->GetPosition().x - transform.position.x;
	float Vertical = Target->GetPosition().y - transform.position.y;

	float Distance = sqrt((Horiaontal * Horiaontal) + (Vertical * Vertical));

	Vector3 Distance = Vector3(
		Horiaontal / Distance,
		Vertical / Distance,
		0.0f
	);
}

void GuideBullet::Render(HDC hdc)
{
	Ellipse(hdc,
		int(Object->GetPosition().x - (Object->GetScale().x * 0.5f)),
		int(Object->GetPosition().y - (Object->GetScale().y * 0.5f)),
		int(Object->GetPosition().x + (Object->GetScale().x * 0.5f)),
		int(Object->GetPosition().y + (Object->GetScale().y * 0.5f)));
}

void GuideBullet::Destroy()
{
}

