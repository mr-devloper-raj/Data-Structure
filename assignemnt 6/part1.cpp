
#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

queue<string> normalCustomers;
priority_queue<string> priorityCustomers;
stack<string> servedCustomers;

int token = 1;

void addNormalCustomer()
{
    string name;

    cout << "Enter customer name: ";
    cin >> name;

    normalCustomers.push(name);

    cout << "Token Number: " << token++ << endl;
    cout << "Normal customer added successfully!\n";
}

void addPriorityCustomer()
{
    string name;

    cout << "Enter customer name: ";
    cin >> name;

    priorityCustomers.push(name);

    cout << "Token Number: " << token++ << endl;
    cout << "Priority customer added successfully!\n";
}

void serveCustomer()
{
    string name;

    if (!priorityCustomers.empty())
    {
        name = priorityCustomers.top();
        priorityCustomers.pop();

        cout << "Serving Priority Customer: " << name << endl;
    }
    else if (!normalCustomers.empty())
    {
        name = normalCustomers.front();
        normalCustomers.pop();

        cout << "Serving Normal Customer: " << name << endl;
    }
    else
    {
        cout << "No customers waiting!\n";
        return;
    }

    servedCustomers.push(name);
}

void showServedCustomers()
{
    if (servedCustomers.empty())
    {
        cout << "No served customers!\n";
        return;
    }

    stack<string> temp = servedCustomers;

    cout << "\nRecently Served Customers:\n";

    while (!temp.empty())
    {
        cout << temp.top() << endl;
        temp.pop();
    }
}

void menu()
{
    int choice;

    cout << "\n===== BANK CUSTOMER SERVICE SYSTEM =====\n";
    cout << "1. Add Normal Customer\n";
    cout << "2. Add Priority Customer\n";
    cout << "3. Serve Customer\n";
    cout << "4. View Served Customers History\n";
    cout << "5. Exit\n";

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
            addNormalCustomer();
            break;

        case 2:
            addPriorityCustomer();
            break;

        case 3:
            serveCustomer();
            break;

        case 4:
            showServedCustomers();
            break;

        case 5:
            cout << "Thank you for using Bank Service System!\n";
            return;

        default:
            cout << "Invalid choice!\n";
    }

    menu();
}

int main()
{
    menu();
    return 0;
}
