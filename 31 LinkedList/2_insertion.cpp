#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};

void insertAtHead(node *&head, int data)
{
    if (head == NULL)
    {
        head = new node(data);
        return;
    }
    node * temp = new node(data);
    temp ->next = head;
    head = temp ;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~ length of LL~~~~~~~~~~~~~~~
int length(node * head)
{
    int cnt =0;
    while(head!=NULL)
    {
        cnt +=1;
        head = head->next;
    }
    return cnt;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void insertAtTail(node *head,int data)
{
    
    while(head->next != NULL)
    {
        head = head->next;
    }
    head->next = new node(data);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void insertAtmid(node * head, int data, int p)
{
    if(head==NULL || p==0)
    {
        insertAtHead(head, data);
        return;
    }
    else if (p>length(head))
    {
        insertAtTail(head,data);
    }
    else
    {
        int n1= p-1;
        while(n1!=0)
        {
            head = head ->next;
            n1--;
        }
        node * temp = new node(data);
        temp->next = head->next;
        head->next = temp;
    }
    
}

void display(node *head)
{
    while (head!= NULL)
    {
        cout << head->data<<" ";
        head = head->next;
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void deleteLL(node *& head, int pos)
{
    if(pos<=1)
    {
        head = head ->next;
    }
    else if (pos >= length(head))
    {
        node * tmp = head;
        int n2 = length(head)-2;
        while(n2!=0)
        {
            tmp = tmp->next;
            n2--;
        }
        tmp->next = NULL;
    }
    else
    {
        node * tmp = head;

        int jump = pos-2;
        while(jump!=0)
        {
            tmp = tmp->next;
            jump--;
        }
        node * x = tmp->next;
        node * x1 = x->next;
        tmp->next = x1;


    }
    
}

// **********************************
void delete_inplace(node * & head)
{
    if(head == NULL)
    return;

    node * temp = head->next;
    delete head; 
    // ^  It will delete the address, that head is pointing too
    // |  It wont't delete head variable
    head = temp;

}
// **********************************
int main()
{
    node *head = NULL;
    insertAtHead(head, 6);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    display(head);
    cout<<endl;
    insertAtmid(head, 3,4); // value and after position
    display(head);
    cout<<endl;
    insertAtTail(head, 70);
    display(head);
    cout<<endl;
    insertAtmid(head,45,1); // value and after position
    display(head);
    cout<<endl;
    deleteLL(head, 10); // without delete, only removed
    display(head);
    cout<<endl;
    delete_inplace(head); // without delete, only removed
    display(head);
}