#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;
vector<int> removeDuplicates(int* arr,int n)
{
    vector<int> output;
    unordered_map<int,bool> seen;  // Creating a map that check if the element is occurred or not by true or false
    for (int i = 0; i < n; i++)
    {
        if(seen.count(arr[i])>0) // This means the element is alredy seen and entered as true value in key in maps
        {
            continue;  
        }
        seen[arr[i]] = true; // other wise we'll put true
        output.push_back(arr[i]);
    }
    return output;
}

int highestFrequency(int* arr,int n)
{
    unordered_map<int , int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    int max = INT_MIN;
    for (int i = 0; i < freq.size(); i++)
    {
        if(freq[arr[i]]>max)
            max = arr[i];
    }
    
    return max;
    
}



int main()
{
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        cin>>arr[i];
    }
    vector<int> ans = removeDuplicates(arr,10);

    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }

    int max = highestFrequency(arr,10);
    cout<<endl;
    cout<<max<<endl;
    
    
    return 0;
}