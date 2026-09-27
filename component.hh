#pragma once

class ICloneable {
    public:
    //virtual destructor
        virtual ~ICloneable();
        //cloning function
        ICloneable* clone();
};

class IPrintable {
    public:
    //virtual destructor
        virtual ~IPrintable();
        //printing function
        void print();
};

class IComparable {
    public:
    //virtual destructor
        virtual ~IComparable();
        //compares two comparable objects
        virtual bool compare_to(IComparable& compare) = 0;
};

//forward declaration
class Entity;

//component inherits all interfaces
class Component : public ICloneable, public IPrintable, public IComparable {
    protected:
        //id of this component
        int id;
        //owner of the component, this is the entity it is put in
        Entity* owner;
    public:
        //returns the id of the component
        int get_id();
        //override of the comparing function
        bool compare_to(IComparable& compare) override;
        //function to set a new owner
        void set_owner(Entity* newOwner);
        //returns current owner
        Entity* get_owner();
};