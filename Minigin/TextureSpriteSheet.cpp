#include "MiniginPCH.h"
#include "TextureSpriteSheet.h"
#include <SDL.h>
#include "Renderer.h"

SDL_Texture* dae::TextureSpriteSheet::GetSDLTexture() const
{
	return m_pCurrentSprite;
}

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
	m_SpriteWidth = m_Width / col;
	m_SpriteHeight = m_Height / row;
	SetIndex(m_CurrentIndex);
}

dae::TextureSpriteSheet::~TextureSpriteSheet()
{
	SDL_DestroyTexture(m_pCurrentSprite);
}

void dae::TextureSpriteSheet::SetIndex(int index)
{
	m_CurrentIndex = index % m_AmountOfSprites;
	
	SDL_Renderer* pRenderer = Renderer::GetInstance().GetSDLRenderer();

	int width, height;
	GetSize(m_Texture, width, height);

	SDL_Texture* pImgPart = SDL_CreateTexture(pRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);

	SDL_Rect srcRect = { m_CurrentIndex % m_AmountOfCols, m_CurrentIndex / m_AmountOfCols, m_SpriteWidth, m_SpriteHeight };
	SDL_Rect dstRect = { 0, 0, m_Width, m_Height };

	SDL_SetRenderTarget(pRenderer, pImgPart);
	SDL_RenderCopy(pRenderer, m_Texture, &srcRect, &dstRect);

	// the folowing line should reset the target to default(the screen)
	SDL_SetRenderTarget(pRenderer, NULL);

	SDL_DestroyTexture(m_pCurrentSprite);
	m_pCurrentSprite = pImgPart;
}

void dae::TextureSpriteSheet::SetSize(int width, int height)
{
	Texture2D::SetSize(width, height);

	SetIndex(m_CurrentIndex);
}
