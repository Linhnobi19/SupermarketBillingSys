#include "Product.h"

int Product::TOTAL_AMOUNT = 1;
Product::Product()
	/*: id(TOTAL_AMOUNT++), name(""), price(0.0), amountLeft(0), discount(0)*/
{
}

Product::Product(int _id, std::string _name, double _price, int _amount, short _discount)
{
	setID(_id);
	setName(_name);
	setPrice(_price);
	setAmount(_amount);
	setDiscount(_discount);
}

//Product::Product(std::string _name, double _price, int _amount, short _discount)
//{
//	setID(TOTAL_AMOUNT++);
//	setName(_name);
//	setPrice(_price);
//	setAmount(_amount);
//	setDiscount(_discount);
//}

Product::~Product()
{
}

int Product::getId() const
{
	return id;
}

std::string Product::getName() const
{
	return name;
}

double Product::getPrice() const
{
	return price;
}

int Product::getAmountLeft() const
{
	return amountLeft;
}

short Product::getDiscount() const
{
	return discount;
}


void Product::setID(int _id)
{
	id = _id;
}

void Product::setName(std::string _name)
{
	name = _name;
}

void Product::setPrice(double _price)
{
	price = _price;
}

void Product::setAmount(int _amount)
{
	amountLeft = _amount;
}

void Product::setDiscount(short _discount)
{
	discount = _discount;
}
