#include "GameLayer.h"
#include "entity\entity.h"

// test
class icon : public entity
{
public:
  icon( b2Vec2 pos )
    : entity("icon.png", pos, b2Vec2(10, 10), 100)
  {
  }
};

void GameLayer::onEnter()
{
  CCLayer::onEnter();
  auto ico = new icon(b2Vec2(0, 0));
  ico->Acceleration().y += 1;
  ico->Velosity() += b2Vec2(1, 0);
}
