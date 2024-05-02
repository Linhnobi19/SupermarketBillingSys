#ifndef BUYER_H
#define BUYER_H
#include <string>

class Buyer
{
public:
	Buyer();
	~Buyer();

	void setName(std::string& pName, std::string& pNum);
	std::string getName() const;
	std::string getNum() const;
	int getSavedPoint() const;

private:
	std::string name;
	std::string phoneNum;
	int savedPoint;			// use for discount
};


#endif // !BUYER_H
