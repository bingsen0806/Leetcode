#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> a;
        int product = 1;
        for (int i = 0; i < nums.size(); i++) {
            a.push_back(product);
            product *= nums[i];
        }
        product = 1;
        for (int i = nums.size()-1; i >= 0; i--) {
            a[i] *= product;
            product *= nums[i];
        }
        return a;
    }
};