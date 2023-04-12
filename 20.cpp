//
// Created by jojo on 2/23/23.
//

#include <iostream>
#include <vector>
#include <stack>


using namespace std;
bool isValid(string s) {
    if (s.size() % 2 != 0) return false;
    stack<char> st;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ')') {
            if (st.empty() || st.top() != '(') return false;
            st.pop();
        }else if (s[i] == '}') {
            if (st.empty() || st.top() != '{') return false;
            st.pop();
        }else if ( s[i] == ']') {
            if (st.empty() || st.top() != '[') return false;
            st.pop();
        }else {
            st.push(s[i]);
        }
    }
    if (!st.empty()) return false;
    return true;
}
int main()
{
    string str = "()[]{}";
    cout << isValid(str) << endl;
}