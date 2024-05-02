#ifndef RECEIPT_H
#define RECEIPT_H
#include "Buyer.h"
#include "Product.h"
#include <string>
#include <vector>
#include <utility>

class Receipt
{
public:
	Receipt();
	~Receipt();

	void addProduct(Product& p, int amount);
	double totalPrice();
	std::string getCode() const;
	std::string getNameBuyer() const;
	void displayList() const;

private:
	std::string codeReceipt;
	std::string nameBuyer;
	std::vector<std::pair<Product, int>> listPros;		// int is the amount
	double amount;
};



#endif // !RECEIPT_H
