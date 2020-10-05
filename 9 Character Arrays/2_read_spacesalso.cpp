#include <iostream>
using namespace std;
int main()
{
    //_________________cin.getline(arr, size,delimeter)
    // ___________read complete sentence including spaces
    char ch[1000];
    cin.getline(ch, 1000, '*');
    cout << ch;


    //_____________char ch = cin.get()_______________
    //____read only one character at a time
    char ca = cin.get();
    cout << ca;


    return 0;
}