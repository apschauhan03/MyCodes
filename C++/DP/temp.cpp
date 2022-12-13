#include<bits/stdc++.h>
using namespace std;
void print_myarray(int** arr,int column,int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

int main(){
    int rows,column;
    cin>>rows;
    cin>>column;
    int **arr = new int*[rows];
    for (int i = 0; i < rows ; i++)
    {
        arr[i] = new int[column];
    }
    

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cin>>arr[i][j];
        }
        
    }
    cout<<endl;
    print_myarray(arr,column,rows);
    
}