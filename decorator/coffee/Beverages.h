#pragma once

#include "IBeverage.h"

// Базовая реализация напитка, предоставляющая его описание
class CBeverage : public IBeverage
{
public:
	virtual std::string GetDescription() const override = 0;
};

// Кофе
class CCoffee : public CBeverage
{
public:
	double GetCost() const override 
	{
		return 60; 
	}

	std::string GetDescription() const override
	{
		return "Coffee";
	}
};

enum class CoffeeSize
{
	Single,
	Double,
};

// Капуччино
class CCapuccino : public CCoffee
{
public:
	CCapuccino(CoffeeSize coffeeSize = CoffeeSize::Single)
		: m_coffeeSize(coffeeSize)
	{}

	double GetCost() const override 
	{
		return (m_coffeeSize == CoffeeSize::Single) ? 80 : 120;
	}

	std::string GetDescription() const override
	{
		return std::string(m_coffeeSize == CoffeeSize::Single ? "" : "Double ") + "Capuccino";
	}

private:
	CoffeeSize m_coffeeSize;
};

// Латте
class CLatte : public CCoffee
{
public:
	CLatte(CoffeeSize coffeeSize = CoffeeSize::Single)
		: m_coffeeSize(coffeeSize)
	{}

	double GetCost() const override
	{
		return (m_coffeeSize == CoffeeSize::Single) ? 90 : 130;
	}

	std::string GetDescription() const override
	{
		return std::string(m_coffeeSize == CoffeeSize::Single ? "" : "Double ") + "Latte";
	}

private:
	CoffeeSize m_coffeeSize;
};

enum class TeaType
{
	Zita,
	Gita,
	Nuri,
	Java
};

// Чай
class CTea : public CBeverage
{
public:
	CTea(TeaType teaType = TeaType::Nuri)
		: m_teaType(teaType)
	{}

	double GetCost() const override 
	{
		return 30; 
	}

	std::string GetDescription() const override
	{
		std::string teaTypeDescription;
		switch (m_teaType)
		{
		case TeaType::Zita:
			teaTypeDescription = "Zita";
			break;
		case TeaType::Gita:
			teaTypeDescription = "Gita";
			break;
		case TeaType::Java:
			teaTypeDescription = "Java";
			break;
		case TeaType::Nuri:
		default:
			teaTypeDescription = "Nuri";
			break;
		}

		return "\"Princess " + teaTypeDescription + "\" Tea";
	}

private:
	TeaType m_teaType;
};

enum class ShakeSize
{
	Small,
	Medium,
	Large,
};

// Молочный коктейль
class CMilkshake : public CBeverage
{
public:
	CMilkshake(ShakeSize shakeSize = ShakeSize::Small)
		: m_shakeSize(shakeSize)
	{}

	double GetCost() const override 
	{
		switch (m_shakeSize)
		{
		case ShakeSize::Large:
			return 80;
		case ShakeSize::Medium:
			return 60;
		case ShakeSize::Small:
		default:
			return 50;
		}
	}

	std::string GetDescription() const override
	{
		std::string sizeDescription;
		switch (m_shakeSize)
		{
		case ShakeSize::Large:
			sizeDescription = "Large";
			break;
		case ShakeSize::Medium:
			sizeDescription = "Medium";
			break;
		case ShakeSize::Small:
		default:
			sizeDescription = "Small";
			break;
		}
		return sizeDescription + " Milkshake";
	}

private:
	ShakeSize m_shakeSize;
};
