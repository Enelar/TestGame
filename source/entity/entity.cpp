#include "entity.h"

entity::entity( std::string _image_name, b2Vec2 _pos, b2Vec2 _size, float32 _life, b2Vec2 _vel)
  : sprite(cocos2d::CCSprite::create(_image_name.c_str())), pos(pos), size(_size), life(_life, _life), vel(_vel)
{

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

void entity::OnUpdate()
{
}

void entity::OnDestroy()
{
}