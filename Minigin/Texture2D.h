#pragma once
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

		virtual void SetSize(int width, int height);
	protected:
		SDL_Texture* m_Texture;

		int m_Width;
		int m_Height;

		void GetSize(SDL_Texture* texture, int& width, int& height);
	};
}
