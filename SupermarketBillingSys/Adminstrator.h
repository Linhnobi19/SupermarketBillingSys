#pragma once
#include <string>

class Adminstrator
{
public:
	static Adminstrator* getAdmin();

	void setPassWord(const std::string& pName, const std::string& pWord);

	bool authenticate(const std::string& name, const std::string& pass) {
		return (name == userName && pass == passWord);
	}

private:
	static Adminstrator* admin;
	Adminstrator() {};
	std::string userName;
	std::string passWord;

	
};




