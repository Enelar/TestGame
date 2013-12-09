#include "kerno.h"

namespace
{
  const float32 KERNO_DEFAULT_LIFE = 42;
  const b2Vec2 KERNO_DEFAULT_SIZE = b2Vec2(32, 32);
  const word KERNO_DEFAULT_ENERGY_MAX = 65;
  const word KERNO_DEFAULT_ENERGY_DELTA = 7;
  const _STL::string KERNO_DEFAULT_SPRITE_ADRESS = "kerno.png";
};

kerno::kerno(b2Vec2 _pos)
: entity(KERNO_DEFAULT_SPRITE_ADRESS, _pos, KERNO_DEFAULT_SIZE, KERNO_DEFAULT_LIFE, b2Vec2_zero, b2Vec2_zero),
eng(KERNO_DEFAULT_ENERGY_MAX, KERNO_DEFAULT_ENERGY_DELTA)
{
  
}