#include <utility>

//
// Created by jorge on 28/10/2022.
//

namespace Core{
    inline Entity::Entity(std::string name): name(std::move(name)){
        components = std::make_unique<componentsMap>();
    }

    template<typename T>
    std::vector<T*> Entity::getComponents() {
        if (!components->count(typeid(T))) return nullptr;
        return (*components)[typeid(T)];
    }

    template<typename T>
    T* Entity::getComponent() {
        auto results = getComponents<T>();
        results == nullptr ? nullptr : results[0];
    }

    template<typename T>
    void Entity::addComponent(BaseComponent* component) {
        std::vector<std::unique_ptr<BaseComponent>> existing;

        if (components->count(typeid(T))){
            existing = (*components)[typeid(T)];
            //existing.push_back(component);
        }
        else{
            auto pair = std::pair<componentPair>(typeid(T),existing);
            components->insert(pair);
        }

    }

    inline Entity::~Entity() {
//        for(auto & component : *components)
//        {
//            for (auto & i : component.second) {
//                delete i;
//            }
//        }
//
//        delete components;
        std::cout<<"cleaning"<<std::endl;
    }


}
