#include <iostream>
using namespace std;
const int size=100;
// Function declarations

int main()
{
    int arr[size];  // Initialize array
    int sz;  // Initialize size variable

    // Input array elements
    // ...

    //display_arr(arr, sz);  // Display initial array

    while (true)
    {
        cout << "***********" << endl;
        cout << "Choose the option:" << endl;
        cout << "1. Insertion of Elements" << endl;
        cout << "2. Deletion of Elements" << endl;
        cout << "3. Sorting of Array" << endl;
        cout << "4. Searching of Elements" << endl;
        cout << "5. Exit" << endl;

        char choice;
        cin >> choice;

        switch (choice)
        {
            case '1':
                // Insertion operations
                while (true)
                {
                    cout << "**Select Operations:**" << endl;
                    cout << "1. Insertion of Element at Beginnig" << endl;
                    cout << "2. Insertion of Element at End" << endl;
                    cout << "3. Insertion of Element at Specific Location" << endl;
                    cout << "4. Back to the menu" << endl;
                    
                    char choice2;
                    cin >> choice2;

                    switch (choice2)
                    {
                        case '1':
                            // Insert at beginning
                            // ...
                            break;

                        case '2':
                            // Insert at end
                            // ...
                            break;

                        case '3':
                            // Insert at specific location
                            // ...
                            break;

                        case '4':
                            break;

                        default:
                            cout << "Enter the valid choice" << endl;
                    }

                    if (choice2 == '4')
                    {
                        break;
                    }
                }
                break;

            case '2':
                // Deletion operations
                while (true)
                {
                    cout << "**Select Operations:**" << endl;
                    cout << "1. Deletion of Element at Beginnig" << endl;
                    cout << "2. Deletion of Element at End" << endl;
                    cout << "3. Deletion of Element at Specific Location" << endl;
                    cout << "4. Back to the main menu" << endl;
                    
                    char choice3;
                    cin >> choice3;

                    switch (choice3)
                    {
                        case '1':
                            // Delete from beginning
                            // ...
                            break;

                        case '2':
                            // Delete from end
                            // ...
                            break;

                        case '3':
                            // Delete from specific location
                            // ...
                            break;

                        case '4':
                            break;

                        default:
                            cout << "Invalid choice" << endl;
                    }

                    if (choice3 == '4')
                    {
                        break;
                    }
                }
                break;

            case '3':
                // Sorting operations
                while (true)
                {
                    cout << "**Select Operations:**" << endl;
                    cout << "1. Insertion sort" << endl;
                    cout << "2. Selection sort" << endl;
                    cout << "3. Bubble sort" << endl;
                    cout << "4. Back to the main menu" << endl;

                    char choice4;
                    cin >> choice4;

                    switch (choice4)
                    {
                        case '1':
                            // Insertion sort
                            // ...
                            break;

                        case '2':
                            // Selection sort
                            // ...
                            break;

                        case '3':
                            // Bubble sort
                            // ...
                            break;

                        case '4':
                            break;

                        default:
                            cout << "Enter the valid Options" << endl;
                    }

                    if (choice4 == '4')
                    {
                        break;
                    }
                }
                break;

            case '4':
                // Searching operation
                cout << "*Searching of Element*" << endl;
                // ...
                break;

            case '5':
                cout << "Program terminated" << endl;
                break;

            default:
                cout << "Choose the correct options:" << endl;
        }

        if (choice == '5')
        {
            break;
        }
    }

    return 0;
}