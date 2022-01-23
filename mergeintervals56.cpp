#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int j = 0;
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            vector<int> next = intervals[i];
            vector<int> prev = ans[j];
            if (next[0] <= prev[1]) {
                ans[j][1] = max(next[1], prev[1]);
            } else {
                j++;
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};