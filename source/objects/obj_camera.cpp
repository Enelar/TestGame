#include "obj_camera.h"

namespace
{
  b2Vec2 InvertConvert( const b2Vec2 &a )
  {
    b2Vec2 ret = a;
    ret *= -1;
    return ret;
  }
}

obj_camera::obj_camera()
  : entity(nullptr, b2Vec2_zero, b2Vec2_zero, 100),
  pos(b2Vec2_zero), vel(b2Vec2_zero), acc(b2Vec2_zero)
{
  RawNodeAccess() = CCDirector::sharedDirector()->getRunningScene();
  entity::Position() = convert<b2Vec2>(RawNodeAccess()->getPosition());
}

obj_camera::~obj_camera()
{
  RawNodeAccess() = nullptr;
}

obj_camera::connector<b2Vec2> obj_camera::Position()
{
  return connector<b2Vec2>(Update(pos, &entity::Position), entity::Position(), InvertConvert);
}

obj_camera::connector<b2Vec2> obj_camera::Velosity()
{
  return connector<b2Vec2>(Update(vel, &entity::Velosity), entity::Velosity(), InvertConvert);
}

obj_camera::connector<b2Vec2> obj_camera::Acceleration()
{
  return connector<b2Vec2>(Update(acc, &entity::Acceleration), entity::Acceleration(), InvertConvert);
}

template<typename OriginT, typename RetT>
b2Vec2 &obj_camera::Update( b2Vec2 &target, RetT (OriginT::*Origin)() )
{
  b2Vec2 &vec = (this->*Origin)();
  target = InvertConvert(vec);
  return target;
}

void obj_camera::OnUpdate( double dt )
{
  entity::Size() = convert<b2Vec2>(RawNodeAccess()->getContentSize());
}


b2Vec2 obj_camera::Size() const
{
  CCAssert(false, "Obj camera size");
  //entity::Size() = convert<b2Vec2>(RawNodeAccess()->getContentSize());
  return entity::Size();
}

b2Vec2 &obj_camera::Size()
{
  CCAssert(false, "You cant change size of camera");
  entity::Size() = convert<b2Vec2>(RawNodeAccess()->getContentSize());
  return entity::Size();
}