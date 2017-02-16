#include "Beverages.h"
#include "Condiments.h"

#include <iostream>
#include <string>
#include <functional>

using namespace std;

template <typename Condiment, typename... Args>
auto MakeCondiment(const Args&...args)
{
	return [=](auto && b) {
		return make_unique<Condiment>(forward<decltype(b)>(b), args...);
	};
}

template <typename Component, typename Decorator>
auto operator << (Component && component, const Decorator & decorate)
{
	return decorate(forward<Component>(component));
}


int main()
{
	{

		auto beverage =
			make_unique<CTea>()
			<< MakeCondiment<CLemon>(2)
			<< MakeCondiment<CIceCubes>(3, IceCubeType::Water);

		cout << beverage->GetDescription() << " costs " << beverage->GetCost() << endl;
	}
	{

		auto beverage =
			make_unique<CTea>(TeaType::Java)
			<< MakeCondiment<CLemon>(2)
			<< MakeCondiment<CIceCubes>(3, IceCubeType::Water);

		cout << beverage->GetDescription() << " costs " << beverage->GetCost() << endl;
	}
	{

		auto beverage =
			make_unique<CTea>(TeaType::Gita)
			<< MakeCondiment<CLemon>(2)
			<< MakeCondiment<CIceCubes>(3, IceCubeType::Water);

		cout << beverage->GetDescription() << " costs " << beverage->GetCost() << endl;
	}

	{
		auto beverage =
			make_unique<CLatte>()
			<< MakeCondiment<CCinnamon>()
			<< MakeCondiment<CLemon>(2)
			<< MakeCondiment<CIceCubes>(2, IceCubeType::Dry)
			<< MakeCondiment<CChocolateCrumbs>(2);

		cout << beverage->GetDescription() << " costs " << beverage->GetCost() << endl;
	}

	{
		auto beverage =
			make_unique<CLatte>(CoffeeSize::Double)
			<< MakeCondiment<CCinnamon>()
			<< MakeCondiment<CLemon>(2)
			<< MakeCondiment<CIceCubes>(2, IceCubeType::Dry)
			<< MakeCondiment<CChocolateCrumbs>(2);

		cout << beverage->GetDescription() << " costs " << beverage->GetCost() << endl;
	}

	{
		auto beverage =
			make_unique<CCapuccino>(CoffeeSize::Double)
			<< MakeCondiment<CCinnamon>()
			<< MakeCondiment<CLemon>(2)
			<< MakeCondiment<CIceCubes>(2, IceCubeType::Dry)
			<< MakeCondiment<CChocolateCrumbs>(2);

		cout << beverage->GetDescription() << " costs " << beverage->GetCost() << endl;
	}

	{
		auto beverage =
			make_unique<CMilkshake>()
			<< MakeCondiment<CSyrup>(SyrupType::Maple)
			<< MakeCondiment<CCoconutFlakes>(8);

		cout << beverage->GetDescription() << " costs " << beverage->GetCost() << endl;
	}

	{
		auto beverage =
			make_unique<CMilkshake>(ShakeSize::Medium)
			<< MakeCondiment<CSyrup>(SyrupType::Maple)
			<< MakeCondiment<CCoconutFlakes>(8);

		cout << beverage->GetDescription() << " costs " << beverage->GetCost() << endl;
	}

	{
		auto beverage =
			make_unique<CMilkshake>(ShakeSize::Large)
			<< MakeCondiment<CSyrup>(SyrupType::Maple)
			<< MakeCondiment<CCoconutFlakes>(8);

		cout << beverage->GetDescription() << " costs " << beverage->GetCost() << endl;
	}
}
