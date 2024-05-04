#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include "Shopping.h"
#include "RECEIPT.h"


using namespace std;

int main() {
	Shopping s;
	s.menu();

	/*Receipt re;
	re.displayList();*/

	/*ofile << left << setw(8) << codeReceipt << left << setw(25) << getDate();

	for (size_t i = 0; i < listPros.size(); i++)
	{
		ofile << listPros[i].first->getId()
			<< setw(15) << listPros[i].first->getName()
			<< setw(5) << listPros[i].second
			<< setw(5) << listPros[i].first->getPrice()
			<< setw(5) << listPros[i].first->getDiscount();
	}
	ofile << setw(10) << totalPrice() << endl;*/

	/*string line;
	ifstream ofile("bills.txt", ios_base::in | ios_base::beg);
	getline(ofile, line);
	cout << line;*/

	return 0;
}