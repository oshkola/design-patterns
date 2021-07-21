#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::unique_ptr;

//subsystem 1
class engine
{
public:
	 void start() const
	 {
	 	cout << "engine::starting" << endl;
	 }
	 void stop() const
	 {
	 	cout << "engine::stopping" << endl;
	 }
};

//subsystem 2
class water_filler
{
public:
	void fill(int volume) const
	{
		cout << "filling the container with " << volume << " l" << endl;
	}
};

//subsystem 3
class heater
{
public:
	void heat(int temp) const
	{
		cout << "heating up to " << temp << " degrees" << endl;	
	}
};

//subsystem 4
class dryer
{
public:
	void dry(int duration) const
	{
		cout << "launching dryer for " << duration << " mins" << endl;
	}	
};

//auxiliary enum
enum class regime{cotton, wool};

//facade
class washing_machine
{
	//holds the objects of all subsystems
	engine _engine;
	water_filler _water;
	heater _heater;
	dryer _dryer;
	regime _regime;

public:
	washing_machine(): _regime{regime::cotton}{}
	washing_machine(regime reg): _regime{reg}{}

	//choose work logic
	void do_work() const
	{
		switch(_regime)
		{
			case regime::cotton:
				wash_cotton();
				break;

			case regime::wool:
				wash_wool();
				break;

			default:
				cout << "unknown regime" << endl;
				break;
		}
	}
	void wash_cotton() const
	{
		cout << "dealing with cotton" << endl;
		_engine.start();
		_water.fill(10);
		_heater.heat(40);
		_dryer.dry(17);
		_engine.stop();
	}

	void wash_wool() const
	{
		cout << "dealing with wool" << endl;
		_engine.start();
		_water.fill(20);
		_heater.heat(70);
		_dryer.dry(40);
		_engine.stop();
	}
};

void client_code(washing_machine* machine)
{
	machine->do_work();
}

int main()
{
	washing_machine* facade = new washing_machine();
	client_code(facade);

	delete facade;
}
