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

node *insert_bst(node *root, int d)
{
    if (root == NULL)
        return new node(d);

    if (d <= root->data)
        root->left = insert_bst(root->left, d);
    else
        root->right = insert_bst(root->right, d);

    return root;
}

void print_inorder(node *root)
{
    if (root == NULL)
        return;

    print_inorder(root->left);
    cout << root->data << " ";
    print_inorder(root->right);

    return;
}

node *build_bst()
{
    int d;
    cin >> d;

    node *root = NULL;
    while (d != -1)
    {
        root = insert_bst(root, d);
        cin >> d;
    }
    return root;
}

node *delete_bst(node *root, int key)
{
    if (root == NULL)
        return NULL;

    if (root->data == key)
    {
        //1 - NO child
        if (root->left == NULL and root->right == NULL)
        {
            delete root;
            return NULL;
        }
        //2 - One child on either side
        else if (root->left != NULL and root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        else if (root->right != NULL and root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        //3 - two childs
        else
        {
            node *replace = root->right;
            while (replace->left != NULL)
            {
                replace = replace->left;
            }
            //replace is the node with which we have to replace

            root->data = replace->data;
            root->right = delete_bst(root->right, root->data);
            return root;
        }
    }
    else if (key < root->data)
    {
        root->left = delete_bst(root->left, key);
        return root;
    }
    else
    {
        root->right = delete_bst(root->right, key);
        return root;
    }
}

int main()
{
    node *root = build_bst();
    print_inorder(root);
    cout << endl;
    delete_bst(root, 2);
    print_inorder(root);
}