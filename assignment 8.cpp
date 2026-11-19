
#include <iostream>
#include <string>
using namespace std;

struct Product
{
    int id;
    string name;
    float price;
    int quantity;
    Product* next;
};

const int SIZE = 10;

Product* head = NULL;
Product* hashTable[SIZE] = {NULL};

int hashFunction(int id)
{
    return id % SIZE;
}

void addProduct()
{
    Product* newProduct = new Product;

    cout << "Enter Product ID: ";
    cin >> newProduct->id;

    int index = hashFunction(newProduct->id);

    Product* temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->id == newProduct->id)
        {
            cout << "Product ID already exists!\n";
            delete newProduct;
            return;
        }
        temp = temp->next;
    }

    cout << "Enter Product Name: ";
    cin >> newProduct->name;

    cout << "Enter Product Price: ";
    cin >> newProduct->price;

    cout << "Enter Product Quantity: ";
    cin >> newProduct->quantity;

    newProduct->next = head;
    head = newProduct;

    Product* hashNode = new Product(*newProduct);
    hashNode->next = hashTable[index];
    hashTable[index] = hashNode;

    cout << "Product Added Successfully!\n";
}

void searchProduct()
{
    int id;

    cout << "Enter Product ID: ";
    cin >> id;

    int index = hashFunction(id);

    Product* temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            cout << "\nProduct Found!\n";
            cout << "Product ID: " << temp->id << endl;
            cout << "Name: " << temp->name << endl;
            cout << "Price: " << temp->price << endl;
            cout << "Quantity: " << temp->quantity << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Product Not Found!\n";
}

void updateProduct()
{
    int id;

    cout << "Enter Product ID: ";
    cin >> id;

    int index = hashFunction(id);

    Product* temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            cout << "Enter New Product Name: ";
            cin >> temp->name;

            cout << "Enter New Price: ";
            cin >> temp->price;

            cout << "Enter New Quantity: ";
            cin >> temp->quantity;

            Product* listTemp = head;

            while (listTemp != NULL)
            {
                if (listTemp->id == id)
                {
                    listTemp->name = temp->name;
                    listTemp->price = temp->price;
                    listTemp->quantity = temp->quantity;
                    break;
                }

                listTemp = listTemp->next;
            }

            cout << "Product Updated Successfully!\n";
            return;
        }

        temp = temp->next;
    }

    cout << "Product Not Found!\n";
}

void removeProduct()
{
    int id;

    cout << "Enter Product ID: ";
    cin >> id;

    Product* temp = head;
    Product* prev = NULL;

    while (temp != NULL && temp->id != id)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Product Not Found!\n";
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    delete temp;

    int index = hashFunction(id);

    Product* htemp = hashTable[index];
    Product* hprev = NULL;

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

    cout << "Product Removed Successfully!\n";
}

void displayProducts()
{
    Product* temp = head;

    if (temp == NULL)
    {
        cout << "No Products Available!\n";
        return;
    }

    cout << "\n===== PRODUCT CATALOG =====\n";

    while (temp != NULL)
    {
        cout << "\nProduct ID: " << temp->id << endl;
        cout << "Name: " << temp->name << endl;
        cout << "Price: " << temp->price << endl;
        cout << "Quantity: " << temp->quantity << endl;

        temp = temp->next;
    }
}

void menu()
{
    int choice;

    cout << "\n===== ONLINE SHOPPING SYSTEM =====\n";
    cout << "1. Add Product\n";
    cout << "2. Search Product\n";
    cout << "3. Update Product\n";
    cout << "4. Remove Product\n";
    cout << "5. Display All Products\n";
    cout << "6. Exit\n";

    cout << "Enter Your Choice: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
            addProduct();
            break;

        case 2:
            searchProduct();
            break;

        case 3:
            updateProduct();
            break;

        case 4:
            removeProduct();
            break;

        case 5:
            displayProducts();
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
