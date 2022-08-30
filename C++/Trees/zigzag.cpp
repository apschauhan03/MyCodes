#include <iostream>
#include <queue>
#include<stack>
template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
void zigZagOrder(BinaryTreeNode<int> *root) {
    if(root==NULL)
    return;

    stack<BinaryTreeNode<int>*> s1;
    stack<BinaryTreeNode<int>*> s2;

    s1.push(root);

    while (s1.size()!=0||s2.size()!=0)
    {
        while(s1.size()!=0)
        {
            BinaryTreeNode<int>* front = s1.top();
            s1.pop();
            cout<<front->data<<" ";
            if(front->left!=NULL)
                s2.push(front->left);

            if(front->right!=NULL)
                s2.push(front->right);
            
            if(s1.size()==0)
                cout<<endl;
        }

        while (s2.size()!=0)
        {
            BinaryTreeNode<int>* front = s2.top();
            s2.pop();
            cout<<front->data<<" ";
            if(front->right!=NULL)
                s1.push(front->right);

            if(front->left!=NULL)
                s1.push(front->left);

            if(s2.size()==0)
                cout<<endl;
        }
        
    }
    


}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    zigZagOrder(root);
}