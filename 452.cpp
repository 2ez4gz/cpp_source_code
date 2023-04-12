//
// Created by jojo on 2/23/23.
//

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int findMinArrowShots(vector<vector<int>> &points) {
  if (points.size() <= 1)
    return points.size();
  sort(points.begin(), points.end(), [](vector<int> v1, vector<int> v2) {
    return v1[0] == v2[0] ? v1[1] < v2[1] : v1[0] < v2[0];
  });
  vector<vector<int>> res;

  vector<int> v0 =
      points[0][1] >= points[1][0]
          ? vector<int>{points[1][0], min(points[0][1], points[1][1])}
          : points[0];
  res.push_back(v0);
  for (int i = 1; i < points.size(); ++i) {
    if (points[i][0] <= res.back()[1]) {
      res.back()[0] = points[i][0];
      res.back()[1] = min(res.back()[1], points[i][1]);
    } else {
      res.push_back(points[i]);
    }
  }

  return res.size();
}
int main() {
  vector<vector<int>> points = {{9, 12}, {1, 10}, {4, 11}, {8, 12},
                                {3, 9},  {6, 9},  {6, 7}};
  int res = findMinArrowShots(points);
  cout << res << endl;

  for (auto i : points) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}