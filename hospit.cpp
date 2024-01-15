#include <iostream>
#include <string>

using namespace std;

struct Patient {
    string name;
    int age;
    string gender;
    string diagnosis;
};

Patient getPatientInfo() {
    Patient patient;

    cout << "Enter patient name: ";
    getline(cin, patient.name);

    cout << "Enter patient age: ";
    cin >> patient.age;
    cin.ignore();

    cout << "Enter patient gender: ";
    getline(cin, patient.gender);

    cout << "Enter patient diagnosis: ";
    getline(cin, patient.diagnosis);

    return patient;
}

int main() {
    cout << "Welcome to the Patient Admission System" << endl;

    Patient newPatient = getPatientInfo();

    cout << "\nPatient Information Entered:" << endl;
    cout << "Name: " << newPatient.name << endl;
    cout << "Age: " << newPatient.age << endl;
    cout << "Gender: " << newPatient.gender << endl;
    cout << "Diagnosis: " << newPatient.diagnosis << endl;


    cout << "\nThank you for using the Patient Admission System" << endl;

    return 0;
}

