#pragma once

#include "stdafx.h"

template<typename T>
class proxy : object
{
  T &origin;
public:
  proxy( proxy && );
  proxy( T &origin );

  proxy( const proxy & );
  void operator=( const proxy & ) const;

  ~proxy();

#define DECLARE_UNAR_OPERATOR(op) \
  DECLARE_SIDE_EFFECT_OPERATOR(op, const T &arg, )
#define DECLARE_SIDE_EFFECT_OPERATOR(op, arg, overload) \
  DECLARE_OPERATOR(T &, op, arg, overload)
#define DECLARE_OPERATOR(ret, name, arg, overload) \
  ret operator name( arg ) overload;

  DECLARE_UNAR_OPERATOR(+=)
  DECLARE_UNAR_OPERATOR(-=)
  DECLARE_UNAR_OPERATOR(*=)
  DECLARE_UNAR_OPERATOR(/=)

  DECLARE_SIDE_EFFECT_OPERATOR(*, void,)
  DECLARE_OPERATOR(, T *, , )
  DECLARE_OPERATOR(T *,->,,)
  DECLARE_OPERATOR(const T *,->,,const)
};

#define TEMPLATE template<typename T> \
  auto proxy<T>
#define TEMPLATE_SPECIAL template<typename T> \
  proxy<T>

#undef DECLARE_OPERATOR
#define DECLARE_OPERATOR(ret, name, arg, overload) \
  TEMPLATE::operator name( arg ) overload -> ret

#define UNAR_OPERATOR(op)  \
  DECLARE_UNAR_OPERATOR(op) \
  {                          \
    origin op arg;            \
    return origin;             \
  }

UNAR_OPERATOR(+=)
UNAR_OPERATOR(-=)
UNAR_OPERATOR(*=)
UNAR_OPERATOR(/=)

DECLARE_SIDE_EFFECT_OPERATOR(*, void,)
{
  return *origin;
}

DECLARE_OPERATOR(T *,->,,)
{
  return origin;
}

DECLARE_OPERATOR(const T *,->,,const)
{
  return origin;
}


TEMPLATE_SPECIAL::operator T *()
{
  return &origin;
}

#undef DECLARE_UNAR_OPERATOR
#undef DECLARE_SIDE_EFFECT_OPERATOR
#undef DECLARE_OPERATOR
#undef UNAR_OPERATOR

TEMPLATE_SPECIAL::proxy( proxy &&a )
  : origin(a.origin)
{

}

TEMPLATE_SPECIAL::proxy( T &_origin )
  : origin(_origin)
{
}

TEMPLATE_SPECIAL::proxy( const proxy & )
{
  compile_error("Copy to proxy forbidden");
}

TEMPLATE::operator=( const proxy & ) const -> void
{
  compile_error("Assign to proxy forbidden");
}

TEMPLATE_SPECIAL::~proxy()
{
}