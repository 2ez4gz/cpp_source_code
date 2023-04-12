//
// Created by jojo on 2/23/23.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;
void trim(string &s)
{

    if( !s.empty() )
    {
        s.erase(0,s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
    }

}
string reverseWords(string s) {
    vector<pair<int,int>> vecs;
    trim(s);
    int i = s.size () - 1;
    while (i >=0) {
        while (i >=0 && s[i] == ' ') --i;
        if (s[i] != ' ') {
            int j = i;
            while (i >=0 && s[i] != ' ') --i;
            vecs.emplace_back(i + 1, j);
        }
    }

    string res = "";
    for (auto& vec: vecs) {
        auto sub = s.substr(vec.first, vec.second - vec.first + 1);
        res += sub;
        res += " ";
    }
    res.erase(res.end() - 1);
    return res;
}
int main()
{
    string s = "shky i s blue";
    cout << reverseWords(s) <<endl;
}