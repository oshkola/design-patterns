#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

//Product 
class Car
{
    string _model;
    int _weight;
    string _engine;

public:
    void set_model(string model)
    {
        _model = model;
    }
    void set_weight(int weight)
    {
        _weight = weight;
    }
    void set_engine(string engine)
    {
        _engine = engine;
    }
    void show() const
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
    virtual ~AbstractBuilder() {};
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
    virtual ~MaserattiBuilder() {};
    virtual void set_model() override
    {
        car.set_model("Maseratti");
    }
    virtual void set_weight() override
    {
        car.set_weight(1880);
    }
    virtual void build_engine() override
    {
        car.set_engine("V8");

    }
};

//concrete builder 2
class FerrariBuilder : public AbstractBuilder
{
public:
    virtual ~FerrariBuilder() {};
    virtual void set_model() override
    {
        car.set_model("Ferrari");
    }
    virtual void set_weight() override
    {
        car.set_weight(1565);
    }
    virtual void build_engine() override
    {
        car.set_engine("F136");

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