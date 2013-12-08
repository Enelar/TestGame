#include "GameLayer.h"
#include "entity\entity.h"

GameLayer::GameLayer()
  : week_camera(nullptr)
{
}

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

#include "entity\entity_manager.h"


void GameLayer::draw()
{
  entity_manager::Instance().Redraw();
}

void GameLayer::update(float dt)
{
	// Update Box2D world
	world->Step(dt, 6, 3);
    entity_manager::Instance().Update(dt);

   // auto obj = CCDirector::sharedDirector()->getRunningScene();
    //auto new_size = b2Vec2(1 * dt, 1 * dt) + convert<b2Vec2>(obj->getPosition());
    /*
    setPosition(convert<cocos2d::CCPoint>(new_size));
    CCCamera *cam = getCamera();
    cam->setCenterXYZ(new_size.x, new_size.y, 0);
    */
    //obj->setPosition(convert<cocos2d::CCPoint>(new_size));
    // BOX2D TIP
    // Update objects from box2d coordinates here
}

