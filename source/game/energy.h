#include "../stdafx.h"

class energy
{
private:
  word max, now;
  int deltaPerSec, prevState;
public:
  energy::energy(word max, int delta = 0, word now = 0);
  void energy::UpdateState();

  word &Max();
  word &Now();
  int &DeltaPerSec();
  int State();
};