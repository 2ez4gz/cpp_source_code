//
// Created by jojo on 2/23/23.
//

#include <algorithm>
#include <iostream>
#include <numeric>
#include <stack>
#include <vector>

using namespace std;

int combinationSum4(vector<int> &nums, int target) {
  sort(nums.begin(), nums.end());
  if (nums[0] > target)
    return 0;
  vector<unsigned long long> dp(target + 1);
  dp[0] = 1;
  for (int j = 0; j <= target; ++j) {
    for (int i = 0; i < nums.size(); ++i) {
      if (j < nums[i])
        continue;
      dp[j] += dp[j - nums[i]];
    }
    for (auto ele : dp) {
      cout << ele << " ";
    }
    cout << endl;
  }

  return dp[target];
}
int main() {
  vector<int> vec = {
      10,  20,  30,  40,  50,  60,  70,  80,  90,  100, 110, 120, 130, 140, 150,
      160, 170, 180, 190, 200, 210, 220, 230, 240, 250, 260, 270, 280, 290, 300,
      310, 320, 330, 340, 350, 360, 370, 380, 390, 400, 410, 420, 430, 440, 450,
      460, 470, 480, 490, 500, 510, 520, 530, 540, 550, 560, 570, 580, 590, 600,
      610, 620, 630, 640, 650, 660, 670, 680, 690, 700, 710, 720, 730, 740, 750,
      760, 770, 780, 790, 800, 810, 820, 830, 840, 850, 860, 870, 880, 890, 900,
      910, 920, 930, 940, 950, 960, 970, 980, 990, 111};
  auto res = combinationSum4(vec, 999);
}