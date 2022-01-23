#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//Sliding window solution
//First expand until max with end, then slow increase start to make window just nice
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> alphaCount(26, 0);
        int maxLength = 0, maxCount = 0, start = 0, end = 0;
        for(; end < s.size(); end++) {
            maxCount = max(maxCount, ++alphaCount[s.at(end) - 'A']);
            while (end - start + 1 - maxCount > k) {
                --alphaCount[s.at(start) - 'A'];
                start++;
            }
            maxLength = max(maxLength, end - start + 1);
        }
        return maxLength;
    }
};