#include "obj_line.h"

namespace
{
  const float32 OBJECT_FOREVER_LIFE = 23;
};

obj_line::obj_line(b2Vec2 _pos, b2Vec2 _size, cocos2d::ccColor4F _color, b2Vec2 _vel, b2Vec2 _acc)
: entity(_pos, b2Vec2(ax::Abs(_size.x), ax::Abs(_size.y)), OBJECT_FOREVER_LIFE, _vel, _acc)
{
  direct = _size - _pos;

  setColor(_color);
}

b2Vec2 obj_line::Size()
{
  //b2Vec2 _size = entity::Size();
  //size = abs(_size)
  //direct = (_size)
  return entity::Size();
}

void obj_line::OnDraw()
{
  cocos2d::ccDrawColor4F(color.r, color.g, color.b, color.a);
  b2Vec2 end = Position() + direct;
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

/*
//CCLabelBMFont *label = CCLabelBMFont::create("bitmap", "test.fnt");
CCLabelAtlas *label = CCLabelAtlas::create("a123", "test.png", 20, 30, 'a');
CCDirector::sharedDirector()->getRunningScene()->addChild(label);
//CCSprite *char_B = label->getChildByTag(0);
*/