#ifndef SHOPPING_H
#define SHOPPING_H
#include "Product.h"
#include "Adminstrator.h"

// for buyer shopping and admin monitor the sales

class Shopping
{
public:
	Shopping();
	~Shopping();

private:
	Adminstrator* admin;
	Product** product[100];
};


#endif // !SHOPPING_H
