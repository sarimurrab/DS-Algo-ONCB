    int position = 0;

    for (int i = 1; i < N; i++)
    {
        if (A[position].second <=A[i].first)
        {
            count++;
        }
        position++;
    }
    cout<<count;