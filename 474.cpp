//
// Created by jojo on 2/23/23.
//

#include <algorithm>
#include <iostream>
#include <numeric>
#include <stack>
#include <vector>

using namespace std;

int findMaxForm(vector<string> &strs, int m, int n) {
  vector<pair<int, int>> zeroAndOne;
  for (auto &str : strs) {
    pair<int, int> pr;
    for (auto c : str) {
      if (c == '0') {
        pr.first++;
      } else {
        pr.second++;
      }
    }
    zeroAndOne.push_back(pr);
  }
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

  for (int i = 0; i < zeroAndOne.size(); ++i) {
    auto [z, o] = zeroAndOne[i];
    for (int j = m; j >= z; --j) {
      for (int k = n; k >= o; --k) {
        dp[j][k] = max(dp[j][k], dp[j - z][k - o] + 1);
      }
    }
  }

  return dp[m][n];
}
int main() {
  vector<string> strs = {"10", "0001", "111001", "1", "0"};
  auto res = findMaxForm(strs, 5, 3);
  cout << res;
}