#include <iostream>
using namespace std;
int main()
{
    // address operator &
    int x = 2;
    //  cout<<&x<<endl;

    float y = 2.2;
    //  cout<<&y<<endl;

    char c = 'A';
    //cout<<(void*)&c<<endl;
    

    float *z = &y;
    cout <<z<<endl;
    cout<<&y;


    return 0;
}