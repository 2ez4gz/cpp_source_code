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
int rob_range(vector<int> &nums, int start, int end) {

  if (end - start <= 0)
    return nums[start];
  if (end - start <= 1)
    return max(nums[start], nums[end]);
  vector<int> dp(nums.size() + 1);
  dp[start] = nums[start];
  dp[start + 1] = max(nums[start], nums[start + 1]);
  for (int i = start + 2; i <= end; ++i) {
    dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
  }

  return dp[end];
}
int rob(vector<int> &nums) {
  if (nums.size() == 0)
    return 0;
  if (nums.size() == 1)
    return nums[0];
  return max(rob_range(nums, 0, nums.size() - 2),
             rob_range(nums, 1, nums.size() - 1));
}

int main() {

  vector<int> nums = {200, 3, 140, 20, 10};
  cout << rob(nums);
}