#include<bits/stdc++.h>
using namespace std;
const int mx = INT_MAX;
int n ;
bool cycle = false;
bool vis[100001];
vector<int> ans;
vector<int> adj[100001];
void dfs(int v)
{
    for(int u : adj[v]){
        if(!vis[u]){
            vis[u] = 1;
            dfs(u);
        }
    }
    ans.push_back(v);
}
void tops()
{
    for(int i = 1 ; i <= n ; i++){
        if(!vis[i]){
            vis[i] = 1;
            dfs(i);
        }
    }
    reverse(begin(ans) , end(ans));
}
int main()
{
    int m;
    cin>>n>>m;
    for(int i = 1 ; i <= m ; ++i){
        int u , v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    tops();
    vector<int> indegre(n+1);
    for(int i = 1 ; i <= n ; i++){
        indegre[ans[i]] = i;
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j : adj[i])
            if(indegre[j] <= indegre[i]){
                cout<<"IMPOSSIBLE\n";
                exit(0);
            }
    }
    for(int r : ans)
        cout<<r<<" ";
    return 0 ;
}

