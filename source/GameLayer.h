#ifndef __GAMELAYER_H__
#define __GAMELAYER_H__

#include "stdafx.h"

#include "objects\obj_camera.h"

class GameLayer : public cocos2d::CCLayer
{
  obj_camera *week_camera;
protected:
    b2World*		world;		// Instance of physics world
public:
    GameLayer();
    ~GameLayer();
    
    // Init method
    virtual bool init();

    virtual void onEnter();

	// Draw method
	virtual void draw();

	// Main update loop
	void update(float dt);

    // Create instance of scene
    static CCScene* scene();
    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(GameLayer);
    
};

#endif // __GAMELAYER_H__

