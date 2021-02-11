#pragma once
#include "Singleton.h"
#include <unordered_map>

namespace dae
{
	class Texture2D;
	class Font;
	class ResourceManager final : public Singleton<ResourceManager>
	{
	public:
		~ResourceManager();
		void Init(const std::string& data);
		Texture2D* LoadTexture(const std::string& file);
		Font* LoadFont(const std::string& file, unsigned int size);
	private:
		friend class Singleton<ResourceManager>;
		ResourceManager() = default;
		std::string m_DataPath;
		std::unordered_map<std::string, Texture2D*> m_Textures;
		std::unordered_map<std::string, Font*> m_Fonts;
	};
}
