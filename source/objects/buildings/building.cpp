#include "building.h"

building::building(_STL::string _texture_str, b2Vec2 _pos, b2Vec2 _size, 
  float32 _life, word _energy_max, int _energy_delta)
: entity(_texture_str, _pos, _size, _life),
eng(_energy_max, _energy_delta)
{

}