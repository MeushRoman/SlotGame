#include "SlotMachineConsole.h"

SlotMachineConsole::SlotMachineConsole() :game(0)
{
	cout << "Welcome\n\n";
	cout << "\nEnter money\n";
	int m;
	cin >> m;
	game.addMoney(m);
	for (size_t i = 0; i < 12; i++)
	{
		int cnt = 0;
		Sleep(300);
		system("cls");

		cout << "Loading";
		for (size_t j = 0; j < cnt; j++)
		{
			cout << ".";
		}
		cnt++;
		if (cnt == 4)
			cnt = 0;
	}
}

void SlotMachineConsole::start()
{
	int ch = 0;
	while (ch != 4)
	{
		system("cls");
		printScreen();
		cin >> ch;
		switch (ch)
		{
		case 1:

			if (!game.pushButton())
			{
				cout << "Money<bet!\n to continue change bet or add money\n";
				system("pause");
			}
			break;
		case 2:
			system("cls");
			cout << "Enter money\n";
			int m;
			cin >> m;
			game.addMoney(m);
			break;
		case 3:
			system("cls");
			cout << "Set bet\n";
			int b;
			cin >> b;
			game.setBet(b);
			break;
		default:
			cout << "\nUnknown command\n";
			Sleep(2000);
			break;
		}
	}
}

void SlotMachineConsole::printScreen() const
{
	cout << "\n------------------------------\n";
	cout << "\n\t" << game.getStringResult() << "\n\n";
	cout << "Your money = " << game.getMoney() << " tg.\n";
	cout << "Your bet = " << game.getBet() << " tg.\n";
	printMenu();

}

void SlotMachineConsole::printMenu() const
{
	cout << "1 - roll\n2 - add money\n3 - set bet\n4 - exit";
}

void SlotMachineConsole::choose(int ch)
{
}
