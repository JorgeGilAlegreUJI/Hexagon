#include <utility>
#include "Entity.h"
#include "../../Exceptions/Core_Exception.h"
#include <iostream>

//
// Created by jorge on 28/10/2022.
//

namespace Core{
    inline Entity::Entity(std::string name): name(std::move(name)),localX(0),localY(0),localScale(1){
        components = std::make_unique<componentsMap>();
    }

    template<typename T>
    std::weak_ptr<T> Entity::getComponent() {
        std::weak_ptr<T> weak{};
        if (components->count(typeid(T)))
        {
            auto component = std::static_pointer_cast<T>(components->at(typeid(T)));
            weak = std::weak_ptr<T>(component);
        }
        return weak;
    }

    template<typename T>
    void Entity::addComponent(std::shared_ptr<T> &component) {

        if (components->count(typeid(T))){
            throw Core_Exception("Entity already has that component");
        }
        component->entity = std::weak_ptr<Entity>(shared_from_this());
        components->template emplace(typeid(T),component);
    }

    inline Entity::~Entity() {
        std::cout<<name << " destroyed"<<std::endl;
    }

    inline void getX(Entity *entity,int &result)
    {
        result += entity->localX;
        if(entity->parent != nullptr)getX(entity->parent.get(),result);
    }
    inline int Entity::getGlobalX() {
        int result = 0;
        getX(this,result);
        return result;
    }

    inline void getY(Entity *entity,int &result)
    {
        result += entity->localY;
        if(entity->parent != nullptr)getY(entity->parent.get(),result);
    }

    inline int Entity::getGlobalY() {
        int  result = 0;
        getY(this,result);
        return result;
    }

    inline std::pair<int, int> Entity::setLocalPosition(int x, int y) {
        std::pair<int, int> result;
        result.first = x; localX = x;
        result.second = y; localY = y;
        return result;
    }

    inline void getScale(Entity *entity,float &result)
    {
        result *= entity->localScale;
        if(entity->parent != nullptr)getScale(entity->parent.get(),result);
    }

    inline float Entity::getGlobalScale() {
        float result = 1;
        getScale(this,result);
        return result;
    }


}
