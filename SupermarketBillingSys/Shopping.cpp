#include "Shopping.h"

#include <string>
#include <iostream>
#include "Adminstrator.h"
#include <conio.h>

using namespace std;

Shopping::Shopping()
{
	// set up the admin
	admin = Adminstrator::getAdmin();
	admin->setPassWord("doanlinh", "hoilamgi");
	receipt = nullptr;
}

Shopping::~Shopping()
{
}

void Shopping::menu()
{
	system("cls");
	cout << "\t\t\t\t ________________________________________ \n";
	cout << "\t\t\t\t|                                        |\n";
	cout << "\t\t\t\t|         Supermarket Main menu          |\n";
	cout << "\t\t\t\t|                                        |\n";
	cout << "\t\t\t\t|________________________________________|\n\n";

	cout << "\t\t\t\t|       1. Adminstrator                  |\n";
	cout << "\t\t\t\t|       2. Buyer                         |\n";
	cout << "\t\t\t\t|       3. Exit                          |\n\n";

	cout << "\t\t\tPlease select the choice: ";
	
	// clear the white space
	char ch = cin.peek();
	while (isspace(ch))
	{
		cin.ignore();
		ch = cin.peek();
	}

	char choice[20];
	cin >> choice;

	// Display the screen for input
	string userName;
	string pass;

	switch (atoi(choice))
	{
	case 1: 
		
		while (true)
		{
			cout << "\t\t\tPlease type the user name: ";
			cin >> userName;
			cout << "\t\t\tType your passWord:        ";
			pass = hiddenPassWord();

			if (!admin->authenticate(userName, pass))
			{
				cout << "\n\t\t\t--> The user name or password are not right! Please type again\n\n";
			}
			else {
				cout << endl;
				break;
			}
		}
		system("pause");
		adminstrator();
		break;
	case 2:
		buyer();
		break;
	case 3:
		// may be come again to menu to make a infinite loop
		menu();
		break;
	default:
		cout << "\t\t\t--> Please type the correct choice\n";
		system("pause");
		menu();
		break;
	}
}

// initialize the admin
void Shopping::adminstrator()
{
	// try to display of Administrator menu
	system("cls");
	cout << "\t\t\t\t ________________________________________ \n";
	cout << "\t\t\t\t|                                        |\n";
	cout << "\t\t\t\t|            Administrator menu          |\n";
	cout << "\t\t\t\t|                                        |\n";
	cout << "\t\t\t\t|________________________________________|\n\n";

	cout << "\t\t\t\t|       1. Add to the products           |\n";
	cout << "\t\t\t\t|       2. Modify the products           |\n";
	cout << "\t\t\t\t|       3. Delete the product            |\n";
	cout << "\t\t\t\t|       4. Display the list of procut    |\n";
	cout << "\t\t\t\t|       5. Back to main menu             |\n\n";

	cout << "\t\t\tPlease type your choice: ";

	char ch = cin.peek();
	while (isspace(ch))
	{
		cin.ignore();
		ch = cin.peek();
	}

	char choice[20];
	cin >> choice;

	switch (atoi(choice))
	{
	case 1:
		add();
		break;
	case 2:
		edit();
		break;
	case 3:
		remove();
		break;
	case 4:
		break;
	case 5:
		system("pause");
		menu();
	default:
		cout << "\t\t\t--> Please type the correct choice\n";
		system("pause");
		adminstrator();
		break;
	}
}

void Shopping::buyer()
{
}

void Shopping::add()
{
}

void Shopping::edit()
{
}

void Shopping::remove()
{
}

void Shopping::printReceipt()
{
}

string Shopping::hiddenPassWord()
{
	string ans;
	char hiddenPass[20];

	char ch;
	int pos = 0;
	while (1)
	{
		ch = _getch();
		
		// when you type enter key
		if (ch == 13)
		{
			hiddenPass[pos] = '\0';
			// out of loop
			break;
		}
		// when you type enter backspace
		else if (ch == 8) {
			// delete when you still have the character in password
			if (pos > 0)
			{
				cout << "\b \b";
				pos--;
			}
		}
		else {
			hiddenPass[pos] = ch;
			pos++;
			cout << "*";
		}

	}
	ans = hiddenPass;
	return ans;
}
