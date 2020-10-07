#include <iostream>
using namespace std;
int main()
{
    //_________________cin.getline(arr, size,delimeter)
    // ___________read complete sentence including spaces
    char ch[10];
    cin.getline(ch, 1000,'$');
    cout << ch;


    //_____________char ch = cin.get()_______________
    //____read only one character at a time
    //char ca[2] ={'a','b'};
    // char ca;
    // ca =cin.get();
    
    // cout << ca;


    return 0;
}