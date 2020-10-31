#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};


node * buildtree()
{
    int d;
    cin>>d;
    if(d==-1)
    return NULL;

    node * root  = new node(d);

    root->left = buildtree();
    root->right = buildtree();

    return root;


}

// kth distance k liye print bna rha hu
int print_at_kth_level(node * root, int k)
{
    if(root == NULL)
    return;

    if(k==0)
    cout<<root->data<<" ";

    print_at_kth_level(root->left,k-1);
    print_at_kth_level(root->right,k-1);

    return 0;
}


int printat_kthdistance(node * root,node *target, int k)
{

    if(root==NULL)
    return -1;

    if(root==target)
    {
        print_at_kth_level(target,k);
        return 0;
    }

    int dl = printat_kthdistance(root->left,target,k);
    if(dl !=-1)
    {
        if(dl+1==k)
        cout<<root->data<<" ";
        else
        {
            print_at_kth_level(root->right,k-2-dl);
        }
        
        return dl+1;

    }

    int dr = printat_kthdistance(root->right,target,k);
    if(dr !=-1)
    {
        if(dr+1==k)
        cout<<root->data<<" ";
        else
        {
            print_at_kth_level(root->right,k-2-dr);
        }
        
        return dr+1;

    }


    return -1;


}

int main()
{
    node * root = buildtree();
    print_at_kth_level(root,3);

    return 0;
}

/*
1
2
4
6
-1
-1
7
10
-1
-1
11
-1
-1
5
8
-1
-1
9
-1
-1
3
-1
-1

*/