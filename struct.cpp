#include<iostream>
using namespace std;
struct node{
    int data;
   struct node*next;
};
void push(struct node** head,int nodedata)
{
    struct node*newnode1=new node;
    newnode1->data=nodedata;
    newnode1->next=(*head);
    (*head)=newnode1;
}
void insertafter(struct node*prevnode, int nodedata)
{
    if(prevnode==NULL)
    {
cout<<"previous node is not given";
return;
}
struct node* newnode1=new node;
newnode1->data=nodedata;
newnode1->next=prevnode->next;
prevnode->next=newnode1;
}
void displaylist(struct node* node)
{
    while(node!=NULL)
    {
        cout<<node->data<<"-->";
        node=node->next;
    }
}
int main()
{
    struct node*head=NULL; 
   push(&head,25);
   push(&head,30);
   push(&head,40);
   push(&head,50);
   insertafter(head->next,15);
   insertafter(head,95);
   insertafter(head->next->next,115);
   insertafter(head->next->next->next,220);
   displaylist(head);
   return 0;
}
