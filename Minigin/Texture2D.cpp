#include "MiniginPCH.h"
#include "Texture2D.h"

dae::Texture2D::~Texture2D()
{
	SDL_DestroyTexture(m_Texture);
}

void dae::Texture2D::SetSize(float width, float height)
{
	(width < 1) ? m_Width = 1 : m_Width = width;
	(height < 1) ? m_Height = 1 : m_Height = height;

	m_CustomBoundaries = true;
}

SDL_Rect dae::Texture2D::GetSourceRect() const
{
	return m_SrcRect;
}

SDL_Texture* dae::Texture2D::GetSDLTexture() const
{
	return m_Texture;
}

dae::Texture2D::Texture2D(SDL_Texture* texture)
	:m_Texture{ texture }
{
	
}
