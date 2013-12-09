#include "../entity/entity.h"
#include <ccTypes.h>

class obj_line : public entity
{
private:
  cocos2d::ccColor4F color;
  b2Vec2 direct;
public:
  obj_line::obj_line(b2Vec2 pos, b2Vec2 size, cocos2d::ccColor4F color, b2Vec2 vel = b2Vec2_zero, b2Vec2 acc = b2Vec2_zero);
  void OnDraw();
  b2Vec2 obj_line::Size();

  cocos2d::ccColor4F obj_line::getColor();
  void setColor(cocos2d::ccColor4F color);
};