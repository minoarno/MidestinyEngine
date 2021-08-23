#include "MiniginPCH.h"
#include "TextComponent.h"

#include "GameObject.h"
#include "Renderer.h"
#include "Font.h"
#include "Texture2D.h"
#include "Transform.h"
#include "ResourceManager.h" 

TextComponent::TextComponent(dae::Font* font, const std::string& text)
	: m_NeedsUpdate(true)
	, m_Text(text)
	, m_Font(font)
{
}

void TextComponent::Initialize()
{
}

void TextComponent::FixedUpdate()
{
	
}

void TextComponent::Update()
{
	
}

void TextComponent::LateUpdate()
{
	if (m_NeedsUpdate)
	{
		if (m_Text != "")
		{
			const SDL_Color color = { 255,255,255 }; // only white text is supported now
			SDL_Surface* surf = TTF_RenderText_Blended(m_Font->GetFont(), m_Text.c_str(), color);
			if (surf == nullptr)
			{
				throw std::runtime_error(std::string("Render text failed: ") + SDL_GetError());
			}
			
			SDL_Texture* texture = SDL_CreateTextureFromSurface(dae::Renderer::GetInstance().GetSDLRenderer(), surf);
			if (texture == nullptr)
			{
				throw std::runtime_error(std::string("Create text texture from surface failed: ") + SDL_GetError());
			}
			SDL_FreeSurface(surf);
			m_pGameObject->SetComponent<dae::Texture2D>(new dae::Texture2D{ texture });
		}
		m_NeedsUpdate = false;
	}
}

void TextComponent::Render() const
{
	if (m_pGameObject->GetComponent<dae::Texture2D>() != nullptr)
	{
		if (m_Text != "")
		{
			const glm::vec3 pos = m_pGameObject->GetComponent<dae::Transform>()->GetPosition();
			dae::Renderer::GetInstance().RenderTexture(m_pGameObject->GetComponent<dae::Texture2D>(), pos.x, pos.y);
		}
	}
}

// This implementation uses the "dirty flag" pattern
void TextComponent::SetText(const std::string& text)
{
	m_Text = text;
	m_NeedsUpdate = true;
}