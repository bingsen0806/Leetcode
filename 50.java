class Solution {
    public static final double epsilon = 1e-10;
    
    public double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n < 0) {
             return 1/x * myPow(1/x, -(n + 1)); // prevent overflow
        }
        return (n%2 == 0) ? myPow(x*x, n/2) : x*myPow(x*x, n/2);
    }
}
