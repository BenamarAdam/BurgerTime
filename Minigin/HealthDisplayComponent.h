#pragma once
#include "Component.h"
#include "Observer.h"

namespace dae
{
	class TextComponent;
	class HealthDisplayComponent : public Component, public Observer
	{
	public:
		void Update(float) override {}
		void FixedUpdate(float) override {}
		HealthDisplayComponent(GameObject* owner);
		void SetActorToDisplay(GameObject* obj);
	protected:
		void OnNotify(const GameObject* obj, Event event) override;
	private:
		TextComponent* m_TextComponent{};
		GameObject* m_HealthActor{};
	};
}
