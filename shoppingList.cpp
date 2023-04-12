#include <iostream>
#include <vector>
using namespace std;
template <class T> void print_dp(vector<T> &dp) {
  for (auto ele : dp) {
    cout << ele << " ";
  }
  cout << endl;
}

int main() {
  int N, m;
  cin >> N >> m;
  N /= 10;
  vector<vector<int>> prices(m);
  for (auto &price : prices) {
    price.push_back(0);
  }
  vector<vector<int>> values(m);
  for (auto &value : values) {
    value.push_back(0);
  }
  for (int i = 0; i < m; ++i) {
    int v, p, q;
    cin >> v >> p >> q;
    v /= 10;
    if (q == 0) {
      prices[i][0] = v;
      values[i][0] = p;
    } else {
      prices[q - 1].push_back(v);
      values[q - 1].push_back(p);
    }
  }
  vector<vector<int>> dp(N + 1, vector<int>(m + 1));
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= m; ++j) {
      dp[i][j] =
          prices[j - 1][0] <= i
              ? max(dp[i][j - 1], dp[i - prices[j - 1][0]][j - 1] +
                                      prices[j - 1][0] * values[j - 1][0])
              : dp[i][j - 1];
      dp[i][j] = prices[j - 1][0] + prices[j - 1][1] <= i
                     ? max(dp[i][j],
                           dp[i - prices[j - 1][0] - prices[j - 1][1]][j - 1] +
                               prices[j - 1][0] * values[j - 1][0] +
                               prices[j - 1][1] * values[j - 1][1])
                     : dp[i][j];
      dp[i][j] = prices[j - 1][0] + prices[j - 1][2] <= i
                     ? max(dp[i][j],
                           dp[i - prices[j - 1][0] - prices[j - 1][2]][j - 1] +
                               prices[j - 1][0] * values[j - 1][0] +
                               prices[j - 1][2] * values[j - 1][2])
                     : dp[i][j];
      dp[i][j] =
          prices[j - 1][0] + prices[j - 1][1] + prices[j - 1][2] <= i
              ? max(dp[i][j], dp[i - prices[j - 1][0] - prices[j - 1][1] -
                                 prices[j - 1][2]][j - 1] +
                                  prices[j - 1][0] * values[j - 1][0] +
                                  prices[j - 1][1] * values[j - 1][1] +
                                  prices[j - 1][2] * values[j - 1][2])
              : dp[i][j];
    }
  }
  for (auto d : dp) {
    print_dp(d);
  }
  cout << dp[N][m] * 10;
}