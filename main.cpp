#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
using namespace std;

class Person {
public:
    string name;
    int age;
    string phone_number;
};

class Doctor : public Person {
public:
    string specialization;
    int doctor_id;
};

class Patient : public Person {
public:
    string address;
};
map<int, Doctor> doctors;
vector<Patient> patients;

int readInt(const string& msg) {
    int x;
    while (true) {
        cout << msg;
        if (cin >> x) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return x;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input, enter a number.\n";
    }
}

string readLine(const string& msg) {
    string s;
    cout << msg;
    getline(cin, s);
    return s;
}

void addDoctor() {
    Doctor d;
    d.doctor_id = readInt("Doctor ID: ");
    if (doctors.count(d.doctor_id)) {
        cout << "ID already exists.\n";
        return;
    }
    d.name = readLine("Name: ");
    d.age = readInt("Age: ");
    d.phone_number = readLine("Phone: ");
    d.specialization = readLine("Specialization: ");
    doctors[d.doctor_id] = d;
    cout << "Doctor added.\n";
}

void addPatient() {
    Patient p;
    p.name = readLine("Name: ");
    p.age = readInt("Age: ");
    p.phone_number = readLine("Phone: ");
    p.address = readLine("Address: ");
    patients.push_back(p);
    cout << "Patient added.\n";
}

void showDoctors() {
    if (doctors.empty()) { cout << "No doctors.\n"; return; }
    for (const auto& pair : doctors) {
        const Doctor& d = pair.second;
        cout << d.doctor_id << " | " << d.name << " | " << d.age << " | "
             << d.phone_number << " | " << d.specialization << endl;
    }
}

void showPatients() {
    if (patients.empty()) { cout << "No patients.\n"; return; }
    for (const Patient& p : patients)
        cout << p.name << " | " << p.age << " | "
             << p.phone_number << " | " << p.address << endl;
}

void searchDoctor() {
    int id = readInt("Enter doctor ID: ");
    auto it = doctors.find(id);
    if (it == doctors.end()) {
        cout << "Not found.\n";
        return;
    }
    cout << "Found: " << it->second.name << " - "
         << it->second.specialization << endl;
}

void searchPatient() {
    string name = readLine("Enter patient name: ");
    bool found = false;
    for (const Patient& p : patients) {
        if (p.name == name) {
            cout << "Found: " << p.name << " | " << p.age
                 << " | " << p.address << endl;
            found = true;
        }
    }
    if (!found) cout << "Not found.\n";
}

void sortPatientsByAge() {
    sort(patients.begin(), patients.end(),
         [](const Patient& a, const Patient& b) { return a.age < b.age; });
    cout << "Patients sorted by age.\n";
    showPatients();
}

int main() {

    Doctor d;
    d.name = "alaa";
    d.age = 21;
    d.phone_number = "23627";
    d.specialization = "Cardiology";
    d.doctor_id = 1;
    doctors[d.doctor_id] = d;

    Patient p;
    p.name = "salma";
    p.age = 21;
    p.phone_number = "67890";
    p.address = "sohag";
    patients.push_back(p);

    int choice;
    do {
        cout << "\n===== Hospital System =====\n"
                "1. Add Doctor\n"
                "2. Add Patient\n"
                "3. Show Doctors\n"
                "4. Show Patients\n"
                "5. Search Doctor by ID\n"
                "6. Search Patient by Name\n"
                "7. Sort Patients by Age\n"
                "0. Exit\n";
        choice = readInt("Choice: ");

        switch (choice) {
            case 1: addDoctor();          break;
            case 2: addPatient();         break;
            case 3: showDoctors();        break;
            case 4: showPatients();       break;
            case 5: searchDoctor();       break;
            case 6: searchPatient();      break;
            case 7: sortPatientsByAge();  break;
            case 0: cout << "Bye!\n";     break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
