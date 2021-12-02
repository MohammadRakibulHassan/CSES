#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
int main()
{
    int t;cin>>t;while(t--){
    int n;
    cin>>n;
    int dp[n+1] = {0};
    dp[0] = dp[1] = 1;
    for(int i = 2 ; i <= n ; i++){
        for(int j = 1 ; j <= 6 ; j++){
            if(i >= j) dp[i] = (dp[i] + dp[i - j]) % M ;
        }
    }
    cout<<dp[n]<<'\n';}
    return 0;
}
