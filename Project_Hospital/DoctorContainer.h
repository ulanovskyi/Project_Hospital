#pragma once
#include <vector>
#include <algorithm>
#include <fstream>
#include "Doctor.h"

using std::vector;
using std::sort;
using std::find;

class DoctorContainer
{
    vector<Doctor> doctors;

public:

    void addDoctor();
    void removeDoctor(const string& name);

    void addAppointment(const string& name);
    void viewAppointments(const string& name)const;

    void addPatient(const string& doctorName);
    void showPatients(const string& doctorName)const;

    void showAll();
    void searchDoctorByName(const string& name);
    void sortDoctorsByExperience();
    void sortDoctorsByName();
    void sortDoctorsBySpecialization();

    void showSpecializations()const;

    void showExactSpecialization(const string& special);

    void saveContainerToFile(const string& filename);
    void loadContainerFromFile(const string& filename);

};

