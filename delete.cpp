#include<iostream>
using namespace std;
int arr[]
void display(int arr[],int n)
{
    //traversal
    for(int i= 0; i<n; i++)
    {
        cout<<arr[i]<<",";
    }
    cout<<endl;
}

void dele_element(int arr[], int size, int index)
    {
        //deletion
            for(int i= index; i<size-1; i++)
            {
                arr[i]=arr[i+1];
            }

    
    }

int main()
{
    int arr[50];
    cout<<
    int size=5,element=8,index=2;
    display(arr,size);
    dele_element(arr, size, index);
    size -=1;
    display(arr,size);
    return 0;


}