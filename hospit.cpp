#include <iostream>
#include <string>

using namespace std;

struct node
{
    string name;
    string id;
    string pass;
    node *next;
};

node *head = NULL;
void push(string name, string id, string pass)
{
    node *newnode = new node;
    newnode->name = name;
    newnode->id = id;
    newnode->pass = pass;
    newnode->next = head;
    head = newnode;
}

node* peek()
{
    return head;
}

node* pop()
{
    node* top = head;
    head = head->next;
    return top;
}

void printList()
{
    node* temp = head;
    while(temp != NULL)
    {
        cout << temp->name << " " << temp->id << "\n";
        temp = temp->next;
    }
}

void patientLogin()
{
    string id, pass;
    cout << "Enter patient ID: ";
    cin >> id;
    cout << "Enter password: ";
    cin >> pass;

    node* temp = head;
    while(temp != NULL)
    {
        if(temp->id == id && temp->pass == pass)
        {
            cout << "Login successful!\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Invalid credentials!\n";
}

int main()
{
    int choice;

    while(1)
    {
        cout << "1. Add Patient\n";
        cout << "2. Patient Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1)
        {
            string name, id, pass;
            cout << "Enter patient name: ";
            cin >> name;
            cout << "Enter patient ID: ";
            cin >> id;
            cout << "Enter password: ";
            cin >> pass;
            push(name, id, pass);
        }
        else if(choice == 2)
        {
            patientLogin();
        }
        else if(choice == 3)
        {
            break;
        }
    }

    return 0;
}

