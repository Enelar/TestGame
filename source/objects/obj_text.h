#include "../entity/entity.h"
#include <ccTypes.h>
#include <CCLabelBMFont.h>

class obj_text : public entity
{
private:
  cocos2d::ccColor4F color;
  std::string str;
public:  
  cocos2d::CCSprite* spriteFromStr(std::string _str);
  obj_text::obj_text(std::string _str, b2Vec2 _pos, cocos2d::ccColor4F _color, b2Vec2 _vel = b2Vec2_zero, b2Vec2 _acc = b2Vec2_zero);
};