/************
https://judge.tcirc.tw/ShowProblem?problemid=d067
楊鐵心帶著義女穆念慈當街頭的武術表演者，他接到許多的邀約，每天均有一場。每一場表演都可以得到某些金額的報酬，但是武術表演很辛苦，無法連續兩天都進行表演，

請你寫一支程式協助他決定應該接受那些表演以得到最大的報酬。

輸入說明
第一行是正整數 n。

第二行有 n 個非負整數，依序代表第 1 天開始每天邀約報酬，數字間以空白隔開。

n≤1e5 ，每天酬勞不超過 10000 。

輸出說明
最大可能獲得的總酬勞。

範例輸入 #1
5
1 2 3 1 5
範例輸出 #1
9
範例輸入 #2
8
2 1 1 7 3 2 9 2
範例輸出 #2
18
*************/
#include<bits/stdc++.h>
#define ct cout 
#define cn cin
#define import(std) using namespace std;
#define it int
#define fl float
#define dl doule
#define ch char
#define ll long
#define rep(i,n) for(int i;i<n;i++)
#define elif else if
#define main int main()

import(std)
main {
    it n,a;
    cn >> n;
    vector<int> cost(n + 1);
    vector<int> dp(n + 1);
    for(int i=1;i<=n;i++){
    	cn>>cost[i];
	}
	dp[0] = 0;
    dp[1] = cost[1];
	for(int i = 2; i <= n; ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + cost[i]);
    }

    cout << dp[n]<< endl;

    return 0;
}
