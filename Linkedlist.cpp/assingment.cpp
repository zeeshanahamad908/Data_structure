#include <iostream>
using namespace std;
int main()
{
    while (true)
    {
        cout << "**********************" << endl;
        cout << ".Show Linked list" << endl;
        cout << "1.Singly Linked list" << endl;
        cout << "2.Doubly Linked Linked list" << endl;
        cout << "3.Singly circular Linked list" << endl;
        cout << "4.Doubly circular Linked list" << endl;
        cout << "5.exit" << endl;
        char choice;
        cin >> choice;
        switch (choice)
        {
        case '1':
            cout << "Singly Linked list" << endl;
            while (true)
            {
                cout << "*********choose the option" << endl;
                cout << "1. Insertion of a Linked list" << endl;
                cout << "2. Deletion of a Linkded list" << endl;
                cout << "3. Sorting of a Linked list" << endl;
                cout << "4. Searching of a Linked list" << endl;
                cout << "5. Searching of Elements at specific index" << endl;
                cout << "6. GO BACK" << endl;
                char choice2;
                cin >> choice2;
                switch (choice2)
                {
                case '1':
                    cout << "1. Insertion of a Linked list" << endl;
                    while (true)
                    {
                        cout << "1. Inseertion of linked list at start" << endl;
                        cout << "2. Inseertion of linked list in between" << endl;
                        cout << "3. Inseertion of linked list at end" << endl;
                        cout << "4. Inseertion of linked list at specific location" << endl;
                        cout << "5. GO BACK" << endl;
                        char choice3;
                        cin >> choice3;

                        switch (choice3)
                        {

                        case '1':
                            break;

                        case '2':

                            break;

                        case '3':

                            break;

                        case '4':

                            break;

                        case '5':
                            cout << "Back to main menu";
                            break;

                        default:
                            cout << "Enter the valid choice" << endl;
                        }
                        if (choice3 == '5')
                        {
                            break;
                        }
                    }
                    break;
                }
            }
            break;
        case '2':
            break;
        case '3':
            break;
        case '4':
            break;
        case '5':
            break;
        case '6':
            cout << "Program is terminated" << endl;
            break;

        default:
            cout << "Choose the correct options:" << endl;
        }
        if (choice == '6')
        {
            break;
        }
    }
}