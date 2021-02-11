#pragma once
#include "BaseComponent.h"

namespace dae
{
	class Font;
	class Texture2D;
}

class TextComponent : public BaseComponent
{
public:
	explicit TextComponent(dae::Font* font, const std::string& text = "Text");
	TextComponent(const TextComponent& other) = default;
	TextComponent& operator=(const TextComponent& other) = default;
	TextComponent(TextComponent&& other) = default;
	TextComponent& operator=(TextComponent&& other) = default;
	virtual ~TextComponent() = default;

	void Initialize() override;
	void FixedUpdate() override;
	void Update() override;
	void LateUpdate() override;
	void Render() const override;

	void SetText(const std::string& text);
protected:
	bool m_NeedsUpdate;
	std::string m_Text;
	dae::Font* m_Font;
};

