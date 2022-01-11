    
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 1) return "";
        int st=0, e=0;
        for (int i = 0; i < s.length(); i++) {
            int len1 = expand(s, i, i);
            int len2 = expand(s, i, i+1);
            int len = max(len1, len2);
            if (len > e - st + 1) {
                st = i - (len - 1)/2;
                e = i + len/2;
            }
        }
        return s.substr(st, e - st + 1);
    }
    
    int expand(string s, int left, int right) {
        int l = left, r = right;
        while (l >= 0 && r < s.length() && s.at(l) == s.at(r)) {
            l--; r++;
        }
        return r-l-1;
    }
};