#ifndef ADMINSTRATOR_H
#define ADMINSTRATOR_H
#include <string>

class Adminstrator
{
public:
	static Adminstrator* getAdmin() {
		if (admin == nullptr)
		{
			admin = new Adminstrator();

			// set the user and password
			setPassWord("doanlinh1902@gmail.com", "hoilamgi");
		}

		return admin;
	}

private:
	static Adminstrator* admin;
	Adminstrator() {};
	static std::string userName;
	static std::string passWord;

	static void setPassWord(std::string pName, std::string pWord) {
		userName = pName;
		passWord = pWord;
	}
};



#endif // !ADMINSTRATOR_H


