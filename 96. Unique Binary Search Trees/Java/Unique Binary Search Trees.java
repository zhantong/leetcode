public class Solution {
    public int numTrees(int n) {
        int[] results = new int[n + 1];
        results[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                results[i] += results[j] * results[i - j - 1];
            }
        }
        return results[n];
    }
}