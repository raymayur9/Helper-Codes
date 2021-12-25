#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
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

void toposortBFS(vector<vector<int> > &edges) // Kahn's alhorithm
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

void djikstra(vector<vector<pair<int, int> > > &edges, int source) // applicable for any non-negative weights
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

void dfsBridges(vector<vector<int> > &edges, vector<int> &in, vector<int> &low, int node, int parent, int &timer)
{
    in[node] = low[node] = timer;
    timer++;
    for (int i = 0; i < edges[node].size(); i++)
    {
        int adj = edges[node][i];
        if (adj == parent)
        {
            continue;
        }

        if (in[adj] != -1)
        {
            low[node] = min(low[node], low[adj]);
        }
        else
        {
            dfsBridges(edges, in, low, adj, node, timer);
            if (low[adj] > in[node])
            {
                cout << node << " -> " << adj << endl;
            }
            low[node] = min(low[node], low[adj]);
        }
    }
}
void bridges(vector<vector<int> > &edges)
{
    vector<int> in(edges.size(), -1), low(edges.size(), -1);
    int timer = 0;
    dfsBridges(edges, in, low, 1, -1, timer);
}

void bellmanFord(int n, vector<edge> &edges) // for negative cycles
{
    vector<int> dist(n + 1, INT_MAX);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < edges.size(); j++)
        {
            int u = edges[j].u;
            int v = edges[j].v;
            int wt = edges[j].wt;
            if (dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int wt = edges[i].wt;
        if (dist[u] + wt < dist[v])
        {
            dist[v] = dist[u] + wt;
            cout << "Exists a cycle\n";
            return;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
}

void dfsCutpoints(vector<vector<int> > &edges, vector<int> &in, vector<int> &low, int node, int parent, int &timer, set<int> &points)
{
    in[node] = low[node] = timer++;
    int children = 0;
    for (int i = 0; i < edges[node].size(); i++)
    {
        int adj = edges[node][i];
        if (adj == parent)
        {
            continue;
        }

        if (in[adj] != -1)
        {
            low[node] = min(low[node], low[adj]);
        }
        else
        {
            children++;
            dfsCutpoints(edges, in, low, adj, node, timer, points);
            if (low[adj] >= in[node] && parent != -1)
            {
                points.insert(node);
            }
            low[node] = min(low[node], low[adj]);
        }
    }
    if (parent == -1 && children > 1)
    {
        points.insert(node);
    }
}
void cutpoints(vector<vector<int> > &edges) // or articulation points
{
    vector<int> in(edges.size(), -1), low(edges.size(), -1);
    set<int> points;
    int timer = 0;
    for (int i = 1; i < edges.size(); i++)
    {
        if (in[i] == -1)
        {
            dfsCutpoints(edges, in, low, 1, -1, timer, points);
        }
    }
    for (set<int>::iterator it = points.begin(); it != points.end(); it++)
    {
        cout << *it << " ";
    }
}

void dfsSort(vector<vector<int> > &adj, vector<bool> &visited, int node, stack<int> &st)
{
    for (int i = 0; i < adj[node].size(); i++)
    {
        int adjNode = adj[node][i];
        if (!visited[adjNode])
        {
            visited[adjNode] = true;
            dfsSort(adj, visited, adjNode, st);
        }
    }
    st.push(node);
}
void revDFS(vector<vector<int> > &transpose, vector<bool> &visited, int node)
{
    cout << node << " ";
    for (int i = 0; i < transpose[node].size(); i++)
    {
        int adjNode = transpose[node][i];
        if (!visited[adjNode])
        {
            visited[adjNode] = true;
            revDFS(transpose, visited, adjNode);
        }
    }
}
void scc(vector<vector<int> > &adj) // Kosaraju's algo
{
    vector<bool> visited(adj.size(), false);
    stack<int> st;

    // stores in stack with decreasing order of out-time (from top to bottom)
    for (int i = 1; i < adj.size(); i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            dfsSort(adj, visited, i, st);
        }
    }

    // creating transpose graph
    vector<vector<int> > transpose(adj.size());
    for (int i = 1; i < adj.size(); i++)
    {
        visited[i] = false;
        for (int j = 0; j < adj[i].size(); j++)
        {
            transpose[adj[i][j]].push_back(i);
        }
    }

    // finding SCCs
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!visited[node])
        {
            visited[node] = true;
            revDFS(transpose, visited, node);
            cout << endl;
        }
    }
}

void dfsTarjan(vector<vector<int> > &adj, vector<bool> &visited, vector<bool> &onStack, vector<int> &in, vector<int> &low, stack<int> &st, int node, int &timer)
{
    in[node] = low[node] = timer;
    timer++;
    onStack[node] = true;
    st.push(node);

    for (int i = 0; i < adj[node].size(); i++)
    {
        int adjNode = adj[node][i];
        if (visited[adjNode] && onStack[adjNode])
        {
            low[node] = min(low[node], in[adjNode]);
        }
        else if (!visited[adjNode])
        {
            visited[adjNode] = true;
            dfsTarjan(adj, visited, onStack, in, low, st, adjNode, timer);
            if (onStack[adjNode])
            {
                low[node] = min(low[node], low[adjNode]);
            }
        }
    }

    if (in[node] == low[node])
    {
        int u;
        while (1)
        {
            u = st.top();
            st.pop();
            onStack[u] = false;
            cout << u << " ";
            if (u == node)
            {
                break;
            }
        }
        cout << '\n';
    }
}
void tarjan(vector<vector<int> > &adj)
{
    vector<bool> visited(adj.size(), false), onStack(adj.size(), false);
    vector<int> in(adj.size(), -1), low(adj.size(), -1);
    stack<int> st;
    int timer = 0;
    for (int i = 1; i < adj.size(); i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            dfsTarjan(adj, visited, onStack, in, low, st, i, timer);
        }
    }
}

bool dfsPrintCycle(vector<vector<int> > &edges, vector<bool> &visited, int node, int parent, vector<int> &ans)
{
    ans.push_back(node);
    for (int i = 0; i < edges[node].size(); i++)
    {
        if (!visited[edges[node][i]])
        {
            visited[edges[node][i]] = true;
            if (dfsPrintCycle(edges, visited, edges[node][i], node, ans))
            {
                return true;
            }
        }
        else if (edges[node][i] != parent)
        {
            ans.push_back(edges[node][i]);
            return true;
        }
    }
    ans.pop_back();
    return false;
}
void printCycle(vector<vector<int> > &edges)
{
    vector<bool> visited(edges.size(), false);
    vector<int> ans;
    for (int i = 1; i < edges.size(); i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            if (dfsPrintCycle(edges, visited, i, 0, ans))
            {
                cout << "YES\n";
                int sz = ans.size();
                vector<int> final;
                final.push_back(ans[sz - 1]);
                for (int i = sz - 2; i >= 0; i--)
                {
                    final.push_back(ans[i]);
                    if (ans[i] == ans[sz - 1])
                    {
                        break;
                    }
                }
                cout << final.size() << '\n';
                for (int j = 0; j < final.size(); j++)
                {
                    cout << final[j] << " ";
                }
                return;
            }
        }
    }
    cout << "NO";
}

void dfsLCA(vector<vector<int> > &adj, vector<int> &depth, vector<int> &parent, int node, int par)
{
    depth[node] = depth[par] + 1;
    parent[node] = par;
    for (int i = 0; i < adj[node].size(); i++)
    {
        if (adj[node][i] != par)
        {
            dfsLCA(adj, depth, parent, adj[node][i], node);
        }
    }
}
int lca(vector<vector<int> > &adj, vector<int> &depth, vector<int> &parent, int u, int v)
{
    if (depth[v] < depth[u])
    {
        swap(u, v);
    }
    int diff = depth[v] - depth[u];
    while (diff--)
    {
        v = parent[v];
    }
    if (u == v)
    {
        return u;
    }
    while (parent[u] != parent[v])
    {
        u = parent[u], v = parent[v];
    }
    return parent[u];
}

void dfsLCA2(vector<vector<int> > &adj, vector<int> &depth, vector<vector<int> > &parent, int node, int par)
{
    depth[node] = depth[par] + 1;
    parent[node][0] = par;
    for (int i = 0; i < adj[node].size(); i++)
    {
        if (adj[node][i] != par)
        {
            dfsLCA2(adj, depth, parent, adj[node][i], node);
        }
    }
}
void precomputeSparseMatrix(vector<vector<int> > &parent, int level)
{
    for (int i = 1; i < level; i++)
    {
        for (int node = 1; node < parent.size(); node++)
        {
            if (parent[node][i - 1] != -1)
            {
                parent[node][i] = parent[parent[node][i - 1]][i - 1];
            }
        }
    }
}
int lca2(vector<vector<int> > &adj, vector<int> &depth, vector<vector<int> > &parent, int level, int u, int v)
{
    if (depth[v] < depth[u])
    {
        swap(u, v);
    }
    int diff = depth[v] - depth[u];
    for (int i = 0; i < level; i++)
    {
        if ((diff >> i) & 1)
        {
            v = parent[v][i];
        }
    }

    if (u == v)
    {
        return u;
    }
    for (int i = level - 1; i >= 0; i--)
    {
        if (parent[u][i] != parent[v][i])
        {
            u = parent[u][i], v = parent[v][i];
        }
    }

    return parent[u][0];
}

int main()
{
    int n, m, u, v, w;
    cin >> n >> m;
    vector<vector<int> > edges(n + 1); // adjacency matrix
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
    // scc(edges);
    // tarjan(edges);

    // vector<int> depth(n+1, 0), parent(n+1);
    // dfsLCA(edges, depth, parent, 1, 0);
    // lca(edges, depth, parent, 4, 10);

    return 0;
}
