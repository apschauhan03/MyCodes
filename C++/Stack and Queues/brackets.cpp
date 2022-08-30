#include<iostream>
using namespace std;
#include <stack>

bool isBalanced(string expression)
{
    stack<char> s;
    bool x=true;
    for (int i = 0; i < expression.size(); i++)
    {
        if(expression[i]=='{'||expression[i]=='['||expression[i]=='(')
        {
            s.push(expression[i]);
        }
        if(expression[i]=='}')
        {
            if(s.top()!='{')
            {
                return false;
            }
            else
            {
                x = true;
                s.pop();
            }
        }
        if(expression[i]==']')
        {
            if(s.top()!='[')
            {
                return false;
            }
            else
            {
                x = true;
                s.pop();
            }
        }
        if(expression[i]==')')
        {
            if(s.top()!='(')
            {
                return false;
            }
            else
            {
                x = true;
                s.pop();
            }
        }
    }
    if(s.empty())
    {
        return x;
    }
    else
    return false;
}


int main() 
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}