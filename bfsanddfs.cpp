#include <bits/stdc++.h>
using namespace std;

// Function prototypes
vector<int> bfs(int v, vector<int> adj[]);
vector<int> dfs(int V, vector<int> adj[]);
void helpingdfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &ls);

int main() {
    int v, e;
    cout << "Enter the number of vertices and edges: ";
    cin >> v >> e;

    vector<int> adj[v];

    cout << "Enter the edges in format (u v):" << endl;
    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Assuming undirected graph
    }

    // Menu
    cout << "Select Traversal Method:\n";
    cout << "1. BFS Traversal\n";
    cout << "2. DFS Traversal\n";
    int choice;
    cin >> choice;

    switch (choice) {
        case 1: {
            vector<int> bfsTraversal = bfs(v, adj);
            cout << "BFS Traversal starting from node 0: ";
            for (int node : bfsTraversal) {
                cout << node << " ";
            }
            cout << endl;
            break;
        }
        case 2: {
            vector<int> dfsTraversal = dfs(v, adj);
            cout << "DFS Traversal starting from node 0: ";
            for (int node : dfsTraversal) {
                cout << node << " ";
            }
            cout << endl;
            break;
        }
        default:
            cout << "Invalid choice!";
    }

    return 0;
}

vector<int> bfs(int v, vector<int> adj[]) {
    vector<int> vis(v + 1, 0);
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    vector<int> bfss;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfss.push_back(node);
        for (auto it : adj[node]) {
            if (!vis[it]) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfss;
}

vector<int> dfs(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    int start = 0;
    vector<int> ls;
    helpingdfs(start, adj, vis, ls);
    return ls;
}

void helpingdfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &ls) {
    vis[node] = 1;
    ls.push_back(node);
    for (auto it : adj[node]) {
        if (!vis[it]) {
            vis[it] = 1;
            helpingdfs(it, adj, vis, ls);
        }
    }
}


/*
Enter the number of vertices and edges: 6 7
Enter the edges in format (u v):
0 1
0 2
1 3
1 4
2 4
3 5
4 5
Select Traversal Method:
1. BFS Traversal
2. DFS Traversal
2
DFS Traversal starting from node 0: 0 1 3 5 4 2 

*/
