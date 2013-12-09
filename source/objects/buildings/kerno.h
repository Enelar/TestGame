#include "../../entity/entity.h"
#include "../../game/energy.h"

class kerno : public entity
{
public:
  energy eng;

  kerno::kerno(b2Vec2 _pos);

};