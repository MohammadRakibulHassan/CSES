#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n , step = 0;
    cin>>n;
    while(n){
        int temp = n , tosub = 0;
        while(temp){
            tosub = max(tosub , temp % 10);
            temp = temp / 10;
        }
        n = n - tosub;
        step++;
    }
    cout<<step<<'\n';
    return 0;
}
