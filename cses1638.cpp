#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int M = 1e9 + 7;
    string s[n][n];
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>s[i][j];
        }
    }
    cout<< %M<<'\n';
    return  0;
}
