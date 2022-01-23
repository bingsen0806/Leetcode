#include <string>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        if (s.length() < 1) return 0;
        int ans = expand(s,0,0); //which is 1
        for (int i = 1; i < s.length(); i++) {
            ans += expand(s, i-1, i);
            ans += expand(s, i, i);
        }
        return ans;
    }
    
    int expand(string s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.length() && s.at(left) == s.at(right)) {
            left--;right++;count++;
        }
        return count;
    }
};