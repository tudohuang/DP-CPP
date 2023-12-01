/*********
ref: https://judge.tcirc.tw/ShowProblem?problemid=d066
內容
小朋友玩上樓梯遊戲，每一步可以往上走一階或兩階，開始位置在第 0 階，從第一階開始每階都有一個數字，踩在第 i 階，分數就要扣第 i 階的數字，

請問走到第 n 階的最少的扣分是多少。

輸入說明
第一行是正整數 n 。

第二行有 n 個正整數，依序代表第 1 階開始的數字，

數字間以空白隔開。 n≤1e5 ，每階的數字不超過 1e4 。

輸出說明
走到第 n 階的最小總扣分。

範例輸入 #1
8
2 1 1 7 3 2 9 2
範例輸出 #1
9

範例輸入 #2
5
1 2 3 1 5
範例輸出 #2
8
**********/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> cost(n + 1);
    vector<int> dp(n + 1);

    // 讀入每一階的分數
    for(int i = 1; i <= n; ++i) {
        cin >> cost[i];
    }

    // 初始化 dp 陣列
    dp[0] = 0; // 開始位置沒有扣分
    dp[1] = cost[1]; // 第一階只有一種走法

    // 計算到達每一階的最小扣分
    for(int i = 2; i <= n; ++i) {
        dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    }

    // 輸出到達第 n 階的最小扣分
    cout << dp[n] << endl;

    return 0;
}
