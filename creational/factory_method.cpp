#include <iostream>
#include <vector>

using namespace std;

//abstract product
class Lexeme
{
public:
	virtual ~Lexeme() {}
	virtual void show_info() const = 0;
};

//concrete product 1
class Operator: public Lexeme
{
public:
	virtual ~Operator() {}
	virtual void show_info() const override
	{
		cout << "operator" << endl;
	}
};

//concrete product 2
class Identifier: public Lexeme
{
public:
	virtual ~Identifier() {}
	virtual void show_info() const override
	{
		cout << "identifier" << endl;
	}
};

//concrete prduct 3
class Number: public Lexeme
{
public:
	virtual ~Number() {}
	virtual void show_info() const override
	{
		cout << "number" << endl;
	}
};

//abstarct creator
class LexemeGenerator
{
public:
	virtual ~LexemeGenerator() {}
	virtual Lexeme* generate_lexeme() const = 0;
};

//concrete creator 1
class OpGenerator: public LexemeGenerator
{
public:
	virtual ~OpGenerator() {}
	virtual Lexeme* generate_lexeme() const override
	{
		return new Operator();
	}
};

//concrete creator 2
class IdGenerator: public LexemeGenerator
{
public:
	virtual ~IdGenerator() {}
	virtual Lexeme* generate_lexeme() const override
	{
		return new Identifier();
	}
};

//concrete creator 3
class NumGenerator: public LexemeGenerator
{
public:
	virtual ~NumGenerator() {}
	virtual Lexeme* generate_lexeme() const override
	{
		return new Number();
	}
};

int main()
{
	vector<Lexeme*> lexemes;
	LexemeGenerator* op_generator = new OpGenerator();
	LexemeGenerator* id_generator = new IdGenerator();
	LexemeGenerator* num_generator = new NumGenerator();

	lexemes.push_back(op_generator->generate_lexeme());
	lexemes.push_back(id_generator->generate_lexeme());
	lexemes.push_back(num_generator->generate_lexeme());

	for (auto token : lexemes)
		token->show_info();

	delete op_generator;
	delete id_generator;
	delete num_generator;
}