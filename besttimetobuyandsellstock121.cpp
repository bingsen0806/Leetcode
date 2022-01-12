#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int m = 0, curr = 0;
        for (int i = 1; i < n; i++) {
            curr += prices[i] - prices[i-1];
            if (curr < 0) curr = 0;
            if (curr > m) {
                m = curr;
            }
        }
        return m;
    }
};