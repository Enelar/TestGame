#pragma once

#include "../stdafx.h"
#include "entity.h"
#include <map>
#include <list>

class entity_manager
{
  std::map<cocos2d::CCObject *, entity *> objects;
  std::map<entity *, entity *> zero_sprite;

public:
  void AddObject( entity & );
  void RemoveObject( entity & );
  void AddObject( entity *const );
  void RemoveObject( entity *const );
  void Update( double dt );
#if CPP11_SUPPORTED
  void Foreach( std::function<void(entity *const)> );
#endif
  void Redraw();
  ~entity_manager();

  static entity_manager &Instance();
};