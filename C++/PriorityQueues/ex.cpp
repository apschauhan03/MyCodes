#include<iostream>
#include<sstream>

using namespace std;
string convertintostring(int a)
{
    //how to  convert integers into the string
    stringstream ss;
    ss<<a;
    string ans;
    ss>>ans;
    return ans;
}

int main()
{
    int a;
    cin>>a;
    string a_string = "Anita";
    cout<<a_string<<endl;

    a_string = convertintostring(a);

    cout<<a_string<<endl;
}