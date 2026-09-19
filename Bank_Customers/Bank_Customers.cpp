#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class BankQueue
{
private:
    struct Node
    {
        int token;
        string service;
        int counter;
        int serviceTime;
        Node* next;
    };
    Node* front;
    Node* rear;
    int nextToken;
public:
    BankQueue()
    {
        front = NULL;
        rear = NULL;
        nextToken = 1;
    }
    bool isEmpty()
    {
        return front == NULL;
    }
    void takeToken()
    {
        int choice;
        string service;
        int counter;
        int serviceTime;

        cout << "-----------------------------------------" << endl;
        cout << "             BANK SERVICES             " << endl;
        cout << "********************************************" << endl;
        cout << "1. Cash Deposit"<<endl;
        cout << "2. Cash Withdrawal"<<endl;
        cout << "3. Bill Payment"  <<endl;
        cout << "4. Account Opening" << endl;
        cout << "5. Account Inquiry" << endl;
        cout << "6. Funds Transfer" << endl;
        cout << "7. Cheque Deposit" << endl;

        cout << "********************************************" <<endl;

        cout << "Select Service: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            service = "Cash Deposit";
            counter = 1;
            serviceTime = 5;
            break;

        case 2:
            service = "Cash Withdrawal";
            counter = 1;
            serviceTime = 5;
            break;

        case 3:
            service = "Bill Payment";
            counter = 1;
            serviceTime = 3;
            break;

        case 4:
            service = "Account Opening";
            counter = 2;
            serviceTime = 15;
            break;

        case 5:
            service = "Account Inquiry";
            counter = 2;
            serviceTime = 5;
            break;

        case 6:
            service = "Funds Transfer";
            counter = 3;
            serviceTime = 7;
            break;

        case 7:
            service = "Cheque Deposit";
            counter = 3;
            serviceTime = 5;
            break;

        default:
            cout << "Invalid service choice" << endl;
            return;
        }
        Node* newNode = new Node;
        newNode->token = nextToken;
        newNode->service = service;
        newNode->counter = counter;
        newNode->serviceTime = serviceTime;
        newNode->next = NULL;

        if (isEmpty())
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;    
            rear = newNode;
        }

        cout << "------------------------------------------------"<<endl;

        cout << "              TOKEN ISSUED"<<endl;

        cout << "------------------------------------------------"<<endl;

        cout << "Token Number: " << nextToken << endl;
        cout << "Service: " << service << endl;
        cout << "Counter: " << counter;

        if (counter == 1)
        {
            cout << " - Cash Counter" << endl;
        }
        else if (counter == 2)
        {
            cout << " - Account Counter" << endl;
        }
        else
        {
            cout << " - Transfer & Cheque Counter" << endl;
        }

        cout << "Estimated Service Time: "
            << serviceTime << " minutes" << endl;

        cout << "Please wait for your turn"<<endl;
        cout << "********************************************" << endl;
        nextToken++;
    }
    void serveCustomer()
    {
        if (isEmpty())
        {
            cout << "No customers are waiting" << endl;
            return;
        }

        Node* temp = front;

        cout << "------------------------------------------------" << endl;

        cout << "           CUSTOMER TURN"<<endl;

        cout << "------------------------------------------------" << endl;

        cout << "Token Number: " << temp->token << endl;
        cout << "Service: " << temp->service << endl;

        cout << "Please proceed to Counter "<< temp->counter;

        if (temp->counter == 1)
        {
            cout << " - Cash Counter";
        }
        else if (temp->counter == 2)
        {
            cout << " - Account Counter";
        }
        else
        {
            cout << " - Transfer & Cheque Counter";
        }

        cout << endl;

        cout << "********************************************" << endl;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        delete temp;
        cout << "Customer served successfully"<<endl;
    }
    void showNextToken()
    {
        if (isEmpty())
        {
            cout << "No customers are waiting"<<endl;
            return;
        }

        cout << "------------------------------------------------" << endl;

        cout << "            NEXT CUSTOMER"<<endl;

        cout << "------------------------------------------------" << endl;

        cout << "Token Number: " << front->token << endl;
        cout << "Service: " << front->service << endl;

        cout << "Counter: " << front->counter;

        if (front->counter == 1)
        {
            cout << " - Cash Counter";
        }
        else if (front->counter == 2)
        {
            cout << " - Account Counter";
        }
        else
        {
            cout << " - Transfer & Cheque Counter";
        }

        cout << endl;

        cout << "Estimated Service Time: "
            << front->serviceTime << " minutes" << endl;

        cout << "********************************************" << endl;
    }
    ~BankQueue()
    {
        while (!isEmpty())
        {
            Node* temp = front;
            front = front->next;
            delete temp;
        }

        rear = NULL;
    }
};
int main()
{
    BankQueue bank;
    int choice;
    do
    {
        cout << "------------------------------------------------" << endl;

        cout << "       BANK TOKEN MANAGEMENT SYSTEM"<<endl;

        cout << "------------------------------------------------" << endl;

        cout << "1. Take Token" << endl;
        cout << "2. Serve Customer" << endl;
        cout << "3. Show Next Token" << endl;
        cout << "4. Exit" <<endl;
        cout << "********************************************" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            bank.takeToken();
            break;

        case 2:
            bank.serveCustomer();
            break;

        case 3:
            bank.showNextToken();
            break;

        case 4:
            cout << "Thank you for using Bank Token Management System" << endl;;
            break;

        default:
            cout << "Invalid choice. Please try again" << endl;
        }

    } while (choice != 4);

    return 0;
}