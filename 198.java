// House Robber 
// DP
class Solution {
    //Bottom up solution
    public int rob(int[] nums) {
        if (nums.length == 1) return nums[0];
        if (nums.length == 2) return Math.max(nums[0], nums[1]);
        int[] dp = new int[nums.length + 1]; //denotes the max amount if must steal from index i, and optionally from left of i
        dp[0] = 0; dp[1] = nums[0]; dp[2] = Math.max(nums[0], nums[1]); 
        for (int i = 3; i <= nums.length; i++) {
            dp[i] = Math.max(dp[i-2] + nums[i-1], dp[i-3] + nums[i-2]);
        }
        return dp[nums.length];
    }
}