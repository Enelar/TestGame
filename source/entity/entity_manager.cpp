#include "entity_manager.h"

void entity_manager::AddObject( entity &obj )
{
  if (obj.sprite)
    objects.insert(std::pair<cocos2d::CCObject *, entity *>(obj.sprite, &obj));
  else
    zero_sprite.insert(std::pair<entity *, entity *>(&obj, &obj));
}

void entity_manager::RemoveObject( entity &obj )
{
  if (obj.sprite)
    objects.erase(obj.sprite);
  else
    zero_sprite.erase(&obj);
}

void entity_manager::Update( double dt )
{
  REQUIRE_CPP11
  auto ForeachEntity = [=]( entity *const obj )
  {
    obj->Update(dt);
  };
  std::for_each(objects.begin(), objects.end(), [ForeachEntity]( std::pair<cocos2d::CCObject *const, entity *> &pair )
  {
    ForeachEntity(pair.second);
  });

  std::for_each(zero_sprite.begin(), zero_sprite.end(), [ForeachEntity]( std::pair<entity *const, entity *> &pair )
  {
    ForeachEntity(pair.second);
  });
}

#if CPP11_SUPPORTED
void entity_manager::Foreach( std::function<void(entity *const)> ForeachEntity )
{
  std::for_each(objects.begin(), objects.end(), [ForeachEntity]( std::pair<cocos2d::CCObject *const, entity *> &pair )
  {
    ForeachEntity(pair.second);
  });

  std::for_each(zero_sprite.begin(), zero_sprite.end(), [ForeachEntity]( std::pair<entity *const, entity *> &pair )
  {
    ForeachEntity(pair.second);
  });
}
#endif

void entity_manager::Redraw()
{
  REQUIRE_CPP11
  auto ForeachEntity = [=]( entity *const obj )
  {
    obj->OnDraw();
  };
  std::for_each(objects.begin(), objects.end(), [ForeachEntity]( std::pair<cocos2d::CCObject *const, entity *> &pair )
  {
    ForeachEntity(pair.second);
  });

  std::for_each(zero_sprite.begin(), zero_sprite.end(), [ForeachEntity]( std::pair<entity *const, entity *> &pair )
  {
    ForeachEntity(pair.second);
  });
}

void entity_manager::AddObject( entity *const obj )
{
  if (obj)
    AddObject(*obj);
}

void entity_manager::RemoveObject( entity *const obj )
{
  if (obj)
    RemoveObject(*obj);
}

entity_manager::~entity_manager()
{
}

namespace
{
  static entity_manager *man = nullptr;
}

entity_manager &entity_manager::Instance()
{
  if (!man)
    man = new entity_manager();
  return *man;


}