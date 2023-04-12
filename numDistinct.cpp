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
int numDistinct(string s, string t) {
  int m = s.size();
  int n = t.size();

  vector<vector<uint64_t>> dp(n + 1, vector<uint64_t>(m + 1, 0));
  for (int j = 0; j <= m; ++j)
    dp[0][j] = 1;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (t[i - 1] == s[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
      } else {
        dp[i][j] = dp[i][j - 1];
      }
    }
  }
  return dp[n][m];
}
int main() {
  string s = "babgbag", t = "bag";
  cout << numDistinct(s, t);
}