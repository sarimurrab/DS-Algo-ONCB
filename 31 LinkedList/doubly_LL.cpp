#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *prev;
    node *next;
    node(int d)
    {
        data = d;
        prev = NULL;
        next = NULL;
    }
};

int length(node * head)
{
    int count = 0;
    while(head!=NULL)
    {
        head= head->next;
        count++;
    }
    return count;
}

void display(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }

    return;
}

//____________________insertAthead___________________________
void insertAthead(node *&head, int data)
{
    if (head == NULL)
    {
        head = new node(data);
        return;
    }
    node *temp = new node(data);

    head->prev = temp;
    temp->next = head;
    head = temp;
    return;
}
//_____________________insertAttail___________________
void insertAttail(node *head, int data)
{
    if (head == NULL )
    {
        insertAthead(head, data);
        return;
    }
    while (head->next != NULL)
    {
        head = head->next;
    }
    node * temp = new node(data);
    head->next = temp;
    temp->prev = head;
    return;
}

//_____________________insertAtpos____start at 1____________
void insertatpos(node * &head, int data, int pos)
{
    node * temp1 = head;
    if(temp1 == NULL or pos <=1)
    {
        insertAthead(head,data);
        return;
    }
    if(pos>length(temp1))
    {
        insertAttail(temp1, data);
        return;
    }

    while(pos-2)
    {
        temp1= temp1->next;
        pos--;
    }
    node * temp = new node(data);
    temp->next = temp1->next;
    temp1->next->prev = temp;

    temp1 ->next = temp;
    temp->prev =  temp1;

    return ;



}

int main()
{
    node *head = NULL;

    insertAthead(head, 2);
    insertAthead(head, 3);
    insertAthead(head, 4);
    insertAthead(head, 1);

    insertAttail(head,50);

    insertatpos(head,67,5);
    
    display(head);

    return 0;
}
