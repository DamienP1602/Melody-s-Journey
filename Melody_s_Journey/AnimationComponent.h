#pragma once
#include "Component.h"
#include "IManager.h"
#include "Animation.h"

class AnimationComponent : public Component, public IManager<string, Animation>
{
    /*Animation* currentAnimation;
    vector<string> animationNames;

public:
    Animation* GetCurrentAnimation() const
    {
        return currentAnimation;
    }
    const vector<string>& GetAnimationNames()
    {
        return animationNames;
    }

public:
    AnimationComponent(Entity* _owner);
    ~AnimationComponent();

public:
    void InitAnimations(const vector<AnimationData>& _animationsData);
    void RunAnimation(const string& _name, const float _directionX = 1.0f);*/
};