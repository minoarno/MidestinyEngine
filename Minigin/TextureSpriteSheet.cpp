#include "MiniginPCH.h"
#include "TextureSpriteSheet.h"
#include "Renderer.h"

dae::TextureSpriteSheet::TextureSpriteSheet(SDL_Texture* texture, int col, int row)
	: TextureSpriteSheet(texture, col, row, col* row)
{
}

dae::TextureSpriteSheet::TextureSpriteSheet(SDL_Texture* texture, int col, int row, int amountOfSprites)
	: dae::Texture2D{ texture }
	, m_AmountOfCols{ col }
	, m_AmountOfRows{ row }
	, m_AmountOfSprites{ amountOfSprites}
{
	int width, height;
	SDL_QueryTexture(texture, NULL, NULL, &width, &height);

	m_SpriteWidth = float(width) / float(col);
	m_SpriteHeight = float(height) / float(row);

	m_UseSourceRect = true;
	SetIndex(m_CurrentIndex);
}

dae::TextureSpriteSheet::~TextureSpriteSheet()
{
}

void dae::TextureSpriteSheet::SetIndex(int index)
{
	m_CurrentIndex = index % m_AmountOfSprites;
	m_SrcRect = { m_CurrentIndex % m_AmountOfCols, m_CurrentIndex / m_AmountOfCols, int(m_SpriteWidth), int(m_SpriteHeight) };
}

void dae::TextureSpriteSheet::SetSize(float width, float height)
{
	Texture2D::SetSize(width, height);

	SetIndex(m_CurrentIndex);
}
