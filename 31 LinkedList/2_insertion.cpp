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
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~ length of LL~~~~~~~~~~~~~~~
int length(node *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        cnt += 1;
        head = head->next;
    }
    return cnt;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void insertAtTail(node *head, int data)
{

    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = new node(data);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void insertAtmid(node *head, int data, int p) // After p position
{
    if (head == NULL || p == 0)
    {
        insertAtHead(head, data);
        return;
    }
    else if (p > length(head))
    {
        insertAtTail(head, data);
    }
    else
    {
        int n1 = p - 1;
        while (n1 != 0)
        {
            head = head->next;
            n1--;
        }
        node *temp = new node(data);
        temp->next = head->next;
        head->next = temp;
    }
}

void display(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void deleteLL(node *&head, int pos)
{
    if (pos <= 1)
    {
        head = head->next;
    }
    else if (pos >= length(head))
    {
        node *tmp = head;
        int n2 = length(head) - 2;
        while (n2 != 0)
        {
            tmp = tmp->next;
            n2--;
        }
        tmp->next = NULL;
    }
    else
    {

        node *tmp = head;

        int jump = pos - 2;
        while (jump != 0)
        {
            tmp = tmp->next;
            jump--;
        }
        node *x = tmp->next;
        node *x1 = x->next;
        tmp->next = x1;
    }
}

// **********************************
void delete_inplace(node *&head)
{
    if (head == NULL)
        return;

    node *temp = head->next;
    delete head;
    //    ^  It will delete the address, that head is pointing too
    //    |  It wont't delete head variable
    head = temp;
}
// **********************************
bool search(node *head, int key) // linear search
{
    while (head != NULL)
    {
        if (head->data == key)
        {
            return true;
        }
        head = head->next;
    }
    return false;
}
// **********************************
bool recursive_search(node *head, int key)
{

    if (head == NULL)
        return false;

    if (head->data == key)
        return true;
    else
        return recursive_search(head->next, key);
}
// ******************************
// read inut from a file
// g++ -o anyname abc.cpp
// srm < input.txt
node *input_linked()
{
    int d;
    cin >> d;
    node *head = NULL;
    while (d != -1)
    {
        insertAtHead(head, d);
        cin >> d;
    }
    return head;
}
ostream &operator<<(ostream &ae, node *head)
{
    display(head);
    cout << endl;
    return ae;
}
istream &operator>>(istream &cin, node *&head)
{
    head = input_linked();
    return cin;
}

void reverseiterate(node *&head)
{
    node *prev = NULL;
    node *curr = head;
    node *n;
    while (curr != NULL)
    {
        n = curr->next;
        curr->next = prev;
        prev = curr;
        curr = n;
    }
    head = prev;
}

node * reverse_reursive(node *head)
{
    if (head->next == NULL || head == NULL)
    {
        return head;
    }
    node *smallhead = reverse_reursive(head->next);
    node *temp = smallhead;

    // while (temp->next != NULL)  ------Optimization
    // {
    //     temp = temp->next;
    // }
    //    |
    //    |
    //   \_/

    temp = head->next; 

    //---------------------
    temp->next = head;
    head->next = NULL;
    return smallhead;
    
}

//_+++_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_++_+_+_+_+_+_+_+_
node * midpoint(node * head)
{
    if(head==NULL || head->next==NULL)
    return head;

    node * slower = head;  // 1 position
    node * faster = head; // 2 position -- to get saved from
                                // segmentation fault--
                                // when null pointer is reffered
                                // some thing like that
    while(faster->next !=NULL && faster!=NULL )
    {
        faster = faster->next->next;
        slower = slower->next;
    }
    return slower;
}
//_____________________________________________________________________________
void knode_fromlast(node *head,int k)
{
    node * slow = head;
    node * fast = head;
    while(k!=0)
    {
        fast = fast->next;
        k--;
    }
    while(fast!=NULL)
    {
        slow = slow->next;
        fast=fast->next;
    }
    cout<<slow->data;
}

//_______________________________________________________________________
node * merge(node* a , node * b)
{
    if(b==NULL)
    return a;
    if(a==NULL)
    return b;

    node * c;
    if(a->data<b->data)
    {
        c=a;
        c->next = merge(a->next, b);
        
    }
    else
    {
        c=b;
        c->next = merge(a, b->next);
    }
    return c;
    
}

int main()
{
    // node * head = input_linked();
    // node * head2 = input_linked();
    node *head, *head2;
    cin >> head >> head2;
    cout << head << head2;
    //reverseiterate(head2);
    // head = reverse_reursive(head);
    // cout << endl;
    // cout << head;
    cout<<"MID POINTER :";
    node * mid =  midpoint(head);
    cout<<mid->data;

    cout<<endl<<"knode from last:";
    knode_fromlast(head,2);

    cout<<endl<<"___________"<<endl;
    cout<<"Merge Two Sorted Array"<<endl;
    node * ab = merge(head, head2);
    cout<<ab;
    //display(head);
    /*
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
    delete_inplace(head); // with delete, delete address also
    display(head);
    cout<<endl;
    cout<<search(head,3);
    cout<<endl;
    cout<<"recursive search :";
    cout<<endl;
    cout<<recursive_search(head,3);
    */
}