#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int currMax = (n-1)* min(height[l], height[r]);
        while (l < n && r >= 0 && l < r) {
            if (height[l] > height[r]) {
                r--;
            } else {
                l++;
            }
            int possibleMax = (r-l) * min(height[l], height[r]);
            if (possibleMax > currMax) {
                currMax = possibleMax;
            }
        }
        return currMax;
    }
};