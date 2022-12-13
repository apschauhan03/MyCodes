#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lcs_R(string s1,string s2)
{
    if(s1.size()==0||s2.size()==0)
        return 0;

    if(s1[0]==s2[0])
        return 1+lcs_R(s1.substr(1),s2.substr(1));

    int a = lcs_R(s1.substr(1),s2);
    int b = lcs_R(s1,s2.substr(1));
    int c = lcs_R(s1.substr(1),s2.substr(1));

    return max(a,max(b,c));
}
int lcs_memhelper(string s1,string s2,int **output)
{
     if(s1.size()==0||s2.size()==0)
        return 0;

    if(output[s1.size()][s2.size()]!=-1)
        return output[s1.size()][s2.size()];


    if(s1[0]==s2[0])
        {
            output[s1.size()][s2.size()] = 1+lcs_memhelper(s1.substr(1),s2.substr(1),output);
            return output[s1.size()][s2.size()];
        }
    int a = lcs_memhelper(s1.substr(1),s2,output);
    int b = lcs_memhelper(s1,s2.substr(1),output);
    int c = lcs_memhelper(s1.substr(1),s2.substr(1),output);

    output[s1.size()][s2.size()]= max(a,max(b,c));
    return output[s1.size()][s2.size()];
}

int lcs_mem(string s1,string s2)
{
    int **output = new int*[s1.size()+1];
    for (int i = 0; i < s1.size()+1 ; i++)
    {
        output[i] = new int[s2.size()+1];
        for (int j = 0; j < s2.size()+1; j++)
        {
             output[i][j] = -1;
        }
        
    }
    return lcs_memhelper(s1,s2,output);
    
}
int lcs_DP(string s1,string s2)
{
    int **output = new int*[s1.size()+1];
    for (int i = 0; i < s1.size()+1; i++)
    {
        output[i] = new int[s2.size()+1];
    }
    for (int i = 0; i < s2.size()+1 ; i++)
    {
        output[0][i] = 0;
    }
    for (int i = 0; i < s1.size()+1 ; i++)
    {
        output[i][0] = 0;
    }

    for (int i = 1; i <s1.size()+1; i++)
    {
        for (int j = 1; j < s2.size()+1; j++)
        {
            if(s1[s1.size()-i]==s2[s2.size()-j])
            {
                output[i][j] = 1 + output[i-1][j-1];
            }
            else
            {
                int ans = max(output[i-1][j],max(output[i][j-1],output[i-1][j-1]));
                output[i][j] = ans;
            }
        }
        
    }
    return output[s1.size()][s2.size()];

    
}
int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;

    cout<<lcs_R(s1,s2)<<endl;
    cout<<lcs_mem(s1,s2)<<endl;
    cout<<lcs_DP(s1,s2)<<endl;


}