#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int n , m , c;
const int MX = 1e5+1;
vector<int> adj[MX];
bool vis[MX];
int x[MX];
void dfs(int s)
{
    vis[s] = 1;
    for(int u : adj[s]){
        if(!vis[u]) dfs(u);
    }
}
int comp()
{
    int cont = 0;
    for(int i = 1 ; i <= n ; ++i){
        if(!vis[i]) {
            x[cont++] = i;
            dfs(i);
        }
    }
    return cont;
}
int main()
{
    cin>>n>>m;
    for(int i = 0 ; i < m ; ++i){
        int u , v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int temp = comp() - 1;
    cout<<temp<<'\n';
    for(int i = 1 ; i <= temp ; ++i)
        cout<<x[i-1]<<" "<<x[i]<<'\n';
    return 0;
}
