//
// Created by jojo on 2/23/23.
//

#include <algorithm>
#include <iostream>
#include <numeric>
#include <stack>
#include <vector>

using namespace std;

template <class T> void print_dp(vector<T> &dp) {
  for (auto ele : dp) {
    cout << ele << " ";
  }
  cout << endl;
}
int maxProfit(vector<int> &prices) {
  vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
  dp[0][0] = -prices[0];
  dp[0][2] = -prices[0];

  for (int i = 1; i < prices.size(); ++i) {
    dp[i][0] = max(dp[i - 1][0], -prices[i]);
    dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i][0]);
    dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] - prices[i]);
    dp[i][3] = max(dp[i - 1][3], prices[i] + dp[i][2]);
  }

  return dp.back().back();
}
int main() {
  vector<int> vec = {1, 2, 4, 2, 5, 7, 2, 4, 9, 0};
  cout << maxProfit(vec);
}