template <typename T>
class Queuesusingarrays
{
    T *data;
    int firstindex;
    int nextindex;
    int size;
    int capacity;

    public:
    Queuesusingarrays()
    {
        data = new T[5];
        capacity = 5;
        firstindex=-1;
        nextindex=0;
        size = 0;
    }

    int getsize()
    {
        return size;
    }

    int isEmpty()
    {
        return size==0;
    }

    void enqueue(T element)
    {
        if(size==capacity)
        {
            T *newdata = new T[2*capacity];
            int j = 0;
            for (int i = firstindex; i < capacity; i++)
            {
                newdata[j] = data[i];
                j++;
            }
            for (int i = 0; i < firstindex; i++)
            {
                newdata[j] = data[i];
                j++;
             }
             delete []data;
             data = newdata;
             capacity = 2*capacity;
             firstindex = 0;
             nextindex = capacity;
            
            
        }
        data[nextindex] = element;
        nextindex = (nextindex+1)%capacity;
        if(firstindex==-1)
        {
            firstindex++;
        }
        size++;
    }

    T front()
    {
        if(firstindex==-1)
        {
            cout<<"the queue is empty"<<endl;
            return 0;
        }
        return data[firstindex];
    }

    T dequeue()
    {
        if(size==0)
        {
            cout<<"the queue is empty"<<endl;
            return 0;
        }
        T ans = data[firstindex];
        firstindex = (firstindex+1)%capacity;
        size--;
        if(size==0)
        {
            firstindex = -1;
            nextindex = 0;
        }
        return ans;
    }
};