
#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

queue<string> normalOrders;
priority_queue<string> vipOrders;
stack<string> cancelledOrders;

void addNormalOrder()
{
    string order;
    cout << "Enter customer order: ";
    cin >> order;

    normalOrders.push(order);
    cout << "Normal order added successfully!\n";
}

void addVIPOrder()
{
    string order;
    cout << "Enter VIP customer order: ";
    cin >> order;

    vipOrders.push(order);
    cout << "VIP order added successfully!\n";
}

void processOrder()
{
    if (!vipOrders.empty())
    {
        cout << "Processing VIP Order: "
             << vipOrders.top() << endl;
        vipOrders.pop();
    }
    else if (!normalOrders.empty())
    {
        cout << "Processing Normal Order: "
             << normalOrders.front() << endl;
        normalOrders.pop();
    }
    else
    {
        cout << "No orders available!\n";
    }
}

void cancelOrder()
{
    if (!normalOrders.empty())
    {
        string order = normalOrders.front();
        normalOrders.pop();

        cancelledOrders.push(order);

        cout << "Order cancelled: " << order << endl;
    }
    else
    {
        cout << "No normal orders to cancel!\n";
    }
}

void showCancelledOrders()
{
    if (cancelledOrders.empty())
    {
        cout << "No cancelled orders!\n";
        return;
    }

    cout << "\nRecently Cancelled Orders:\n";

    stack<string> temp = cancelledOrders;

    while (!temp.empty())
    {
        cout << temp.top() << endl;
        temp.pop();
    }
}

void menu()
{
    int choice;

    cout << "\n===== RESTAURANT ORDER SYSTEM =====\n";
    cout << "1. Add Normal Order\n";
    cout << "2. Add VIP Order\n";
    cout << "3. Process Order\n";
    cout << "4. Cancel Normal Order\n";
    cout << "5. View Cancelled Orders\n";
    cout << "6. Exit\n";

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
            addNormalOrder();
            break;

        case 2:
            addVIPOrder();
            break;

        case 3:
            processOrder();
            break;

        case 4:
            cancelOrder();
            break;

        case 5:
            showCancelledOrders();
            break;

        case 6:
            cout << "Thank you!\n";
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
