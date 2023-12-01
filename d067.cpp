/************
ref: https://judge.tcirc.tw/ShowProblem?problemid=d067
*************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> cost(n + 1);
    vector<int> dp(n + 1);

    // 讀入每天的報酬
    for(int i = 1; i <= n; ++i) {
        cin >> cost[i];
    }

    // 初始化 dp 陣列
    dp[0] = 0;
    dp[1] = cost[1]; 

    // 計算最大收入
    for(int i = 2; i <= n; ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + cost[i]);
    }

    // 輸出最大可能獲得的總酬勞
    cout << dp[n] << endl; 
    return 0;
}

