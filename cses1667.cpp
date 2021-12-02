#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n , m;
    cin>>n>>m;
    vector<int> dist(n+1 , INT_MAX) , par(n+1);
    vector<vector<int>> adj(n+1);
    for(int i = 0 ; i < m ;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    par[1] = 1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int u : adj[v]){
            if(dist[u] == INT_MAX){
                dist[u] = dist[v] + 1;
                q.push(u);
                par[u] = v;
            }
        }
    }
    if(dist[n] == INT_MAX)
        cout<<"IMPOSSIBLE\n";
    else{
        cout<<dist[n] + 1<<'\n';
        vector<int> path{n};
        while(path.back() != 1){
            path.push_back(par[path.back()]);
        }
        reverse(path.begin() , path.end());
        for(int x : path)
            cout<<x<<" ";
    }
    return 0;
}
