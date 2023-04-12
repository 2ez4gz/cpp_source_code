

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    for (auto& num: nums) {
        mp[num]++;
    }
    auto cmp = [](pair<int,int> &a, pair<int,int> &b) {
        return a.second > b.second;
    };
    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);

    for (auto& [num, cnt]: mp) {
        if (pq.size() == k) {
            if (cnt < pq.top().second) continue;
            pq.pop();
        }
        pq.push(make_pair(num, cnt));
    }
    vector<int> res(pq.size());
    for (int i = pq.size() - 1; i>=0; --i) {
        res[i] = pq.top().first;
        pq.pop();
    }

    return res;
}

int main()
{
    vector<int> vec = {1,1,1,2,2,3};
    int k = 2;

    auto res = topKFrequent(vec, k);

    for (auto& i: res) {
        cout << i << " ";
    }
}