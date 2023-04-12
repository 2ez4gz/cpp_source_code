//
// Created by jojo on 4/11/23.
//
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> heights(N);
  for (int i = 0; i < N; ++i) {
    cin >> heights[i];
  }

  vector<int> bigger_path(N, 1);
  vector<int> smaller_path(N, 1);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < i; ++j) {
      if (heights[j] < heights[i])
        bigger_path[i] = max(bigger_path[i], bigger_path[j] + 1);
    }
  }
  for (int i = N - 1; i >= 0; --i) {
    for (int j = N - 1; j > i; --j) {
      if (heights[j] < heights[i])
        smaller_path[i] = max(smaller_path[i], smaller_path[j] + 1);
    }
  }
  int max = 0;
  for (int i = 0; i < N; ++i) {
    if (bigger_path[i] + smaller_path[i] > max)
      max = bigger_path[i] + smaller_path[i];
  }
  cout << N - max + 1;
}
// 64 位输出请用 printf("%lld")