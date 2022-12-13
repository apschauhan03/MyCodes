#include<iostream>
using namespace std;

void inplaceHeapdecSort(int input[],int n)
{
    for (int i = 1; i < n; i++)
    {
        int child_Index = i;
        while (child_Index>0)
        {
            int parent_Index = (child_Index-1)/2;
            if(input[parent_Index]>input[child_Index])
            {
                int temp = input[parent_Index];
                input[parent_Index] = input[child_Index];
                input[child_Index] = temp;
            }
            else
                break;

            child_Index = parent_Index;     
        }
    }

    //sorting in decreasing order

    int size = n;
    while (size!=1)
    {
    int temp = input[0];
    input[0] = input[size-1];
    input[size - 1] = temp;
    size--;


     int parent_Index = 0;
        int CI_Left = (2*parent_Index+1); 
        int CI_Right = (2*parent_Index+2); 
       


        while (CI_Left<size)
        {
             int min_Index = parent_Index;
            if(input[min_Index]>input[CI_Left])
                min_Index = CI_Left;

            if(input[min_Index]>input[CI_Right]&&CI_Right<size)
                min_Index = CI_Right;


            if(min_Index==parent_Index)
                break;


            
            int temp = input[min_Index];
            input[min_Index] = input[parent_Index];
            input[parent_Index] = temp;

            parent_Index = min_Index;
             CI_Left = (2*parent_Index+1); 
             CI_Right = (2*parent_Index+2); 
        }
        

    }
    

    
}


int main()
{
    int input[] = {8,5,2,1,0};
    inplaceHeapdecSort(input,5);
    for (int i = 0; i < 5; i++)
    {
        cout<<input[i]<<" ";
    }
    
    return 0;
}