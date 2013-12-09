#include "../entity/entity.h"

class energy
{
private:
  word max, now;
  int delta;
public:
  energy::energy(word _max, word _delta = 0, int _now = 0);

  word &Max();
  word &Now();
  int &Delta();
};