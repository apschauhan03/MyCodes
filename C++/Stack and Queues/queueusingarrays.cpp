#include<iostream>
using namespace std;
#include "Queuesusingarrays.h"

int main()
{
    Queuesusingarrays<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    cout<<q.front()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.front()<<endl;

    q.enqueue(65);
    q.enqueue(70);
    q.enqueue(80);
    q.enqueue(90);
    q.enqueue(100);
    q.enqueue(110);
    q.enqueue(120);

    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    cout<<q.front()<<endl;

    cout<<q.getsize()<<endl;
    cout<<q.isEmpty()<<endl;


}