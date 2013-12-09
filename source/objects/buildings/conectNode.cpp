#include "conectNode.h"

conectNode::conectNode(_STL::string _texture_str, word _distance, b2Vec2 _pos, b2Vec2 _size,
  float32 _life, word _energy_max, int _energy_delta)
: building(_texture_str, _pos, _size, _life,
  _energy_max, _energy_delta)
{
  distance = _distance;
}