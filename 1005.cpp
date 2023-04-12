//
// Created by jojo on 2/23/23.
//

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int largestSumAfterKNegations(vector<int> &nums, int k) {
  sort(nums.begin(), nums.end(), [](int a, int b) { return abs(a) > abs(b); });
  for (int i = 0; i < nums.size(); ++i) {
    if (nums[i] < 0 && k != 0) {
      k--;
      nums[i] *= -1;
    }
  }
  if (k % 2 != 0) {
    nums[nums.size() - 1] *= -1;
  }

  int res = 0;
  for (auto i : nums) {
    cout << i << " ";
    res += i;
  }
  return res;
}
int main() {
  vector<int> vec{4, -5, 4, -5, 9, 4, 5};
  int res = largestSumAfterKNegations(vec, 1);
  cout << res << endl;
}