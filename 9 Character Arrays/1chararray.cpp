#include<iostream>
using namespace std;
int main()
{
    //_______________type 1
    //_print until '\0' not occurs
    char a[] ={'a','b','c','\0','a','b','c'};
    cout<<a;

    //________________type 2
    //______automatically put '\0' in the last when '\n' occurs
    char array[10];
    cin>>array;
    cout<<array;


    //________________type 3

    char ch[]="sarimAnkita";
    cout<<endl<<ch[2];
    cout<<endl<<ch<<" "<<"Size: "<<sizeof(ch);


    return 0;

}