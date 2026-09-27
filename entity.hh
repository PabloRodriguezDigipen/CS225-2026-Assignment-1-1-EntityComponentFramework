#pragma once

#include "component.hh"
#include <vector>

class Entity {
    protected:
        //vector of components is the container type i chose
        std::vector<Component*> components;
    public:
        //returns component ammount
        int component_count();
        //attaches new component
        void attach(Component* component);
        //overloaded []operator to find components
        Component& operator[](int index);
        //attaches new component by adress
        void attach(Component& component);
};