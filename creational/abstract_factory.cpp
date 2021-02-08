#include <iostream>

using std::cout;
using std::endl;

//Abstract product 1
class Infantry
{
public:
	virtual ~Infantry() {}
	virtual void show_info() const = 0;
};

class Swordsman : public Infantry

{
public:
	virtual ~Swordsman() {}
	virtual void show_info() const override
	{
		cout << "swordsman" << endl;
	}
};

class Spearman : public Infantry
{
public:
	virtual ~Spearman() {}
	virtual void show_info() const override
	{
		cout << "spearman" << endl;
	}
};

//Abstract product 2
class Cavalry
{
public:
	virtual ~Cavalry() {}
	virtual void show_info() const = 0;
};


class HorseArcher : public Cavalry
{
public:
	virtual ~HorseArcher() {}
	virtual void show_info() const override
	{
		cout << "horse archer" << endl;
	}
};

class HeavyCavalry : public Cavalry
{
public:
	virtual ~HeavyCavalry() {}
	virtual void show_info() const override
	{
		cout << "heavy cavalry" << endl;
	}
};


//Abstract factory
class Recruiter
{
public:
	virtual ~Recruiter() {}
	virtual Infantry* hire_infantry() const = 0;
	virtual Cavalry* hire_cavalry() const = 0;
};

class RomanRecruiter: public Recruiter
{
public:
	virtual ~RomanRecruiter() {};
	virtual Infantry* hire_infantry() const override
	{
		return new Spearman();
	}
	virtual Cavalry* hire_cavalry() const override
	{
		return new HeavyCavalry();
	}
};

class MongolRecruiter: public Recruiter
{
public:
	virtual ~MongolRecruiter() {};
	virtual Infantry* hire_infantry() const override
	{
		return new Swordsman();
	}
	virtual Cavalry* hire_cavalry() const override
	{
		return new HorseArcher();
	}
};

int main()
{
	Recruiter* recruiter = new RomanRecruiter();
	recruiter->hire_infantry()->show_info();
	recruiter->hire_cavalry()->show_info();

	Recruiter* recruiter2 = new MongolRecruiter();
	recruiter2->hire_infantry()->show_info();
	recruiter2->hire_cavalry()->show_info();

	delete recruiter;
	delete recruiter2;
}