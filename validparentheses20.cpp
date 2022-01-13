#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            char c = s.at(i);
            if (c == '{' || c == '[' || c == '(') {
                st.push(c);
            } else if (st.empty() || (!matches(st.top(), c))) {
                return false;
            } else {
                st.pop();
            }
        }
        return st.empty();
    }

    bool matches (char a, char b) {
        if (a == '{' && b == '}') return true;
        if (a == '[' && b == ']') return true;
        if (a == '(' && b == ')') return true;
        return false;
    }
};