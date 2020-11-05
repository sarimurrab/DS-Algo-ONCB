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

    void bfs(int src)
    {
        map<int, int> dist;
        queue<int> q;

        for (int i = 0; i < v; i++)
        {
            dist[i] = INT_MAX;
        }

        q.push(src);
        dist[src] = 0;

        while (!q.empty())
        {
            int particular_node = q.front();
            //cout<<save<<" ";
            q.pop();
            for (auto e : l[particular_node])
            {
                if (dist[e] == INT_MAX)
                {
                    q.push(e);
                    dist[e] = dist[particular_node] + 1;
                }
            }
        }

        //____________single_source_shortest_path________________
        for (auto pr : dist)
        {
            int till = pr.first;
            int distance = pr.second;
            cout << "From " << src << " till " << till << " --> " << distance;
            cout<<endl;
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

    g.print();
    cout << endl;
    g.bfs(0);
    

    return 0;
}
