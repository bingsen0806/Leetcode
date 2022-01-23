#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), l = 0, r = n-1;
        int rotateIdx = -1;
        if (nums[r] >= nums [0]) rotateIdx = 0;
        else {
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (nums[mid] > nums[mid + 1]) {
                    rotateIdx = mid + 1;
                    break;
                }
                if (nums[mid - 1] > nums[mid]) {
                    rotateIdx = mid;
                    break;
                }
                if (nums[mid] > nums[0]) l = mid + 1;
                else r = mid - 1;
            }
        }
        if (target >= nums[0]){
            l = 0, r = rotateIdx > 0 ? rotateIdx - 1: n-1;
            return binSearch(nums, l, r, target);
        } else {
            l = rotateIdx, r = n -1;
            return binSearch(nums, l, r, target);
        }
        return -1;
    }
    int binSearch(vector<int>& nums, int l, int r, int target) {
        while (l <= r) {
            if (nums[l] == target) return l;
            if (nums[r] == target) return r;
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
};

//Alternative Sollution with 1 while loop
// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int l = 0, r = nums.size()-1;
//         while (l <= r) {
//             int mid = (l+r) / 2;
//             if (target == nums[mid])
//                 return mid;
//             // there exists rotation; the middle element is in the left part of the array
//             if (nums[mid] > nums[r]) {
//                 if (target < nums[mid] && target >= nums[l])
//                     r = mid - 1;
//                 else
//                     l = mid + 1;
//             }
//             // there exists rotation; the middle element is in the right part of the array
//             else if (nums[mid] < nums[l]) {
//                 if (target > nums[mid] && target <= nums[r])
//                     l = mid + 1;
//                 else
//                     r = mid - 1;
//             }
//             // there is no rotation; just like normal binary search
//             else {
//                 if (target < nums[mid])
//                     r = mid - 1;
//                 else
//                     l = mid + 1;
//             }
//         }
//         return -1;
//     }
// };