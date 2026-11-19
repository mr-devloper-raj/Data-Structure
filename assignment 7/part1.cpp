
#include <iostream>
#include <string>
using namespace std;

struct Patient
{
    int id;
    string name;
    int age;
    string disease;
    Patient* next;
};

const int SIZE = 10;

Patient* head = NULL;
Patient* hashTable[SIZE] = {NULL};

int hashFunction(int id)
{
    return id % SIZE;
}

void registerPatient()
{
    Patient* newPatient = new Patient;

    cout << "Enter Patient ID: ";
    cin >> newPatient->id;

    int index = hashFunction(newPatient->id);

    Patient* temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->id == newPatient->id)
        {
            cout << "Patient ID already exists!\n";
            delete newPatient;
            return;
        }
        temp = temp->next;
    }

    cout << "Enter Patient Name: ";
    cin >> newPatient->name;

    cout << "Enter Patient Age: ";
    cin >> newPatient->age;

    cout << "Enter Disease: ";
    cin >> newPatient->disease;

    newPatient->next = head;
    head = newPatient;

    Patient* hashNode = new Patient(*newPatient);
    hashNode->next = hashTable[index];
    hashTable[index] = hashNode;

    cout << "Patient Registered Successfully!\n";
}

void searchPatient()
{
    int id;

    cout << "Enter Patient ID: ";
    cin >> id;

    int index = hashFunction(id);

    Patient* temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            cout << "\nPatient Found!\n";
            cout << "ID: " << temp->id << endl;
            cout << "Name: " << temp->name << endl;
            cout << "Age: " << temp->age << endl;
            cout << "Disease: " << temp->disease << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Patient Not Found!\n";
}

void updatePatient()
{
    int id;

    cout << "Enter Patient ID: ";
    cin >> id;

    int index = hashFunction(id);

    Patient* temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            cout << "Enter New Name: ";
            cin >> temp->name;

            cout << "Enter New Age: ";
            cin >> temp->age;

            cout << "Enter New Disease: ";
            cin >> temp->disease;

            Patient* listTemp = head;

            while (listTemp != NULL)
            {
                if (listTemp->id == id)
                {
                    listTemp->name = temp->name;
                    listTemp->age = temp->age;
                    listTemp->disease = temp->disease;
                    break;
                }

                listTemp = listTemp->next;
            }

            cout << "Patient Updated Successfully!\n";
            return;
        }

        temp = temp->next;
    }

    cout << "Patient Not Found!\n";
}

void dischargePatient()
{
    int id;

    cout << "Enter Patient ID: ";
    cin >> id;

    Patient* temp = head;
    Patient* prev = NULL;

    while (temp != NULL && temp->id != id)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Patient Not Found!\n";
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    delete temp;

    int index = hashFunction(id);

    Patient* htemp = hashTable[index];
    Patient* hprev = NULL;

    while (htemp != NULL && htemp->id != id)
    {
        hprev = htemp;
        htemp = htemp->next;
    }

    if (htemp != NULL)
    {
        if (hprev == NULL)
            hashTable[index] = htemp->next;
        else
            hprev->next = htemp->next;

        delete htemp;
    }

    cout << "Patient Discharged Successfully!\n";
}

void displayPatients()
{
    Patient* temp = head;

    if (temp == NULL)
    {
        cout << "No Patient Records Available!\n";
        return;
    }

    cout << "\n===== PATIENT RECORDS =====\n";

    while (temp != NULL)
    {
        cout << "\nPatient ID: " << temp->id << endl;
        cout << "Name: " << temp->name << endl;
        cout << "Age: " << temp->age << endl;
        cout << "Disease: " << temp->disease << endl;

        temp = temp->next;
    }
}

void menu()
{
    int choice;

    cout << "\n===== HOSPITAL MANAGEMENT SYSTEM =====\n";
    cout << "1. Register Patient\n";
    cout << "2. Search Patient\n";
    cout << "3. Update Patient\n";
    cout << "4. Discharge Patient\n";
    cout << "5. Display All Patients\n";
    cout << "6. Exit\n";

    cout << "Enter Your Choice: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
            registerPatient();
            break;

        case 2:
            searchPatient();
            break;

        case 3:
            updatePatient();
            break;

        case 4:
            dischargePatient();
            break;

        case 5:
            displayPatients();
            break;

        case 6:
            cout << "Thank You!\n";
            return;

        default:
            cout << "Invalid Choice!\n";
    }

    menu();
}

int main()
{
    menu();
    return 0;
}
