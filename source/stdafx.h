#define _MEMLEAK_DETECT_ENABLED
#define _AX_EXCEPTIONS_H_
#include "../AX/source/ax/def.h"

using ax::convert;

#include "cocos2d.h"
#include "Box2D\Box2D.h"

template<>
cocos2d::CCPoint convert( const b2Vec2 &);
template<>
b2Vec2 convert( const cocos2d::CCPoint &);