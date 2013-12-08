#include "obj_text.h"
#include "CCSpriteBatchNode.h"
namespace
{
  const float32 OBJECT_FOREVER_LIFE = 23;
};

cocos2d::CCNode* obj_text::spriteFromStr(std::string _str)
{
  cocos2d::CCLabelBMFont *label = cocos2d::CCLabelBMFont::create( _str.c_str(), "java.fnt");// 85, kCCTextAlignmentLeft);
  //label->setPositionX(100);
  //label->setPositionY(100);                                         s
  return label;
}

obj_text::obj_text(std::string _str, b2Vec2 _pos, cocos2d::ccColor4F _color, b2Vec2 _vel, b2Vec2 _acc)
: entity(spriteFromStr(_str), _pos, b2Vec2(100, 100), OBJECT_FOREVER_LIFE, _vel, _acc)
{

}