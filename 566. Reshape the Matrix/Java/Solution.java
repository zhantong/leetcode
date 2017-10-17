public class Solution {
    public int[][] matrixReshape(int[][] nums, int r, int c) {
        if (nums.length == 0) {
            return nums;
        }
        int m = nums.length;
        int n = nums[0].length;
        if (m * n < r * c) {
            return nums;
        }
        int[][] newNums = new int[r][c];
        for (int i = 0; i < r * c; i++) {
            newNums[i / c][i % c] = nums[i / n][i % n];
        }
        return newNums;
    }
}