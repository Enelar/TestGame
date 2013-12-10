#include "proxy.h"

namespace
{
  static class test
  {
  public:
    test()
    {
      b2Vec2 a(0, 0);


      {
         [&]()
          {
            return proxy<b2Vec2>(a);
         }() += b2Vec2(1, 1);
      }
    }
  } A;
}