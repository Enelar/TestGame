#include "../entity/entity.h"

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

  void OnCreate() override;
  void OnDraw() override;
  void OnUpdate( double dt ) override;
private:
  void SyncValues();
  template<typename OriginT>
  b2Vec2 &Update( b2Vec2 &, b2Vec2 &(OriginT::*)() ); 
};

template<typename T>
struct obj_camera::connector
{
  typedef T (*connector_method)( const T & );
private:
  T &origin, &depended;
  connector_method method;
public:
  connector( connector && );
  connector( T &origin, T &depended, connector_method );

  connector(const connector &);
  void operator=(const connector &);

  ~connector();
  T &operator *();
};

template<typename T>
obj_camera::connector<T>::connector( T &_origin, T &_depended, connector_method _cm )
  : origin(_origin), depended(_depended), method(_cm)
{

}

template<typename T>
obj_camera::connector<T>::connector( connector &&a )
  : origin(a.origin), depended(a.depended), method(a.method)
{
}

template<typename T>
obj_camera::connector<T>::~connector()
{
  depended = method(origin);
}

template<typename T>
T &obj_camera::connector<T>::operator *()
{
  return origin;
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