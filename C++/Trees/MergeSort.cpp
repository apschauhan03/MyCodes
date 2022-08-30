#include<iostream>
#include<vector>
using namespace std;
vector<int> Merge(vector<int> arr,int si,int ei,int mid,vector<int> first,vector<int> second)
{
    int  i = 0;
    int j = 0;
    vector<int> finalarray;
    while(i<first.size()&&j<second.size())
    {
        if(first[i]<second[j])
        {
            finalarray.push_back(first[i]);
            i++;
        }
        else
        {
            finalarray.push_back(second[j]);
            j++;
        }
    }
    while (i<first.size())
    {
        /* code */
        finalarray.push_back(first[i]);
        i++;
    }
    while (j<second.size())
    {
        /* code */
        finalarray.push_back(second[j]);
        j++;
    }
    return finalarray;
    
    
    

    
}
vector<int> mergeSort(vector<int> arr,int si,int ei)
{
    if (si>=ei)
    {
        vector<int> farr;
        if(si==ei)
        {
            farr.push_back(arr[si]);
        }
        return farr;
    }
    int mid = (si+ei)/2;
    vector<int> first = mergeSort(arr,si,mid);
    vector<int> second = mergeSort(arr,mid+1,ei);
    vector<int> finala = Merge(arr,si,ei,mid,first,second);
    return finala;
    
}
int main()
{
    vector<int> arr;
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(9);
    arr.push_back(10);
    //arr.push_back(2);
    //arr.push_back(111);
    
    vector<int> farr = mergeSort(arr,0,arr.size()-1);
    for (int i = 0; i < farr.size(); i++)
    {
        /* code */
        cout<<farr[i]<<endl;
    }
    
    return 0;
}