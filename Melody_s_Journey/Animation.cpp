#include "Animation.h"
#include "AnimationComponent.h"
#include "Timer.h"
#include "Macro.h"

Animation::Animation(const string& _name, AnimationComponent* _owner, Shape* _shape,
    const AnimationData& _data) : IManagable(_name)
{
    currentIndex = -1;
    owner = _owner;
    shape = _shape;
    data = _data;
    Register();
}

Animation::~Animation()
{
    delete shape;
    delete timer;
}

void Animation::Register()
{
    owner->Add(id, this);
}

void Animation::SetNext()
{
    if (!CanNext())
    {
        if (!data.canLoop)
        {
            if (data.linkedAnimation != "")
            {
                Stop();
                Reset();
                //owner->RunAnimation(data.linkedAnimation, directionX);
                return;
            }

            Stop();
            return;
        }

        Reset();
    }

    currentIndex++;

    const Vector2i& _start = GetNewStart();
    const int _sizeX = static_cast<int>(data.size.x);
    const int _sizeY = static_cast<int>(data.size.y);
    IntRect _rect = IntRect(_start.x, _start.y, _sizeX, _sizeY);
    shape->setTextureRect(_rect);
    //shape->setScale(data.displayFromLeftToRight ? 1.0f : -1.0f, 1.0f);
    //shape->setScale(directionX, 1.0f);
}

Vector2i Animation::GetNewStart()
{
    int _x = static_cast<int>(data.start.x);
    int _y = static_cast<int>(data.start.y);

    switch (data.readDirection)
    {
    case READ_DOWN:
        _y += static_cast<int>(currentIndex * data.size.y);
        break;

    case READ_RIGHT:
        _x += static_cast<int>(currentIndex * data.size.x);
        break;

    default:
        break;
    }

    return Vector2i(_x, _y);
}

void Animation::Start(const float _directionX)
{
    directionX = _directionX;
    timer = new Timer(S_APPEND("Animation" + data.name), [&]() {
        //cout << "SetNext" << endl;
        SetNext();
        }, seconds(data.timeBetween), -1, false);
}

void Animation::Reset()
{
    currentIndex = -1;
}

void Animation::Stop()
{
    Reset();
    if (!timer) return;
    timer->Pause();
}