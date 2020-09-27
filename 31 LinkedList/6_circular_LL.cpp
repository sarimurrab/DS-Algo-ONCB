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
void insertAthead(node *&head, int data)
{
    node * temp = new node(data);
    temp->next = head;

    node * xyz = head;

    if(xyz == NULL)
    {
        temp->next = temp;
        head=temp;
        return;
    }
    else
    {
        while(xyz->next!=head)
        {
            xyz=xyz->next;
        }
        xyz ->next = temp;
        head=temp;
        return;
    }
    



}

void display(node *head)
{
    cout<<head->data<<" ";
    node * temp = head->next;
    while(temp!=head)
    {
        cout<<temp->data<<" ";
        temp= temp->next;
    }
}

int main()
{
    node *head = NULL;
    insertAthead(head, 5);
    insertAthead(head, 4);
    insertAthead(head, 3);
    insertAthead(head, 2);
    

    display(head);
}