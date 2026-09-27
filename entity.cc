#include "entity.hh"

//returns the ammount of components
int Entity::component_count(){
    return components.size();
}

//attaches a new component
void Entity::attach(Component* component){
    //set the owner of the component to this entity
    component->set_owner(this);
    //add the component to the entity
    components.push_back(component);
}

//returns the component on the given index
Component& Entity::operator[](int index){
    return *components[index];
}

//attaches new component by adress
void Entity::attach(Component& component){
    //get the IClonable of the given component and cast it to a component
    Component* newComponent = dynamic_cast<Component*>(component.clone());
    //call the attaching function for pointers
    attach(newComponent);
}