#include "BossGalaga.h"
#include "TextureSpriteSheet.h"
#include "GameObject.h"

BossGalaga::BossGalaga()
	:Enemy{150,400}
{
}

BossGalaga::~BossGalaga()
{
}

int BossGalaga::GetHit()
{
	if (m_IsDamaged)
	{
		return GetScoreFromKilling();
	}
	else
	{
		m_pGameObject->GetComponent<dae::TextureSpriteSheet>()->SetIndex(1);
		return 0;
	}
}

void BossGalaga::Dive()
{
}
