#include "Appointment.h"

Appointment::Appointment()
    : date(Date()), time(1, 1, 1), patientName("No Patient"), description("No Description") {}

Appointment::Appointment(const Date& date, const Time_& time, const string& patientName, const string& description)
    : date(date), time(time), patientName(patientName), description(description) {}

const Date& Appointment::getDate() const
{
    return date;
}

const Time_& Appointment::getTime() const 
{
    return time;
}

const string& Appointment::getPatientName() const
{
    return patientName;
}

const string& Appointment::getDescription() const 
{
    return description;
}

void Appointment::setDate(const Date& date) 
{
    this->date = date;
}

void Appointment::setTime(const Time_& time) 
{
    this->time = time;
}

void Appointment::setPatientName(const string& patientName) 
{
    this->patientName = patientName;
}

void Appointment::setDescription(const string& description)
{
    this->description = description;
}
bool Appointment::operator<(const Appointment& appointment2) const&
{
    if (this->getDate() < appointment2.getDate()) {
        return true;
    }
    else if (this->getDate() == appointment2.getDate()) {
        return this->getTime() < appointment2.getTime();
    }
    return false;
}
