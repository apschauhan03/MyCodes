#include<iostream>
#include<unordered_map> //include the library for unordered map, we can also use map but it will use logn time
#include<string>


using namespace std;
int main()
{
    unordered_map<string,int> my_Map; // template takes input in form of <key,value> pair

    //Insertion of pairs
    pair<string,int> p("abc",1);
    pair<string,int> q("def",2);
    my_Map.insert(p);
    my_Map.insert(q);
    // my_Map.insert("ghi",3); can't do this
 

    //Access of  pairs
    // two ways
    // first - Use at function
    cout<<my_Map.at("abc")<<endl;
   // cout<<my_Map.at("xyz")<<endl; // Will give error if we try to find a key which doesnt exitst

    // Second - Use square bracketes but carefully
    cout<<my_Map["abc"]<<endl;
    cout<<my_Map["def"]<<endl;
    cout<<"Size : "<<my_Map.size()<<endl;
    // but if we try to access a key that does not exist 
    // square bracket will insert a key with value 0;
    cout<<my_Map["xyz"]<<endl;
    cout<<"Size : "<<my_Map.size()<<endl;
    // Now this can be dangerous so we do

    // Pre check
    if(my_Map.count("tuv")>0)
    {
        cout<<"pre-check : "<<my_Map["tuv"]<<endl;
    }
    if(my_Map.count("xyz")>0)
    {
        cout<<"pre-check : "<<my_Map["xyz"]<<endl;
    }



    return 0;
}