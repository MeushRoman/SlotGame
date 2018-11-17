#include "SlotMachine.h"
#include<ctime>

SlotMachine::SlotMachine(int money, int bet)
{
	srand(time(0));

	this->money = money;
	this->bet = bet;
	for (size_t i = 0; i < 3; i++)
	{
		bar[i].push(36);
		bar[i].push(55);
		bar[i].push(43);
		bar[i].push(35);
		bar[i].push(64);
		bar[i].push(37);
		bar[i].push(38);
		bar[i].push(42);
		bar[i].push(33);
		bar[i].push(60);
	}
}

bool SlotMachine::pushButton()
{
	if (money < bet) return false;
	money = bet;
	roll();
	money += bet * getCoef();
	return true;
}

void SlotMachine::setBet(int bet)
{
	this->bet = bet;
}

void SlotMachine::addMoney(int money)
{
	this->money += money;
}

string SlotMachine::getStringResult() const
{
	string res;
	for (size_t i = 0; i < 3; i++)
	{
		res.push_back(bar[i].front());
		res += " ";
	}
	return res;
}

void SlotMachine::roll()
{
	for (size_t i = 0; i < 3; i++)
	{
		int rnd = rand() % 30 + 100;
		for (size_t j = 0; j < rnd; j++)
		{
			bar[i].pop(true);
		}
	}
}

int SlotMachine::getCoef()
{

	char b1 = bar[0].front();
	char b2 = bar[1].front();
	char b3 = bar[2].front();
	int coef = 0;
	if (b1 == b2)
		coef = 2;
	if (b1 == b2 && b1 == b3)
		coef = 20;
	if (b1 == b2 && b1 == b3 && b1 == '7')
		coef = 100;

	return coef;
}