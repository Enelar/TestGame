#include "obj_line.h"

namespace
{
  const float32 OBJECT_FOREVER_LIFE = 23;
};

obj_line::obj_line(b2Vec2 _pos, b2Vec2 _size, cocos2d::ccColor4F _color, b2Vec2 _vel, b2Vec2 _acc)
: entity(_pos, _size, OBJECT_FOREVER_LIFE, _vel, _acc)
{    
  setColor(_color);
}

void obj_line::OnUpdate(double dt)
{
  cocos2d::ccDrawColor4F(color.r, color.g, color.b, color.a);
  auto end = Position() + Size();
  cocos2d::ccDrawLine(convert<cocos2d::CCPoint>(Position()), convert<cocos2d::CCPoint>(end));
}

cocos2d::ccColor4F obj_line::getColor()
{
  return color;
}

void obj_line::setColor(cocos2d::ccColor4F _color)
{
  color = _color;
}