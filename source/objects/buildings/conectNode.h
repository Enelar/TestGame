#include "building.h"

class conectNode : public building
{
private:
  int distance;
public:

  conectNode::conectNode(_STL::string texture_str, word distance, b2Vec2 pos, b2Vec2 size,
    float32 life, word energy_max, int energy_delta);

};