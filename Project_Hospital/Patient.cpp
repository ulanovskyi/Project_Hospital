#include "Patient.h"

Patient::Patient()
    : currentDisease("No disease"), priorityLevel(3) {}

Patient::Patient(const string& name, bool gender, const Date& dateOfBirth,
    const string& bloodType, const string& phoneNum, const string& currentDisease,
    int priorityLevel)
    : Person(gender, name, dateOfBirth, bloodType, phoneNum) 
{
    try
    {
        if (currentDisease.empty()) 
        {
            throw std::invalid_argument("Current disease cannot be empty.");
        }

        if (priorityLevel < 1 || priorityLevel > 3) 
        {
            throw std::invalid_argument("Invalid priority level.");
        }

        this->currentDisease = currentDisease;
        this->priorityLevel = priorityLevel;
    }
    catch (const std::invalid_argument& e) 
    {
        cout << "Error in patient constructor: " << e.what() << endl;
    }
}

const string& Patient::getCurrentDisease() const
{
    return currentDisease;
}

const list<string>& Patient::getMedicalHistory() const 
{
    return medicalHistory;
}

int Patient::getPriorityLevel() const
{
    return priorityLevel;
}

void Patient::setCurrentDisease(const string& currentDisease) 
{
    if (currentDisease.empty()) 
    {
        throw std::invalid_argument("Current disease cannot be empty.");
    }
    this->currentDisease = currentDisease;
}

void Patient::setMedicalHistory(const list<string>& medicalHistory)
{
    if (medicalHistory.size() == 0)
    {
        throw std::invalid_argument("The med history cannot be empty.");
    }
    this->medicalHistory = medicalHistory;
}

void Patient::setPriorityLevel(int priorityLevel) 
{
    if (priorityLevel < 1 || priorityLevel > 3)
    {
        throw std::invalid_argument("Invalid priority level.");
    }
    this->priorityLevel = priorityLevel;
}

void Patient::addDisease(const string& disease)
{
    if (disease.empty())
    {
        throw std::invalid_argument("Invalid disease.");
    }
    medicalHistory.push_back(disease);
}

void Patient::healPerson()
{
    if (currentDisease == "Healthy")
    {
        throw "The person is already healthy.";
    }
    medicalHistory.push_back(currentDisease);
    currentDisease = "Healthy";
}

void Patient::showInfo() const
{
    Person::showInfo();
    cout << "Current Disease: " << currentDisease << endl;
    cout << "Priority Level: " << priorityLevel << endl;

}

void Patient::showHistory() const
{
    cout << "Name: " << name << endl;

    for (auto item : medicalHistory)
    {
        cout << "\t" << item << endl;
    }
}
