#include <iostream>

using std::cout;
using std::endl;

//An old interface we have to use but can't modify
class old_interface
{
public:
	virtual void update() const
	{
		cout << "update() from the old interface" << endl;
	}
};

//A new interface we have to adapt
class adaptee
{
public:
	void __update__() const
	{
		cout << "__update__() from the new interface" << endl;
	}
};

//class adapter does the trick
class adapter: public old_interface, public adaptee
{
public:
	void update() const override
	{
		cout << "adapter::update() to call..." << endl;
		__update__();
	}
};


void client_code(old_interface* old)
{
	old->update();
}


int main()
{
	old_interface* target = new adapter();
	client_code(target);

	delete target;
}
