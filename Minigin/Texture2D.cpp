#include "MiniginPCH.h"
#include "Texture2D.h"

dae::Texture2D::~Texture2D()
{
	SDL_DestroyTexture(m_Texture);
}

void dae::Texture2D::SetSize(int width, int height)
{
	(width < 1) ? m_Width = 1 : m_Width = width;
	(height < 1) ? m_Height = 1 : m_Height = height;
}

void dae::Texture2D::GetSize(SDL_Texture* texture, int& width, int& height)
{
	SDL_QueryTexture(texture, NULL, NULL, &width, &height);
}

SDL_Texture* dae::Texture2D::GetSDLTexture() const
{
	return m_Texture;
}

dae::Texture2D::Texture2D(SDL_Texture* texture)
	:m_Texture{ texture }
{
	GetSize(texture,m_Width,m_Height);
}
