//
// Created by jojo on 2/23/23.
//

#include <iostream>
#include <vector>
#include <stack>


using namespace std;
vector<string> res;
int count;
vector<string> list;


bool is_valid(string s, int i, int j) {
    if (i > j) return false;
    if (s[i] == '0' && i != j) return false;
    int num = stol(s.substr(i, j - i + 1));
    if (num > 255 || num < 0) return false;
    return true;
}

void find_path(string s, int start) {
    if (count == 3) {
        if (is_valid(s, start, s.size() - 1)) {
            string tmp = "";
            for (auto str: list) {
                tmp += str;
                tmp += ".";
            }
            tmp += s.substr(start, s.size() - start);
            res.push_back(tmp);
        }
        return;
    }

    for (int i = start; i < s.size(); ++i) {
        if (is_valid(s, start, i)) {
            list.push_back(s.substr(start, i - start + 1));
            count++;
            find_path(s, i + 1);
            count--;
            list.pop_back();
        }else {
            break;
        }
    }
}

vector<string> restoreIpAddresses(string s) {
    if (s.size() == 0) return res;
    find_path(s, 0);
    return res;
}
int main()
{
    string s ="2736786374048";
    vector<string> res = restoreIpAddresses(s);
    for (auto& str: res) {
        cout << str << " ";
    }

}