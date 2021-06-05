#pragma once
#include "Texture2D.h"

struct SDL_Texture;
namespace dae
{
	class TextureSpriteSheet final : public Texture2D
	{
	public:
		virtual SDL_Texture* GetSDLTexture() const override;
		explicit TextureSpriteSheet(SDL_Texture* texture, int col, int row);
		explicit TextureSpriteSheet(SDL_Texture* texture,int col, int row, int amountOfSprites);

		~TextureSpriteSheet();

		void SetIndex(int index);
		int GetCurrentIndex()const { return m_CurrentIndex; };

		void SetSize(int width, int height) override;

		TextureSpriteSheet(const TextureSpriteSheet&) = delete;
		TextureSpriteSheet(TextureSpriteSheet&&) = delete;
		TextureSpriteSheet& operator= (const TextureSpriteSheet&) = delete;
		TextureSpriteSheet& operator= (const TextureSpriteSheet&&) = delete;
	protected:
		int m_CurrentIndex = 0;
		int m_AmountOfCols = 1;
		int m_AmountOfRows = 1;
		int m_AmountOfSprites = 1;

		int m_SpriteWidth = 1;
		int m_SpriteHeight = 1;

		SDL_Texture* m_pCurrentSprite;
	};
}