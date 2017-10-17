public class Solution {
    public int getMoneyAmount(int n) {
        class Utils {
            int getMoney(int start, int end, int[][] memory) {
                if (start >= end) {
                    return 0;
                }
                if (memory[start][end] != 0) {
                    return memory[start][end];
                }
                int result = Integer.MAX_VALUE;
                for (int i = start; i <= end; i++) {
                    int current = i + Math.max(getMoney(start, i - 1, memory), getMoney(i + 1, end, memory));
                    result = Math.min(result, current);
                }
                memory[start][end] = result;
                return result;
            }
        }
        int[][] memory = new int[n + 1][n + 1];
        Utils utils = new Utils();
        return utils.getMoney(1, n, memory);
    }
}