#pragma once
#include <SDL_stdinc.h>
#include <string>
#include <vector>

#include "Component.h"

namespace dae
{
	enum class Selection
	{
		singleplayer,
		coop,
		versus
	};
	class TextComponent;

	class MenuComponent : public Component
	{
	public:
		MenuComponent(GameObject* owner):Component(owner){}

		void Update(float) override;
		void FixedUpdate(float) override{}

		void SetTextComps(const std::vector<TextComponent*>& textComps);

		void NextSelection();
		void PreviousSelection();
		void Start();
		
	private:
		char GetPressedKey();
		TextComponent* m_SinglePlayer = nullptr;
		TextComponent* m_Coop = nullptr;
		TextComponent* m_Versus = nullptr;
		TextComponent* m_Name = nullptr;

		std::string m_NameStr;
		Selection m_Selection = Selection::singleplayer;
		bool m_Started = false;

		char m_LastKey = ';';
	};
}


