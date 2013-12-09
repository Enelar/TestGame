#include "../stdafx.h"

class energy
{
private:
  word max, now;
  int delta;
public:
  energy::energy(word max, int delta = 0, word now = 0);

  word &Max();
  word &Now();
  int &Delta();
};