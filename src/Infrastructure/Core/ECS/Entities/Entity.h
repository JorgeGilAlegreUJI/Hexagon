//
// Created by jorge on 28/10/2022.
//

#ifndef HEXAGON_ENTITY_H
#define HEXAGON_ENTITY_H
#include <vector>
#include <unordered_map>
#include <typeindex>
#include <memory>
#define componentPair  std::type_index,std::shared_ptr<BaseComponent>
#define componentsMap  std::unordered_map<componentPair>



namespace Core{
    class BaseComponent;
    class Entity {
    private:
    public:

// Constructors
        explicit Entity(std::string name);
        ~Entity();

// Components
        template<typename T>
        void addComponent(const std::shared_ptr<T>& component,const std::shared_ptr<Entity>& entity);
        template<typename T>
        std::shared_ptr<T> getComponent();

// Transform
        std::pair<int,int> setLocalPosition(int x,int y);
        float getGlobalScale();
        int getGlobalX();
        int getGlobalY();

        float localScale;
        int localX,localY;

//Hierarchy
        std::unique_ptr<componentsMap> components;
        std::string name;
        std::shared_ptr<Entity> parent;
        std::vector<std::shared_ptr<Entity>> children;


    };


}

#include "Entity.tpp"
#endif //HEXAGON_ENTITY_H
