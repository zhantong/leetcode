public class Solution {
    public int nthSuperUglyNumber(int n, int[] primes) {
        int[] factors = new int[primes.length];
        Arrays.fill(factors, 1);
        int[] indexes = new int[primes.length];
        Arrays.fill(indexes, -1);
        int[] ugly = new int[n];
        for (int i = 0; i < n; i++) {
            int theMin = Integer.MAX_VALUE;
            for (int factor : factors) {
                theMin = Math.min(theMin, factor);
            }
            ugly[i] = theMin;
            for (int j = 0; j < factors.length; j++) {
                if (ugly[i] == factors[j]) {
                    indexes[j]++;
                    factors[j] = ugly[indexes[j]] * primes[j];
                }
            }
        }
        return ugly[ugly.length - 1];
    }
}