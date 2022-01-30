// Combination Sum IV
// DP
class Solution {
    public int combinationSum4(int[] nums, int target) {
        int[] dp = new int[target + 1];
        dp[0] = 1;
        for (int sum = 1; sum <=target; sum++) {
            boolean reachable = false;
            for (int number: nums) {
                if (number > sum) continue;
                if (dp[sum-number] != -1) {
                    reachable = true;
                    dp[sum] += dp[sum-number];
                }
            }
            if (!reachable) dp[sum] = -1;
        }
        return dp[target] == -1 ? 0 : dp[target];
    }
}
