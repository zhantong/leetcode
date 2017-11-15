class Solution {
    public int[][] imageSmoother(int[][] M) {
        int m = M.length;
        int n = M[0].length;
        int[][] result = new int[m][n];
        int[] range = new int[] {-1, 0, 1};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int current = 0;
                int count = 0;
                for (int a : range) {
                    for (int b : range) {
                        int row = i + a;
                        int col = j + b;
                        if (row >= 0 && row < m && col >= 0 && col < n) {
                            current += M[row][col];
                            count++;
                        }
                    }
                }
                result[i][j] = (int) Math.floor((double) current / count);
            }
        }
        return result;
    }
}