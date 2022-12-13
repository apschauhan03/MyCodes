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

    int remove_Min() {
        if(pq.size()==0)
            return 0;

        int ans = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();

        int parent_Index = 0;
        int CI_Left = (2*parent_Index+1); 
        int CI_Right = (2*parent_Index+2); 
       


        while (CI_Left<pq.size())
        {
             int min_Index = parent_Index;
            if(pq[min_Index]>pq[CI_Left])
                min_Index = CI_Left;

            if(pq[min_Index]>pq[CI_Right]&&CI_Right<pq.size())
                min_Index = CI_Right;


            if(min_Index==parent_Index)
                break;


            
            int temp = pq[min_Index];
            pq[min_Index] = pq[parent_Index];
            pq[parent_Index] = temp;

            parent_Index = min_Index;
             CI_Left = (2*parent_Index+1); 
             CI_Right = (2*parent_Index+2); 
        }
        

        return ans;
        
    }

};