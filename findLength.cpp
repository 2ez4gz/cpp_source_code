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
int findLength(vector<int> &nums1, vector<int> &nums2) {
  int n = nums1.size();
  int m = nums2.size();
  int res = 0;
  vector<vector<int>> dp(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    if (nums1[i] == nums2[0])
      dp[i][0] = 1;
  }

  for (int j = 0; j < m; ++j) {
    if (nums1[0] == nums2[j])
      dp[0][j] = 1;
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      if (nums1[i] == nums2[j])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      res = max(res, dp[i][j]);
    }
  }
  return res;
}
int main() {
  vector<int> nums1 = {1, 2, 3, 2, 1};
  vector<int> nums2 = {3, 2, 1, 4};
  cout << findLength(nums1, nums2);
}