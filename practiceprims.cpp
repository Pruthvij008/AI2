#include<bits/stdc++.h>
using namespace std;

int prims(vector<vector<int>>adj[],int v,vector<pair<int,int>>&nades)
{
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    vector<int>vis(v,0);

    pq.push({0,{0,-1}});
    vis[0]=1;
        int sum=0;
    while(!pq.empty())
    {
        int node=pq.top().second.first;
        int pnode=pq.top().second.second;
        int wt=pq.top().first;
        if(vis[node]==1)
        {
            continue;
        }
        vis[node]=1;

        pq.pop();

        if(pnode!=-1)
        {
            nades.push_back({node,pnode});
            sum+=wt;
        }
        for(auto it:adj[node])
        {
            int adjacentnode=it[0];
            int adwt=it[1];
            if(!vis[adjacentnode])
            {
                pq.push({adwt,{adjacentnode,node}});
            }
        }

    }
    return sum;

}