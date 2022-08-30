
template <typename T>
class Node{
    public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};


template <typename T>
class stack{
    Node<T> *head;
    int capacity;
    public:
    stack()
    {
        head = NULL;
        capacity = 0;
    }
    int size()
    {
        return capacity;
    }
    bool isEmpty()
    {
        return capacity==0;
    }


    void push(T element)
    {
        if(head==NULL)
        {
            Node<T> *newnode = new Node<T>(element);
            this->head = newnode;
            capacity++;
            return;
        }
        else
        {
            Node<T> *newnode = new Node<T>(element);
            newnode -> next = head;
            head = newnode;
            capacity++;
            return;
        }
    }

    T top()
    {
        if(head!=NULL)
        return head->data;
        else
        return 0;
    }

    T pop()
    {
         if(head!=NULL)
         {
            T ans = head->data;
            Node<T> *temp = head;
            head = head ->next;
            delete temp;
            capacity--;
            return ans;

         }
        else
        return 0;
    }
};