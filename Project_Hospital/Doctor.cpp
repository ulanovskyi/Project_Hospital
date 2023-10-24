#include "Doctor.h"

Doctor::Doctor()
    : specialization("None"), yearsOfExperience(0) {}

Doctor::Doctor(const string& name, bool gender, const Date& dateOfBirth, const string& bloodType, const string& phoneNum, const string& specialization, int yearsOfExperience)
    : Person(gender, name, dateOfBirth, bloodType, phoneNum)
{
    try 
    {
        if (specialization.empty()) 
        {
            throw std::invalid_argument("Specialization cannot be empty.");
        }

        if (yearsOfExperience < 0)
        {
            throw std::invalid_argument("Years of experience cannot be negative.");
        }

        this->specialization = specialization;
        this->yearsOfExperience = yearsOfExperience;
    }
    catch (const std::invalid_argument& e) 
    {
        cout << "Error in Doctor constructor: " << e.what() << endl;
    }
}

const string& Doctor::getSpecialization() const 
{
    return specialization;
}

int Doctor::getYearsOfExperience() const 
{
    return yearsOfExperience;
}

void Doctor::setSpecialization(const string& specialization)
{
    if (specialization.empty()) {
        throw std::invalid_argument("Specialization cannot be empty.");
    }
    this->specialization = specialization;
}

void Doctor::setYearsOfExperience(int years)
{
    if (years < 0) {
        throw std::invalid_argument("Years of experience cannot be negative.");
    }
    this->yearsOfExperience = years;
}

void Doctor::addAppointment(const Appointment& app)
{
    if (app.getDate() >= Date())
    {
        appointments.insert(app);
    }

    else
    {
        throw std::invalid_argument("Incorrect date of the appointment.");
    }
}

void Doctor::assignPatient(const Patient* patient)
{
    patients.push_back(*patient);
}

void Doctor::showInfo() const
{
    cout << "Specialization: " << specialization << endl;
    Person::showInfo();
    cout << "Years of experience: " << yearsOfExperience << endl;
    cout << "Number of patients: " << patients.size() << endl;
}

void Doctor::showAllApointments() const
{
    Date d;
    cout << "All Appointments: " << endl;
        for (const Appointment& appointment : appointments) {
            if (d != appointment.getDate())
            {
                cout << "Date: " << appointment.getDate() << endl;
                cout << "------------\n";
            }
            cout << "\tTime: " << appointment.getTime() << " - Description: " << appointment.getDescription() << endl;
            d = appointment.getDate();
        }
}

void Doctor::showAllPatients() const
{
    if (patients.empty())
    {
        cout << "Doctor has no patients.\n";
        return;
    }
    for (auto patient : patients)
    {
        patient.showInfo();
        cout << endl;
    }
}

const set<Appointment>& Doctor::getAppointments() const
{
    return appointments;
}

const list<Patient>& Doctor::getPatients()const
{
    return patients;
}
