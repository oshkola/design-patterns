#include <iostream>
#include <string>

using namespace std;

//Product
class Car
{
    public:
    string _model;
    int _weight;
    string _engine;
   
    void show()
    {
        cout << "model : " << _model << endl;
        cout << "weight : " << _weight << endl;
        cout << "engine : " << _engine << endl;
    }
};

class AbstractBuilder
{
    protected:
    Car car;

    public:
    virtual ~AbstractBuilder(){};
    virtual void set_model() = 0;
    virtual void set_weight() = 0;
    virtual void build_engine() = 0;
    virtual Car get_car()
    {
        return car;
    }  
};

//concrete builder 1
class MaserattiBuilder : public AbstractBuilder
{
    public:
    virtual ~MaserattiBuilder(){};
    virtual void set_model() override
    {
        car._model = "Maseratti";
    }
    virtual void set_weight() override
    {
        car._weight = 1880;
    }
    virtual void build_engine() override
    {
        car._engine = "V8";
       
    }
};

//concrete builder 1
class FerrariBuilder : public AbstractBuilder
{
    public:
    virtual ~FerrariBuilder(){};
    virtual void set_model() override
    {
        car._model = "Ferrari";
    }
    virtual void set_weight() override
    {
        car._weight = 1565;
    }
    virtual void build_engine() override
    {
        car._engine = "F136";
       
    }
};

class Director
{
    AbstractBuilder* builder;
   
    public:
   
    void set_builder(AbstractBuilder * b)
    {
        builder = b;
    }
   
    Car get_car()
    {
        return builder->get_car();
    }
   
    void construct_car()
    {
        builder->set_model();
        builder->set_weight();
        builder->build_engine();
    }
};

int main()
{
    Director d;
    MaserattiBuilder m;
    d.set_builder(&m);
    d.construct_car();
    Car maseratti = d.get_car();
    maseratti.show();
   
    FerrariBuilder f;
    d.set_builder(&f);
    d.construct_car();
    Car ferrari = d.get_car();
    ferrari.show();
}