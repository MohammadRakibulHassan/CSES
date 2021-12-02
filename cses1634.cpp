#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n , x;
    cin>>n>>x;
    vector<int> coin(n);
    for(int &i : coin) cin>>i;
    vector<int> minC(x+1 , 1e9);
    minC[0] = 0;
    for(int i = 1 ; i <= x ; i++){
        for(int j = 0 ; j < n ; j++){
            if(i - coin[j] >= 0){
                minC[i] = min(minC[i] , minC[i - coin[j]] + 1);
            }
        }
    }
    cout<<(minC[x] == 1e9 ? -1 : minC[x])<<'\n';
    return 0;
}
