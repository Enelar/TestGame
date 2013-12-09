#include "../../entity/entity.h"
#include "../../game/energy.h"

class building : public entity
{
public:
  energy eng;

  building::building(_STL::string texture_str, b2Vec2 pos, b2Vec2 size,
    float32 life, word energy_max, int energy_delta);
};