#include <bits/stdc++.h>
using namespace std;

bool emptyLocation(int arr[9][9], int &row, int &col)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (arr[i][j] == 0)
            {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

bool isSafeinColumn(int arr[9][9], int row, int col, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (arr[i][col] == num)
            return false;
    }
    return true;
}

bool isSafeinRow(int arr[9][9], int row, int col, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (arr[row][i] == num)
            return false;
    }
    return true;
}

bool isSafeinGrid(int arr[9][9], int row, int col, int num)
{
    int rowf = row - (row % 3);
    int colf = col - (col % 3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i + rowf][j + colf] == num)
                return false;
        }
    }
    return true;
}
bool isSafetoput(int arr[9][9], int row, int col, int num)
{
    return isSafeinRow(arr, row, col, num) &&
           isSafeinColumn(arr, row, col, num) && isSafeinGrid(arr, row, col, num);
}
bool sudukoSolver(int arr[9][9])
{
    int row, col;
    if (!emptyLocation(arr, row, col))
    {
        return true;
    }
    for (int i = 1; i <= 9; i++)
    {
        if (isSafetoput(arr, row, col, i))
        {
            arr[row][col] = i;
            if (sudukoSolver(arr))
            {
                return true;
            }
            arr[row][col] = 0;
        }
    }
    return false;
}
int main()
{
    int arr[9][9];
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> arr[i][j];
        }
    }
    bool ans = sudukoSolver(arr);
    if (ans == 1)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    else
        cout << "false" << endl;
    return 0;
}