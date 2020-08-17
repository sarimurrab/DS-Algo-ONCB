#include <iostream>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

void activity_selection(int N)
{
    pair<int, int> A[N];
    int m, n;
    for (int i = 0; i < N; i++)
    {
        cin >> m >> n;
        A[i] = make_pair(m, n);
    }

    sort(A, A + N, compare);

    int count = 1;
    int position = 0;

    for (int i = 1; i < N; i++)
    {
        if (A[i].first >= A[position].second)
        {
            count++;
            position = i;
        }
        
    }
    cout << count;
}
int main()
{
    int T, N;
    cin >> T;
    while (T != 0)
    {
        cin >> N;
        activity_selection(N);
        T = T - 1;
    }
    return 0;
}