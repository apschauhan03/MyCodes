#include<iostream>
using namespace std;
template <typename T , typename V>
class Pair
{
    private:
    T x;
    V y;
    public:
    T getX()
    {
        return x;
    }
    void setX(T x)
    {
        this->x = x; 
    }

    V getY()
    {
        return y;
    }
    void setY(V y)
    {
        this->y = y; 
    }
};

int main()
{
    Pair<Pair<int,int>,int> p2;
    p2.setY(10);
    Pair<int,int> p4;
    p4.setX(40);
    p4.setY(20);
    p2.setX(p4);


    cout<<p2.getX().getX()<<" "<<p2.getX().getY()<<" "<<p2.getY();

    return 0;
}