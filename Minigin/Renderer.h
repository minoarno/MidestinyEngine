#pragma once
#include "Singleton.h"

struct SDL_Window;
struct SDL_Renderer;

namespace dae
{
	class Texture2D;
	/**
	 * Simple RAII wrapper for the SDL renderer
	 */
	class Renderer final : public Singleton<Renderer>
	{
	public:
		void Init(SDL_Window* window);
		static int GetOpenGLDriverIndex();
		void Render() const;
		void Destroy();

		void RenderTexture(const Texture2D* pTexture, float x, float y) const;
		void RenderTexture(const Texture2D* pTexture, float x, float y, float width, float height) const;
		void RenderTexture(const Texture2D* pTexture, SDL_Rect srcRect, const float x, const float y, const float width, const float height) const;
		void RenderTexture(const Texture2D* pTexture, SDL_Rect srcRect, const float x, const float y) const;

		SDL_Renderer* GetSDLRenderer() const { return m_Renderer; }
	private:
		SDL_Renderer* m_Renderer{};

		SDL_Window* m_Window = nullptr;
		static bool m_ShowDemo;
	};
}

