#include <iostream>
#include <string>
using namespace std;

struct AdminNode {
    string username;
    string password;
    AdminNode* next;

    AdminNode(string u, string p) : username(u), password(p), next(NULL) {}
};

class AdminList {
private:
    AdminNode* adminHead;

public:
    AdminList() : adminHead(NULL) {}

    void addAdmin(string username, string password) {
        AdminNode* newAdmin = new AdminNode(username, password);
        newAdmin->next = adminHead;
        adminHead = newAdmin;
        cout << "\n";
    }

    AdminNode* authenticateAdmin(string enteredUsername, string enteredPassword) {
        AdminNode* current = adminHead;
        while (current != NULL) {
            if (current->username == enteredUsername && current->password == enteredPassword) {
                return current;
            }
            current = current->next;
        }
        return NULL;
    }
};

struct Node {
    string name;
    string schedule;
    string illness;
    double billAmount;
    string appointment;
    string phoneNumber;
    string email;
    Node* next;

    Node(string n, string s, string i, double b, string appt, string phone, string mail)
        : name(n), schedule(s), illness(i), billAmount(b), appointment(appt), phoneNumber(phone), email(mail), next(NULL) {}
};

class LinkedList {
private:
    Node* doctorHead;
    Node* patientHead;
    Node* billingHead;
    Node* appointmentHead;
    AdminList adminList;

public:
    LinkedList() : doctorHead(NULL), patientHead(NULL), billingHead(NULL), appointmentHead(NULL) {}

    void addAdmin(string username, string password) {
        adminList.addAdmin(username, password);
    }

    AdminNode* authenticateAdmin(string enteredUsername, string enteredPassword) {
        return adminList.authenticateAdmin(enteredUsername, enteredPassword);
    }


void updateDoctorContactInfo(string doctorName, string newPhone, string newEmail) {
    Node* currentDoctor = doctorHead;
    while (currentDoctor != NULL && currentDoctor->name != doctorName) {
        currentDoctor = currentDoctor->next;
    }

    if (currentDoctor != NULL) {
        currentDoctor->phoneNumber = newPhone;
        currentDoctor->email = newEmail;
        cout << "Contact information updated successfully.\n";
        showDoctors();  // Display updated doctor list
    } else {
        cout << "Doctor not found. Cannot update contact information.\n";
    }
}




    void addDoctor(string name, string schedule) {
        Node* newDoctor = new Node(name, schedule, "", 0.0, "", "", "");
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
        cout << "Name: " << current->name << ", Schedule: " << current->schedule
             << ", Phone: " << current->phoneNumber << ", Email: " << current->email << endl;
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
        Node* newPatient = new Node(name, "", illness, 0.0, "", "", "");
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
        Node* newBilling = new Node(name, "", "", billAmount, "", "", "");
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
                cout << "Billing record found. Name: "

 << current->name << ", Bill Amount: $" << current->billAmount << endl;
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

        if (!currentPatient->appointment.empty()) {
            cout << "Appointment already scheduled for the patient.\n";
        } else {
            currentPatient->appointment = "Doctor: " + doctorName + ", Time: " + appointmentTime;
            cout << "Appointment scheduled successfully.\n";
        }
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
    cout << "Welcome TO The Hospital Management System" << endl << endl;

    LinkedList list;

    // Adding an admin (you can customize the username and password)
    list.addAdmin("admin", "admin123");

    string enteredUsername, enteredPassword;

    cout << "Log in as admin" << endl;
    cout << "Enter username: ";
    cin >> enteredUsername;
    cout << "Enter password: ";
    cin >> enteredPassword;

    AdminNode* authenticatedAdmin = list.authenticateAdmin(enteredUsername, enteredPassword);

    if (authenticatedAdmin != NULL) {
        cout << "Admin login successful." << endl;

        int choice;
        string name, schedule, illness;
        double billAmount;
        string doctorName, patientName, appointmentTime, newPhone, newEmail;

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
            cout << "15. Update Doctor Contact Info\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter doctor name and schedule: ";
                    cin >> name >> schedule;
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
                    cout << "Enter patient name and illness: ";
                    cin >> name >> illness;
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
                    cout << "Enter billing name and amount: ";
                    cin >> name >> billAmount;
                    list.addBilling(name, billAmount);
                    break;
                case 10:
                    list.showBilling();
                    break;
                case 11:
                    cout << "Enter billing name to search: ";
                    cin >> name;
                    list.searchBilling(name);
                    break;
                case 12:
                    cout << "Enter doctor name, patient name, and appointment time: ";
                    cin >> doctorName >> patientName >> appointmentTime;
                    list.scheduleAppointment(doctorName, patientName, appointmentTime);
                    break;
                case 13:
                    list.showAppointments();
                    break;
                case 14:
                    cout << "Exiting program.\n";
                    break;
                case 15:
                    cout << "Enter doctor name: ";
                    cin >> doctorName;
                    cout << "Enter new phone number: ";
                    cin >> newPhone;
                    cout << "Enter new email: ";
                    cin >> newEmail;
                 list.updateDoctorContactInfo(doctorName, newPhone, newEmail);
                    break;
list.showDoctors();
                default:
                    cout << "Invalid choice. Please enter a valid option.\n";
                    break;
            }
        } while (choice != 14);
    } else
 {
        cout << "Admin login unsuccessful. Exiting program." << endl;
    }

    return 0;
}
