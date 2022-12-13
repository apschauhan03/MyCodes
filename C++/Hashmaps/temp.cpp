#include<iostream>
#include<math.h>
using namespace std;
int converttoInt(string binarynum,int stringsize)
{
    int ans = 0;
    for (int i = 0; i <stringsize ; i++)
    {
        ans = ans + (binarynum[stringsize-i-1]-48)*pow(2,i);
    }
    return ans;
}
int main(){
    int stringsize;
    cin>>stringsize;
    string binarynum;
    cin>>binarynum;
    int num = converttoInt(binarynum,stringsize);
    cout<<num<<endl;
}
