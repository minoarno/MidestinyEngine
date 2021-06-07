#pragma once
#include "Texture2D.h"

struct SDL_Texture;
namespace dae
{
	class TextureSpriteSheet final : public Texture2D
	{
	public:
		explicit TextureSpriteSheet(SDL_Texture* texture, int col, int row);
		explicit TextureSpriteSheet(SDL_Texture* texture,int col, int row, int amountOfSprites);
		TextureSpriteSheet(const TextureSpriteSheet&) = delete;
		TextureSpriteSheet(TextureSpriteSheet&&) = delete;
		TextureSpriteSheet& operator= (const TextureSpriteSheet&) = delete;
		TextureSpriteSheet& operator= (const TextureSpriteSheet&&) = delete;
		~TextureSpriteSheet();

		void SetIndex(int index);
		int GetCurrentIndex()const { return m_CurrentIndex; };

		void SetSize(float width, float height) override;
	protected:
		int m_CurrentIndex = 0;
		int m_AmountOfCols = 1;
		int m_AmountOfRows = 1;
		int m_AmountOfSprites = 1;

		float m_SpriteWidth = 1;
		float m_SpriteHeight = 1;
	};
}