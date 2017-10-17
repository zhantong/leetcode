public class Solution {
    public int maxSumSubmatrix(int[][] matrix, int k) {
        int m = matrix.length;
        int n = matrix[0].length;
        int result = Integer.MIN_VALUE;
        for (int colStart = 0; colStart < n; colStart++) {
            int[] current = new int[m];
            for (int colEnd = colStart; colEnd < n; colEnd++) {
                for (int i = 0; i < m; i++) {
                    current[i] += matrix[i][colEnd];
                }
                TreeSet<Integer> sums = new TreeSet<>();
                sums.add(0);
                int currentSum = 0;
                for (int item : current) {
                    currentSum += item;
                    int target = currentSum - k;
                    Integer get = sums.ceiling(target);
                    if (get != null) {
                        result = Math.max(result, currentSum - get);
                    }
                    sums.add(currentSum);
                }
            }
        }
        return result;
    }
}