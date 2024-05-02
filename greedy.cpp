#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

int prims(int v, vector<vector<int>> adj[], vector<pair<int, pair<int, int>>>& nades) {
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    vector<int> vis(v, 0);
    pq.push({0, {0, -1}}); // Start with node 0 and its parent -1
    int sum = 0;
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int node = it.second.first;
        int parent = it.second.second;
        int wt = it.first;
        if (vis[node] == 1) {
            continue;
        }
        vis[node] = 1;
        if (parent != -1) { // Exclude the initial dummy edge
            nades.push_back({wt, {parent, node}});
            sum += wt; // Add the weight of the edge to the sum
        }
        for (auto it : adj[node]) {
            int adjnode = it[0];
            int edw = it[1];
            if (!vis[adjnode]) {
                pq.push({edw, {adjnode, node}});
            }
        }
    }
    return sum;
}

int main() {
    int v, e;
    cout << "Enter the number of vertices and edges: ";
    cin >> v >> e;

    vector<vector<int>> adj[v];

    cout << "Enter the edges and their weights in format (u v weight):" << endl;
    for (int i = 0; i < e; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight}); // Assuming undirected graph
    }

    vector<pair<int, pair<int, int>>> nades; // Vector to store MST edges (weight, (parent, child))
    int minCost = prims(v, adj, nades);

    cout << "Minimum Cost Spanning Tree: " << minCost << endl;
    cout << "Edges in the Minimum Spanning Tree:\n";
    for (auto edge : nades) {
        cout << edge.second.first << " -- " << edge.second.second << " (Weight: " << edge.first << ")" << endl;
    }

    return 0;
}
/*
Enter the number of vertices and edges: 5 6
Enter the edges and their weights in format (u v weight):
0 1 2
0 3 6
1 3 8
1 4 5
1 2 3
2 4 7
Minimum Cost Spanning Tree: 16*/
