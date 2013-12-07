#include "stdafx.h"

template<>
cocos2d::CCPoint convert( const b2Vec2 &a )
{
  return ccp(a.x, a.y);
}

template<>
b2Vec2 convert( const cocos2d::CCPoint &a )
{
  b2Vec2 ret(a.x, a.y);
  return ret;
}