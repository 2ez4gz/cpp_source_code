//
// Created by jojo on 2/23/23.
//

#include <algorithm>
#include <iostream>
#include <numeric>
#include <stack>
#include <vector>

using namespace std;

int longestPalindromeSubseq(string s) {
  int n = s.size();
  vector<vector<int>> dp(n, vector<int>(n, false));
  for (int i = n - 1; i >= 0; --i) {
    for (int j = i; j < n; ++j) {
      if (s[i] == s[j]) {
        if (j - i == 0) {
          dp[i][j] = 1;
        } else if (j - i == 1) {
          dp[i][j] = 2;
        } else {
          dp[i][j] = dp[i + 1][j - 1] + 2;
        }
      } else {
        dp[i][j] = max(dp[i + 1][j - 1], max(dp[i][j - 1], dp[i + 1][j]));
      }
    }
  }
  return dp[0].back();
}
int main() {
  string s = "bbbab";
  cout << longestPalindromeSubseq(s);
}