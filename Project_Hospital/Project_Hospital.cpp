#include <iostream>
#include "DoctorContainer.h"

int main() {
    DoctorContainer container;
    int choice;

    do {
        cout << "1. Add Doctor" << endl;
        cout << "2. Remove Doctor" << endl;
        cout << "3. Add Appointment" << endl;
        cout << "4. View Appointments" << endl;
        cout << "5. Add Patient" << endl;
        cout << "6. Show Patients" << endl;
        cout << "7. Show All Doctors" << endl;
        cout << "8. Search Doctor by Name" << endl;
        cout << "9. Show Specializations" << endl;
        cout << "10. Show Doctors by Specialization" << endl;
        cout << "11. Save Data to File" << endl;
        cout << "12. Load Data from File" << endl;
        cout << "0. Exit" << endl;


        cin >> choice;

        switch (choice) {
        case 1:
            container.addDoctor();
            break;
        case 2:
        {
            string name;
            cout << "Enter the name of the doctor to remove: ";
            cin.ignore();
            getline(cin, name);
            container.removeDoctor(name);
        }
        break;
        case 3:
        {
            string name;
            cout << "Enter the name of the doctor to add an appointment to: ";
            cin.ignore();
            getline(cin, name);
            container.addAppointment(name);
        }
        break;
        case 4:
        {
            string name;
            cout << "Enter the name of the doctor to view appointments: ";
            cin.ignore();
            getline(cin, name);
            container.viewAppointments(name);
        }
        break;
        case 5:
        {
            string doctorName;
            cout << "Enter the name of the doctor to add a patient to: ";
            cin.ignore();
            getline(cin, doctorName);
            container.addPatient(doctorName);
        }
        break;
        case 6:
        {
            string doctorName;
            cout << "Enter the name of the doctor to show patients: ";
            cin.ignore();
            getline(cin, doctorName);
            container.showPatients(doctorName);
        }
        break;
        case 7:
            container.showAll();
            break;
        case 8:
        {
            string name;
            cout << "Enter the name of the doctor to search for: ";
            cin.ignore();
            getline(cin, name);
            container.searchDoctorByName(name);
        }
        break;
        case 9:
            container.showSpecializations();
            break;
        case 10:
        {
            string specialization;
            cout << "Enter the specialization to show doctors: ";
            cin.ignore();
            getline(cin, specialization);
            container.showExactSpecialization(specialization);
        }
        break;
        case 11:
        {
            string filename;
            cout << "Enter the filename to save data: ";
            cin.ignore();
            getline(cin, filename);
            container.saveContainerToFile(filename);
        }
        break;
        case 12:
        {
            string filename;
            cout << "Enter the filename to load data: ";
            cin.ignore();
            getline(std::cin, filename);
            container.loadContainerFromFile(filename);
        }
        break;

        case 0:
            return 0;

        default:
            cout << "Invalid choice. Please try again." << std::endl;
        }

    } while (choice != 0);

    return 0;
}
