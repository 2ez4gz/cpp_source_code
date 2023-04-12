//
// Created by jojo on 2/23/23.
//

#include <iostream>
#include <vector>
#include <stack>


using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> q;
    for (int i = 0; i < k; i++) {
        while (!q.empty() && nums[i] >= nums[q.back()]) {
            q.pop_back();
        }
        q.push_back(i);
    }

    vector<int> res(nums.size() - k + 1);
    res[0] = nums[q.front()];
    for (int i = k; i < nums.size(); ++i) {
        if (q.front() <= i - k) q.pop_front();
        while (!q.empty() && nums[i] >= nums[q.back()]) {
            q.pop_back();
        }
        q.push_back(i);
        res[i - k + 1] = nums[q.front()];
    }

    return res;
}
int main()
{
    vector<int> nums = {1,3,1,2,0,5};
    int k = 3;

    auto res = maxSlidingWindow(nums, k);
    for (auto i: res) {
        cout << i << endl;
    }
}