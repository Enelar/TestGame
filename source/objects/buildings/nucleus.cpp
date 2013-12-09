#include "nucleus.h"

namespace
{
  const float32 nucleus_DEFAULT_LIFE = 42;
  const b2Vec2 nucleus_DEFAULT_SIZE = b2Vec2(32, 32);
  const word nucleus_DEFAULT_ENERGY_MAX = 65;
  const int nucleus_DEFAULT_ENERGY_DELTA = 7;
  const word nucleus_DEFAULT_DISTANCE = 65;
  const _STL::string nucleus_DEFAULT_SPRITE_ADRESS = "nucleus.png";
};

nucleus::nucleus(b2Vec2 _pos)
: conectNode(nucleus_DEFAULT_SPRITE_ADRESS, nucleus_DEFAULT_DISTANCE, _pos, nucleus_DEFAULT_SIZE, nucleus_DEFAULT_LIFE,
  nucleus_DEFAULT_ENERGY_MAX, nucleus_DEFAULT_ENERGY_DELTA)
{
  
}