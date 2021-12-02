#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n , x;
    cin>>n>>x;
    vector<int> coin(n);
    for(int i = 0 ; i < n ; i++) cin>>coin[i];
    vector<int> way(x+1 , 0);
    way[0] = 1;
    const int M = 1e9+7;
    for(int j = 0 ; j < n ; j++){
        for(int i = 1 ; i <= x ; i++){
            if(i >= coin[j])
                way[i] = (way[i] + way[i - coin[j]]) % M;
        }
    }
    cout<<way[x]<<'\n';
    return 0;
}
