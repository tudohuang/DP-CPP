/************
ref : https://cses.fi/problemset/task/1634
************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<int> dp(x + 1, 1e9);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= x; j++) {
            dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
    }

    if (dp[x] == 1e9) {
        cout << "-1" << endl;
    } else {
        cout << dp[x] << endl;
    }

    return 0;
}
