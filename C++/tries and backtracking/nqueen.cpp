#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int board[11][11];
bool ispossible(int n,int row,int column)
{
    //The vertical condition
    for (int i = row-1; i >= 0; i--)
    {
        if(board[i][column]==1)
        {
            return false;
        }
    }

    //The left diagonal condition
    for (int i = row-1,j=column-1; i >= 0&&j>=0; i--,j--)
    {
        if(board[i][j]==1)
        {
            return false;
        }
    }

    //The right diagonal condition

    for (int i = row-1,j=column+1; i >= 0&&j>=0; i--,j++)
    {
        if(board[i][j]==1)
        {
            return false;
        }
    }

    return true;
    
    
}
void nqueenhelper(int n,int row)
{
    if(row==n)
    {
        //print the board
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout<<board[i][j]<<" ";
            }
           
        }
        cout<<endl;
        return;
        
    }


    //small calculation
    for (int i = 0; i < n; i++)
    {
        if(ispossible(n,row,i))
        {
            board[row][i] = 1;
            nqueenhelper(n,row+1);
            board[row][i] = 0;
         }
    }
    return;
}
void nqueen(int n)
{
    memset(board,0,11*11*sizeof(int));
    nqueenhelper(n,0);
}
int main()
{
    int n;
    cin>>n;
    nqueen(n);
}