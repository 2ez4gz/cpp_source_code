//
// Created by jojo on 2/23/23.
//

#include <algorithm>
#include <iostream>
#include <numeric>
#include <stack>
#include <vector>

using namespace std;

int lastStoneWeightII(vector<int> &stones) {
  sort(stones.begin(), stones.end());
  int sum = accumulate(stones.begin(), stones.end(), 0);
  int target = sum / 2;
  vector<int> dp(target + 1);

  for (int i = 0; i < stones.size(); ++i) {
    for (int j = target; j >= stones[i]; --j) {
      dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
    }
    for (auto ele : dp) {
      cout << ele << " ";
    }
    cout << endl;
  }

  return sum - dp[target] * 2;
}
int main() {
  vector<int> vec = {2, 7, 4, 1, 8, 1};
  auto res = lastStoneWeightII(vec);
}