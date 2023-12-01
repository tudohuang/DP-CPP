/*********
ref: https://judge.tcirc.tw/ShowProblem?problemid=d066
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
