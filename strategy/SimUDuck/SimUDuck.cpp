#include <iostream>
#include <memory>
#include <cassert>
#include <vector>
#include <functional>

using namespace std;

enum class FlyBehavior
{
	NO_WAY,
	WITH_WINGS,
};
enum class QuackBehavior
{
	MUTE,
	SQUEAK,
	QUACK,
};
enum class DanceBehavior
{
	NO_WAY,
	MINUET,
	WALTZ,
};

namespace
{
	typedef std::function<void()> FlyBehaviorFn;

	FlyBehaviorFn CreateFlyBehavior(FlyBehavior behavior)
	{
		switch (behavior)
		{
		case FlyBehavior::WITH_WINGS:
			return [flyCount = 0]() mutable { cout << "I'm flying with wings! #" << ++flyCount << endl; };
			break;
		default:
			return []() {};
		}
	}

	typedef std::function<void()> QuackBehaviorFn;

	QuackBehaviorFn CreateQuackBehavior(QuackBehavior behavior)
	{
		switch (behavior)
		{
		case QuackBehavior::QUACK:
			return []() { cout << "Quack Quack!" << endl; };
		case QuackBehavior::SQUEAK:
			return []() { cout << "Squeek!" << endl; };
		default:
			return []() {};
		}
	}

	typedef std::function<void()> DanceBehaviorFn;

	DanceBehaviorFn CreateDanceBehavior(DanceBehavior behavior)
	{
		switch (behavior)
		{
		case DanceBehavior::WALTZ:
			return []() { cout << "I'm dancing waltz!" << endl; };
		case DanceBehavior::MINUET:
			return []() { cout << "I'm dancing minuet!" << endl; };
		default:
			return []() {};
		}
	}
}

class Duck
{
public:
	Duck(FlyBehavior flyBehavior, QuackBehavior quackBehavior, DanceBehavior danceBehavior)
	{
		SetFlyBehavior(flyBehavior);
		SetQuackBehavior(quackBehavior);
		SetDanceBehavior(danceBehavior);
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
	void SetFlyBehavior(FlyBehavior flyBehavior)
	{
		m_flyBehaviorFn = CreateFlyBehavior(flyBehavior);
	}
	void SetQuackBehavior(QuackBehavior quackBehavior)
	{
		m_quackBehaviorFn = CreateQuackBehavior(quackBehavior);
	}
	void SetDanceBehavior(DanceBehavior danceBehavior)
	{
		m_danceBehaviorFn = CreateDanceBehavior(danceBehavior);
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
		: Duck(FlyBehavior::WITH_WINGS, QuackBehavior::QUACK, DanceBehavior::WALTZ)
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
		: Duck(FlyBehavior::WITH_WINGS, QuackBehavior::QUACK, DanceBehavior::MINUET)
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
		: Duck(FlyBehavior::NO_WAY, QuackBehavior::MUTE, DanceBehavior::NO_WAY)
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
		: Duck(FlyBehavior::NO_WAY, QuackBehavior::SQUEAK, DanceBehavior::NO_WAY)
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
		: Duck(FlyBehavior::NO_WAY, QuackBehavior::MUTE, DanceBehavior::NO_WAY)
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
	modelDuck.SetFlyBehavior(FlyBehavior::WITH_WINGS);
	modelDuck.SetQuackBehavior(QuackBehavior::SQUEAK);
	modelDuck.SetDanceBehavior(DanceBehavior::WALTZ);
	PlayWithDuck(modelDuck);
}