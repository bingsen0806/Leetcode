// Unique Paths
// Math, DP
class Solution {
    //Math: (m+n-2)!/((m-1)! * (n-1)!)
    public int uniquePaths(int m, int n) {
        m--;
        n--;
        if(m < n) { // Swap, so that m is the bigger number
            int temp = m;
            m = n;
            n = temp;
        }
        long res = 1;
        int j = 1;
        for(int i = m+1; i <= m+n; i++, j++){
            res *= i;
            res /= j;
        }
            
        return (int)res;
    }
}
