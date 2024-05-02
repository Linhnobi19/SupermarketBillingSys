#include "Product.h"

Product::Product()
{
}

Product::~Product()
{
}

int Product::getId() const
{
	return 0;
}

std::string Product::getName() const
{
	return std::string();
}

double Product::getPrice() const
{
	return 0.0;
}

int Product::getAmountLeft() const
{
	return 0;
}

short Product::getDiscount() const
{
	return 0;
}

void Product::setID(int _id)
{
}

void Product::setName(std::string _name)
{
}

void Product::setPrice(double _price)
{
}

void Product::setAmount(int _amount)
{
}

void Product::setDiscount(short _discount)
{
}
