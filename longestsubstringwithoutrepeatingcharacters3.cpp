#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

//Sliding Window
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> alphaBool;
        int start = 0, end = 0, maxLength = 0;
        for(; end < s.size(); end++) {
            if (alphaBool.find(s.at(end)) != alphaBool.end()) {
                while(s.at(start) != s.at(end)) {
                    alphaBool.erase(s.at(start));
                    start++;
                }
                start++;
            } else {
                alphaBool.insert(s.at(end));
            }
            maxLength = max(maxLength, end - start + 1);
        }
        return maxLength;
    }
};