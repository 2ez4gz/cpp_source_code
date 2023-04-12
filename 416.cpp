//
// Created by jojo on 2/23/23.
//

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
bool canPartition(vector<int> &nums) {
  int sum = 0;
  for (auto num : nums) {
    sum += num;
  }
  if (sum % 2 != 0)
    return false;
  sort(nums.begin(), nums.end());
  vector<int> dp(sum / 2 + 1, 0);
  for (int i = 0; i < nums.size(); ++i) {
    for (int j = dp.size() - 1; j >= nums[i]; --j) {
      dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
    }
    for (auto ele : dp) {
      cout << ele << " ";
    }
    cout << endl;
    if (dp[sum / 2] == sum / 2)
      return true;
  }

  return false;
}
int main() {
  vector<int> vec = {1, 2, 5};
  auto res = canPartition(vec);
}