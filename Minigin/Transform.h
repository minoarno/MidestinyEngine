#pragma once
#pragma warning(push)
#pragma warning (disable:4201)
#include <glm/glm.hpp>
#pragma warning(pop)

namespace dae
{
	class Transform final
	{
	public:
		Transform() = default;
		~Transform() = default;
		const glm::vec3& GetPosition() const { return m_Position; }
		void SetPosition(float x, float y, float z);
		void Translate(float x, float y, float z);
		void Translate(const glm::vec3& vec);
	private:
		glm::vec3 m_Position;
	};
}
