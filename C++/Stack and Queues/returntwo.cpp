#include<iostream>
using namespace std;

class headandtail
{
    public:
    int *head;
    int *tail;

    headandtail()
    {
        head=NULL;
        tail=NULL;
    }
};

headandtail value(int *pu,int *py)
{
    headandtail t;
     t.head = pu;
    t.tail = py;
    return t;
}
int main()
{
    headandtail x;
    int u = 5;
    int *pu = &u;
    cout<<&u<<endl;
    int y = 10;
    int *py = &y;
    x = value(pu,py);

    cout<<x.head<<endl;
    cout<<x.tail<<endl;

    return 0;
}