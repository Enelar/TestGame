#include "entity.h"

namespace
{
  cocos2d::CCScene *GetScene()
  {
    return cocos2d::CCDirector::sharedDirector()->getRunningScene();
  }
}

entity::entity( std::string _image_name, b2Vec2 _pos, b2Vec2 _size, float32 _life, b2Vec2 _vel, b2Vec2 _acc )
  : sprite(cocos2d::CCSprite::create(_image_name.c_str())),
  pos(pos), size(_size), life(_life, _life), vel(_vel), acc(_acc), stage(CREATE), recurse_contstraight(false)
{
  GetScene()->addChild(sprite);
}

entity::~entity()
{
  GetScene()->removeChild(sprite);
}

b2Vec2 &entity::Position()
{
  return pos;
}

b2Vec2 &entity::Velosity()
{
  return vel;
}

b2Vec2 &entity::Size()
{
  return size;
}

float32 entity::MaxLife() const
{
  return life.y;
}

float32 &entity::CurLife()
{
  return life.x;
}

void entity::OnCreate()
{
}

void entity::OnUpdate( double dt )
{
}

void entity::OnDestroy()
{
}

void entity::Update( double dt )
{
  if (recurse_contstraight)
    return;
  recurse_contstraight = true;
  switch (stage)
  {
  case entity::CREATE:
    OnCreate();
    stage = ONLINE;
    break;
  case entity::ONLINE:
    OnUpdate(dt);
    break;
  case entity::PREOFF:
    stage = OFFLINE;
    OnDestroy();
  case entity::OFFLINE:
    break;
  default:
    break;
  }
  SyncValues();
}

void entity::RecalculateValues( double dt )
{
  auto Mult = []( b2Vec2 vec, double mult )
  {
    vec *= (float32)mult;
    return vec;
  };

  vel += Mult(acc, dt);
  pos += Mult(vel, dt);
}

void entity::SyncValues() const
{
  sprite->setPosition(convert<cocos2d::CCPoint>(pos));
}