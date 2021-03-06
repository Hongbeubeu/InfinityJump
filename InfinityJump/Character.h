#pragma once
#include "..\3DEngine\AnimSprite.h"
#include "Box2D/Box2D.h"
#include "Define.h"
#include "Pad.h"

class Character :
    public AnimSprite
{
    std::shared_ptr<b2World> m_world;
    b2Body* m_body = NULL;
    Pad* m_currentPad = NULL;
    bool m_isOnTheGround = false;
    bool m_isJumpingFirst = false;
    bool m_isJumpingSecond = false;
    bool m_isDead = false;

public:
    Character(std::shared_ptr<b2World> world, std::shared_ptr<AnimSprite> obj);
    ~Character();

    b2Body* getBody();
    Pad* getCurrentPad();
    void setCurrentPad(Pad* pad);
    bool isOnTheGround();
    void setIsOnTheGround(bool isOnTheGround);
    bool isJumpingFirst();
    bool isJumpingSecond();
    bool isDead();
    void die();

    virtual void InitBody();
    virtual void Update(GLfloat dt);

    void JumpFirst();
    void JumpSecond();
};

