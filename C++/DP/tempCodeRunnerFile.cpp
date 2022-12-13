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