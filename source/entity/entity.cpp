#include "entity.h"
#include "entity_manager.h"

namespace
{
  cocos2d::CCScene *GetScene()
  {
    cocos2d::CCScene *scene = cocos2d::CCDirector::sharedDirector()->getRunningScene();
    CCAssert(scene, "You trying to create object before scene initiated!");
    return scene;
  }
}

entity::entity( cocos2d::CCNode *_sprite, b2Vec2 _pos, b2Vec2 _size, float32 _life, b2Vec2 _vel, b2Vec2 _acc)
  : sprite(_sprite),
  pos(_pos), size(_size), life(_life, _life), vel(_vel), acc(_acc), stage(CREATE), recurse_contstraight(false)
{
  if (sprite)
    GetScene()->addChild(sprite);
  entity_manager::Instance().AddObject(this);
}


entity::entity( std::string _image_name, b2Vec2 _pos, b2Vec2 _size, float32 _life, b2Vec2 _vel, b2Vec2 _acc )
  : sprite(cocos2d::CCSprite::create(_image_name.c_str())),
  pos(_pos), size(_size), life(_life, _life), vel(_vel), acc(_acc), stage(CREATE), recurse_contstraight(false)
{
  GetScene()->addChild(sprite);
  entity_manager::Instance().AddObject(this);
}

entity::entity( b2Vec2 _pos, b2Vec2 _size, float32 _life, b2Vec2 _vel, b2Vec2 _acc )
  : sprite(nullptr),
  pos(_pos), size(_size), life(_life, _life), vel(_vel), acc(_acc), stage(CREATE), recurse_contstraight(false)
{
  entity_manager::Instance().AddObject(this);
}

entity::~entity()
{
  if (sprite != nullptr)
    GetScene()->removeChild(sprite);
  entity_manager::Instance().RemoveObject(this);
}

b2Vec2 &entity::Position()
{
  return pos;
}

b2Vec2 &entity::Velosity()
{
  return vel;
}

b2Vec2 &entity::Acceleration()
{
  return acc;
}

b2Vec2 &entity::Size()
{
  return size;
}

b2Vec2 entity::Size() const
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

void entity::OnDraw()
{
}

void entity::Update( double dt )
{
  CCAssert(!recurse_contstraight, "Object recursive updating forbidden");
  recurse_contstraight = true;
  switch (stage)
  {
  case entity::CREATE:
    OnCreate();
    OnUpdate(0);
    stage = ONLINE;
    break;
  case entity::ONLINE:
    OnUpdate(dt);
    break;
  case entity::PREOFF:
    stage = OFFLINE;
    OnUpdate(0);
    OnDestroy();
  case entity::OFFLINE:
    break;
  default:
    break;
  }
  RecalculateValues(dt);
  SyncValues();
  recurse_contstraight = false;
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
  if (!sprite)
    return;
  sprite->setPosition(convert<cocos2d::CCPoint>(pos));

  auto scale =
  [this]()
  {
    auto content = sprite->getContentSize();
    auto GetScale = []( b2Vec2 wish, b2Vec2 cur )
    {
      return b2Vec2(wish.x / cur.x, wish.y / cur.y);
    };
    auto scale = GetScale(size, convert<b2Vec2>(content));
    return scale;
  }();

  [this, scale]()
  {
    sprite->setScaleX(scale.x);
    sprite->setScaleY(scale.y);
  }();
}

CCNode *&entity::RawNodeAccess()
{
  return sprite;
}

CCNode *entity::RawNodeAccess() const
{
  return sprite;
}