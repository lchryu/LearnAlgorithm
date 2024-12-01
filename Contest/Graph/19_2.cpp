#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;

struct Edge
{
    int u, v;
};

vector<int> adj[MAXN];
vector<Edge> edges;
int visited[MAXN];
int n, m;

void DFS(int node, int skip_u, int skip_v)
{
    visited[node] = 1;
    for (int neighbor : adj[node])
    {
        if (!visited[neighbor] && !(node == skip_u && neighbor == skip_v) && !(node == skip_v && neighbor == skip_u))
        {
            DFS(neighbor, skip_u, skip_v);
        }
    }
}

bool count_connected(int initial_components, Edge edge)
{
    memset(visited, 0, sizeof(visited));
    int components = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            DFS(i, edge.u, edge.v);
            components++;
        }
    }

    return components > initial_components;
}

int main()
{
    cin >> n >> m;

    edges.resize(m);

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges[i] = {u, v};
    }

    // Initial DFS to count connected components without removing any edges
    memset(visited, 0, sizeof(visited));
    int initial_components = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            DFS(i, 0, 0);
            initial_components++;
        }
    }

    // Check for bridges by removing each edge
    int bridge_count = 0;
    for (const auto &edge : edges)
    {
        if (count_connected(initial_components, edge))
        {
            bridge_count++;
        }
    }

    cout << bridge_count << endl;
    return 0;
}
