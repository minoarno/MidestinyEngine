#pragma once
#pragma warning(push)
#pragma warning(disable : 4005)
#include <SDL.h>
#pragma warning(pop)


struct SDL_Texture;
namespace dae
{
	/**
	 * Simple RAII wrapper for an SDL_Texture
	 */
	class Texture2D
	{
	public:
		virtual SDL_Texture* GetSDLTexture() const;
		explicit Texture2D(SDL_Texture* texture);
		virtual ~Texture2D();

		Texture2D(const Texture2D &) = delete;
		Texture2D(Texture2D &&) = delete;
		Texture2D & operator= (const Texture2D &) = delete;
		Texture2D & operator= (const Texture2D &&) = delete;

		virtual void SetSize(float width, float height);
		float GetWidth()const { return m_Width; }
		float GetHeight()const { return m_Height; }

		bool IsCustomBoundaries()const { return m_CustomBoundaries; }
		bool UseSourceRect()const { return m_UseSourceRect; }
		
		SDL_Rect GetSourceRect()const;
	protected:
		SDL_Texture* m_Texture;

		float m_Width;
		float m_Height;
		bool m_CustomBoundaries = false;
		bool m_UseSourceRect = false;
		SDL_Rect m_SrcRect = {};
	};
}
