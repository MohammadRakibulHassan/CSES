#include<bits/stdc++.h>
using namespace std;
const int dr[] = {0 , 1 , 0 , -1};
const int dc[] = {1 , 0 , -1 , 0};
const int mx = 1002;
string s[mx];
bool vis[mx][mx];
int n , m;
void ff(int r , int c)
{
    stack<pair<int , int>> f;
    f.push({r , c});
    while(!f.empty()){
        r = f.top().first;
        c = f.top().second;
        f.pop();
        if(r >= n || r < 0 || c < 0 || c >= m || s[r][c] == '#' || vis[r][c])
            continue;
        vis[r][c] = 1;
        for(int i = 0 ; i < 4 ; i++){
            f.push({r + dr[i] , c + dc[i]});
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i = 0 ; i < n ; i++){
        cin>>s[i];
    }
    int cont  = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(s[i][j] == '.' && !vis[i][j]){
                ff ( i , j );
                cont++;
            }
        }
    }
    cout<<cont<<'\n';
    return 0;
}
