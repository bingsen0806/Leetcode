#include <algorithm>
#include <vector>
using namespace std;

//Solution 1
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 0) return 0;
//         if (n == 1) return nums[0];
//         int m = nums[0], curr = 0;
//         for (int i = 0; i < n; i++) {
//             if (curr < 0) curr = 0;
//             curr += nums[i];
//             if (curr > m) {
//                 m = curr;
//             }
//         }
//         return m; 
//     }
// };


//Solution 2: Kadane's algo
class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int n = nums.size();
            int m = nums[0], curr_best = nums[0];
            for(int i = 1; i < n; i++) {
                curr_best = max(nums[i], nums[i] + curr_best);
                if (curr_best > m) { 
                    m = curr_best;
                }
            }
            return m;
        }
};