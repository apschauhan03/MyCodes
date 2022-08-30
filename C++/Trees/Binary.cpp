#include<iostream>
#include<queue>
using namespace std;


template <typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(T data)
    {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

void printBinaryTree(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<":";
    if(root->left!=NULL)
    {
        cout<<"L"<<root->left->data;
    }
     if(root->right!=NULL)
    {
        cout<<"R"<<root->right->data;
    }
    cout<<endl;

    printBinaryTree(root->left);
    printBinaryTree(root->right);
    return;
}

BinaryTreeNode<int>* takeinputbinary()
{
    int rootdata;
    cout<<"Enter the data:\n";
    cin>>rootdata;
    if(rootdata==-1)
    {
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootdata);
    BinaryTreeNode<int>* leftchild = takeinputbinary();
    BinaryTreeNode<int>* rightchild = takeinputbinary();
     
    root->left = leftchild;
    root->right = rightchild;

    return root;

}

BinaryTreeNode<int>* takeinputlevelwise()
{
    int rootdata;
    cout<<"Enter the root data:\n";
    cin>>rootdata;
    if(rootdata==-1)
    {
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootdata);
    queue<BinaryTreeNode<int>*> pendingnodes;
    pendingnodes.push(root);
    while (pendingnodes.size()!=0)
    {
        BinaryTreeNode<int>* front = pendingnodes.front();
        pendingnodes.pop();

        int leftdata;
        cout<<"Enter the Left data of "<<front->data<<endl;
        cin>>leftdata;
        if(leftdata!=-1)
        {
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftdata);
            front->left = child;
            pendingnodes.push(child);
        }

        int rightdata;
         cout<<"Enter the Right data of "<<front->data<<endl;
        cin>>rightdata;
        if(rightdata!=-1)
        {
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightdata);
            front->right = child;
            pendingnodes.push(child);
        }

        
    }
    return root;
}


void printlevelwise(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }

    
    queue<BinaryTreeNode<int>*> pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size()!=0)
    {
        BinaryTreeNode<int>* front = pendingnodes.front();
        pendingnodes.pop();
        cout<<front->data<<" : ";
        if(front->left!=NULL)
        {
            cout<<"L"<<front->left->data;
            pendingnodes.push(front->left);
        }
         if(front->right!=NULL)
        {
            cout<<"R"<<front->right->data;
            pendingnodes.push(front->right);
        }
        cout<<endl;
    }
}


int numnodes(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+numnodes(root->right)+numnodes(root->left);
}


//three traversals are there in binary trees
//1) level wise
//2) Post order
//3) Pre order
//4) Inorder

void Inorder(BinaryTreeNode<int>* root)
{
    if(root==NULL)
        return;

    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
    return;
}


pair<int,int> heightdiameter(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        pair<int,int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int,int> left = heightdiameter(root->left);
    pair<int,int> right = heightdiameter(root->right);

    int lh = left.first;
    int ld = left.second;
    int rh = right.first;
    int rd = right.second;

    int height = 1 + max(lh,rh);
    int diameter = max(lh+rh,max(ld,rd));

    pair<int,int> ans;
    ans.first = height;
    ans.second = diameter;

    return ans;
}
//tree 1 2 3 4 5 6 -1 7 -1 10 20 8 -1 -1 -1 -1 -1 -1 -1 -1 -1
int main()
{
    // BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int>* Node1 = new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int>* Node2 = new BinaryTreeNode<int>(3);

    // root->left = Node1;
    // root->right = Node2;

    //BinaryTreeNode<int>* root = takeinputbinary();


    BinaryTreeNode<int>* root = takeinputlevelwise();
    //printBinaryTree(root);
    printlevelwise(root);

    int numnode = numnodes(root);
    cout<<numnode<<endl;

    Inorder(root);
    
    pair<int,int> ans = heightdiameter(root);
    cout<<endl;
    cout<<"Height"<<":"<<ans.first<<" ";
    cout<<"diameter"<<":"<<ans.second<<" ";

    delete root;
    return 0;
}