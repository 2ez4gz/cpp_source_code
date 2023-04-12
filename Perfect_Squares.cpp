//
// Created by jojo on 2/23/23.
//

#include <algorithm>
#include <climits>
#include <iostream>
#include <numeric>
#include <stack>
#include <vector>

using namespace std;

int numSquares(int n) {
  vector<int> bag;
  for (int i = 1; i * i <= n; ++i) {
    bag.push_back(i * i);
  }
  vector<unsigned long long> dp(n + 1, INT_MAX);
  dp[0] = 0;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j < bag.size(); ++j) {
      if (i >= bag[j]) {
        dp[i] = min(dp[i - bag[j]] + 1, dp[i]);
      } else {
        break;
      }
    }
    for (auto ele : dp) {
      cout << ele << " ";
    }
    cout << endl;
  }
  return dp[n];
}
int main() {
  int n = 12;
  cout << numSquares(n);
}