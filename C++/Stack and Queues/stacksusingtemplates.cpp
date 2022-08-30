// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
template <typename T>
class StackusingArray{
  T *data;
  int capacity;
  int nextindex;
  public:
  StackusingArray()
  {
      data = new T[4];
      capacity = 4;
      nextindex = 0;
    }
    void push(T element)
    {
        if(nextindex==capacity)
        {
            T *newdata = new T[2*capacity];
            for(int i=0;i<capacity;i++)
            {
                newdata[i] = data[i];
            }
            delete [] data;
            data = newdata;
            capacity *= 2;
        }
        data[nextindex] = element;
        nextindex++;
    }
    
    T pop()
    {
        if(nextindex==0)
        {
            cout<<"The Stack is empty"<<endl;
        }
        
        nextindex--;
         return data[nextindex];
       
    }
    
    T top()
    {
         if(nextindex==0)
        {
            cout<<"The Stack is empty"<<endl;
            
        }
        return data[nextindex-1];
    }
    
    int size()
    {
        return nextindex;
    }
    
    bool isempty()
    {
        return nextindex==0;
    }
};
int main() {
    StackusingArray<char> s;
    s.push('u');
    s.push('v');
    s.push('w');
    s.push('x');
    s.push('y');
    
    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    
    cout<<s.size()<<endl;
    
    cout<<s.isempty()<<endl;

    return 0;
}