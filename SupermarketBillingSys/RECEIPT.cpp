#define _CRT_SECURE_NO_WARNINGS 

#include "RECEIPT.h"
#include <utility>
#include <vector>
#include <iostream>
#include <ctime>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <fstream>
#include "Product.h"

using namespace std;

Receipt::Receipt()
	: codeReceipt(0), date("")
{
	
}

Receipt::~Receipt()
{
}

void Receipt::addProduct(Product* p, int amount)
{
	listPros.push_back(make_pair(p, amount ));
}

double Receipt::totalPrice()
{
	double total = 0;
	for (size_t i = 0; i < listPros.size(); i++)
	{
		double beforeDis = listPros[i].first->getPrice() * listPros[i].second;
		total += beforeDis * (100 - listPros[i].first->getDiscount()) / 100;
	}
	return total;
}

int Receipt::getCode() const
{
	return codeReceipt;
}

std::string Receipt::getDate() const
{
	return date;
}

std::vector<std::pair<Product*, int>> Receipt::getList() const
{
	return listPros;
}


void Receipt::setCode(int& _code)
{
	codeReceipt = _code;
}

void Receipt::setDate(std::string& _date)
{
	date = _date;
}



void Receipt::displayList()
{
	// get the time and date
	getTimeAndDate();

	cout << "\t\t\t\t ________________________________________ \n";
	cout << "\t\t\t\t|                                        |\n";
	cout << "\t\t\t\t|               Receipt order            |\n";
	cout << "\t\t\t\t|________________________________________|\n\n";

	cout << "\t\t     Date - Time:" << setw(25) << "" << getDate() << endl;

	cout << "\t\t";
	for (size_t i = 0; i < 70; i++)
	{
		cout << '_';
	}
	cout << endl << endl;
	cout << "\t\t" << setw(5) << " " << left
		<< setw(10) << "Name" << setw(10) << " "
		<< setw(5) << "Price" << setw(5) << " "
		<< setw(5) << "Amount" << setw(5) << " "
		<< setw(10) << "Discount" << setw(5) << " "
		<< setw(5) << "Total" << setw(5) << " " << endl;
	cout << "\t\t";
	for (size_t i = 0; i < 70; i++)
	{
		cout << '_';
	}
	cout << endl << endl;

	// display in4 products
	double total_price = 0;
	for (size_t i = 0; i < listPros.size(); i++)
	{
		double totalPiece = listPros[i].first->getPrice() * listPros[i].second
			* (100 - listPros[i].first->getDiscount()) / 100;
		cout << "\t\t" << setw(5) << " " << left
			<< setw(10) << listPros[i].first->getName() << setw(10) << " "
			<< setw(5) << listPros[i].first->getPrice() << setw(5) << " "
			<< setw(5) << listPros[i].second << setw(5) << " "
			<< setw(10) << listPros[i].first->getDiscount() << setw(5) << " "
			<< setw(5) << fixed << setprecision(2) << totalPiece << setw(5) << " " << endl;
		total_price += totalPiece;
	}

	cout << "\n\t\t";

	for (size_t i = 0; i < 70; i++)
	{
		cout << '_';
	}
	cout << endl << endl;
	cout << "\t\t" << setw(5) << " " << setw(10) << "TOTAL"
		<< setw(46) << "" << fixed << setprecision(2) << total_price << endl << endl;
}

void Receipt::updateToDB(bool ans)
{
	if (ans)
	{
		// open file
		ofstream ofile("bills.txt", ios_base::out | ios_base::app | ios_base::end);
		if (!ofile.is_open())
		{
			cerr << "\t\t\tCouldn't open file to update the bill" << endl << endl;
		}

		ofile << left << setw(8) << codeReceipt << left << setw(25) << getDate();

		for (size_t i = 0; i < listPros.size(); i++)
		{
			ofile << setw(4) << listPros[i].first->getId()
				<< setw(15) << listPros[i].first->getName()
				<< setw(5) << listPros[i].second
				<< setw(5) << listPros[i].first->getPrice()
				<< setw(5) << listPros[i].first->getDiscount();
		}
		ofile << setw(10) << totalPrice() << endl;

		ofile.close();
		
	}
	else
	{
		cout << "\t\t\t--> Transaction cancled\n\n";
	}
}

void Receipt::getTimeAndDate()
{
	
	// Some computation here
	auto _now = std::chrono::system_clock::now();

	std::time_t _date = std::chrono::system_clock::to_time_t(_now);

	date = std::ctime(&_date);
}
