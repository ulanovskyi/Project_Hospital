#pragma once
#include "Date.h"
#include "Time_.h"
#include <string>

using std::string;

class Appointment
{
    Date date;
    Time_ time;
    string patientName;
    string description;

public:
    Appointment();
    Appointment(const Date& date, const Time_& time, const string& patientName, const string& description);

    const Date& getDate()const;
    const Time_& getTime()const;
    const string& getPatientName()const;
    const string& getDescription()const;

    void setDate(const Date& date);
    void setTime(const Time_& time);
    void setPatientName(const string& patientName);
    void setDescription(const string& description);

    bool operator<(const Appointment& appointment2)const&;

};
