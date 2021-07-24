#include <iostream>

using std::cout;
using std::endl;

class icomponent
{
public:
    virtual void operation() const = 0;
    virtual ~icomponent(){}
};

class component: public icomponent
{
public:
    virtual void operation() const override
    {
        cout << "component::operation()" << endl;
    }
};

class decorator: public icomponent
{
protected:    
    icomponent *_component;
    
public:
    decorator(icomponent* component): _component{component}{}
    virtual void operation() const override
    {
        cout << "some decoration" << endl;
        this->_component->operation();
    }
};

class concrete_decorator: public decorator
{
public:
    concrete_decorator(icomponent* component) : decorator(component) {}
    virtual void operation() const override
    {
        cout << "some decoration" << endl;
        _component->operation();
    }
};

void client_code(icomponent* component)
{
    component->operation();
}

int main()
{
    icomponent* comp = new component();
    comp->operation();
    
    icomponent* dec = new concrete_decorator(comp);
    dec->operation();
    
    delete comp;
    delete dec;
    
}
