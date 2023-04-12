//
// Created by jojo on 2/23/23.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
  int m = obstacleGrid.size();
  int n = obstacleGrid[0].size();
  vector<vector<int>> dp(m, vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    if (obstacleGrid[0][i] == 1) {
      while (i < n) {
        dp[0][i] = 0;
        ++i;
      }
      break;
    }
    dp[0][i] = 1;
  }
  for (int i = 0; i < m; ++i) {
    if (obstacleGrid[i][0] == 1) {
      while (i < m) {
        dp[i][0] = 0;
        ++i;
      }
      break;
    }
    dp[i][0] = 1;
  }
  for (int i = 1; i < m; ++i) {
    for (int j = 1; j < n; ++j) {
      if (obstacleGrid[i][j] == 1) {
        dp[i][j] = 0;
        continue;
      }
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
  }

  return dp[m - 1][n - 1];
}
int main() {
  vector<vector<int>> vec = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  int res = uniquePathsWithObstacles(vec);
  cout << res;
}