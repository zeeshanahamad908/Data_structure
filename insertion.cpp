#include<iostream>
using namespace std;
 void display(int arr[],int n)
 {
    //traversel
    for( int i= 0; i< n; i++)
    {
        cout<<arr[i]<<",";
    }
    cout<<endl;
 }
    int indinsertion(int arr[], int size, int element, int capacity, int index)
    {
        //insertion
        if(size>=capacity){
            return -1;
        }
        for(int i=size-1; i>=index; i--)
        {
            arr[i+1]=arr[i];
        }
        arr[index]=element;
        return 1;
    }

int main()
{
    int arr[100]={6,8,9,4,3};
    int size=5, element=56, index=2;
    display(arr,size);
    indinsertion(arr, size, element, 100, index);
    size +=1;
    display(arr,size);

    return 0;
}