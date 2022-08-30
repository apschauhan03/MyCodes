#include<iostream>
#include <stack>

using namespace std;



int main()
{
    stack<char> s;
    s.push('q');
    s.push('w');
    s.push('e');
    s.push('r');
    s.push('t');
    s.push('y');

    cout<<s.size()<<endl;
    cout<<s.empty()<<endl;

    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;

    cout<<s.top()<<endl;

    cout<<s.size()<<endl;
    cout<<s.empty()<<endl;




    return 0;
}