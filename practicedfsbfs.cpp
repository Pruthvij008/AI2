#include<bits/stdc++.h>
using namespace std;

vector<int>bfs(int V,vector<int>adj[])
{
    vector<int>vis(V,0);
    queue<int>q;
    vis[0]=1;
    q.push(0);
    vector<int>bf;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        bf.push_back(node);
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                vis[it]=1;
                q.push(it);
            }
        }
        
    }
    return bf;
}
void helpingdfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&ls)
{
    vis[node]=1;
    ls.push_back(node);
    for(auto it:adj[node])
    {
         if (!vis[it]) {
            vis[it] = 1;
            helpingdfs(it, adj, vis, ls);
        }
    }
}

vector<int>dfs(int V,vector<int>adj[])
{
    vector<int> vis(V, 0);
    int start = 0;
    vector<int> ls;
    helpingdfs(start, adj, vis, ls);
    return ls;
}

int main()
{
        int v, e;
    cout << "Enter the number of vertices and edges: ";
    cin >> v >> e;

    vector<int> adj[v];

    cout << "Enter the edges in format (u v):" << endl;
    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
     vector<int> bfsTraversal = bfs(v, adj);
      cout << "BFS Traversal starting from node 0: ";
            for (int node : bfsTraversal) {
                cout << node << " ";
            }
     vector<int> dfsTraversal = dfs(v, adj);
            cout << "DFS Traversal starting from node 0: ";
            for (int node : dfsTraversal) {
                cout << node << " ";
            }
}