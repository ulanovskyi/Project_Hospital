#include "DoctorContainer.h"

void DoctorContainer::addDoctor()
{
        string name;
        bool gender;
        Date dateOfBirth;
        string bloodType;
        string phoneNum;
        string specialization;
        int yearsOfExperience;


        cout << "Enter doctor's name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter doctor's gender (0 for Female, 1 for Male): ";
        cin >> gender;

        cout << "Enter doctor's date of birth: ";
        cin >> dateOfBirth;

        cout << "Enter doctor's phone number: ";
        cin >> phoneNum;

        cout << "Enter doctor's specialization: ";
        cin.ignore();
        getline(cin, specialization);

        cout << "Enter doctor's blood type: ";
        cin >> bloodType;

        cout << "Enter doctor's years of experience: ";
        cin >> yearsOfExperience;


        Doctor newDoctor(name, gender, dateOfBirth, bloodType, phoneNum, specialization, yearsOfExperience);

        doctors.push_back(newDoctor);

}

void DoctorContainer::removeDoctor(const string& name)
{
    auto it = std::remove_if(doctors.begin(), doctors.end(),
        [&name](const Doctor& doctor) {
            return doctor.getName() == name;
        });

    if (it != doctors.end()) {
        doctors.erase(it);
        cout << "Doctor " << name << " removed from the list." << endl;
    }
    else {
        cout << "Doctor " << name << " not found in the list." << endl;
    }
}

void DoctorContainer::addAppointment(const string& name)
{
    auto it = std::find_if(doctors.begin(), doctors.end(),
        [&name](const Doctor& doctor) {
            return doctor.getName() == name;
        });

    if (it != doctors.end())
    {
        string patientName, description;
        Date date;
        Time_ time_;

        cout << "Enter patient name: ";
        cin.ignore();
        getline(cin, patientName);
        cout << "Enter date: ";
        cin >> date;
        cout << "Enter time: ";
        cin >> time_;
        cout << "Enter appointment description: ";
        cin.ignore();
        getline(cin, description);

        it->addAppointment(Appointment(date, time_, patientName, description));
        return;
    }
    
    cout << "Doctor " << name << " not found in the list." << endl;
}

void DoctorContainer::viewAppointments(const string& name) const
{
    for (const auto& doctor : doctors) {
        if (doctor.getName() == name) {
            cout << "Appointments for Dr. " << doctor.getName() << " (" << doctor.getSpecialization() << "):" << std::endl;
            doctor.showAllApointments();
            return;
        }
    }

    cout << "Doctor " << name << " not found in the list." << endl;

}

void DoctorContainer::addPatient(const string& doctorName)
{
    auto doctorIt = std::find_if(doctors.begin(), doctors.end(),
        [&doctorName](const Doctor& doctor) {
            return doctor.getName() == doctorName;
        });

    if (doctorIt != doctors.end())
    {
        string patientName, bloodType, phoneNum, currentDisease;
        bool gender;
        Date dateOfBirth;
        int priorityLevel;

        cout << "Enter patient's name: ";
        cin.ignore(); 
        getline(cin, patientName);
        cout << "Enter patient's gender (0 for Female, 1 for Male): ";
        cin >> gender;
        cout << "Enter patient's date of birth: ";
        cin >> dateOfBirth;
        cout << "Enter patient's blood type (A, B, AB, O): ";
        cin >> bloodType;
        cout << "Enter patient's phone number: ";
        cin.ignore();
        getline(cin, phoneNum);
        cout << "Enter patient's current disease: ";
        getline(cin, currentDisease);
        cout << "Enter patient's priority level (1 - serious, 2 - partially serious, 3 - not serious): ";
        cin >> priorityLevel;

        const Patient* newPatient = new Patient(patientName, gender, dateOfBirth, bloodType, phoneNum, currentDisease, priorityLevel);
        doctorIt->assignPatient(newPatient);
    }
    else
    {
        cout << "Doctor " << doctorName << " not found in the doctor list." << endl;
    }
}

void DoctorContainer::showPatients(const string& doctorName) const 
{
    auto doctorIt = std::find_if(doctors.begin(), doctors.end(),
        [&doctorName](const Doctor& doctor) {
            return doctor.getName() == doctorName;
        });

    if (doctorIt != doctors.end())
    {

        cout << "Patients assigned to Dr. " << doctorName << ":" << endl;
        doctorIt->showAllPatients();
    }
    else 
    {
        cout << "Doctor " << doctorName << " not found in the doctor list." << endl;
    }
}

void DoctorContainer::showAll()
{
    int ch = 0;
    cout << "Select the sort type (1 - by experience, 2 - by name, 3 - specialization): " << endl;
    cin >> ch;

    switch (ch)
    {
    case 1:
        sortDoctorsByExperience();
        break;
    case 2:
        sortDoctorsByName();
        break;
    case 3:
        sortDoctorsBySpecialization();
        break;

    default:
        cout << "Invalid input.";
        return;
    }
    for (auto doctor : doctors)
    {
        doctor.showInfo();
    }
}

void DoctorContainer::searchDoctorByName(const string& name)
{
    for (Doctor& doctor : doctors) {
        if (doctor.getName() == name) {
            doctor.showInfo();
            return;
        }
    }

    cout << "Doctor wasn't found.\n";
}

void DoctorContainer::sortDoctorsByExperience()
{
    sort(doctors.begin(), doctors.end(), [](const Doctor& a, const Doctor& b) {
        return a.getYearsOfExperience() < b.getYearsOfExperience();
        });
}

void DoctorContainer::sortDoctorsByName()
{
    sort(doctors.begin(), doctors.end(), [](const Doctor& a, const Doctor& b) {
        return a.getName() < b.getName();
        });
}

void DoctorContainer::sortDoctorsBySpecialization() 
{
    sort(doctors.begin(), doctors.end(), [](const Doctor& a, const Doctor& b) {
        return a.getSpecialization() < b.getSpecialization();
        });
}

void DoctorContainer::showSpecializations() const
{
    set<string> uniqueSpecializations;

    for (const Doctor& doctor : doctors) 
    {
        uniqueSpecializations.insert(doctor.getSpecialization());
    }

    cout << "Specializations:\n";
    for (const string& specialization : uniqueSpecializations) 
    {
        cout << specialization << endl;
    }
}

void DoctorContainer::showExactSpecialization(const string& special)
{
    sortDoctorsByExperience();

    int c = 0;

    for (const auto& doctor : doctors)
    {
        if (doctor.getName() == special)
        {
            doctor.showInfo();
            c++;
        }
    }

    if (c)
    {
        cout << "Total amount: " << c << endl;
        return;
    }

    cout << "Invalid specialization.\n";
}

void DoctorContainer::saveContainerToFile(const string& filename) {
    std::ofstream outFile(filename);

    if (outFile.is_open()) {
        outFile << doctors.size() << std::endl;

        for (const Doctor& doctor : doctors) {
            outFile << doctor.getName() << " ";
            outFile << doctor.getGender() << " ";
            outFile << doctor.getDateOfBirth() << " ";
            outFile << doctor.getBloodType() << " ";
            outFile << doctor.getPhoneNum() << " ";
            outFile << doctor.getSpecialization() << " ";
            outFile << doctor.getYearsOfExperience() << " ";

            const std::list<Patient>& patients = doctor.getPatients();
            outFile << patients.size() << " ";
            for (const Patient& patient : patients) {
                outFile << patient.getName() << " ";
                outFile << patient.getGender() << " ";
                outFile << patient.getDateOfBirth() << " ";
                outFile << patient.getBloodType() << " ";
                outFile << patient.getPhoneNum() << " ";
                outFile << patient.getCurrentDisease() << " ";
                outFile << patient.getPriorityLevel() << " ";
            }

            const auto& appointments = doctor.getAppointments();
            outFile << appointments.size() << " ";
            for (const Appointment& appointment : appointments) {
                outFile << appointment.getDate() << " ";
                outFile << appointment.getTime() << " ";
                outFile << appointment.getPatientName() << " ";
                outFile << appointment.getDescription() << " ";
            }
        }

        outFile.close();
    }
    else {
        cout << "Error: Unable to open the file for saving." << endl;
    }
}

void DoctorContainer::loadContainerFromFile(const std::string& filename) {
    std::ifstream inFile(filename);

    if (inFile.is_open()) {
        doctors.clear();

        size_t numDoctors;
        inFile >> numDoctors;

        for (size_t i = 0; i < numDoctors; ++i) {
            string name, specialization;
            bool gender;
            Date dateOfBirth;
            string bloodType, phoneNum;
            int yearsOfExperience;

            inFile >> name >> gender >> dateOfBirth >> bloodType >> phoneNum >> specialization >> yearsOfExperience;

            Doctor newDoctor(name, gender, dateOfBirth, bloodType, phoneNum, specialization, yearsOfExperience);

            size_t numPatients;
            inFile >> numPatients;

            for (size_t j = 0; j < numPatients; ++j) {
                string patientName, currentDisease;
                bool patientGender;
                Date patientDateOfBirth;
                string patientBloodType, patientPhoneNum;
                int priorityLevel;

                inFile >> patientName >> patientGender >> patientDateOfBirth >> patientBloodType >> patientPhoneNum >> currentDisease >> priorityLevel;

               const Patient* newPatient = new Patient(
                    patientName, patientGender, patientDateOfBirth, patientBloodType, patientPhoneNum, currentDisease, priorityLevel
                );

                newDoctor.assignPatient(newPatient);
            }

            size_t numAppointments;
            inFile >> numAppointments;

            for (size_t k = 0; k < numAppointments; ++k) {
                Date appointmentDate;
                Time_ appointmentTime;
                string patientName, description;

                inFile >> appointmentDate >> appointmentTime >> patientName;
                inFile.ignore();
                getline(inFile, description);

                newDoctor.addAppointment(Appointment(appointmentDate, appointmentTime, patientName, description));
            }

            doctors.push_back(newDoctor);
        }

        inFile.close();
    }
    else {
        cout << "Error: Unable to open the file for loading." << endl;
    }
}

