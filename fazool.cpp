   const int capacity=20;
int arr[capacity];
int get_arr_size()
{
    int size;
    cout << "Enter array of size";
    while(true)
    {
    if(size>capacity)
    {
        
        cin >> size;
        return size;
    }
    else
    {
        cout<<"please enter range 1 to 20";
    }
    }    
}
   int pos;
                cout<<"Where you want to insert new number";
                int element;
                cin>>element;
                indinsertion(arr, size, element, capacity, pos);
                display(arr,size);