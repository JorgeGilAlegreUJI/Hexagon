//
// Created by jorge on 28/10/2022.
//

#ifndef HEXAGON_ENTITY_H
#define HEXAGON_ENTITY_H
#include <vector>
#include <unordered_map>
#include <typeindex>
#include <memory>
#define componentPair  std::type_index,std::vector<std::unique_ptr<BaseComponent>>
#define componentsMap  std::unordered_map<componentPair>



namespace Core{
    class BaseComponent;
    class Entity {
    private:
    public:
        std::unique_ptr<componentsMap> components;
        explicit Entity(std::string name);
        template<typename T>
        std::vector<T*> getComponents();

        template<typename T>
        T *getComponent();

        template<typename T>
        void addComponent(BaseComponent* component);

        ~Entity();

        std::string name;
        Entity* parent;
        std::vector<Entity*> children;
    };


}

#include "Entity.tpp"
#endif //HEXAGON_ENTITY_H
