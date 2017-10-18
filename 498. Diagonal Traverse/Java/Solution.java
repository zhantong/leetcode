public class Solution {
    public int[] findDiagonalOrder(int[][] matrix) {
        if (matrix.length == 0) {
            return new int[] {};
        }
        int m = matrix.length - 1;
        int n = matrix[0].length - 1;
        int i = 0;
        int j = 0;
        int[] result = new int[(m + 1) * (n + 1)];
        result[0] = matrix[0][0];
        int index = 1;
        while (i != m || j != n) {
            if ((i + j) % 2 == 0) {
                if (i == 0 && j < n) {
                    j++;
                } else if (j == n) {
                    i++;
                } else {
                    i--;
                    j++;
                }
            } else {
                if (i < m && j == 0) {
                    i++;
                } else if (i == m) {
                    j++;
                } else {
                    i++;
                    j--;
                }
            }
            result[index++] = matrix[i][j];
        }
        return result;
    }
}