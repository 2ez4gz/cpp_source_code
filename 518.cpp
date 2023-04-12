//
// Created by jojo on 2/23/23.
//

#include <algorithm>
#include <iostream>
#include <numeric>
#include <stack>
#include <vector>

using namespace std;

int change(int amount, vector<int> &coins) {
  vector<int> dp(amount + 1);
  dp[0] = 1;
  for (int i = 0; i < coins.size(); ++i) {
    for (int j = 0; j <= amount; ++j) {
      if (j >= coins[i])
        dp[j] += dp[j - coins[i]];
    }
  }
  return dp[amount];
}
int main() {
  vector<int> coins = {1, 2, 5};
  auto res = change(5, coins);
  cout << res;
}