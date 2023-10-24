#pragma once
#include "Person.h"
#include "Appointment.h"
#include "Patient.h"
#include <set>

using std::set;

class Doctor : public Person
{
    string specialization;
    int yearsOfExperience;
    set<Appointment> appointments;
    list<Patient> patients;

public:
    Doctor();
    Doctor(const string& name, bool gender, const Date& dateOfBirth, const string& bloodType, const string& phoneNum, const string& specialization, int yearsOfExperience);

    const string& getSpecialization() const;
    int getYearsOfExperience() const;

    void setSpecialization(const string& specialization);
    void setYearsOfExperience(int years);
    void addAppointment(const Appointment& app);
    void assignPatient(const Patient* patient);

    void showInfo()const override;
    void showAllApointments()const;
    void showAllPatients()const;

    const set<Appointment>& getAppointments()const;

    const list<Patient>& getPatients()const;
};

