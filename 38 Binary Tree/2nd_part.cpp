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


void bfs(node * root)  // not in new line
{
    queue<node *> q;
    q.push(root);
    while(!q.empty())
    {
        node * temp = q.front();
        cout<<temp->data<<" ";
        q.pop();

        q.push(temp->left);
        q.push(temp->right);

    }
}

int count_numofnodes(node * root)
{
    if(root==NULL)
    return 0;
    int l_count = count_numofnodes(root->left);
    int r_count = count_numofnodes(root->right);
    return l_count + r_count + 1;
}


int sum_of_nodes(node * root)
{
    if(root==NULL)
    return 0;

    int l_sum = sum_of_nodes(root->left);
    int r_sum = sum_of_nodes(root->right);

    return l_sum + r_sum+root->data;


}



void bfs_newline(node * root)  // In new line
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* f = q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<f->data<<",";
            q.pop();

            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
    return;
}

class HBpair
{
    public:
    int height;
    bool balance;
};

HBpair isheightbalanced(node * root)
{
    HBpair p;
    if(root == NULL)
    {
        p.height =0;
        p.balance = true;
        return p;
    }

    HBpair left = isheightbalanced(root->left);
    HBpair right = isheightbalanced(root->right);
    
    if(abs(left.height-right.height)<=1  && left.balance && right.balance)
    {
    	p.balance = true;
    	p.height = max(left.height, right.height)+1;
    }
    else
    {
        p.balance = false;
        p.height = max(left.height, right.height)+1;
    }
    return p;
    
}


node * buildbalancedfromarray(int *a, int s, int e)
{
    if(s>e)
    return NULL;

    int mid = (s+e)/2;
    node * root = new node(a[mid]);
    root->left = buildbalancedfromarray(a,s,mid-1);
    root->right = buildbalancedfromarray(a,mid+1,e);


    return root;
}


node * createfrom_in_pre(int * in, int * pre, int s, int e)
{
    static int i=0;
    if(s>e)
    return NULL;

    node * root = new node(pre[i]);
    

    int index =-1;
    for(int j=0;j<e;j++)
    {
        if(in[j]==pre[i])
        {
            index = j;
            break;
        }
    }
    i++;
    
	root->left = createfrom_in_pre(in, pre, s,index-1);
    root->right = createfrom_in_pre(in,pre,index+1, e);

    return root;
}


int diameter(node * root)
{
    if(root==NULL)
    return 0;

    int h1 = height(root->left);
    int h2 = height(root->right);
    int optn1 = h1+h2;
    int optn2 = diameter(root->left);
    int optn3 = diameter(root->right);


    return max(optn1, max(optn2, optn3));


}

void printrightview(node * root)
{
    if(root==NULL)
    return ;

    queue<node *> q;
    q.push(root);

    while(!q.empty())
    {
        int n = q.size();
        for(int i=1;i<=n;i++)
        {
            node * temp = q.front();
            q.pop();

            if(i==1 )  //  right view i==n
            cout<<temp->data<<" ";

            if(temp->left !=NULL)
            q.push(temp->left);

            if(temp->right!=NULL)
            q.push(temp->right);
		}
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
    
    printAllevels(root);
    */
    
    
    /*
    bfs_newline(root);
    bfs(root);

    cout<<"Number of Node : "<<count_numofnodes(root);
    cout<<endl<<"Sum of Nodes : "<<sum_of_nodes(root);
    */
    // cout<<endl<<"Diameter : "<<diameter(root);

    // HBpair p = isheightbalanced(root);
    // cout<<endl<<p.balance;

    // int a[6] = {1,2,3,4,5,6};
    // node * root1 = buildbalancedfromarray(a,0,5);
    printAllevels(root);
    cout<<endl;
    printrightview(root);
    

    return 0;
}