#include "UI.h"

UI::UI()
{
	monthlyExpenses = Expenses();
}

UI::UI(const Expenses& other)
{
	this->monthlyExpenses = other;
}


void UI::run()
{
	bool running = true;

	while (running) {
		string key;

		cout << "Please select your option: \n";

		cout << setw(5) << "A|a		Add an expense to current day: \n";
		cout << setw(5) << "I|i		Insert an expense to a day: \n";
		cout << setw(5) << "ED|ed	Eliminate expenses by day: \n";
		cout << setw(5) << "EF|ef	Eliminate expenses from a day to another day: \n";
		cout << setw(5) << "ET|et	Eliminate expenses by type: \n";
		cout << setw(5) << "C|c		Show current day expenses: \n";
		cout << setw(5) << "S|s		Show all expenses \n";
		cout << setw(5) << "SF|sf	Show all expenses for food \n";
		cout << setw(5) << "GTF|gtf Get total food expenses for this month: \n";
		cout << setw(5) << "GTM|gtm Get day with maximum expenses: \n";
		cout << setw(5) << "FF|ff	Keep only food expenses \n";
		cout << setw(5) << "FS|fs   Filter food bigger than a given value: \n";
		cout << setw(5) << "U|u		Undo operation \n";
		cout << setw(5) << "Q|q		Quit \n";

		cin >> key;

		if (key == "A" || key == "a") {
			int price;
			char type[10];

			cout << setw(5) << "Input Price: \n"; cin >> price;
			cout << setw(5) << "Input Type: \n"; cin >> type;

			monthlyExpenses.addExpense(price, type);

			cout << setw(5) << "Month Expense has been added! \n";
		}

		if (key == "I" || key == "i") {
			int day;
			int price;
			char type[10];

			cout << setw(5) << "Input Day: \n"; cin >> day;
			cout << setw(5) << "Input Price: \n"; cin >> price;
			cout << setw(5) << "Input Type: \n"; cin >> type;

			monthlyExpenses.insertExpense(price, day, type);

			cout << setw(5) << "Month Expense has been added! \n";
		}

		if (key == "ED" || key == "ed") {
			int day;

			cout << setw(5) << "Input Day: \n"; cin >> day;
			monthlyExpenses.elimExpenseByDay(day);

			cout << setw(5) << "Month Expense has been removed! \n";
		}

		if (key == "EF" || key == "ef") {
			int from, to;

			cout << setw(5) << "Input start day: \n"; cin >> from;
			cout << setw(5) << "Input end day: \n"; cin >> to;

			monthlyExpenses.elimExpenseFromTo(from, to);

			cout << setw(5) << "Month Expense has been removed! \n";
		}

		if (key == "ET" || key == "et") {
			char type[10];

			cout << setw(5) << "Input type: \n"; cin >> type;

			monthlyExpenses.elimExpenseByType(type);

			cout << setw(5) << "Month Expense has been removed! \n";
		}

		if (key == "C" || key == "c") {
			int currDay = monthlyExpenses.getCurrentDay();
			cout << "Day " << currDay << '\n';
			cout << "Menaj: " << monthlyExpenses.getAll()[currDay].getMenaj() << "\n";
			cout << "Mancare: " << monthlyExpenses.getAll()[currDay].getMancare() << "\n";
			cout << "Transport: " << monthlyExpenses.getAll()[currDay].getTransport() << "\n";
			cout << "Internet: " << monthlyExpenses.getAll()[currDay].getInternet() << "\n";
			cout << "Haine: " << monthlyExpenses.getAll()[currDay].getHaine() << "\n";
		}

		if (key == "S" || key == "s") {
			for (int i = 0; i < monthlyExpenses.getSize(); i++)
			{
				cout << "Day " << i << '\n';
				cout << "Menaj: " << monthlyExpenses.getAll()[i].getMenaj() << "\n";
				cout << "Mancare: " << monthlyExpenses.getAll()[i].getMancare() << "\n";
				cout << "Transport: " << monthlyExpenses.getAll()[i].getTransport() << "\n";
				cout << "Internet: " << monthlyExpenses.getAll()[i].getInternet() << "\n";
				cout << "Haine: " << monthlyExpenses.getAll()[i].getHaine() << "\n";
			}
		}

		if (key == "SF" || key == "sf") {
			for (int i = 0; i < monthlyExpenses.getSize(); i++)
			{
				cout << "Day " << i << '\n';
				cout << "Mancare: " << monthlyExpenses.getAll()[i].getMancare() << "\n";
			}
		}

		if (key == "GTF" || key == "gtf") {
			cout << "Total food expenses this month are: " << monthlyExpenses.getTotalFoodExpenses() << '\n';
		}

		if (key == "GTM" || key == "gtm") {
			cout << "Day with maximum expenses is: " << monthlyExpenses.getDayMaxExp() << '\n';
		}

		if (key == "FF" || key == "ff") {
			monthlyExpenses.filterFoodExpenses();

			cout << "Monthly expenses filtered! \n";
		}

		if (key == "FS" || key == "fs") {
			int value;

			cout << setw(5) << "Input value: \n"; cin >> value;

			monthlyExpenses.filterFoodExpensesSmallerThan(value);

			cout << "Monthly expenses filtered! \n";
		}

		if (key == "U" || key == "u") {
			monthlyExpenses.undo();
		}

		if (key == "Q" || key == "q")
			running = false;

		cout << '\n';
	}
}
