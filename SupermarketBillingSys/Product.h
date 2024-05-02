#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

// represent the product will be sale in stock

class Product
{
public:
	Product();
	~Product();

private:
	
	std::string name;
	double price;
	int amoutLeft;
	short discount;		// from 0 - 100 percent
};




#endif // !PRODUCT_H
