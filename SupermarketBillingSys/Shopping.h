#ifndef SHOPPING_H
#define SHOPPING_H
#include "Product.h"
#include "Adminstrator.h"
#include "RECEIPT.h"
#include <string>
#include <vector>

// for buyer shopping and admin monitor the sales

class Shopping
{
public:
	Shopping();
	~Shopping();

	void menu();		// display option to log to admin or buyer
	void adminstrator();	// for log to admin
	void buyer();			// for buy products
	void add();			// add product to the list of product
	void edit();		// edit product
	void remove();		// remove product
	void printReceipt();		// print in4 for paying the bill

	

private:
	Adminstrator* admin = nullptr;
	Product** product = new Product*[100];
	Receipt* receipt;
	bool state;		// for decide that the file for newest update or not
	int total_product;


	// utility for hidden the password when you type
	std::string hiddenPassWord();

};


#endif // !SHOPPING_H
