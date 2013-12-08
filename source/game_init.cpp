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
  //CCLabelBMFont *label = CCLabelBMFont::create("bitmap", "test.fnt");
  CCLabelAtlas *label = CCLabelAtlas::create("a123", "test.png", 20, 30, 'a');
  CCDirector::sharedDirector()->getRunningScene()->addChild(label);
  //CCSprite *char_B = label->getChildByTag(0);
}
