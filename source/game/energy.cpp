#include "energy.h"

energy::energy(word _max, word _delta, int _now)
{
  max = _max;
  delta = _delta;
  now = _now;
}

word &energy::Max()
{
  return max;
}
word &energy::Now()
{
  return now;
}
int &energy::Delta()
{
  return delta;
}