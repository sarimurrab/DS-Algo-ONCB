#include <iostream>
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

node *buildtree()
{
    int d;
    cin >> d;
    if (d == -1)
        return NULL;

    node *root = new node(d);
    root->left = buildtree();
    root->right = buildtree();

    return root;
}

void preorder_print(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder_print(root->left);
    preorder_print(root->right);
    return;
}


void inorder_print(node *root)
{
    if (root == NULL)
        return;

    inorder_print(root->left);
    cout << root->data << " ";
    inorder_print(root->right);
    return;
}

void postorder_print(node *root)
{
    if (root == NULL)
        return;
    
    postorder_print(root->left);
    postorder_print(root->right);
    cout << root->data << " ";
    return;
}

int height(node * root)
{
    if(root == NULL)
    return 0;

    int hl = height(root->left);
    int hr = height(root->right);

    return max(hl,hr)+1;
}

void printk_level(node * root, int k)
{
    if(root ==NULL)
    return;

    if(k==1)
    {
    cout<<root->data<<" ";
    return;
    }

    printk_level(root->left,k-1);
    printk_level(root->right,k-1);
    

    return;
}

void printAllevels(node * root)
{
    int h = height(root);

    for(int i=1;i<=h;i++)
    {
        printk_level(root,i);
        cout<<endl;
    }
}


int main()
{
    node *root = buildtree();
    /*
    preorder_print(root);
    cout<<endl;
    inorder_print(root);
    cout<<endl;
    postorder_print(root);
    

    cout<<endl<<"height : ";
    cout<<height(root);
    */

    printAllevels(root);

    return 0;
}