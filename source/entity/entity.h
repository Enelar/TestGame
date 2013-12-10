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
    typedef typename std::conditional<is_const, proxy<const T>, proxy<T>>::type type;
  };

  entity( std::string image_name, b2Vec2 pos, b2Vec2 size, float32 life, b2Vec2 vel = b2Vec2_zero, b2Vec2 acc = b2Vec2_zero);
  entity( b2Vec2 pos, b2Vec2 size, float32 life, b2Vec2 vel = b2Vec2_zero, b2Vec2 acc = b2Vec2_zero);
  entity( cocos2d::CCNode *sprite, b2Vec2 pos, b2Vec2 size, float32 life, b2Vec2 vel = b2Vec2_zero, b2Vec2 acc = b2Vec2_zero);

  virtual ~entity();

  ret_type<b2Vec2>::type Position();
  ret_type<b2Vec2>::type Velosity();
  ret_type<b2Vec2>::type Acceleration();
  ret_type<b2Vec2, true>::type Size() const;
  ret_type<b2Vec2>::type Size();
  ret_type<float32, true>::type MaxLife() const;
  ret_type<float32>::type CurLife();

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

protected:  ret_type<word>::type Tag();
public: ret_type<word, true>::type Tag() const;

protected:
  CCNode *&RawNodeAccess();
  CCNode *RawNodeAccess() const;

  friend class entity_manager;
};