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

#include "objects\obj_text.h"
void GameLayer::onEnter()
{
  CCLayer::onEnter();
  auto ico = new icon(b2Vec2(0, 0));
  ico->Acceleration().y += 1;
  ico->Velosity() += b2Vec2(1, 0);
  //CCLabelBMFont *label = CCLabelBMFont::create("bitmap", "test.fnt");
  //CCLabelBMFont *label = CCLabelBMFont::create("FUCK!", "java.fnt");// 85, kCCTextAlignmentLeft);
  //label->setPositionX(100);
  //label->setPositionY(100);
  //CCDirector::sharedDirector()->getRunningScene()->addChild(label);
  //CCSprite *char_B = label->getChildByTag(0);
  auto tx = new obj_text("123", b2Vec2(0, 0), ccc4f(1, 0, 0, 1));
}
