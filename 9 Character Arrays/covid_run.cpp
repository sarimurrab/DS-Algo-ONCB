#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node * next;
    node(int d)
    {
        data = d;
        next = NULL;

    }
};

void insertAtfront(node *&head, int data)
{
    if(head==NULL)
    {
        head = new node(data);
        return;
    }
    node * temp = new node(data);
    temp->next = head;
    head = temp;

    return;
}
void display(node * head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head= head->next;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,x,y;
        cin>>n>>k>>x>>y;
        node * head = NULL;
        for(int i=1;i<=n;i++)
        {
            insertAtfront(head,i);
        }
        //display(head);

        node * ex, * yi;      // ex at x
        node * temp = head;  // yi at  y
        while(temp->next!=NULL)
        {
            if(temp->data==x)
                ex=temp;
            if(temp->data ==y)
                yi = temp;
            temp = temp->next;
        }
        temp->next = head;
        //___________circular tayyar____________

        int sarim = -1;
        int ankita = k;
        while(n--)
        {
            while(ankita--)
            {
                ex = ex->next;
            }
            ankita=k;
            if(ex==yi)
            {
                sarim = 1;
                break;
            }

        }

        if(sarim==1)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
        
        

    }

    return 0;
}