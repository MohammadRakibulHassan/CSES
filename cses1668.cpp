#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int mx = 2e5+10;
int m , n;
bool vis[mx] , col[mx] , bad = false;
vector<int> adj[mx];
void dfs(int s , bool x = false)
{
    vis[s] = 1;
    col[s] = x;
    for(int u : adj[s]){
        if(vis[u]) {
            if(col[u] == x) bad = 1;
        }
        else dfs(u , !x);
    }
}
int main()
{
    cin>>n>>m;
    for(int i = 0 ; i < m ; i++){
        int u , v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i = 1 ; !bad && i <= n ; i++) if(!vis[i]) dfs(i);
    if(bad){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    else{
    for(int i = 1 ; i <= n ; i++){
        if(col[i] == 0) cout<<2<<' ';
        else cout<<1<<' ';
    }
    }
    return 0;
}
