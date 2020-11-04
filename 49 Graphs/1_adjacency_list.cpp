#include "bits/stdc++.h"
using namespace std;

// v = number of vertex
class graph
{
    int v;
    list<int> * l;

    public:
    graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }
    void add_edges(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void show_adjacency_list()
    {
        for(int i=0;i<v;i++)
        {
            cout<<i<<"-->";
            for(auto e: l[i])
            {
                cout<<e<<",";
            }
            cout<<endl;
        }
    }
};

int main()
{
    graph g(4);
    g.add_edges(0,1);
    g.add_edges(2,0);
    g.add_edges(2,1);
    g.add_edges(3,2);
    g.show_adjacency_list();


}


