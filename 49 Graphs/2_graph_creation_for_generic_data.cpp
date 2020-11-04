#include "bits/stdc++.h"
using namespace std;

class graph
{
    map<string, list<pair<string,int>>> l;
    public:
    void add_eges(string s, string d, bool bidirectional,int wt)
    {
        l[s].push_back(make_pair(d,wt));
        if(bidirectional)
        {
           l[d].push_back(make_pair(s,wt)); 
        }
    }


    void print()
    {
        for(auto pr: l)
        {
            string source = pr.first;
            cout<<source<<"-->";
            list<pair<string, int>> edges = pr.second;
            for(auto pr2 : edges)
            {
                string destination  = pr2.first;
                int weight = pr2.second;
                cout<<destination<<" "<<weight <<" | ";

            }
            cout<<endl;
        }
    }
};

int main()
{
    
    graph g;
    g.add_eges("a","b",true, 3);
    g.add_eges("a","c",true, 4);
    g.add_eges("b","c",true, 6);
    g.add_eges("a","d",false, 5);

    g.print();

}


