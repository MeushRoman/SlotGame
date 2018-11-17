#pragma once
#include"SlotMachine.h"
#include<Windows.h>
class SlotMachineConsole
{
	SlotMachine game;
public:
	SlotMachineConsole();
	void start();
private:
	void printScreen() const;
	void printMenu() const;
	void choose(int ch);

};