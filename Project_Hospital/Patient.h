#pragma once
#include "Person.h"
#include <list>

using std::string;
using std::list;

class Patient : public Person 
{
    string currentDisease;
    list<string> medicalHistory;
    int priorityLevel; //1 - serious, 2 - partially serious, 3 - not serious

public:

    Patient();
    Patient(const string& name, bool gender, const Date& dateOfBirth,
        const string& bloodType, const string& phoneNum, const string& currentDisease, 
        int priorityLevel);

    const string& getCurrentDisease()const;
    const list<string>& getMedicalHistory()const;
    int getPriorityLevel()const;

    void setCurrentDisease(const string& currentDisease);
    void setMedicalHistory(const list<string>& medicalHistory);
    void setPriorityLevel(int priorityLevel);

    void addDisease(const string& disease);
    void healPerson();

    void showInfo()const override;
    void showHistory()const;
};
