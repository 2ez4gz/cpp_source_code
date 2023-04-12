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
int maxProfit(vector<int> &prices, int fee) {
  vector<vector<int>> dp(prices.size(), vector<int>(3));

  dp[0][0] = -prices[0];
  dp[0][1] = -fee;
  dp[0][2] = 0;
  for (int i = 1; i < prices.size(); ++i) {
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
    dp[i][1] = prices[i] + dp[i][0] - fee;
    dp[i][2] = max(dp[i - 1][2], dp[i][1]);
    for (auto d : dp) {
      print_dp(d);
    }
    cout << "------------" << endl;
  }

  return max(dp[prices.size() - 1][1], dp[prices.size() - 1][2]);
}
int main() {
  vector<int> vec = {4, 5, 2, 4, 3, 3, 1, 2, 5, 4};
  cout << maxProfit(vec, 1);
}