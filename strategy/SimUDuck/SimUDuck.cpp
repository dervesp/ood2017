#include <iostream>
#include <memory>
#include <cassert>
#include <vector>
#include <functional>

using namespace std;

namespace
{
	typedef std::function<void()> FlyBehaviorFn;

	FlyBehaviorFn MakeWithWingsFlyBehavior()
	{
		return[flyCount = 0]() mutable { cout << "I'm flying with wings! #" << ++flyCount << endl; };
	}

	FlyBehaviorFn MakeNoWayFlyBehavior()
	{
		return []() {};
	}

	typedef std::function<void()> QuackBehaviorFn;

	QuackBehaviorFn MakeQuackQuackBehavior()
	{
		return []() { cout << "Quack Quack!" << endl; };
	}

	QuackBehaviorFn MakeSqueekQuackBehavior()
	{
		return []() { cout << "Squeek!" << endl; };
	}

	QuackBehaviorFn MakeMuteQuackBehavior()
	{
		return []() {};
	}

	typedef std::function<void()> DanceBehaviorFn;

	DanceBehaviorFn MakeWaltzDanceBehavior()
	{
		return []() { cout << "I'm dancing waltz!" << endl; };
	}

	DanceBehaviorFn MakeMinuetDanceBehavior()
	{
		return []() { cout << "I'm dancing minuet!" << endl; };
	}

	DanceBehaviorFn MakeNoWayDanceBehavior()
	{
		return []() {};
	}
}

class Duck
{
public:
	Duck(FlyBehaviorFn flyBehaviorFn, QuackBehaviorFn quackBehaviorFn, const DanceBehaviorFn & danceBehaviorFn)
	{
		SetFlyBehaviorFn(flyBehaviorFn);
		SetQuackBehaviorFn(quackBehaviorFn);
		SetDanceBehaviorFn(danceBehaviorFn);
	}
	void Quack() const
	{
		m_quackBehaviorFn();
	}
	void Swim()
	{
		cout << "I'm swimming" << endl;
	}
	void Fly()
	{
		m_flyBehaviorFn();
	}
	void Dance()
	{
		m_danceBehaviorFn();
	}
	void SetFlyBehaviorFn(const FlyBehaviorFn & flyBehaviorFn)
	{
		m_flyBehaviorFn = flyBehaviorFn;
	}
	void SetQuackBehaviorFn(const QuackBehaviorFn & quackBehaviorFn)
	{
		m_quackBehaviorFn = quackBehaviorFn;
	}
	void SetDanceBehaviorFn(const DanceBehaviorFn & danceBehaviorFn)
	{
		m_danceBehaviorFn = danceBehaviorFn;
	}
	virtual void Display() const = 0;
	virtual ~Duck() {};
private:
	FlyBehaviorFn m_flyBehaviorFn;
	QuackBehaviorFn m_quackBehaviorFn;
	DanceBehaviorFn m_danceBehaviorFn;
};

class MallardDuck : public Duck
{
public:
	MallardDuck()
		: Duck(MakeWithWingsFlyBehavior(), MakeQuackQuackBehavior(), MakeWaltzDanceBehavior())
	{
	}

	void Display() const override
	{
		cout << "I'm mallard duck" << endl;
	}
};

class RedheadDuck : public Duck
{
public:
	RedheadDuck()
		: Duck(MakeWithWingsFlyBehavior(), MakeQuackQuackBehavior(), MakeMinuetDanceBehavior())
	{
	}
	void Display() const override
	{
		cout << "I'm redhead duck" << endl;
	}
};

class DeckoyDuck : public Duck
{
public:
	DeckoyDuck()
		: Duck(MakeNoWayFlyBehavior(), MakeMuteQuackBehavior(), MakeNoWayDanceBehavior())
	{
	}
	void Display() const override
	{
		cout << "I'm deckoy duck" << endl;
	}
};

class RubberDuck : public Duck
{
public:
	RubberDuck()
		: Duck(MakeNoWayFlyBehavior(), MakeSqueekQuackBehavior(), MakeNoWayDanceBehavior())
	{
	}
	void Display() const override
	{
		cout << "I'm rubber duck" << endl;
	}
};

class ModelDuck : public Duck
{
public:
	ModelDuck()
		: Duck(MakeNoWayFlyBehavior(), MakeMuteQuackBehavior(), MakeNoWayDanceBehavior())
	{
	}
	void Display() const override
	{
		cout << "I'm model duck" << endl;
	}
};

void DrawDuck(Duck const& duck)
{
	duck.Display();
}

void PlayWithDuck(Duck & duck)
{
	duck.Quack();
	duck.Dance();
	duck.Fly();
	duck.Fly();
	duck.Fly();
	DrawDuck(duck);
	cout << "-----------" << endl;
}


void main()
{
	MallardDuck mallarDuck;
	PlayWithDuck(mallarDuck);
	RedheadDuck redheadDuck;
	PlayWithDuck(redheadDuck);
	RubberDuck rubberDuck;
	PlayWithDuck(rubberDuck);
	DeckoyDuck deckoyDuck;
	PlayWithDuck(deckoyDuck);
	ModelDuck modelDuck;
	PlayWithDuck(modelDuck);
	modelDuck.SetFlyBehaviorFn(MakeWithWingsFlyBehavior());
	modelDuck.SetQuackBehaviorFn(MakeSqueekQuackBehavior());
	modelDuck.SetDanceBehaviorFn(MakeWaltzDanceBehavior());
	PlayWithDuck(modelDuck);
}