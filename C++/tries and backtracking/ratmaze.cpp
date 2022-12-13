#include<iostream>
using namespace std;

void printSolution(int **visited,int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j= 0; j < n; j++)
        {
            cout<<visited[i][j]<<" ";
        }
       
    }
     cout<<endl;
}

void ratmazeHelper(int **arr,int n,int **visited,int x,int y)
{
    if(x==n-1&&y==n-1)
    {
        visited[x][y] = 1;
        printSolution(visited,n);
        visited[x][y] = 0;
        return;
    }

    if(x<0||x>=n||y<0||y>=n||arr[x][y]==0||visited[x][y]==1)
    {
        return;
    }

    // Alphabetical order of LRUD is DLRU which is also known as Lexicographical
    visited[x][y] = 1;
    ratmazeHelper(arr,n,visited,x,y+1);
    ratmazeHelper(arr,n,visited,x-1,y);
    ratmazeHelper(arr,n,visited,x+1,y);
    ratmazeHelper(arr,n,visited,x,y-1);
    visited[x][y] = 0;




}

void ratmaze(int **arr,int n)
{
    int **visited = new int*[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }
    
    ratmazeHelper(arr,n,visited,0,0);
    
}
int main()
{
    int n;
    cin>>n;
    int **arr = new int*[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>arr[i][j];
        }
        
    }

    ratmaze(arr,n);
    
    
    


    return 0;
}