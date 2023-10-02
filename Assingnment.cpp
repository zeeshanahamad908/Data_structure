#include<iostream>
using namespace std;
void get_arr(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout << arr[i];

    }
}
void display(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout << arr[i]<<",";

    }
    cout << endl;

}
int main()
{
    cout << "Select the option\n";
    cout << "I.insertion of the elements in array:\n";
    cout << "D.deletion of the elements in array:\n";
    cout << "S.sorting elements in array:\n";
    cout << "Z.searching of the elements in array:\n";
    cout << "M.Back to main menu";
    char choice; 
    cin >> choice;
    while(true)
    {
        switch(choice)
        {
            case 'I':
            cout << "Insertion of the elements in array:\n";
            cout << "B.Insert at beginning:\n";
            cout << "E.Insert at end:\n";
            cout << "P.Insert at specific position:\n";
            cout << "Back to main menu";
            char choice3;
            cin >> choice3;
            while(true)
            {
                switch(choice3)
                {
                    case 'B':
                    break;
                    case 'E':
                    break;
                    case 'P':
                    break;
                }
            }

        }
        break;
        char choice3;
        cin >> choice3;
        while(true)
        {
            switch(choice3)
            {
                case 'D':
            cout << "Deletion of the elements in array:\n";
            cout << "B.Delete at the beginning:\n";
            cout << "E.Delete at the end:\n";
            cout << "P.Delete at the specific position:\n";
            cout << "Back to main menu";
            char choice4;
            cin >> choice4;
            while(true)
            {
                switch(choice)
                {
                    case 'B':
                    break;
                    case 'E':
                    break;
                    case 'P':
                    break;
                }
            }
            break;
            }
        }
        char choice5;
        cin >> choice5;
        while(true)
        {
            switch(choice5)
            case 'S':
            cout << "sorting elements in array:\n";
            cout << "s.selection sort:\n";
            cout << "B.bubble sort:\n";
            cout << "i.insertion sort:\n";
            cout << "M.Back to main menu";
            char choice6;
            cin >> choice6;
            while(true)
            {
                switch(choice6)
                {
                    case 's':
                    break;
                    case'B':
                    break;
                    case 'i':
                    break;
                }
            }
            break;
        }
        
        }
        char choice7;
        cin >> choice7;
        while(true)
        {
            switch(choice7)
            {
                case 'Z':
                cout << " searching of the elements in array:\n";
                break;
                case 'G':
                cout << " programe end";
                default:
                cout << "Enter valid option";

            }
        }
    }
