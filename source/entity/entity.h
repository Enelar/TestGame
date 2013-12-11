#pragma once

#include "../stdafx.h"
#include <string>
#include "../proxy.h"

class entity
{
  cocos2d::CCNode *sprite;
  b2Vec2 pos, vel, acc, size;
  b2Vec2 life;

  enum STAGES
  {
    CREATE,
    ONLINE,
    PREOFF,
    OFFLINE
  } stage;
  bool recurse_contstraight;
  void RecalculateValues( double dt );
  void SyncValues() const;
public:
  template<typename T, bool is_const = false>
  struct ret_type
  {
    typedef proxy<T> readwrite;
    typedef proxy<const T> readonly;
    typedef typename std::conditional<is_const, readonly, readwrite>::type type;
  };

  entity( std::string image_name, b2Vec2 pos, b2Vec2 size, float32 life, b2Vec2 vel = b2Vec2_zero, b2Vec2 acc = b2Vec2_zero);
  entity( b2Vec2 pos, b2Vec2 size, float32 life, b2Vec2 vel = b2Vec2_zero, b2Vec2 acc = b2Vec2_zero);
  entity( cocos2d::CCNode *sprite, b2Vec2 pos, b2Vec2 size, float32 life, b2Vec2 vel = b2Vec2_zero, b2Vec2 acc = b2Vec2_zero);

  virtual ~entity();

  ret_type<b2Vec2>::readwrite Position();
  ret_type<b2Vec2>::readwrite Velosity();
  ret_type<b2Vec2>::readwrite Acceleration();
  ret_type<b2Vec2>::readonly Size() const;
  ret_type<b2Vec2>::readwrite Size();
  ret_type<float32>::readonly MaxLife() const;
  ret_type<float32>::readwrite CurLife();

  void Update( double dt );

  virtual void OnCreate();
  virtual void OnDraw();
  virtual void OnUpdate( double dt );
  virtual void OnDestroy();
  /*
  virtual void OnDamageTaken();
  virtual void OnDamageDealt();
  virtual void OnKill();
  virtual void OnKillee();
  virtual void OnMove();
  //etc
  */

protected:  ret_type<word>::readwrite Tag();
public: ret_type<word>::readonly Tag() const;

protected:
  CCNode *&RawNodeAccess();
  CCNode *RawNodeAccess() const;

  friend class entity_manager;
};