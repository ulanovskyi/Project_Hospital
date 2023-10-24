#pragma once
#include <iostream>
#include <string>
#include "Date.h"

using std::string;

class Person
{
protected:
	bool gender;
	string name;
	Date dateOfBirth;
	string bloodType;
	string phoneNum;

public:
	Person();
	Person(bool gender, const string& name, const Date& dateOfBirth, const string& bloodType, const string& phoneNum);

	bool getGender()const;
	const string& getName()const;
    const Date& getDateOfBirth()const;
    const string& getBloodType()const;
    const string& getPhoneNum()const;

	void setGender(bool gender);
	void setName(const string& name);
	void setDateOfBirth(const Date& dateOfBirth);
	void setBloodType(const string& bloodType);
	void setPhoneNum(const string& phoneNum);

	virtual void showInfo()const;
};

