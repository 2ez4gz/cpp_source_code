//
// Created by jojo on 2/23/23.
//

#include <iostream>
#include <vector>


using namespace std;
vector<int> get_next(string s) {
    vector<int> next(s.size());
    next[0] = 0;
    int j = 0;
    for (int i = 1; i < next.size(); ++i) {
        while (j > 0 && s[i] != s[j]) j = next[j - 1];
        if (s[i] == s[j]) j++;
        next[i] = j;
    }
    return next;
}
int strStr(string haystack, string needle) {
    if (needle.size() == 0) return 0;
    auto next = get_next(needle);
    int j = 0;
    for (int i = 0; i < haystack.size(); ++i) {
        while (j > 0 && haystack[i] != needle[j]) {
            j = next[j - 1];
        }
        if (haystack[i] == needle[j]) j++;
        if (j == needle.size()) return i - needle.size() + 1;
    }

    return -1;
}

int main()
{
//    string haystack = "sdbutsad", needle = "sad";
//    cout << strStr(haystack, needle) << endl;
    string needle = "aabacaabaa";
    auto vec = get_next(needle);
    for (auto v: vec) {
        cout << v << " ";
    }
}