#include "energy.h"

energy::energy(word _max, int _deltaPerSec, word _now)
{
  max = _max;
  deltaPerSec = prevState = _deltaPerSec;
  now = _now;
}

void energy::UpdateState()
{
  prevState = now;
}

word &energy::Max()
{
  return max;
}
word &energy::Now()
{
  return now;
}
int &energy::DeltaPerSec()
{
  return deltaPerSec;
}

int energy::State()
{
  return now - prevState;
}