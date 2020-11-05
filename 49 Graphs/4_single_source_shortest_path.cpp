#include "bits/stdc++.h"
using namespace std;

// v = number of vertex
class graph
{
    int v;
    list<int> *l;

public:
    graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }

    void add_edges(int s, int d)
    {
        l[s].push_back(d);
        l[d].push_back(s);
    }

    void print()
    {
        for (int i = 0; i < v; i++)
        {
            cout << i << "--> ";
            for (auto x : l[i])
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }

    void bfs()
    {
        set<int> visited;
        queue<int> q;

        q.push(0);
        visited.insert(0);
        
        while(!q.empty())
        {
            int save = q.front();
            cout<<save<<" ";
            q.pop();
            for(auto e : l[save])
            {
                if(visited.count(e)!=1)
                {
                q.push(e);
                visited.insert(e);
                }
            }
        }

    }
};

int main()
{

    graph g(6);
    g.add_edges(0, 1);
    g.add_edges(0, 3);
    g.add_edges(2, 3);
    g.add_edges(1, 2);
    g.add_edges(3, 4);
    g.add_edges(4, 5);

    g.bfs();
}
