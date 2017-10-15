#pragma once
#ifndef __CURRENCY_H
#define __CURRENCY_H
#include <string>
#include <iostream>
#define plus 0
#define minus 1
typedef int signType;

class illegalParameterValue
{
public:
	illegalParameterValue() :message("Illegal parameter value") {}
	illegalParameterValue(char * theMessage) :message(theMessage) {}
	void outputMessage() { std::cout << message << std::endl; }
private:
	std::string message;
};

class currency
{
public:

	currency(signType theSign =plus, unsigned long theDollas = 0, unsigned int theCents = 0);
	~currency() {};
	void setValue(signType, unsigned long, unsigned int);
	void setValue(double);
	signType getSign() const { return sign; }
	unsigned long getDollars()const { return dollars; }
	unsigned int getCents()const { return cents; }
	currency add(const currency&)const;
	currency& increment(const currency&);
	void output() const;

private:
	signType sign;
	unsigned long dollars;
	unsigned int cents;
};
currency::currency(signType theSign, unsigned long theDollars, unsigned int theCents) 
	:sign(theSign), dollars(theDollars), cents(theCents) {}

void currency::setValue(signType theSign, unsigned long theDollars, unsigned int theCents)
{
	if (theCents >= 100)
		throw illegalParameterValue("Cents should be <100");
	sign = theSign;
	dollars = theDollars;
	cents = theCents;
}
void currency::setValue(double theAmount)
{
	if (theAmount < 0) { sign = minus; theAmount = -theAmount; }
	else sign = plus;

	dollars = (unsigned long)theAmount;
	cents = (unsigned int)((theAmount + 0.001 - dollars) * 100);
}

currency currency::add(const currency & x)const
{
	long a1, a2, a3;
	currency result;

	a1 = dollars * 100 + cents;
	if (sign == minus)a1 = -a1;

	a2 = x.dollars * 100 + x.cents;
	if (x.sign == minus)a2 = -a2;

	a3 = a1 + a2;
	if (a3 < 0)
	{
		result.sign = minus;
		a3 = -a3;
	}
	else
		result.sign = plus;
	result.dollars = a3 / 100;
	result.cents = a3 - result.dollars * 100;

	return result;
}

currency& currency::increment(const currency &x)
{
	*this = add(x);
	return *this;
}

void currency::output() const
{
	if (sign == minus)
		std::cout << '-';
	std::cout << '$' << dollars << '.';
	if (cents < 10)
		std::cout << '0';
	std::cout << cents;
}


class AnotherCurrency 
{
public:
	AnotherCurrency(signType theSign = plus, unsigned long theDollars = 0, unsigned int theCents = 0);
	~AnotherCurrency() {}
	void setValue(signType, unsigned long, unsigned int);
	void setValue(double);
	signType getSign() const
	{
		if (amount < 0 )return minus;
		else return plus;
	}
	unsigned long getDollars() const
	{
		if (amount < 0)
			return -amount / 100;
		else
			return amount / 100;
	}
	unsigned int getCents()const
	{
		if (amount < 0)
			return -amount - getDollars() * 100;
		else
			return amount - getDollars() * 100;
	}
	AnotherCurrency add(const AnotherCurrency &x)const;
	AnotherCurrency& increment(const AnotherCurrency& x)
	{
		amount += x.amount;
		return *this;
	}
	void output() const;
private:
	long amount;
};

AnotherCurrency::AnotherCurrency(signType theSign, unsigned long theDollars, unsigned int theCents)
{
	setValue(theSign, theDollars, theCents);
} 

void AnotherCurrency::setValue(signType theSign, unsigned long theDollars, unsigned int theCents)
{
	if (theCents > 99)
		throw illegalParameterValue("Cents should be < 100");
	amount = theDollars * 100 + theCents;
	if (theSign == minus)
		amount = -amount;
}

void AnotherCurrency::setValue(double theAmount)
{
	if (theAmount < 0)
		amount = (long)((theAmount - 0.001) * 100);
	else
		amount = (long)((theAmount + 0.001) * 100);
}
AnotherCurrency AnotherCurrency::add(const AnotherCurrency &x)const
{
	AnotherCurrency y;
	y.amount =amount+ x.amount;
	return y;
}

void AnotherCurrency::output() const
{
	long theAmount = amount;
	if (theAmount < 0)
	{
		std::cout << "-";
		theAmount = -theAmount;
	}
	long dollars = theAmount / 100;
	std::cout << "$" << dollars << '.';
	int cents = theAmount - dollars * 100;
	if (cents < 10)std::cout << '0';
	std::cout << cents;
}

class currency3
{
public:
	currency3(signType theSign = plus, unsigned long theDollars = 0, unsigned int theCents = 0)
	{
		setValue(theSign, theDollars, theCents);
	}
	~currency3() {}
	void setValue(signType theSign, unsigned long theDollars, unsigned int theCents) {
		if (theCents > 99)
			throw illegalParameterValue("Cents should be < 100");
		amount = theDollars * 100 + theCents;
		if (theSign == minus)
			amount = -amount;
	}
	void setValue(double theAmount)
	{
		if (theAmount < 0)
			amount = (long)((theAmount - 0.001) * 100);
		else
			amount = (long)((theAmount + 0.001) * 100);
	}
	signType getSign() const
	{
		if (amount < 0)return minus;
		else return plus;
	}
	unsigned long getDollars() const
	{
		if (amount < 0)return (-amount) / 100;
		else return amount / 100;
	}
	unsigned int getCents()const
	{
		if (amount < 0)return -amount - getDollars ()* 100;
		else return amount - getDollars() * 100;
	}
	currency3 operator+(const currency3 &)const;
	currency3 &operator+=(const currency3 &x)
	{
		amount += x.amount; 
		return *this;
	}
	void output(std::ostream&)const;
private:
	long amount;
};

currency3 currency3::operator+(const currency3& x)const
{
	currency3 result;
	result.amount = amount + x.amount;
	return result;
}
void currency3::output(std::ostream& out)const
{
	long theAmount = amount;
	if (theAmount < 0) { out << '-'; theAmount = -theAmount; }
	long dollars = theAmount / 100;
	out << '$' << dollars << '.';
	int cents = theAmount - dollars * 100;
	if (cents < 10) out << '0';
	out << cents;
}
std::ostream& operator<<(std::ostream& out, const currency3 &x)
{
	x.output(out);
	return out;
}
#endif