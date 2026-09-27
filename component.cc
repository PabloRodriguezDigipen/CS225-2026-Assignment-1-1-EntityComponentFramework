#include "component.hh"
#include <iostream>

//virtual destructor
ICloneable::~ICloneable(){}
//returns a copy of this
ICloneable* ICloneable::clone(){
    return this;
}

//virtual destructor
IPrintable::~IPrintable(){}
//porints generic text to prove it can print
void IPrintable::print(){
    std::cout << "Prove that it prints" << std::endl;
}

//virtual destructor
IComparable::~IComparable(){}

//returns id of this component
int Component::get_id(){
    return id;
}

//overrided function to compare
bool Component::compare_to(IComparable& compare){
    //cast into a component
    Component& component = dynamic_cast<Component&>(compare);
    //compare component ids
    return get_id() == component.get_id();
}

//sets new owner
void Component::set_owner(Entity* newOwner){
    owner = newOwner;
}

//returns current owner
Entity* Component::get_owner(){
    return owner;
}