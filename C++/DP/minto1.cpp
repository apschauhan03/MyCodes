#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int minStepsBF(int n)
{
    if(n==1||n==0)
        return 0;

    int x = INT_MAX , y = INT_MAX , z = INT_MAX;
    if(n%3==0)
    {
        x = minStepsBF(n/3);
    }
    if(n%2==0)
    {
        y = minStepsBF(n/2);
    }
    z = minStepsBF(n-1);

    int ans = min(x,min(y,z));
    return ans + 1;
}


int minStepsMhelp(int arr[],int n)
{
    if(n==1||n==0)
        return arr[n];
    

    if(arr[n]!=-1)
    {
       return arr[n];
    }
    int x = INT_MAX , y = INT_MAX , z = INT_MAX;
    if(n%3==0)
    {
        x = minStepsMhelp(arr,n/3);
    }
    if(n%2==0)
    {
        y = minStepsMhelp(arr,n/2);
    }
    z = minStepsMhelp(arr,n-1);

    int ans = min(z,min(x,y));
    arr[n] = ans+1;
    return arr[n];
}

int minStepsM(int n)
{
    int arr[n+1];
    arr[0] = 0;
    arr[1] = 0;
    for (int i = 2; i < n+1 ; i++)
    {
        arr[i] = -1;
    }
    
    return minStepsMhelp(arr,n);
}


int minStepsDP(int n)
{
    int *arr = new int[n+1];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i < n+1; i++)
    {
        if(!n%2&&n%3)
        {
            table[i] = 1 + min(table)
        }
    }
    
}
int main()
{
    int n;
    cin>>n;
//    cout<<minStepsBF(n)<<endl;//BruteForce
    cout<<minStepsM(n)<<endl;//Memoisation
    //cout<<minStepsDP(n)<<endl;//Dynamic Programming
    return 0;
}