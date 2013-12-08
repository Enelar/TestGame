#include "GameLayer.h"
#include "entity\entity.h"

GameLayer::~GameLayer()
{
}

CCScene* GameLayer::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    GameLayer *layer = GameLayer::create();

    // Add layer as a child to scene
    scene->addChild(layer);

    // Return the scene
    return scene;
}

void test(double)
{
}

// on "init" you need to initialize your instance
bool GameLayer::init()
{
    if (!CCLayer::init())
        return false;

    schedule(schedule_selector(GameLayer::update));

    // COCOS2D TIP
    // Create Cocos2D objects here

	// Create Box2D world
	world = new b2World(b2Vec2(0, 100));

    // BOX2D TIP
    // Create Box2D objects here

    return true;
}

void GameLayer::draw()
{
  //CCLabelAtlas *label1 = CCLabelAtlas::create("Hello World", "test.png", 48, 64, ' ');
  
}

#include "entity\entity_manager.h"

void GameLayer::update(float dt)
{
	// Update Box2D world
	world->Step(dt, 6, 3);
    entity_manager::Instance().Update(dt);
    // BOX2D TIP
    // Update objects from box2d coordinates here
}

