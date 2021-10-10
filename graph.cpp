#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
void printGraph(vector<vector<int> > &edges)
{
    for (int i = 1; i < edges.size(); i++)
    {
        cout << i << " : ";
        for (int j = 0; j < edges[i].size(); j++)
        {
            cout << edges[i][j] << " ";
        }
        cout << endl;
    }
}
void dfs(vector<vector<int> > &edges, vector<bool> &visited, int i)
{
    cout << i << " ";
    for (int j = 0; j < edges[i].size(); j++)
    {
        if (!visited[edges[i][j]])
        {
            visited[edges[i][j]] = true;
            dfs(edges, visited, edges[i][j]);
        }
    }
}
void dfsGraph(vector<vector<int> > &edges)
{
    vector<bool> visited(edges.size(), false);

    for (int i = 1; i < edges.size(); i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            dfs(edges, visited, i);
        }
    }
}
void bfs(vector<vector<int> > &edges, vector<bool> &visited, int i)
{
    queue<int> q;
    q.push(i);
    while (!q.empty())
    {
        int x = q.front();
        cout << x << " ";
        q.pop();
        for (int j = 0; j < edges[x].size(); j++)
        {
            if (!visited[edges[x][j]])
            {
                visited[edges[x][j]] = true;
                q.push(edges[x][j]);
            }
        }
    }
}
void bfsGraph(vector<vector<int> > &edges)
{
    vector<bool> visited(edges.size(), false);

    for (int i = 1; i < edges.size(); i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            bfs(edges, visited, i);
        }
    }
}
bool dfsCycle(vector<vector<int> > &edges, vector<bool> &visited, int node, int parent)
{
    for (int i = 0; i < edges[node].size(); i++)
    {
        if (!visited[edges[node][i]])
        {
            visited[edges[node][i]] = true;
            if (dfsCycle(edges, visited, edges[node][i], node))
            {
                return true;
            }
        }
        else if (edges[node][i] != parent)
        {
            return true;
        }
    }
    return false;
}
void dfsCheckCycle(vector<vector<int> > &edges)
{
    vector<bool> visited(edges.size(), false);

    for (int i = 1; i < edges.size(); i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            if (dfsCycle(edges, visited, i, 0))
            {
                cout << "YES";
                return;
            }
        }
    }
    cout << "NO";
}
bool bfsCycle(vector<vector<int> > &edges, vector<bool> &visited, int node, int parent)
{
    queue<pair<int, int> > q;
    q.push(make_pair(node, parent));
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < edges[x].size(); i++)
        {
            if (!visited[edges[x][i]])
            {
                visited[edges[x][i]] = true;
                q.push(make_pair(edges[x][i], x));
            }
            else if (edges[x][i] != y)
            {
                return true;
            }
        }
    }
    return false;
}
void bfsCheckCycle(vector<vector<int> > &edges)
{
    vector<bool> visited(edges.size(), false);

    for (int i = 1; i < edges.size(); i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            if (bfsCycle(edges, visited, i, 0))
            {
                cout << "YES";
                return;
            }
        }
    }
    cout << "NO";
}
bool dfsCycleDG(vector<vector<int> > &edges, vector<bool> &visited, vector<bool> &path, int node)
{
    for (int i = 0; i < edges[node].size(); i++)
    {
        if (!visited[edges[node][i]])
        {
            visited[edges[node][i]] = true;
            path[edges[node][i]] = true;
            if (dfsCycleDG(edges, visited, path, edges[node][i]))
            {
                return true;
            }
            path[edges[node][i]] = false;
        }
        else if (path[edges[node][i]])
        {
            return true;
        }
    }
    return false;
}
void dfsCheckCycleDG(vector<vector<int> > &edges)
{
    vector<bool> visited(edges.size(), false);
    vector<bool> path(edges.size(), false);

    for (int i = 1; i < edges.size(); i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            path[i] = true;
            if (dfsCycleDG(edges, visited, path, i))
            {
                cout << "YES";
                return;
            }
            path[i] = false;
        }
    }
    cout << "NO";
}
int main()
{
    int n, m, u, v;
    cin >> n >> m;
    vector<vector<int> > edges(n + 1);
    while (m--)
    {
        cin >> u >> v;
        edges[u].push_back(v);
        // edges[v].push_back(u);
    }
    // printGraph(edges);
    // dfsGraph(edges);
    // bfsGraph(edges);
    // dfsCheckCycle(edges);
    // bfsCheckCycle(edges);
    dfsCheckCycleDG(edges);
    return 0;
}
