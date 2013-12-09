#include "transmitter.h"

namespace
{
  const float32 KERNO_DEFAULT_LIFE = 17;
  const b2Vec2 KERNO_DEFAULT_SIZE = b2Vec2(32, 32);
  const word KERNO_DEFAULT_ENERGY_MAX = 0;
  const int KERNO_DEFAULT_ENERGY_DELTA = -1;
  const _STL::string KERNO_DEFAULT_SPRITE_ADRESS = "transmitter.png";
};

transmitter::transmitter(b2Vec2 _pos)
: building(KERNO_DEFAULT_SPRITE_ADRESS, _pos, KERNO_DEFAULT_SIZE, KERNO_DEFAULT_LIFE,
KERNO_DEFAULT_ENERGY_MAX, KERNO_DEFAULT_ENERGY_DELTA)
{

}