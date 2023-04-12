//
// Created by jojo on 2/23/23.
//

#include <algorithm>
#include <iostream>
#include <numeric>
#include <stack>
#include <vector>

using namespace std;

int findTargetSumWays(vector<int> &nums, int target) {
  int sum = accumulate(nums.begin(), nums.end(), 0);
  if (sum < target)
    return 0;
  int bag = (sum - target) / 2;

  vector<int> dp(bag + 1);
  dp[0] = 1;
  for (int i = 0; i < nums.size(); ++i) {
    for (int j = bag; j >= nums[i]; --j) {
      dp[j] += dp[j - nums[i]];
    }
    for (auto ele : dp) {
      cout << ele << " ";
    }
    cout << endl;
  }

  return dp[bag];
}
int main() {
  vector<int> vec = {7, 9, 3, 8, 0, 2, 4, 8, 3, 9};
  auto res = findTargetSumWays(vec, 0);
}