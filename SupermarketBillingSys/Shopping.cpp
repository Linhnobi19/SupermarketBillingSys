#include "Shopping.h"

#include <string>
#include <iostream>
#include "Adminstrator.h"
#include <conio.h>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;


// for explode from file
vector<std::string> explode(std::string& s, const char& c);
void DisplayAdminMenu();
void clearWhiteSpace(istream&);
void optionEdit();



Shopping::Shopping()
	: state (false), total_product(0)
{
	// set up the admin
	admin = Adminstrator::getAdmin();
	admin->setPassWord("doanlinh", "hoilamgi");
	receipt = nullptr;
	
	// initialize the product
	for (size_t i = 0; i < 100; i++)
	{
		product[i] = nullptr;
	}
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
	
	clearWhiteSpace(cin);

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
	DisplayAdminMenu();

	cout << "\t\t\tPlease type your choice: ";

	clearWhiteSpace(cin);

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

// add the product
void Shopping::add()
{
	string name;
	double price;
	int amountLeft;
	short discount;
	if (!state) {
		readProducts(name, price, amountLeft, discount);
	}


	string choice;
	do
	{
		if (choice.size() != 0)
		{
			system("cls");
			DisplayAdminMenu();
		}
		
		// ask admin enter infomation about the product
		cout << "\t\t\t\tPlease enter the name of the product: ";
		clearWhiteSpace(cin);
		getline(cin, name);
		cout << "\t\t\t\tEnter the price of the product:       ";
		clearWhiteSpace(cin);
		cin >> price;
		cout << "\t\t\t\tEnter the amount of this product:     ";
		clearWhiteSpace(cin);
		cin >> amountLeft;
		cout << "\t\t\t\tEnter the discount for this product:  ";
		clearWhiteSpace(cin);
		cin >> discount;

		Product* ptr = new Product(total_product++, name, price, amountLeft, discount);
		product[ptr->getId()] = ptr;
		
		cout << "\n\n\t\t\tDo you want to add new product? ('y' or 'Y' for continue | any key will exiting): ";
		cin >> choice;
		
	} while (choice == "y" || choice == "Y");


	// store info into file
	ofstream ofile("products.txt", ios_base::out | ios_base::trunc);
	if (!ofile.is_open())
	{
		cout << "\t\t\t--> Couldn't open file for update new products" << endl;
	}
	else
	{
		//cout << "Number of count is " << count << endl;
		for (size_t i = 0; i < total_product; i++)
		{
			if (product[i] == nullptr) continue;

			//cout << "The " << i << " element is tag into the file" << endl;
			ofile << product[i]->getId() << ';'
				<< product[i]->getName() << ';'
				<< product[i]->getPrice() << ';'
				<< product[i]->getAmountLeft() << ';'
				<< product[i]->getDiscount() << endl;
		}

		cout << "\t\t\t--> Updated successfully\n";

		state = true;
	}
	ofile.close();

	system("pause");

	// turn back to administrator
	adminstrator();
}

void Shopping::edit()
{
	string name;
	double price;
	int amountLeft;
	short discount;
	if (!state) {
		readProducts(name, price, amountLeft, discount);
	}

	// enter the option want to change
	int choice;
	do
	{
		cout << "\t\t\tEnter the id of the product: ";
		clearWhiteSpace(cin);
		cin >> choice;
		if (choice > 99 || choice < 0) {
			cout << "\t\t\t--> You entered the id that didn't expected\n\n";
			system("pause");
		}
		

		if (choice >= total_product) {
			cout << "\t\t\t--> You entered the id that doestn't has the data\n";
			cout << "\t\t\tYou will directed to administrator menu()\n";
			system("pause");

			adminstrator();
		}
	} while (choice > 99 || choice < 0);
	
	// edit option
	system("cls");
	optionEdit();

	cout << "\t\t\tEnter your choice: ";
	clearWhiteSpace(cin);
	int ans;
	cin >> ans;

	string _name;
	double _price;
	int _amount;
	short _dis;
	switch (ans)
	{
	case 1:
		cout << "\n\n\t\t\tEnter the name you want to change: ";
		clearWhiteSpace(cin);
		getline(cin, _name);
		product[choice]->setName(_name);
		break;
	case 2:
		cout << "\n\n\t\t\tEnter the price you want to change: ";
		clearWhiteSpace(cin);
		cin >> _price;
		product[choice]->setPrice(_price);
		break;
	case 3:
		cout << "\n\n\t\t\tEnter the amount you want to change: ";
		clearWhiteSpace(cin);
		cin >> _amount;
		product[choice]->setAmount(_amount);
		break;
	case 4:
		cout << "\n\n\t\t\tEnter the discount you want to change: ";
		clearWhiteSpace(cin);
		cin >> _dis;
		product[choice]->setDiscount(_dis);
		break;
	case 5:
		cout << "\t\t\tEnter the name of the product: ";
		clearWhiteSpace(cin);
		getline(cin, _name);
		product[choice]->setName(_name);
		cout << "\t\t\t\tEnter the price of the product:       ";
		clearWhiteSpace(cin);
		cin >> _price;
		product[choice]->setPrice(_price);
		cout << "\t\t\t\tEnter the amount of this product:     ";
		clearWhiteSpace(cin);
		cin >> _amount;
		product[choice]->setAmount(_amount);
		cout << "\t\t\t\tEnter the discount for this product:  ";
		clearWhiteSpace(cin);
		cin >> _dis;
		product[choice]->setDiscount(_dis);
		break;
	case 6: 
		adminstrator();
		break;
	default:
		cout << "\n\n\t\t\t--> The option is not in this board\n\n";
		break;
	}

	// update to the file
	outputProducts();

	system("pause");
	adminstrator();

}

void Shopping::remove()
{
	string name;
	double price;
	int amountLeft;
	short discount;
	if (!state) {
		readProducts(name, price, amountLeft, discount);
	}

	if (total_product == 0)
	{
		cerr << "\t\t\tYou don't have any products to remove\n";
		cout << "\t\t\tYou will be directed to admin menu\n\n";
		system("pause");
		adminstrator();
	}

	int choice;
	do
	{
		cout << "\t\t\tEnter the id of the product: ";
		clearWhiteSpace(cin);
		cin >> choice;
		if (choice > 99 || choice < 0) {
			cout << "\t\t\t--> You entered the id that didn't expected\n\n";
			system("pause");
		}


		if (product[choice] == nullptr) {
			cout << "\t\t\t--> You entered the id that doestn't has the data\n";
			cout << "\t\t\tYou will directed to administrator menu()\n";
			system("pause");

			adminstrator();
		}
	} while (choice > 99 || choice < 0);
	

	// display information to confirm delete
	cout << "\n\n\n";
	cout << "\t\t\t\t ________________________________________ \n";
	cout << "\t\t\t\t|                                        |\n";
	cout << "\t\t\t\t|         Information to remove          |\n";
	cout << "\t\t\t\t|________________________________________|\n\n";

	cout << "\t\t\t\t" << "|      Name:       " << setw(20) << product[choice]->getName() << "  |\n";
	cout << "\t\t\t\t" << "|      Price:      " << setw(20) << product[choice]->getPrice() << "  |\n";
	cout << "\t\t\t\t" << "|      AmountLeft: " << setw(20) << product[choice]->getAmountLeft() << "  |\n";
	cout << "\t\t\t\t" << "|      Discount:   " << setw(20) << product[choice]->getDiscount() << "  |\n\n";
	
	cout << "\t\t\tDo you want to remove this item? ('y' or 'Y' to remove) ";
	char ch;
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
	{
		delete product[choice];
		product[choice] = nullptr;

		// try to update in product line
		int pos = choice;
		while(true)
		{
			if (product[pos + 1] == nullptr)
			{
				delete product[pos];
				product[pos] = nullptr;
				break;
			}
			product[pos] = product[pos + 1];
			// set new id
			product[pos]->setID(pos);
			pos++;
		}

		// update
		outputProducts();

		
	}
	system("pause");
	adminstrator();
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


vector<std::string> explode(std::string& s, const char& c)

{
	string buff{ "" };
	vector<string> v;				// Lưu từng thành phần được ngăn nhau bởi c

	for (auto n : s)
	{
		if (n != c)
			buff += n;
		else if (n == c && buff != "")
		{
			v.push_back(buff);
			buff = "";
		}
	}
	if (buff != "")
		v.push_back(buff);	// tránh trường hợp để xót đối tượng cuối cùng khi k gặp ký tự c

	return v;
}


void DisplayAdminMenu() {
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
}

void clearWhiteSpace(istream& input) {
	// clear the white space
	char ch = input.peek();
	while (isspace(ch))
	{
		input.ignore();
		ch = input.peek();
	}
}

void optionEdit() {
	cout << "\t\t\t\t ________________________________________ \n";
	cout << "\t\t\t\t|                                        |\n";
	cout << "\t\t\t\t|            Option to edit              |\n";
	cout << "\t\t\t\t|________________________________________|\n\n";

	cout << "\t\t\t\t|       1. Edit the name                 |\n";
	cout << "\t\t\t\t|       2. Edit the price                |\n";
	cout << "\t\t\t\t|       3. Edit the amountLeft           |\n";
	cout << "\t\t\t\t|       4. Edit the Discount             |\n";
	cout << "\t\t\t\t|       5. Edit all information          |\n";
	cout << "\t\t\t\t|       6. Back to main menu             |\n\n";
}

void Shopping::readProducts(string& name, double& price, int& amountLeft, short& discount) {
	total_product = 0;
	// open file that contians product
	ifstream ifile("products.txt", ios_base::in | ios_base::app);
	if (!ifile.is_open())
	{
		cout << "\n\t\t\t-> The file of the product couldn't be opened\n\n";
		// go back to the admin menu
		adminstrator();
	}

	// read file to add product to the list;
	string line;


	while (getline(ifile, line))
	{
		vector<string> ans = explode(line, ';');
		if (ans.size() < 5)
		{
			break;		// not contain enough data
		}
		total_product = stoi(ans[0]);
		name = ans[1];
		price = stod(ans[2]);
		amountLeft = stoi(ans[3]);
		discount = stoi(ans[4]);

		product[total_product++] = new Product(total_product, name, price, amountLeft, discount);
	}
	ifile.close();
}

void Shopping::outputProducts() {
	ofstream ofile("products.txt", ios_base::out | ios_base::trunc);
	if (!ofile.is_open())
	{
		cout << "\t\t\t--> Couldn't open file for update new products" << endl;
	}
	else
	{
		//cout << "Number of count is " << count << endl;
		for (size_t i = 0; i < 99; i++)
		{
			if (product[i] == nullptr) continue;

			//cout << "The " << i << " element is tag into the file" << endl;
			ofile << product[i]->getId() << ';'
				<< product[i]->getName() << ';'
				<< product[i]->getPrice() << ';'
				<< product[i]->getAmountLeft() << ';'
				<< product[i]->getDiscount() << endl;
		}

		cout << "\t\t\t--> Updated successfully\n";

		state = true;
	}
	ofile.close();
}