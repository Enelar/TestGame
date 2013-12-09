#include "../entity/entity.h"

class obj_text : public entity
{
private:
  cocos2d::ccColor4F color;
  std::string str;
public:  
  cocos2d::CCNode* spriteFromStr(std::string str);
  obj_text::obj_text(std::string str, b2Vec2 pos, cocos2d::ccColor4F color, 
    b2Vec2 vel = b2Vec2_zero, b2Vec2 acc = b2Vec2_zero);
};