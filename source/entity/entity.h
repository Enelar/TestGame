#include "cocos2d.h"
#include "Box2D\Box2D.h"
#include <string>

class entity
{
  cocos2d::CCSprite *sprite;
  b2Vec2 pos, vel, size;
  b2Vec2 life;
public:
  entity( std::string image_name, b2Vec2 pos, b2Vec2 size, float32 life, b2Vec2 vel = b2Vec2(0, 0));

  b2Vec2 &Position();
  b2Vec2 &Velosity();
  b2Vec2 &Size();
  float32 MaxLife() const;
  float32 &CurLife();

  virtual void OnCreate();
  virtual void OnUpdate();
  virtual void OnDestroy();
  /*
  virtual void OnDamageTaken();
  virtual void OnDamageDealt();
  virtual void OnKill();
  virtual void OnKillee();
  virtual void OnMove();
  //etc
  */
};