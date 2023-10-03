#pragma once
#include <vector>

#include "Component.h"
#include "RenderComponent.h"
#include "Structs.h"
#include "Transform.h"

namespace dae {
    class AnimatedRenderComponent;
    class CollisionComponent;

    class EnemyComponent : public Component
    {
    public:
        enum class State
        {
            left,
            right,
            up,
            down,
            stunned,
            falling,
            dead
        };
        EnemyComponent(GameObject* owner);
        void Update(float deltaTime) override;
        void FixedUpdate(float) override{}

        void SetPeter(GameObject* peterObj);

        void SetState(State state);
        State GetState() const { return m_State; }

        void InitAnimation(AnimatedRenderComponent* animComp, std::string textureLoc);

        void Kill();

        void Stun();

        void CalcDirection();

    private:
        void Initialize();
        void HandleMovement(float deltaTime);
        void HandleAnim() const;
        void HandleStun(float deltaTime);

        State m_State = State::left;

        float m_Speed{ 35.f },
            m_ClimbSpeed{ 30.f };

        float m_StunTime{ 1.5f },
            m_StunElapsed{};

        bool m_OnPlatform{ true },
            m_OnLadder{ false },
            m_DirChanged{ false };

        GameObject* m_Peter{};

        Vec2 m_Direction{}, m_MovementDir{};

        AnimatedRenderComponent* m_Anim{};

        CollisionComponent* m_CollisionComp = nullptr;

        Transform* m_Transform = nullptr;
        //Anim
        int m_RunLeft{},
            m_RunRight{},
            m_Climb{},
            m_ClimbDown{},
            m_Stunned{};

        //Sound
        int m_Hit{},
            m_Fall{};

    };
}
