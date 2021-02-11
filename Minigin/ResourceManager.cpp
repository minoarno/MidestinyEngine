#include "MiniginPCH.h"
#include "ResourceManager.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "Renderer.h"
#include "Texture2D.h"
#include "Font.h"
#include <unordered_map>

dae::ResourceManager::~ResourceManager()
{
	for(auto& p : m_Textures)
	{
		delete p.second;
		p.second = nullptr;
	}
	m_Textures.clear();
	
	for (auto& p : m_Fonts)
	{
		delete p.second;
		p.second = nullptr;
	}
	m_Fonts.clear();
}

void dae::ResourceManager::Init(const std::string& dataPath)
{
	m_DataPath = dataPath;

	// load support for png and jpg, this takes a while!

	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) 
	{
		throw std::runtime_error(std::string("Failed to load support for png's: ") + SDL_GetError());
	}

	if ((IMG_Init(IMG_INIT_JPG) & IMG_INIT_JPG) != IMG_INIT_JPG) 
	{
		throw std::runtime_error(std::string("Failed to load support for jpg's: ") + SDL_GetError());
	}

	if (TTF_Init() != 0) 
	{
		throw std::runtime_error(std::string("Failed to load support for fonts: ") + SDL_GetError());
	}
}

dae::Texture2D* dae::ResourceManager::LoadTexture(const std::string& file)
{
	if (m_Textures.find(file) == m_Textures.end())
	{
		const auto fullPath = m_DataPath + file;
		auto texture = IMG_LoadTexture(Renderer::GetInstance().GetSDLRenderer(), fullPath.c_str());
		if (texture == nullptr)
		{
			throw std::runtime_error(std::string("Failed to load texture: ") + SDL_GetError());
		}
		m_Textures.emplace(file, new Texture2D{ texture });
	}

	return m_Textures.at(file);
}

dae::Font* dae::ResourceManager::LoadFont(const std::string& file, unsigned int size)
{
	if (m_Fonts.find(file) == m_Fonts.end())
	{
		const auto fullPath = m_DataPath + file;
		m_Fonts.emplace( file,new Font{m_DataPath + file, size});
	}
	
	return m_Fonts.at(file);
}
