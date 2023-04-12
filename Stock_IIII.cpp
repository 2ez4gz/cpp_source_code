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
int maxProfit(int k, vector<int> &prices) {
  vector<vector<int>> dp(prices.size(), vector<int>(1 + k * 2, 0));
  for (int i = 0; i < k; ++i) {
    dp[0][1 + 2 * i] = -prices[0];
  }
  for (int i = 1; i < prices.size(); ++i) {
    for (int j = 1; j < 2 * k + 1; ++j) {
      if (j % 2 != 0) {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1] - prices[i]);
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1] + prices[i]);
      }
    }
    for (auto d : dp) {
      print_dp(d);
    }
    cout << "~~~~~" << endl;
  }
  return dp.back().back();
}
int main() {
  vector<int> vec = {3, 3, 5, 1, 1, 4, 6, 4, 10};
  cout << maxProfit(3, vec);
}