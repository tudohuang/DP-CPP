/********
ref: https://atcoder.jp/contests/dp/tasks/dp_c
********/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int dp[n+1][3];
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=n; ++i){
        int a,b,c;
        cin>>a>>b>>c;
        if(i==1){
            dp[i][0]=a;
            dp[i][1]=b;
            dp[i][2]=c;
        }
        else{
            dp[i][0]=max(dp[i-1][1],dp[i-1][2])+a;
            dp[i][1]=max(dp[i-1][0],dp[i-1][2])+b;
            dp[i][2]=max(dp[i-1][0],dp[i-1][1])+c;
        }
    }
    cout<<max({dp[n][0],dp[n][1],dp[n][2]})<<'\n';
}
