#include "../entity/entity.h"
#include "../proxy.h"

class obj_camera : public entity
{
  b2Vec2 pos, vel, acc;
public:
  template<typename T> struct connector;
  obj_camera();
  ~obj_camera();

  connector<b2Vec2> Position();
  connector<b2Vec2> Velosity();
  connector<b2Vec2> Acceleration();

  b2Vec2 Size() const;
  b2Vec2 &Size();

  void OnUpdate( double dt ) override;

private:
  template<typename OriginT, typename RetT>
  b2Vec2 &Update( b2Vec2 &, RetT (OriginT::*)() ); 
};

template<typename T>
struct obj_camera::connector : public proxy<T>
{
  typedef T (*connector_method)( const T & );
private:
  T &depended;
  connector_method method;
public:
  connector( connector && );
  connector( T &origin, T &depended, connector_method );

  connector(const connector &);
  void operator=(const connector &);

  ~connector();
  operator proxy<T> &();
};

template<typename T>
obj_camera::connector<T>::connector( T &_origin, T &_depended, connector_method _cm )
  : proxy(_origin), depended(_depended), method(_cm)
{

}

template<typename T>
obj_camera::connector<T>::connector( connector &&a )
  : proxy(a.origin), depended(a.depended), method(a.method)
{
}

template<typename T>
obj_camera::connector<T>::~connector()
{
  depended = method(convert<T>(*this));
}

template<typename T>
obj_camera::connector<T>::operator proxy<T> &()
{
  return *this;
}


template<typename T>
obj_camera::connector<T>::connector(const connector &)
{
  static_assert("You cant copy this object");
}

template<typename T>
void obj_camera::connector<T>::operator=(const connector &)
{
  static_assert("You cant assign this object");
}

template<typename B, typename T>
B convert( const obj_camera::connector<T> &a )
{
  const proxy<T> &res = a;
  return convert<B>(res);
}