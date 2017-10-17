public class Solution {
    public int findKthNumber(int n, int k) {
        int current = 1;
        k -= 1;
        while (k > 0) {
            int steps = 0;
            long start = current;
            long end = start + 1;
            while (start <= n) {
                steps += Math.min(n + 1, end) - start;
                start *= 10;
                end *= 10;
            }
            if (steps <= k) {
                current++;
                k -= steps;
            } else {
                current *= 10;
                k--;
            }
        }
        return current;
    }
}