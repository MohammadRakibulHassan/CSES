#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define PB push_back
#define F first
#define S second

const ll INF = 1e18;
const ll mx = 2*10e5+1;
ll dist[mx];
vector<pii> adj[mx];

void dijk(ll s , ll n)
{
    for(ll i = 0 ; i <= n ; i++) dist[i] = INF;
    dist[s] = 0;
    priority_queue < pll , vector<pll> , greater <pll> > pq;
    pq.push( {0 , s} );
    while(!pq.empty()){
        ll u = pq.top().S;
        ll c = pq.top().F;
        pq.pop();
        if(dist[u] < c)
            continue;
        for(auto x : adj[u]){
            ll v = x.F;
            ll w = x.S;
            if(c + w < dist[v]){
                dist[v] = c + w;
                pq.push({dist[v] , v});
            }
        }
    }

}
int main()
{
    ll n, m;
    cin>>n>>m;
    for(ll i = 0 ; i < m ; i++){
        ll a, b, c;
        cin>>a>>b>>c;
        adj[a].PB({b , c});
        ///adj[b].PB({a , c});
    }
    dijk(1 , n);
    for(ll i = 1 ; i <= n ; i++)
        cout<<dist[i]<<" ";
    return 0;
}
