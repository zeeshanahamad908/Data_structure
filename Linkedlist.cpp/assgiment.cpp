#include <iostream>
using namespace std;
int n;
struct Node
{
	int data;
	struct Node * next;
};

struct Dnode
{
	int data;
	Dnode * prev;
	Dnode * next;
};
struct Cnode
{
	int data; 
	Cnode * prev;
	Cnode * next;
};   
struct DCnode
{
	int data;
	DCnode * prev;
	DCnode * next;
};

void insertat_end(struct Node*& head, int data)
{
struct Node* newnode1 = new Node;
	newnode1->data = data;
	newnode1->next = NULL;
	if  (head == NULL)
	{
		head =newnode1;
		
	}
	else
	{
		Node* ptr = head;
		while(ptr->next !=NULL){
		
		ptr = ptr->next;
	}
	ptr->next = newnode1;
	}
}
void inserat_start(struct Node*& head, int data)
{
	struct Node * newnode1=new Node;
//	newnode1->next=head;
	newnode1->data=data;
	newnode1->next = head;
	 head = newnode1;
}

    void insertAt_Position(struct Node*&head, int data, int position) {
     //  Node* newNode = new Node(data);
	struct Node * newnode1=new Node;
	newnode1->data=data;
	newnode1->next=NULL;
        if (position <= 0) {
            cout<<"Invalide position";
            return;
        }
        if(position==1)
        {
        	inserat_start(head,data);
		}

		else
		{
		
        Node* current = head;
        int count = 0;

        while (current != NULL) {
            if (count == position - 1) {
                newnode1->next = current->next;
                current->next = newnode1;
                return;
            }
            current = current->next;
            count++;
        }

        if (position > count + 1) {
            cout << "Position exceeds the length of the list." << endl;
        }
    }
    }
// Function to delete the first node of the linked list
void DeleAt_start(Node*& head) {
    if (head == NULL) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp; // Use 'delete' to deallocate memory
}
void DeleAt_end(Node*& head) {
    if (head == NULL) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    if (head->next == NULL) {
        // If there's only one node in the list, delete it and set head to nullptr
        delete head;
        head = NULL;
        return;
    }

    Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    // 'current' now points to the second-to-last node
    delete current->next; // Delete the last node
    current->next = NULL; // Update the 'next' pointer of the second-to-last node
}

// Function to delete a node at a specific location (index) in the linked list
void DeleAt_Location(Node*& head, int index) {
    if (head == NULL) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    if (index <= 0) {
       cout << "Invalid index." <<endl;
        return;
    }

    if (index == 1) {
        // Special case: Deleting the first node
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    int count = 1;

    while (current != NULL && count < index - 1) {
        current = current->next;
        count++;
    }

    if (current == NULL|| current->next == NULL) {
       cout << "Index exceeds the length of the list." << endl;
        return;
    }

    // 'current' now points to the node just before the one to be deleted
    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
}
void sort_ing()
{
	
}
void search(struct Node*& head, int search_data) {
    if (head == NULL) {
        cout << "Your linked list is empty";
        return;
    }

    struct Node* ptr = head;
    int count = 1; // Move count declaration outside the loop
    while (ptr != NULL) {
        if (ptr->data == search_data) {
            cout << search_data << " found at location " << count << endl;
            return;
        }
        else {
            count++;
            ptr = ptr->next;
        }
    }

    cout << search_data << " not found in the linked list" << endl;
}

void slget_list(struct Node*& head) {
cout << "How Many elements you want to enter in list" << endl;
int n;
cin >> n;
  for (int i = 0; i < n; i++) {
  	int value;
       cout << "Enter element " << i + 1 << ": ";
       cin >> value;
         insertat_end(head, value);
    }
}


void sldisplay_list(struct Node * node)
{
	while(node!=NULL)
	{
		cout << node->data<<"-->";
		node=node->next;
	}
	cout << "nullptr" << endl;
}
// Function to insert a node at the beginning of a doubly linked list
void douinsertat_start(Dnode*& head, int data) {
    // Create a new node
    Dnode* newnode1 = new Dnode;
    newnode1->data = data;
    newnode1->prev = NULL;
    newnode1->next = head;

    // Update the previous pointer of the current head (if it exists)
    if (head != NULL) {
        head->prev = newnode1;
    }

    // Update the head pointer to the new node
    head = newnode1;
}

void douinsertat_end(Dnode*& head, int data)
{
	Dnode* newnode1 = new Dnode;
	newnode1->data = data;
	newnode1->next = NULL;
	if(head == NULL)
	{
		newnode1->prev = NULL;
		head = newnode1;
	}
	else {
        Dnode* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newnode1;
        newnode1->prev = current;
    }
	
}

// Function to insert a node at a specific position in the doubly linked list
void douinsertAt_Position(Dnode*& head, int data, int position) {
    Dnode* newnode1 = new Dnode;
    newnode1->data = data;
    newnode1->prev = NULL;
    newnode1->next = NULL;

    if (position < 0) {
        cout << "Invalid position." << endl;
        delete newnode1;
        return;
    }

    if (position == 0) {
        // Inserting at the beginning of the list.
        newnode1->next = head;
        if (head != NULL) {
            head->prev = newnode1;
        }
        head = newnode1;
        return;
    }

    Dnode* current = head;
    int currentPosition = 0;

    while (current != NULL && currentPosition < position - 1) {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL) {
        cout << "Position out of bounds." << endl;
        delete newnode1;
        return;
    }

    newnode1->next = current->next;
    newnode1->prev = current;
    current->next = newnode1;

    if (newnode1->next != NULL) {
        newnode1->next->prev = newnode1;
    }
}

void doudeleteAt_Start(Dnode*& head) {
    if (head == NULL) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    Dnode* nodeToDelete = head;

    if (head->next != NULL) {
        // If there's more than one node in the list, update the head.
        head = head->next;
        head->prev = NULL;
    } else {
        // If there's only one node in the list, set head to nullptr.
        head =NULL;
    }

    delete nodeToDelete;
}

void doudeleteAt_End(Dnode*& head) {
    if (head == NULL) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    Dnode* current = head;

    while (current->next != NULL) {
        current = current->next;
    }

    if (current->prev != NULL) {
        current->prev->next =NULL;
    } else {
        head = NULL;
    }

    delete current;
}

void doudeleteAt_Position(Dnode*& head, int position) {
    if (head == NULL) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    if (position < 0) {
        cout << "Invalid position." << endl;
        return;
    }

    Dnode* current = head;
    int currentPosition = 0;

    while (current !=NULL && currentPosition < position) {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL) {
        cout << "Position out of bounds." << endl;
        return;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        // If deleting the first node, update the head pointer.
        head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    delete current;
}
void dousort_ing()
{
	
}
void dousearch(Dnode* head, int search_data) {
    if (head == NULL) {
        cout << "Your doubly linked list is empty." << endl;
        return;
    }

    Dnode* current = head;
    int count = 1;

    while (current != NULL) {
        if (current->data == search_data) {
            cout << search_data << " found at position " << count << endl;
            return;
        } else {
            count++;
            current = current->next;
        }
    }

    cout << search_data << " not found in the doubly linked list." << endl;
}
void douget_list(struct Dnode*& head) {
cout << "How Many elements you want to enter in list" << endl;
int n;
cin >> n;
  for (int i = 0; i < n; i++) {
  	int value;
       cout << "Enter element " << i + 1 << ": ";
       cin >> value;
         douinsertat_end(head, value);
    }
}


void doudisplay_list(struct Dnode * node)
{
	while(node!=NULL)
	{
		cout << node->data<<"-->";
		node=node->next;
	}
	cout << "nullptr" << endl;
}
// Singly circular
void slcirinsertAt_start(Cnode*& head, int data) {
    Cnode* newnode1 = new Cnode;
    newnode1->data = data;

    if (head == NULL) {
        // If the list is empty, make the new node point to itself
        newnode1->next = newnode1;
        head = newnode1;
    } else {
        // If the list is not empty, find the last node and update pointers
        Cnode* last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = newnode1;
        newnode1->next = head;
        head = newnode1;
    }
}
void slcirinsertat_end(Cnode*& head, int data) {
    Cnode* newnode1 = new Cnode;
    newnode1->data = data;

    if (head == NULL) {
        newnode1->next = newnode1; // Make it point to itself
        head = newnode1; // Update the head to the new node
    } else {
        Cnode* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newnode1;
        newnode1->next = head;
    }
}

void slcirinsertAt_Position(Cnode*& head, int data, int position) {
    Cnode* newnode1 = new Cnode;
    newnode1->data = data;

    // Handle the case where the list is empty or the position is 0
    if (head ==NULL || position <= 0) {
        newnode1->next = head;
        newnode1->prev = NULL;
        if (head != NULL) {
            head->prev = newnode1;
        }
        head = newnode1;
        return;
    }

    Cnode* current = head;
    int currentPosition = 0;

    // Traverse the list to find the position
    while (current != NULL && currentPosition < position - 1) {
        current = current->next;
        currentPosition++;
    }

    // Handle the case where the position is out of bounds
    if (current == NULL) {
        cout << "Position out of bounds." << endl;
        delete newnode1;
        return;
    }

    // Insert the new node at the specified position
    newnode1->next = current->next;
    newnode1->prev = current;
    current->next = newnode1;

    if (newnode1->next != NULL) {
        newnode1->next->prev = newnode1;
    }
}



void slcirdeleteAt_Start(Cnode*& head) {
    if (head == NULL) {
        cout << "The list is empty. Deletion is not possible." << endl;
        return;
    }

    Cnode* currentNode = head;

    if (currentNode->next == head) {
        // If there's only one node in the list, set head to nullptr
        delete currentNode;
        head = NULL;
        return;
    }

    Cnode* temp = head;

    while (currentNode->next != head) {
        currentNode = currentNode->next;
    }

    currentNode->next = temp->next;
    head = temp->next; // Update the head to the new start
    delete temp;
}
void slcirdeleteAt_End(Cnode*& head) {
    if (head == NULL) {
        cout << "The list is empty. Deletion is not possible." << endl;
        return;
    }

    Cnode* currentNode = head;
    Cnode* previousNode = NULL;

    if (currentNode->next == head) {
        // If there's only one node in the list, set head to nullptr
        delete currentNode;
        head = NULL;
        return;
    }

    while (currentNode->next != head) {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    previousNode->next = head; // Update the last node to point to the head
    delete currentNode;
}

void slcirdeleteAt_Position(Cnode*& head, int position) {
    if (head == NULL) {
        cout << "The list is empty. Deletion is not possible." << endl;
        return;
    }

    if (position == 1) {
        // If the position is 1, delete the head node
        Cnode* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        if (temp == head) {
            // If there's only one node in the list, set head to nullptr
            delete head;
            head = NULL;
        } else {
            temp->next = head->next;
            delete head;
            head = temp->next;
        }
        return;
    }

    Cnode* currentNode = head;
    int currentPosition = 1;

    do {
        if (currentPosition == position - 1) {
            Cnode* temp = currentNode->next;
            currentNode->next = temp->next;
            delete temp;
            return;
        }
        currentNode = currentNode->next;
        currentPosition++;
    } while (currentNode != head);

    cout << "Position " << position << " not found in the list." << endl;
}
void slcirsor_ting()
{
	
}
void slcirsearch(Cnode* head, int search_data) {
    if (head == NULL) {
        cout << "Your singly circular linked list is empty." << endl;
        return;
    }

    Cnode* current = head;
    int count = 1;

    while (current != NULL) {
        if (current->data == search_data) {
            cout << search_data << " found at position " << count << endl;
            return;
        } else {
            count++;
            current = current->next;
        }
    }

    cout << search_data << " not found in the singly circular  linked list." << endl;
}

// Function to input elements and create a singly circular linked list
void slcirget_list(struct Cnode*& head) {
    cout << "How many elements do you want to enter in the list: ";
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int value;
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;
        slcirinsertat_end(head, value);
    }
}


void slcirdisplay_list(struct Cnode * head)
{
	if(head==NULL)
	{
		cout<<"your linked list is empty";
		return;
	}
	struct Cnode*node=head;
	
	do
	{
		cout << node->data<<"-->";
		node=node->next;
	}
	while(node!=head);
	cout << "nullptr" << endl;
}
  // Doubly circular
 void docirinsertAt_Start(DCnode*& head, int data) {
    DCnode* newnode1 = new DCnode{data, NULL, NULL};

    if (head == NULL) {
        // If the list is empty, make the new node the head
        newnode1->next = newnode1;
        newnode1->prev = newnode1;
        head = newnode1;
    } else {
        // Find the last node (previous head node)
        DCnode* lastNode = head->prev;

        // Update pointers to insert the new node
        newnode1->next = head;
        newnode1->prev = lastNode;
        lastNode->next = newnode1;
        head->prev = newnode1;

        // Update the head pointer to the new node
        head = newnode1;
    }
}

  void docirinsertAt_End(DCnode*& head, int data) {
    DCnode* newnode1 = new DCnode{data, NULL, NULL};

    if (head == NULL) {
        // If the list is empty, make the new node the head
        newnode1->next = newnode1;
        newnode1->prev = newnode1;
        head = newnode1;
    } else {
        // Find the last node (previous head node)
        DCnode* lastNode = head->prev;

        // Update pointers to insert the new node
        newnode1->next = head;
        newnode1->prev = lastNode;
        lastNode->next = newnode1;
        head->prev = newnode1; // Change "newNode" to "newnode1"
    }
}
void docirinsertAt_Position(DCnode*& head, int data, int position) {
    DCnode* newnode1 = new DCnode{data, NULL, NULL};

    if (head == NULL) {
        // If the list is empty and the position is 1, make the new node the head
        if (position == 1) {
            newnode1->next = newnode1;
            newnode1->prev = newnode1;
            head = newnode1;
        } else {
            cout << "Position " << position << " not found in the empty list." << endl;
        }
    } else {
        DCnode* current = head;
        int currentPosition = 1;

        // Traverse the list to find the position
        while (currentPosition < position - 1 && current->next != head) {
            current = current->next;
            currentPosition++;
        }

        // Update pointers to insert the new node
        newnode1->next = current->next;
        newnode1->prev = current;
        current->next->prev = newnode1;
        current->next = newnode1;
    }
}
void docirdeleteAt_Start(DCnode*& head) {
    if (head == NULL) {
        cout << "The list is empty. Deletion is not possible." << endl;
        return;
    }

    if (head->next == head) {
        // If there's only one node in the list, set head to nullptr
        delete head;
        head = NULL;
    } else {
        // Find the last node (previous head node)
        DCnode* lastNode = head->prev;

        // Update pointers to remove the first node
        head = head->next;
        head->prev = lastNode;
        lastNode->next = head;

        // Delete the old head node
        delete lastNode->next;
    }
}
void docirdeleteAt_End(DCnode*& head) {
    if (head == NULL) {
        cout << "The list is empty. Deletion is not possible." << endl;
        return;
    }

    if (head->next == head) {
        // If there's only one node in the list, set head to nullptr
        delete head;
        head = NULL;
    } else {
        // Find the last node (previous head node)
        DCnode* lastNode = head->prev;

        // Update pointers to remove the last node
        lastNode->prev->next = head;
        head->prev = lastNode->prev;

        // Delete the old last node
        delete lastNode;
    }
}
void docirdeleteAt_Position(DCnode*& head, int position) {
    if (head == NULL) {
        cout << "The list is empty. Deletion is not possible." << endl;
        return;
    }

    if (position == 1) {
        // If the position is 1, delete the first node
        DCnode* lastNode = head->prev;

        // Update pointers to remove the first node
        head = head->next;
        head->prev = lastNode;
        lastNode->next = head;

        // Delete the old head node
        delete lastNode->next;
    } else {
        DCnode* current = head;
        int currentPosition = 1;

        // Traverse the list to find the position
        while (currentPosition < position - 1 && current->next != head) {
            current = current->next;
            currentPosition++;
        }

        if (currentPosition == position - 1) {
            // Delete the node at the specified position
            DCnode* nodeToDelete = current->next;
            current->next = nodeToDelete->next;
            nodeToDelete->next->prev = current;
            delete nodeToDelete;
        } else {
            cout << "Position " << position << " not found in the list." << endl;
        }
    }
}
void sor_ting()
{
	
}
void docirsearch(DCnode* head, int search_data) {
    if (head == NULL) {
        cout << "Your Doubly circular linked list is empty." << endl;
        return;
    }

    DCnode* current = head;
    int count = 1;

    while (current != NULL) {
        if (current->data == search_data) {
            cout << search_data << " found at position " << count << endl;
            return;
        } else {
            count++;
            current = current->next;
        }
    }

    cout << search_data << " not found in the Doubly circular  linked list." << endl;
}

void docirget_list(struct DCnode*& head) {
    cout << "How many elements do you want to enter in the list: ";
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int value;
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;
        docirinsertAt_End(head, value);
    }
}


void docirdisplay_list(struct DCnode * head)
{
	if(head==NULL)
	{
		cout<<"your linked list is empty";
		return;
	}
	struct DCnode*node=head;
	
	do
	{
		cout << node->data<<"-->";
		node=node->next;
	}
	while(node!=head);
	cout << "nullptr" << endl;
}
int main()
{
		

    while(true)
    {
        cout <<"**********************" << endl;
		cout << ".Show Linked list" << endl;
		cout << "1.Singly Linked list" << endl;
		cout << "2.Doubly Linked Linked list" << endl;
		cout << "3.Singly circular Linked list" << endl;
		cout << "4.Doubly circular Linked list" << endl;
		cout << "5.exit" <<endl;
		
        char choice;
        cin >> choice;
        switch(choice)
        {
            case '1':
          {
            cout << "Singly Linked list" <<endl;
            struct Node *head=NULL;
            slget_list(head);
            sldisplay_list(head);
            
            while(true)
            {
                cout << "*********choose the option***********" << endl;
                cout << "1. Insertion of a Linked list" << endl;
                cout << "2. Deletion of a Linkded list" << endl;
                cout << "3. Sorting of a Linked list" << endl;
                cout << "4. Searching of a Linked list" << endl;
             // cout << "5. Searching of Elements at specific index" << endl;
                cout << "5. exit" << endl;
                
                char choice2;
                cin >> choice2;
                switch(choice2)
                {
                	// Insertion
                	
                    case '1':
                    	
                    cout << "Insertion of a Linked list" << endl;
                    
                    while(true)
                    {
                        cout << "1. Inseertion of linked list at start" << endl;
                        cout << "2. Inseertion of linked list in between" << endl;
                        cout << "3. Insertion of linked list at end" << endl;
                        cout << "4. Inseertion of linked list at specific position" << endl;
                        cout << "5. GO BACK" << endl;
                        
                    char choice3;
                    cin >> choice3;
                    switch (choice3)
                    {
                    	
            // Insertion at start
                
                        case '1':
                        	cout << "insert at start" << endl;
                        	int node;
                        	cout << "enter a node you want to insert at start :" << endl;
                        	cin >> node;
                        	inserat_start(head, node);
                        	sldisplay_list(head);
                        
                            break;
                            
           // Insertion in between
           
                        case '2':

                            break;
                           
           // Insertion at end   
		     
                        case '3':
                        	cout << "insert at end" << endl;
                        	int node2;
                        	cout << "enter a node you want to insert at last :" << endl;
                             cin >> node2;
                             insertat_end(head, node2);
                            sldisplay_list(head);
                            break;
                            
            // Insertion specific location
            
                           case '4':
                           	 cout << "insert at postion" << endl;
	                        int position;
	                        int node3;
                        	cout << "enter a node you want to insert at position :" << endl;
                             cin>>position;
                             cout<<"enter the data";
							 cin >> node3;
                             
                             insertAt_Position(head, node3, position);
                            sldisplay_list(head);                     
                            break;

                        case '5':
                        	cout << "Go BACK";
                            break;

                        default:
                            cout << "Enter the valid choice" << endl;
                            
                    }///end of inserion of switch
                    
                        if (choice3 == '5')
                        {
                            break;
                        
						}
						
                    }//end of the while loop of the insertion process
                    
                    break;
                    
                    //Deletion
                    
                    case '2':
                    	
                    	cout << "Deletion of a Linked list" << endl;
                    	
                    while(true)
                    {
                        cout << "1. Deletion of linked list at start" << endl;
                        cout << "2. Deletion of linked list in between" << endl;
                        cout << "3. Deletion of linked list at end" << endl;
                        cout << "4. Deletion of linked list at specific location" << endl;
                        cout << "5. GO BACK" << endl;
                        
                    char choice4;
                    cin >> choice4;
                    switch (choice4)
                    {
                    	
                // Deletion at start
                
                        case '1':
                        	cout << "Delete at start" << endl;
                        	DeleAt_start(head);
                        	sldisplay_list(head);
                            break;
                            
                // Deletion in between
                
                        case '2':
                        
                            break;
                            
                // Deletion at end
                
                        case '3':
                
                          	cout << "Delete at end" << endl;
                        	DeleAt_end(head);
                        	sldisplay_list(head);
                            break;
                            
                // Deletion at specific location
                
                           case '4':
                           	cout << "Delate at location" << endl;
                           	int index;
                           	cout<<"Enter the location";
                           	cin>>index;
							 DeleAt_Location(head, index);
							sldisplay_list(head);
                            break;

                        case '5':
                        	cout << "Go BACK";
                            break;

                        default:
                            cout << "Enter the valid choice" << endl;
                            
                    }///end of inserion of switch
                    
                        if (choice4 == '5')
                        {
                            break;
                        
						}
						
                    }//end of the while loop of the insertion process
                    
                    	break;
                    
                    //sorting
                    
                    case '3':
                    	break;
                    	
                    //searching
                    
                    case '4':
                    	int data;
                    	cout<<"Enter the data you want to search";
                    	cin>>data;
                    	search(head,data);
                    	sldisplay_list(head);
                    	break;
                    	
                    //back to the menu
                    
                    case '5':
                    	
                    	break;
                    	
                    default:
                    	
                    	cout<<"Enter the correct option";
                    
                }// End of switch of the singly linked list
                if(choice2 == '5')
                {
                	break;
				}
            }// end of while loop of the singy linked list
            break;
         }
            //Doubly
            
         	case '2':
           		{
				   
           		cout<<"Doubly linked list\n";
           	//	 Dnode* head = NULL; // Initialize head
             //    Dnode* tail = NULL; // Initialize tail
           		struct Dnode *head=NULL;
                douget_list(head);
                doudisplay_list(head);
           		 while(true)
            {
                cout << "*********choose the option" << endl;
                cout << "1. Insertion of a Linked list" << endl;
                cout << "2. Deletion of a Linkded list" << endl;
                cout << "3. Sorting of a Linked list" << endl;
                cout << "4. Searching of a Linked list" << endl;
             // cout << "5. Searching of Elements at specific index" << endl;
                cout << "5. exit" << endl;
                
                char choice2;
                cin >> choice2;
                switch(choice2)
                {
                	// Insertion 
                	
                    case '1':
                    	
                    cout << "1. Insertion of a Linked list" << endl;
                    
                    while(true)
                    
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
                    	
                // Insertion at start
				 
                        case '1':
                        	cout << "insert at start" << endl;
                        	int node;
                        	cout << "enter a node you want to insert at start :" << endl;
                        	cin >> node;
                        	douinsertat_start(head, node);
                        	doudisplay_list(head);
                            break;
                            
                // Insertion in between
                
                        case '2':
                       	
                            break;
                            
                // Insertion at end
                
                        case '3':
                	cout << "insert at end" << endl;
                        	int node2;
                        	cout << "enter a node you want to insert at end :" << endl;
                        	cin >> node2;
                        douinsertat_end(head, node2);
                        	doudisplay_list(head);
                            
                            break;
                            
                // Insertion at specific location
                
                           case '4':
							 cout << "insert at postion" << endl;
	                        int position;
	                        int node3;
                        	cout << "enter a node you want to insert at position :" << endl;
                             cin>>position;
                             cout<<"enter the data";
							 cin >> node3;
							 douinsertAt_Position(head, node3, position);
							 doudisplay_list(head);
                            break;
                            
                // main menu
                
                        case '5':
                        	
							
                        	cout << "Go BACK";
                        	
                            break;

                        default:
                            cout << "Enter the valid choice" << endl;
                            
                    }///end of inserion of switch
                    
                        if (choice3 == '5')
                        {
                            break;
                        
						}
						
                    }//end of the while loop of the insertion process
                    
                    break;
            
                    
                    //Deletion
                    
                    case '2':
                    	
                    	cout << "1. Deletion of a Linked list" << endl;
                    	
                    while(true)
                    
                    {
                        cout << "1. Deletion of linked list at start" << endl;
                        cout << "2. Deletion of linked list in between" << endl;
                        cout << "3. Deletion of linked list at end" << endl;
                        cout << "4. Deletion of linked list at specific location" << endl;
                        cout << "5. GO BACK" << endl;
                        
                    char choice4;
                    cin >> choice4;
                    switch (choice4)
                    {
                    	
                // Deletion at start
                
                        case '1':
                        	cout << "Delete at start" << endl;
                        	doudeleteAt_Start(head);
                        	doudisplay_list(head);
                            break;
                            
                // Deletion in between
                
                        case '2':
                        
                            break;
                            
                // Deletion at end
                
                        case '3':
                cout << "Delete at end" << endl;
				doudeleteAt_End(head);
				doudisplay_list(head);                            
                            break;
                            
                // Deletion at specific location
                
                           case '4':
                 	cout << "Delate at location" << endl;
                           	int Position;
                           	cout<<"Enter the location";
                           	cin>>Position;
                           	doudeleteAt_Position(head, Position);
			            	doudisplay_list(head);
                            break;
                            
                // main menu
                
                        case '5':
                        	cout << "Go BACK";
                            break;

                        default:
                            cout << "Enter the valid choice" << endl;
                            
                    }///end of inserion of switch
                    
                        if (choice4 == '5')
                        {
                            break;
                        
						}
						
                    }//end of the while loop of the insertion process
                    
                    	break;
                    
                    //sorting
                    
                    case '3':
                    	
                    	break;
                    	
                    //searching
                    
                    case '4':
                    	int data;
                    	cout<<"Enter the data you want to search";
                    	cin>>data;
                    	dousearch(head, data);
                    	doudisplay_list(head);
                    	break;
                    	
                    //back to the menu
                    
                    case '5':
                    	
                    	break;
                    default:
                    	cout<<"Enter the correct option";
                    
                }// End of switch of the doubly linked list
                if(choice2 == '5')
                {
                	break;
				}
            }// end of while loop of the doubly linked list
            
           	break;
           }
       
           	//singly circular
           	
          case '3':
           {
					
            	cout<<"Singly Circular linked list\n";
            	struct Cnode *head=NULL;
                slcirget_list(head);
                slcirdisplay_list(head);
            	 while(true)
            {
                cout << "*********choose the option*********" << endl;
                cout << "1. Insertion of a Linked list" << endl;
                cout << "2. Deletion of a Linkded list" << endl;
                cout << "3. Sorting of a Linked list" << endl;
                cout << "4. Searching of a Linked list" << endl;
             // cout << "5. Searching of Elements at specific index" << endl;
                cout << "5. exit" << endl;
                
                char choice2;
                cin >> choice2;
                switch(choice2)
                {
                	// Insertion
                	
                    case '1':
                    	
                    cout << "1. Insertion of a Linked list" << endl;
                    
                    while(true)
                    
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
                    	
                // Insertion at start
                
                        case '1':
                        	cout << "insert at start" << endl;
                        	int node;
                        	cout << "enter a node you want to insert at start :" << endl;
                        	cin >> node;
                        	slcirinsertAt_start(head, node);
                        	slcirdisplay_list(head);
                            break;
                            
                // Insertion in between
                
                        case '2':
                        
                            break;
                            
                // Insertion at end
                
                        case '3':
                        	cout << "insert at end" << endl;
                        	int node2;
                        	cout << "enter a node you want to insert at end :" << endl;
                        	cin >> node2;
                        	slcirinsertat_end(head, node2);
                        	slcirdisplay_list(head);
                            
                            break;
                            
                   // Insertion at specific location 
                   
                           case '4':
     						cout << "insert at postion" << endl;
	                        int position;
	                        int node3;
                        	cout << "enter a node you want to insert at position :" << endl;
                             cin>>position;
                             cout<<"enter the data";
							 cin >> node3;
							 slcirinsertAt_Position(head, node3, position);
							 slcirdisplay_list(head);
                            break;

                    // main menu

                        case '5':
                        	cout << "Go BACK";
                            break;

                        default:
                            cout << "Enter the valid choice" << endl;
                            
                    }///end of inserion of switch
                    
                        if (choice3 == '5')
                        {
                            break;
                        
						}
						
                    }//end of the while loop of the insertion process
                    
                    break;
                    
                    //Deletion
                    
                    case '2':
                    	
                    	cout << "Deletion of a Linked list" << endl;
                    	
                    while(true)
                    {
                    	
                        cout << "1. Deletion of linked list at start" << endl;
                        cout << "2. Deletion of linked list in between" << endl;
                        cout << "3. Deletion of linked list at end" << endl;
                        cout << "4. Deletion of linked list at specific location" << endl;
                        cout << "5. GO BACK" << endl;
                        
                    char choice4;
                    cin >> choice4;
                    switch (choice4)
                    {
                    	
                // Deletion at start
                
                        case '1':
                        cout << "Delete at start";
                        slcirdeleteAt_Start(head);
                        slcirdisplay_list(head);
                            break;
                            
                // Deletion in between
                
                        case '2':
                        
                            break;
                            
                // Deletion at end
                
                        case '3':
                    	 cout << "Delete at end";
                        slcirdeleteAt_End(head);
                        slcirdisplay_list(head);
                
                            
                            break;
                            
                // Deletion at at specific position
                
                           case '4':
	                 cout << "Delate at location" << endl;
                           	int position;
                           	cout<<"Enter the location";
                           	cin>>position;
                           	slcirdeleteAt_Position(head, position);
                           	slcirdisplay_list(head);
                            break;

                // main menu

                        case '5':
                        	cout << "Go BACK";
                            break;

                        default:
                            cout << "Enter the valid choice" << endl;
                            
                    }///end of inserion of switch
                    
                        if (choice4 == '5')
                        {
                            break;
                        
						}
						
                    }//end of the while loop of the insertion process
                    
                    	break;
                    
                    //sorting
                    
                    case '3':
                    	
                    	break;
                    	
                    //searching
                    
                    case '4':
                    	int data; 
                    	cout << "enter a data you want to search";
                    	cin>>data;
                    	slcirsearch(head, data);
                    	slcirdisplay_list(head);
                    	break;
                    	
                    //back to the menu
                    
                    case '5':
                    	
                    	break;
                    default:
                    	cout<<"Enter the correct option";
                    
                }// End of switch of the singly circular linked list
                if(choice2 == '5')
                {
                	break;
				}
            }// end of while loop of the singy circular linked list
            break;
   }
            //Doubly circular
            
           case '4':
            
			{
							
            	cout<<"Doubly circular linked list\n";
            	struct DCnode *head=NULL;
            	docirget_list(head);
            	docirdisplay_list(head);
            	 while(true)
            {
                cout << "*********choose the option*********" << endl;
                cout << "1. Insertion of a Linked list" << endl;
                cout << "2. Deletion of a Linkded list" << endl;
                cout << "3. Sorting of a Linked list" << endl;
                cout << "4. Searching of a Linked list" << endl;
             // cout << "5. Searching of Elements at specific index" << endl;
                cout << "5. exit" << endl;
                
                char choice2;
                cin >> choice2;
                switch(choice2)
                {
                	
                	// Insertion 
                	
                    case '1':
                    	
                    cout << "1. Insertion of a Linked list" << endl;
                    
                    while(true)
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
                    	
                // Insertion at start
                
                        case '1':
                        	cout << "Insert a start";
                        	int node;
                        	cout << "enter a node you want to insert at start";
                        	cin >> node;
                        	docirinsertAt_Start(head, node);
                        	docirdisplay_list(head);
                            break;
                            
                // Insertion in between
                
                        case '2':
                        
                            break;
                            
                // Insertion at end
                
                        case '3':
                            cout << "insert at end" << endl;
                        	int node2;
                        	cout << "enter a node you want to insert at end :" << endl;
                        	cin >> node2;
                        	docirinsertAt_End(head, node2);
                        	docirdisplay_list(head);
                            
                            break;
                            
                // Insertion at specific location
                
                           case '4':
						cout << "insert at postion" << endl;
	                        int position;
	                        int node3;
                        	cout << "enter a node you want to insert at position :" << endl;
                             cin>>position;
                             cout<<"enter the data";
							 cin >> node3;
							 docirinsertAt_Position(head, node3, position);
							 docirdisplay_list(head);
                            break;

                        case '5':
                        	cout << "Go BACK";
                            break;

                        default:
                            cout << "Enter the valid choice" << endl;
                            
                    }///end of inserion of switch
                    
                        if (choice3 == '5')
                        {
                            break;
                        
						}
						
                    }//end of the while loop of the insertion process
                    
                    break;
                    
                    //Deletion
                    
                    case '2':
                    	
                    	cout << "1. Deletion of a Linked list" << endl;
                    	
                    while(true)
                    {
                        cout << "1. Deletion of linked list at start" << endl;
                        cout << "2. Deletion of linked list in between" << endl;
                        cout << "3. Deletion of linked list at end" << endl;
                        cout << "4. Deletion of linked list at specific location" << endl;
                        cout << "5. GO BACK" << endl;
                        
                    char choice4;
                    cin >> choice4;
                    switch (choice4)
                    {
                    	
                // Deletion at start 
                
                        case '1':
                        cout << "Delete at start";	
                        docirdeleteAt_Start(head);
                        docirdisplay_list(head);
                            break;
                            
            //    Deletion in between
            
                        case '2':
                        
                            break;
                            
                // Deletion at end
                
                        case '3':
                cout << "Delete at end";
                docirdeleteAt_End(head);
				docirdisplay_list(head);                            
                            break;
                            
//               Deletion at specific location

                           case '4':
						 cout << "Delate at location" << endl;
                           	int position;
                           	cout<<"Enter the location";
                           	cin>>position;
                           	docirdeleteAt_Position(head, position);
                           	docirdisplay_list(head);
                            break;

                        case '5':
                        	cout << "Go BACK";
                            break;

                        default:
                            cout << "Enter the valid choice" << endl;
                            
                    }///end of inserion of switch
                    
                        if (choice4 == '5')
                        {
                            break;
                        
						}
						
                    }//end of the while loop of the insertion process
                    
                    	break;
                    
                    //sorting
                    
                    case '3':
                    	
                    	break;
                    	
                    //searching
                    
                    case '4':
                    	int data; 
                    	cout << "enter a data you want to search";
                    	cin>>data;
                    	docirsearch(head, data);
                    	docirdisplay_list(head);
                    	break;
                    	
                    //back to the menu
                    
                    case '5':
                    	
                    	break;
                    	
                    default:
                    	cout<<"Enter the correct option";
                    
                }// End of switch of the doubly circular linked list
                if(choice2 == '5')
                {
                	break;
				}
            }// end of while loop of the doubly circular linked list
            break;
}
            //end of overall program
            case '5':
              cout << "Program is terminated" << endl;
                break;

            default:
                cout << "Choose the correct options:" << endl;
        }
        if(choice == '5')
        {
            break;
        }
    }
}

