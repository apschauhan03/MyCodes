#include<cstring>
#include<iostream>
using namespace std;


//This is brute force approach
int fibb_1(int n)
{
    if(n<=1)
        return n;
    
    int a = fibb_1(n-1);
    int b = fibb_1(n-2);

    return a+b;
}


//This is memoisation since it is using recurrsion and to calculate the nth ans we need n-1 and n-1
//hence its also drop down approach

int fibb_2helper(int n,int *arr)
{
    if(n<=1)
        return n;

    //cheak the ans
    if(arr[n]!=-1)
    {
        return arr[n];
    }
    
    //Calculation
    int a = fibb_2helper(n-1,arr);
    int b = fibb_2helper(n-2,arr);
    //saving for future reference
    arr[n] = a+b;
    return arr[n];
}
int fibb_2(int n)
{
    int *arr = new int[n+1];
    for (int i = 0; i < n+1; i++)
    {
        arr[i] = -1;
    }
    
    return fibb_2helper(n,arr);
}



/*Now this is dynamic programming approach
    there is nothing different in approach of dp and memoisation since both of them
    saving data so that we dont have to recalculate everytime

    but in dp we use iterative approach and bottom to top 
    we start from the base case and calculate upwards*/
int fibb_3(int n)
{
    int *arr = new int[n+1];
    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i < n+1; i++)
    {
        arr[i] = arr[i-1] + arr[i-2];
    }
    
    return arr[n];
}


int main()
{
    int n;
    cin>>n;
    cout<<fibb_1(n)<<endl;

}