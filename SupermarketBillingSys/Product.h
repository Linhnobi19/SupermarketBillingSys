#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

// represent the product will be sale in stock

class Product
{
public:
	Product();
	~Product();

	int getId() const;
	std::string getName() const;
	double getPrice() const;
	int getAmountLeft() const;
	short getDiscount() const;

	void setID(int _id);
	void setName(std::string _name);
	void setPrice(double _price);
	void setAmount(int _amount);
	void setDiscount(short _discount);

private:
	int id;
	std::string name;
	double price;
	int amoutLeft;
	short discount;		// from 0 - 100 percent
};




#endif // !PRODUCT_H
