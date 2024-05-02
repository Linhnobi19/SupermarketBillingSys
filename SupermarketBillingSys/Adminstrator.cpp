#include "Adminstrator.h"


Adminstrator* Adminstrator::admin = nullptr;

Adminstrator* Adminstrator::getAdmin()
{
    if (admin == nullptr) {
        admin = new Adminstrator();
    }

    return admin;
}

void Adminstrator::setPassWord(const std::string& pName, const std::string& pWord)
{
    this->userName = pName;
    this->passWord = pWord;
}


