#include "../entity/entity.h"
#include <ccTypes.h>

class obj_line : entity
{
private:
  cocos2d::ccColor4F color;
public:
  obj_line::obj_line(b2Vec2 _pos, b2Vec2 _size, cocos2d::ccColor4F _color, b2Vec2 _vel = b2Vec2_zero, b2Vec2 _acc = b2Vec2_zero);
  void OnUpdate(double dt);

  cocos2d::ccColor4F obj_line::getColor();
  void setColor(cocos2d::ccColor4F _color);
};