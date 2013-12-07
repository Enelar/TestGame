#include "stdafx.h"

template<>
cocos2d::CCPoint convert( const b2Vec2 &a )
{
  return ccp(a.x, a.y);
}

template<>
b2Vec2 convert( const cocos2d::CCPoint &a )
{
  return b2Vec2(a.x, a.y);
}

template<>
cocos2d::CCSize convert( const b2Vec2 &a)
{
  return cocos2d::CCSize(a.x, a.y);;
}

template<>
b2Vec2 convert( const cocos2d::CCSize &a)
{
  return b2Vec2(a.width, a.height);
}

template<>
cocos2d::CCPoint convert( const cocos2d::CCSize &a )
{
  return convert<cocos2d::CCPoint>(convert<b2Vec2>(a));
}

template<>
cocos2d::CCSize convert( const cocos2d::CCPoint &a )
{
  return convert<cocos2d::CCSize>(convert<b2Vec2>(a));
}
