#include "Person.h"

Person::Person()
    : gender(true), name("Noname"), dateOfBirth(Date()), bloodType("A"), phoneNum("None") {}

Person::Person(bool gender, const string& name, const Date& dateOfBirth, const string& bloodType, const string& phoneNum)
{
    try 
    {
        if (gender != true && gender != false) 
        {
            throw std::invalid_argument("Invalid gender value.");
        }

        if (name.empty()) 
        {
            throw std::invalid_argument("Name cannot be empty.");
        }

        if (!dateOfBirth.valid())
        {
            throw std::invalid_argument("Invalid date of birth.");
        }

        if (bloodType != "A" && bloodType != "B" && bloodType != "AB" && bloodType != "O")
        {
            throw std::invalid_argument("Invalid blood type.");
        }

        if (!(phoneNum.length() >= 10 && phoneNum.length() <= 18))
        {
            throw std::invalid_argument("Invalid phone number.");
        }

        this->gender = gender;
        this->name = name;
        this->dateOfBirth = dateOfBirth;
        this->bloodType = bloodType;
        this->phoneNum = phoneNum;
    }

    catch (const std::invalid_argument& e)
    {
        cout << "Error in person constructor: " << e.what() << endl;
    }
}

bool Person::getGender() const
{
    return gender;
}

const string& Person::getName() const
{
    return name;
}

const Date& Person::getDateOfBirth() const
{
    return dateOfBirth;
}

const string& Person::getBloodType() const
{
    return bloodType;
}

const string& Person::getPhoneNum() const
{
    return phoneNum;
}

void Person::setGender(bool gender) {
    if (gender != true && gender != false) {
        throw std::invalid_argument("Invalid gender value.");
    }
    this->gender = gender;
}

void Person::setName(const string& name) {
    if (name.empty()) {
        throw std::invalid_argument("Name cannot be empty.");
    }
    this->name = name;
}

void Person::setDateOfBirth(const Date& dateOfBirth) {
    if (!dateOfBirth.valid()) {
        throw std::invalid_argument("Invalid date of birth.");
    }
    this->dateOfBirth = dateOfBirth;
}

void Person::setBloodType(const string& bloodType) {
    if (bloodType != "A" && bloodType != "B" && bloodType != "AB" && bloodType != "O") {
        throw std::invalid_argument("Invalid blood type.");
    }
    this->bloodType = bloodType;
}

void Person::setPhoneNum(const string& phoneNum) {
    if (!(phoneNum.length() <= 18 && phoneNum.length() >= 10)) {
        throw std::invalid_argument("Invalid phone number.");
    }
    this->phoneNum = phoneNum;
}

void Person::showInfo() const
{
    cout << "Name: " << name << endl;
    cout << "Gender: " << (gender ? "Male" : "Female") << endl;
    cout << "Date of birth: " << dateOfBirth << endl;
    cout << "Phone number: " << phoneNum << endl;
    cout << "Blood type: " << bloodType << endl;
}
