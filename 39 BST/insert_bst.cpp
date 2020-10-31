#include <iostream>
using namespace std;

class node
{
    public:
    int data;
    node * left;
    node * right;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};


node * insert_bst(node * root, int d)
{
    if(root == NULL)
    return new node(d);




    if(d<= root->data )
    root->left = insert_bst(root->left,d);
    else
    root->right = insert_bst(root->right,d);
    
    return root;
    


}


void print_inorder(node * root)
{
    if(root ==NULL)
    return;

    print_inorder(root->left);
    cout<<root->data<<" ";
    print_inorder(root->right);

    return;

}

node * build_bst()
{
    int d;
    cin>>d;

    node * root = NULL;
    while(d!=-1)
    {
        root  = insert_bst(root,d);
        cin>>d;
    }
    return root;
}

int main()
{
    node * root = build_bst();
    print_inorder(root);


}