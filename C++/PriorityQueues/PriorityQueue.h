#include<vector>
using namespace std;
class priorityQueue {
    vector<int> pq;

    public:

    priorityQueue(){

    }

    bool isEmpty()
    {
        return pq.size()==0;
    }

    int size()
    {
        return pq.size();
    }

    int getMin()
    {
        if(pq.isEmpty())
            return 0;
        return pq[0];
    }

    void insert(int element)
    {
        pq.push_back(element);
        int child_Index = pq.size() - 1;
        while (child_Index>0)
        {
            int parent_Index = (child_Index-1)/2;
            if(pq[parent_Index]>pq[child_Index])
            {
                int temp = pq[parent_Index];
                pq[parent_Index] = pq[child_Index];
                pq[child_Index] = temp;
            }
            else
                break;

            child_Index = parent_Index;     
        }
        
    }

    void remove_Min() {
        if(pq.isEmpty())
            return;

        int last_Element = pq[pq.size()-1];
        pq[pq.size()-1] = pq[0];
        pq[0] = last_Element;
        pq.pop_back();

        int parent_Index = 0;
        int min_Index = 0;
        while (parent_Index!=pq.size())
        {
            int child_indexLeft = (2*parent_Index+1)/2;
            int child_indexright = (2*parent_Index+2)/2;

            
        }
        
    }

};