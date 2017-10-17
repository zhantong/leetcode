public class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix.length == 0) {
            return false;
        }
        int i = 0;
        int j = matrix[0].length - 1;
        while (i < matrix.length && j >= 0) {
            int current = matrix[i][j];
            if (current == target) {
                return true;
            } else if (current > target) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
}