//
// Created by jojo on 2/20/23.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> res;
vector<int> path;

void findPath(vector<int>& nums, int start) {
    if (path.size() > 1) res.push_back(path);
    int used[201] = {0};
    for (int i = start; i < nums.size(); ++i) {
        if (used[nums[i] + 100]) continue;
        if (path.empty() || nums[i] >= path.back()) {
            path.push_back(nums[i]);
            used[nums[i] + 100] += 1;
            findPath(nums, i + 1);
            path.pop_back();

        }

    }
}
vector<vector<int>> findSubsequences(vector<int>& nums) {
    if (nums.size() == 0) return res;
    findPath(nums, 0);
    return res;
}

void print2Dvector(vector<vector<int>> vecs) {
    for(auto &vec: vecs) {
        for(auto &ele: vec) {
            cout << ele << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<int> vec{4, 6, 7, 7};
    auto res = findSubsequences(vec);
    print2Dvector(res);

}