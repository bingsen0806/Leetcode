#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++) v.push_back({nums[i], i});
        sort(v.begin(), v.end());
        int start = 0, end = n-1;
        while (start < end) {
            if (v[start].first + v[end].first == target) {
                return vector<int>{v[start].second, v[end].second};
            } else if (v[start].first + v[end].first < target) start++;
            else end--;
        }
        return vector<int>{-1,-1};
    }
    
};