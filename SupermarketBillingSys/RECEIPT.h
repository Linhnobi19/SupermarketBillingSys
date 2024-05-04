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

	void addProduct(Product* p, int amount);
	double totalPrice();

	int getCode() const;
	std::string getDate() const;
	std::vector<std::pair<Product*, int>> getList() const;

	void setCode(int&);
	void setDate(std::string&);
	
	void displayList();
	void updateToDB(bool ans);	// if the bill payed --> update to to billed

private:
	int codeReceipt;		// can use the number of receipt to decide
	std::string date;
	std::vector<std::pair<Product*, int>> listPros;		// int is the amount

	// utility for get time and date
	void getTimeAndDate();
};



#endif // !RECEIPT_H
