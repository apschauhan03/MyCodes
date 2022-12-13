#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
int main()
{
    unordered_map<string,int> map;
    map["abc"] = 1;
    map["abc1"] = 2;
    map["abc2"] = 3;
    map["abc3"] = 4;
    map["abc4"] = 5;
    map["abc5"] = 6;

    // iterator ka syntax
    unordered_map<string,int>:: iterator it = map.begin(); // gives the address of  1st element not necesary abc
    while(it != map.end())
    {
        cout<<"Key : "<<it->first<<" Value : "<<it->second<<endl;
        it++;
    }

    // We can even use functions like find
    unordered_map<string,int>:: iterator find = map.find("abc"); // return the address of abc
    cout<<"The value at find : "<<find->second<<endl;

    // We can use them in vector too
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    v.erase(v.begin(),v.begin()+3);

    vector<int>::iterator itv = v.begin();
    while(itv != v.end())
    {
        cout<<*itv<<endl;
        itv++;
    }

    //v.begin means before the first data
    //v.end means after the first data

    return 0;
}