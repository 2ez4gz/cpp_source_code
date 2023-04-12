//
// Created by jojo on 2/23/23.
//

#include <algorithm>
#include <climits>
#include <iostream>
#include <numeric>
#include <stack>
#include <unordered_set>
#include <vector>

using namespace std;

template <class T> void print_dp(vector<T> &dp) {
  for (auto ele : dp) {
    cout << ele << " ";
  }
  cout << endl;
}
bool wordBreak(string s, vector<string> &wordDict) {
  unordered_set<string> us(wordDict.begin(), wordDict.end());

  vector<bool> dp(s.size() + 1, false);
  dp[0] = true;
  for (int i = 0; i <= s.size(); ++i) {
    for (int j = 0; j < i; ++j) {
      string str = s.substr(j, i - j);
      if (us.find(str) != us.end() && dp[j]) {
        dp[i] = true;
      }
    }
  }
  return dp[s.size()];
}

int main() {
  string s = "leetcode";
  vector<string> wordDict = {"leet", "code"};
  wordBreak(s, wordDict);
}