public class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> result = new ArrayList<>();
        if (matrix.length == 0) {
            return result;
        }
        int m = matrix.length;
        int n = matrix[0].length;
        int left = 0;
        int right = n;
        int up = 0;
        int down = m;
        while (left < right && up < down) {
            for (int j = left; j < right; j++) {
                result.add(matrix[up][j]);
            }
            up++;
            if (up == down) {
                break;
            }
            for (int i = up; i < down; i++) {
                result.add(matrix[i][right - 1]);
            }
            right--;
            if (right == left) {
                break;
            }
            for (int j = right - 1; j >= left; j--) {
                result.add(matrix[down - 1][j]);
            }
            down--;
            if (down == up) {
                break;
            }
            for (int i = down - 1; i >= up; i--) {
                result.add(matrix[i][left]);
            }
            left++;
            if (left == right) {
                break;
            }
        }
        return result;
    }
}