public class Solution {
    public int countPrimes(int n) {
        if (n < 2) {
            return 0;
        }
        boolean[] notPrimes = new boolean[n];
        notPrimes[0] = true;
        notPrimes[1] = true;
        for (int i = 2; i <= Math.sqrt(n); i++) {
            if (!notPrimes[i]) {
                for (int j = i * i; j < n; j += i) {
                    notPrimes[j] = true;
                }
            }
        }
        int count = 0;
        for (boolean notPrime : notPrimes) {
            if (!notPrime) {
                count++;
            }
        }
        return count;
    }
}