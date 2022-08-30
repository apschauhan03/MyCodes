// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include<queue>
using namespace std;
template<typename T>
class TreeNode{
  public:
  T data;
  vector<TreeNode<T>*> children;
  
  TreeNode(T data)
  {
      this -> data = data;
  }


  ~TreeNode()
  {
    for (int i = 0; i < this->children.size(); i++)
    {
        delete children[i];
    }
    
  }
};

TreeNode<int>* TakeInputLevelWise()
{
    int RootData;
    cout<<"Enter the RootData : "<<endl;
    cin>>RootData;
    TreeNode<int>* Root = new TreeNode<int>(RootData);
    queue<TreeNode<int>*> TreeNodeQueue;
    TreeNodeQueue.push(Root);
    while(TreeNodeQueue.size()!=0)
    {
        int Child;
        TreeNode<int>* Front = TreeNodeQueue.front();
        cout<<"How many Childrens are there of :"<<Front->data<<endl;
        TreeNodeQueue.pop();
        cin>>Child;
        for (int i = 0; i < Child; i++)
        {
            int Childdata;
            // TreeNode<int>* front = new TreeNode<int>(TreeNodeQueue.front()->data);
            cout<<"Enter the Data of the "<<i<<"th child"<<" of "<<Front->data<<endl;
            cin>>Childdata;
            TreeNode<int>* ChildDataNode = new TreeNode<int>(Childdata);
            //TreeNodeQueue.pop();
            TreeNodeQueue.push(ChildDataNode);
            Front->children.push_back(ChildDataNode);
        }
        
    }
    return Root;
}



//Print Level Wise
void PrintTreeLevelWise(TreeNode<int>* Root)
{
    queue<TreeNode<int>*> pendingnodes;
    pendingnodes.push(Root);
    while(pendingnodes.size()!=0)
    {
        TreeNode<int>* Front = pendingnodes.front();
        pendingnodes.pop();
        cout<<Front->data<<":";
        for (int i = 0; i < Front->children.size(); i++)
        {
            if(i==Front->children.size()-1)
            {
                cout<<Front->children[i]->data;
           		 pendingnodes.push(Front->children[i]);
            }
            else
            {    
            cout<<Front->children[i]->data<<",";
            pendingnodes.push(Front->children[i]);
            }       
            }
        cout<<endl;
        
    }
}













//count nodes
int CountNodes(TreeNode<int>* Root)
{
    int sumofchild=0;
    for (int i = 0; i < Root->children.size(); i++)
    {
         sumofchild = sumofchild + CountNodes(Root->children[i]);
    }
    return 1+sumofchild;
}



int SumofNodes(TreeNode<int>* Root)
{
    int sumofchildren=0;
    for (int i = 0; i < Root->children.size(); i++)
    {
        sumofchildren = sumofchildren + SumofNodes(Root->children[i]);
    }
    
    return Root->data+sumofchildren;
}


TreeNode<int>* maxdatanode(TreeNode<int>* Root)
{
    TreeNode<int>* Max = new TreeNode<int>(-101101);
    if(Root->data>Max->data)
    {
        Max = Root;
    }
    TreeNode<int>* elsemax = new TreeNode<int>(-110202);
    for (int i = 0; i < Root->children.size(); i++)
    {
        elsemax = maxdatanode(Root->children[i]);
    }
    if(elsemax->data>Max->data)
        return elsemax;

        else
        return Max;
    
}



void printatlevel(TreeNode<int>* Root,int k)
{
    if(Root == NULL)
    {
        return ;
    }
    if(k==0)
    {
        cout<<Root->data<<endl;
        return;
    }

    for (int i = 0; i < Root->children.size(); i++)
    {
        printatlevel(Root->children[i],k-1);
    }
    
}


// template<typename T>
TreeNode<int>* TakeInput()
{
    int RootData;
    cout<<"Enter the Data"<<endl;
    cin>>RootData;
      TreeNode<int>* Root = new TreeNode<int>(RootData);
      
      cout<<"Enter the Number of Childrens of"<<RootData<<endl;
      int child;
      cin>>child;
      
      for(int i=0;i<child;i++)
      {
          TreeNode<int>* SmallRoot = TakeInput();
          Root->children.push_back(SmallRoot);
      }
    
    return Root;
}


template<typename T>
void PrintTree(TreeNode<T>* Root)
{
    if(Root==NULL)
    {
        return;
    }
    cout<< Root->data<<":";
    for(int i = 0;i<Root->children.size();i++)
    {
        cout<<Root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<Root->children.size();i++)
    {
        PrintTree(Root->children[i]);
    }
}







void destructor(TreeNode<int>* Root)
{
    for (int i = 0; i < Root->children.size(); i++)
    {
        destructor(Root->children[i]);
    }
    delete Root;
    
}
int main() {
   
     TreeNode<int>* Root = TakeInputLevelWise();
    // PrintTreeLevelWise(Root);
    // int count = CountNodes(Root);
    // cout<<count<<endl;

    // int sum = SumofNodes(Root);
    // cout<<sum<<endl;

    // TreeNode<int>* max = maxdatanode(Root);
    // cout<<max->data<<endl;

   
//    /////////level wala case
//     int level;
//     cin>>level;
//     printatlevel(Root,level);

//After the use of the trees since we have allocated them using dynamic programming
//we have to delete them too
//there are two ways of doing this

//function method

destructor(Root);
    return 0;
}

//class destructor method
//make a destructor in class itself and it will do everything in it and then delete the node
