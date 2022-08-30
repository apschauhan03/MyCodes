/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
#include<iostream>
using namespace std;

class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };
class handt
{
	public:
    Node *HEAD;
    Node *TAIL;
    
    handt()
    {
    	HEAD = NULL;
        TAIL = NULL;
    }
    
    
    handt reverse(Node *head)
    {
        handt Y;
    	if(head==NULL)
        {
           return Y;
        }
        handt SO = reverse(head->next);
        Node *lastelement = head -> next;
        lastelement->next = head;
        head -> next = NULL;
        Y.HEAD = SO.HEAD;
        Y.TAIL = head;
        return Y;
    }
};

// handt reverse(Node *head)
// {
//     if(head==NULL)
//     {
        
//         return 
//     }
// }


Node *kReverse(Node *head, int k)
{
	//Write your code here
    if(head==NULL)
    {
        return head;
    }
    Node *h1 = head;
    Node *t1 = head;
    int count = 1;
    while(count!=k)
    {
        t1 = t1 -> next;
        count++;
    }
    
    Node *h2 = t1 -> next;
    t1 -> next = NULL;
    
    handt X;
    X.reverse(h1);

    Node *so = kReverse(h2,k);

    X.TAIL ->next = so;

    return head;
    
}