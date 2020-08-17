#include<iostream>
#include <algorithm>
using namespace std;

// 2
// 3
// 1 2 3 
// 3
// 3 2 1

int main() 
{	
	int T,N;
	cin>>T;
	while(T!=0)
	{
        cin>>N;
        int A[N];
        for (int i=0;i<N;i++)
        {
            cin>>A[i];
        }
        next_permutation(A,A+N);
        for (int i=0;i<N;i++)
        {
            cout<<A[i]<<" ";
        }
        cout<<endl;
        T =T-1;
		
	}
	return 0;
}