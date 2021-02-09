#include <iostream>
#include <vector>

using namespace std;

class A
{
public:
	virtual ~A(){}
	virtual A* clone() const = 0;
};

class B : public A
{
public:
	B()
	{
		cout << "B()" << endl;
	}
	B(const B&)
	{
		cout << "B(const B&)" << endl;
	}
	virtual ~B(){}
	virtual A* clone() const override
	{
		return new B(*this);
	}
};

class C : public A
{
public:
	C()
	{
		cout << "C()" << endl;
	}
	C(const C&)
	{
		cout << "C(const C&)" << endl;
	}
	virtual ~C(){}
	virtual A* clone() const override
	{
		return new C(*this);
	}
};

int main()
{
	vector<A*> prot {new B(), new C()};

	for(auto x : prot)
	{
		A* a = x->clone();
		delete a;
	}
}