#include "MiniginPCH.h"
#include "ResourceManager.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "Renderer.h"
#include "Texture2D.h"
#include "TextureSpriteSheet.h"
#include "Font.h"
#include <unordered_map>

dae::ResourceManager::~ResourceManager()
{
	CleanUp();
}

void dae::ResourceManager::CleanUp()
{
	for (std::pair<const std::string, Texture2D*>& p : m_pTextures)
	{
		delete p.second;
		p.second = nullptr;
	}
	m_pTextures.clear();

	for (std::pair<const std::string, Font*>& p : m_pFonts)
	{
		delete p.second;
		p.second = nullptr;
	}
	m_pFonts.clear();
}

void dae::ResourceManager::Init(const std::string& dataPath)
{
	m_DataPath = dataPath;

	// load support for png and jpg, this takes a while!

	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) 
	{
		std::cout << SDL_GetError() << '\n';
		throw std::runtime_error(std::string("Failed to load support for png's: ") + SDL_GetError());
	}

	if ((IMG_Init(IMG_INIT_JPG) & IMG_INIT_JPG) != IMG_INIT_JPG) 
	{
		std::cout << SDL_GetError() << '\n';
		throw std::runtime_error(std::string("Failed to load support for jpg's: ") + SDL_GetError());
	}

	if (TTF_Init() != 0) 
	{
		std::cout << SDL_GetError() << '\n';
		throw std::runtime_error(std::string("Failed to load support for fonts: ") + SDL_GetError());
	}
}

dae::Texture2D* dae::ResourceManager::LoadTexture(const std::string& file)
{
	if (m_pTextures.find(file) == m_pTextures.end())
	{
		const std::string fullPath = m_DataPath + file;
		SDL_Texture* texture = IMG_LoadTexture(Renderer::GetInstance().GetSDLRenderer(), fullPath.c_str());
		if (texture == nullptr)
		{
			std::cout << SDL_GetError() << '\n';
			throw std::runtime_error(std::string("Failed to load texture: ") + SDL_GetError());
		}
		m_pTextures.emplace(file, new Texture2D{ texture });
	}

	return m_pTextures.at(file);
}

dae::Texture2D* dae::ResourceManager::LoadTexture(const std::string& file, int col, int row)
{
	dae::Texture2D* texture = LoadTexture(file);

	TextureSpriteSheet* sprite = new TextureSpriteSheet{ texture->GetSDLTexture(), col, row };
	m_pSprites.push_back(sprite);

	return sprite;
}

dae::Texture2D* dae::ResourceManager::LoadTexture(const std::string& file, int col, int row, int amountOfSprites)
{
	dae::Texture2D* texture = LoadTexture(file);

	TextureSpriteSheet* sprite = new TextureSpriteSheet{ texture->GetSDLTexture(), col, row, amountOfSprites };
	m_pSprites.push_back(sprite);

	return sprite;
}

dae::Font* dae::ResourceManager::LoadFont(const std::string& file, unsigned int size)
{
	if (m_pFonts.find(file) == m_pFonts.end())
	{
		const std::string fullPath = m_DataPath + file;
		m_pFonts.emplace( file,new Font{m_DataPath + file, size});
	}
	
	return m_pFonts.at(file);
}
