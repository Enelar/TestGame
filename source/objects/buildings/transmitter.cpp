#include "transmitter.h"

namespace
{
  const float32 transmitter_DEFAULT_LIFE = 17;
  const b2Vec2 transmitter_DEFAULT_SIZE = b2Vec2(32, 32);
  const word transmitter_DEFAULT_ENERGY_MAX = 0;
  const int transmitter_DEFAULT_ENERGY_DELTA = -1;
  const word transmitter_DEFAULT_DISTANCE = 65;
  const _STL::string transmitter_DEFAULT_SPRITE_ADRESS = "transmitter.png";
};

transmitter::transmitter(b2Vec2 _pos)
: conectNode(transmitter_DEFAULT_SPRITE_ADRESS, transmitter_DEFAULT_DISTANCE, _pos, transmitter_DEFAULT_SIZE, transmitter_DEFAULT_LIFE,
transmitter_DEFAULT_ENERGY_MAX, transmitter_DEFAULT_ENERGY_DELTA)
{

}