#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
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
bool checkBipartiteDFS(vector<vector<int> > &edges, vector<int> &colours, int i, int col)
{
    for (int j = 0; j < edges[i].size(); j++)
    {
        if (colours[edges[i][j]] == -1)
        {
            colours[edges[i][j]] = !col;
            if (!checkBipartiteDFS(edges, colours, edges[i][j], !col))
            {
                return false;
            }
        }
        else if (colours[edges[i][j]] == col)
        {
            return false;
        }
    }
    return true;
}
bool checkBipartiteBFS(vector<vector<int> > &edges, vector<int> &colours, int node, int col)
{
    queue<pair<int, int> > q;
    q.push(make_pair(node, col));
    while (!q.empty())
    {
        node = q.front().first;
        col = q.front().second;
        q.pop();
        for (int i = 0; i < edges[node].size(); i++)
        {
            if (colours[edges[node][i]] == -1)
            {
                colours[edges[node][i]] = !col;
                q.push(make_pair(edges[node][i], !col));
            }
            else if (colours[edges[node][i]] == col)
            {
                return false;
            }
        }
    }
    return true;
}
void bipartite(vector<vector<int> > &edges)
{
    vector<int> colours(edges.size(), -1);
    for (int i = 1; i < edges.size(); i++)
    {
        if (colours[i] == -1)
        {
            colours[i] = 0;
            // if (!checkBipartiteDFS(edges, colours, i, 0))
            if (!checkBipartiteBFS(edges, colours, i, 0))
            {
                cout << "Not Bipartite";
                return;
            }
        }
    }
    cout << "Bipartite";
}
void toposortHelper(vector<vector<int> > &edges, vector<bool> &visited, stack<int> &st, int i)
{
    for (int j = 0; j < edges[i].size(); j++)
    {
        if (!visited[edges[i][j]])
        {
            visited[edges[i][j]] = true;
            toposortHelper(edges, visited, st, edges[i][j]);
        }
    }
    st.push(i);
}
void toposort(vector<vector<int> > &edges) // applicable only for DAG (Directed Acyclic Graph)
{
    vector<bool> visited(edges.size(), false);
    stack<int> st;
    for (int i = 1; i < edges.size(); i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            toposortHelper(edges, visited, st, i);
        }
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}
void toposortBFS(vector<vector<int> > &edges) // Kahn' alhorithm
{
    vector<int> inDegree(edges.size(), 0);

    for (int i = 1; i < edges.size(); i++)
    {
        for (int j = 0; j < edges[i].size(); j++)
        {
            inDegree[edges[i][j]]++;
        }
    }
    queue<int> q;
    for (int i = 1; i < edges.size(); i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int j = 0; j < edges[node].size(); j++)
        {
            inDegree[edges[node][j]]--;
            if (inDegree[edges[node][j]] == 0)
            {
                q.push(edges[node][j]);
            }
        }
    }
}

void bfs0_1(vector<vector<pair<int, int> > > &edges, int source) // applicable for 0/n weights
{
    deque<pair<int, int> > dq;
    vector<int> dis(edges.size(), INT_MAX);
    dis[source] = 0;
    dq.push_front(make_pair(source, 0));
    while (!dq.empty())
    {
        int node = dq.front().first;
        int dist = dq.front().second;
        dq.pop_front();
        for (int i = 0; i < edges[node].size(); i++)
        {
            int adjNode = edges[node][i].first;
            int wt = edges[node][i].second;
            if (dist + wt < dis[adjNode])
            {
                dis[adjNode] = dist + wt;
                if (wt == 1)
                {
                    dq.push_back(make_pair(adjNode, dist + wt));
                }
                else
                {
                    dq.push_front(make_pair(adjNode, dist + wt));
                }
            }
        }
    }
    for (int i = 1; i < edges.size(); i++)
    {
        cout << dis[i] << " ";
    }
}

void djikstra(vector<vector<pair<int, int> > > &edges, int source) // applicable for any weights
{
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    vector<int> dis(edges.size(), INT_MAX);
    dis[source] = 0;
    pq.push(make_pair(0, source));
    while (!pq.empty())
    {
        int node = pq.top().second;
        int dist = pq.top().first;
        pq.pop();
        if (dis[node] <= dist) // check before using
            continue;
        for (int i = 0; i < edges[node].size(); i++)
        {
            int adjNode = edges[node][i].first;
            int wt = edges[node][i].second;
            if (dist + wt < dis[adjNode])
            {
                dis[adjNode] = dist + wt;
                pq.push(make_pair(dist + wt, adjNode));
            }
        }
    }
    for (int i = 1; i < edges.size(); i++)
    {
        cout << dis[i] << " ";
    }
}

class DSU
{
private:
    vector<int> parent, size, rank;

public:
    DSU(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            parent.push_back(i);
            size.push_back(1);
            rank.push_back(0);
        }
    }
    int findParent(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }
        // path compression -> (log n)
        // path compression and size -> O(4 x alpha)
        parent[node] = findParent(parent[node]);
        return parent[node];
    }
    void unionSize(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv)
        {
            return;
        }
        if (size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
    void unionRank(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv)
        {
            return;
        }
        if (rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else if (rank[pv] < rank[pu])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};

struct edge
{
    int u, v, wt;
    edge(int _u, int _v, int _wt)
    {
        u = _u;
        v = _v;
        wt = _wt;
    }
};

bool comp(edge &e1, edge &e2)
{
    return e1.wt < e2.wt;
}

int kruskal(int n, vector<edge> &edges)
{
    sort(edges.begin(), edges.end(), comp);

    DSU dsu(n);
    int cost = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int wt = edges[i].wt;
        if (dsu.findParent(u) != dsu.findParent(v))
        {
            dsu.unionSize(u, v);
            cost += wt;
        }
    }
    return cost;
}

int main()
{
    int n, m, u, v, w;
    cin >> n >> m;
    vector<vector<int> > edges(n + 1);
    // vector<vector<pair<int, int> > > edges(n+1);    // for weighted graphs
    while (m--)
    {
        cin >> u >> v;
        edges[u].push_back(v);
        // edges[v].push_back(u);              // only for undirected graph
        // cin >> w;                           // for weighted graphs
        // edges[u].push_back(make_pair(v, w));
        // edges[v].push_back(make_pair(u, w));
    }
    // printGraph(edges);
    // dfsGraph(edges);
    // bfsGraph(edges);
    // dfsCheckCycle(edges);
    // bfsCheckCycle(edges);
    // dfsCheckCycleDG(edges);
    // bipartite(edges);
    // toposort(edges);
    // toposortBFS(edges);
    // bfs0_1(edges, 1);
    return 0;
}
