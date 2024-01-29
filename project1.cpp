#include <iostream>
#include <string>
using namespace std;


struct Node {
    string name;
    string schedule;
    string illness;
    double billAmount;
    string appointment;
    Node* next;

    Node(string n, string s, string i, double b, string appt) : name(n), schedule(s), illness(i), billAmount(b), appointment(appt), next(NULL) {}
};


class LinkedList {
private:
    Node* doctorHead;
    Node* patientHead;
    Node* billingHead;
    Node* appointmentHead;

public:
    LinkedList() : doctorHead(NULL), patientHead(NULL), billingHead(NULL), appointmentHead(NULL) {}


    void addDoctor(string name, string schedule) {
        Node* newDoctor = new Node(name, schedule, "", 0.0, "");
        newDoctor->next = doctorHead;
        doctorHead = newDoctor;
        cout << "Doctor added successfully.\n";
    }


    void deleteDoctor(string name) {
        Node* current = doctorHead;
        Node* prev = NULL;

        while (current != NULL && current->name != name) {
            prev = current;
            current = current->next;
        }

        if (current == NULL) {
            cout << "Doctor not found.\n";
            return;
        }

        if (prev == NULL) {
            doctorHead = current->next;
        } else {
            prev->next = current->next;
        }

        delete current;
        cout << "Doctor deleted successfully.\n";
    }


    void showDoctors() {
        Node* current = doctorHead;
        if (current == NULL) {
            cout << "No doctors available.\n";
            return;
        }

        cout << "List of Doctors:\n";
        while (current != NULL) {
            cout << "Name: " << current->name << ", Schedule: " << current->schedule << endl;
            current = current->next;
        }
    }


    void searchDoctor(string name) {
        Node* current = doctorHead;
        while (current != NULL) {
            if (current->name == name) {
                cout << "Doctor found. Name: " << current->name << ", Schedule: " << current->schedule << endl;
                return;
            }
            current = current->next;
        }

        cout << "Doctor not found.\n";
    }


    void addPatient(string name, string illness) {
        Node* newPatient = new Node(name, "", illness, 0.0, "");
        newPatient->next = patientHead;
        patientHead = newPatient;
        cout << "Patient added successfully.\n";
    }


    void deletePatient(string name) {
        Node* current = patientHead;
        Node* prev = NULL;

        while (current != NULL && current->name != name) {
            prev = current;
            current = current->next;
        }

        if (current == NULL) {
            cout << "Patient not found.\n";
            return;
        }

        if (prev == NULL) {
            patientHead = current->next;
        } else {
            prev->next = current->next;
        }

        delete current;
        cout << "Patient deleted successfully.\n";
    }


    void showPatients() {
        Node* current = patientHead;
        if (current == NULL) {
            cout << "No patients available.\n";
            return;
        }

        cout << "List of Patients:\n";
        while (current != NULL) {
            cout << "Name: " << current->name << ", Illness: " << current->illness << endl;
            current = current->next;
        }
    }


    void searchPatient(string name) {
        Node* current = patientHead;
        while (current != NULL) {
            if (current->name == name) {
                cout << "Patient found. Name: " << current->name << ", Illness: " << current->illness << endl;
                return;
            }
            current = current->next;
        }

        cout << "Patient not found.\n";
    }


    void addBilling(string name, double billAmount) {
        Node* newBilling = new Node(name, "", "", billAmount, "");
        newBilling->next = billingHead;
        billingHead = newBilling;
        cout << "Billing information added successfully.\n";
    }


    void showBilling() {
        Node* current = billingHead;
        if (current == NULL) {
            cout << "No billing records available.\n";
            return;
        }

        cout << "Billing Records:\n";
        while (current != NULL) {
            cout << "Name: " << current->name << ", Bill Amount: $" << current->billAmount << endl;
            current = current->next;
        }
    }


    void searchBilling(string name) {
        Node* current = billingHead;
        while (current != NULL) {
            if (current->name == name) {
                cout << "Billing record found. Name: " << current->name << ", Bill Amount: $" << current->billAmount << endl;
                return;
            }
            current = current->next;
        }

        cout << "Billing record not found.\n";
    }


    void scheduleAppointment(string doctorName, string patientName, string appointmentTime) {
        Node* currentDoctor = doctorHead;
        Node* currentPatient = patientHead;

        while (currentDoctor != NULL && currentDoctor->name != doctorName) {
            currentDoctor = currentDoctor->next;
        }

        while (currentPatient != NULL && currentPatient->name != patientName) {
            currentPatient = currentPatient->next;
        }

        if (currentDoctor == NULL || currentPatient == NULL) {
            cout << "Doctor or patient not found. Cannot schedule appointment.\n";
            return;
        }

        currentPatient->appointment = "Doctor: " + doctorName + ", Time: " + appointmentTime;
        cout << "Appointment scheduled successfully.\n";
    }


    void showAppointments() {
        Node* currentPatient = patientHead;
        if (currentPatient == NULL) {
            cout << "No appointments scheduled.\n";
            return;
        }

        cout << "List of Appointments:\n";
        while (currentPatient != NULL) {
            if (!currentPatient->appointment.empty()) {
                cout << "Patient: " << currentPatient->name << ", " << currentPatient->appointment << endl;
            }
            currentPatient = currentPatient->next;
        }
    }
};

int main() {
    cout<<"Welcome TO The Hospital Management System"<<endl<<endl;
    cout<<"Log in as admin"<<endl;
    LinkedList list;

    int choice;
    string name, schedule, illness;
    double billAmount;
    string doctorName, patientName, appointmentTime;

    do {
        cout << "\n Information:\n";
        cout << "1. Add Doctor\n";
        cout << "2. Delete Doctor\n";
        cout << "3. Show Doctors\n";
        cout << "4. Search Doctor\n";
        cout << "5. Add Patient\n";
        cout << "6. Delete Patient\n";
        cout << "7. Show Patients\n";
        cout << "8. Search Patient\n";
        cout << "9. Add Billing\n";
        cout << "10. Show Billing\n";
        cout << "11. Search Billing\n";
        cout << "12. Schedule Appointment\n";
        cout << "13. Show Appointments\n";
        cout << "14. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter doctor name: ";
                cin >> name;
                cout << "Enter doctor schedule: ";
                cin >> schedule;
                list.addDoctor(name, schedule);
                break;

            case 2:
                cout << "Enter doctor name to delete: ";
                cin >> name;
                list.deleteDoctor(name);
                break;

            case 3:
                list.showDoctors();
                break;

            case 4:
                cout << "Enter doctor name to search: ";
                cin >> name;
                list.searchDoctor(name);
                break;

            case 5:
                cout << "Enter patient name: ";
                cin >> name;
                cout << "Enter patient illness: ";
                cin >> illness;
                list.addPatient(name, illness);
                break;

            case 6:
                cout << "Enter patient name to delete: ";
                cin >> name;
                list.deletePatient(name);
                break;

            case 7:
                list.showPatients();
                break;

            case 8:
                cout << "Enter patient name to search: ";
                cin >> name;
                list.searchPatient(name);
                break;

            case 9:
                cout << "Enter patient name for billing: ";
                cin >> name;
                cout << "Enter bill amount: $";
                cin >> billAmount;
                list.addBilling(name, billAmount);
                break;

            case 10:
                list.showBilling();
                break;

            case 11:
                cout << "Enter patient name to search billing: ";
                cin >> name;
                list.searchBilling(name);
                break;

            case 12:
                cout << "Enter doctor name: ";
                cin >> doctorName;
                cout << "Enter patient name: ";
                cin >> patientName;
                cout << "Enter appointment time: ";
                cin >> appointmentTime;
                list.scheduleAppointment(doctorName, patientName, appointmentTime);
                break;

            case 13:
                list.showAppointments();
                break;

            case 14:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 14);

    return 0;
}
