#include <iostream>
using namespace std;
int main()
{
    /////////////////////////////////////
    // 1--> pair<int,char>
    pair<int, char> p;
    p.first = 786;
    p.second = 'S';

    cout << p.second << '\n'
         << '\n'
         << '\n';

    // alternate way
    pair<int, char> p1(p);
    cout << p1.first << endl;
    cout << p1.second << endl;

    /////////////////////////////////////
    // 2--> make_pair(xx,xx)  function
    pair<int, string> car = make_pair(10, "Sarim");
    // car.first = 10;
    // car.second = "Sarim";
    cout << car.first << endl;
    cout << car.second;
}