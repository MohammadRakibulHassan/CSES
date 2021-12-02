#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n , x;
    cin>>n>>x;
    vector<int> c(n);
    for(int& i : c) cin>>i;
    vector<int> way(x+1 , 0);
    way[0] = 1;
    const int M = 1e9 + 7;
    for(int i = 1 ; i <= x ; i++){
        for(int j = 0 ; j < n ; j++){
            if(i >= c[j]){
                way[i] = (way[i] + way[i - c[j]]) % M;
            }
        }
    }
    cout<<way[x]<<'\n';
    return 0;
}
