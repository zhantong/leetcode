public class Solution {
    public List<List<Integer>> updateMatrix(List<List<Integer>> matrix) {
        Queue<int[]> queue = new ArrayDeque<>();
        int m = matrix.size();
        int n = matrix.get(0).size();
        int MAX_VALUE = m + n;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix.get(i).get(j) == 1) {
                    matrix.get(i).set(j, MAX_VALUE);
                } else {
                    queue.add(new int[] {i, j});
                }
            }
        }
        int current = 1;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int k = 0; k < size; k++) {
                int[] coord = queue.poll();
                int i = coord[0];
                int j = coord[1];
                if (i > 0 && matrix.get(i - 1).get(j) == MAX_VALUE) {
                    matrix.get(i - 1).set(j, current);
                    queue.add(new int[] {i - 1, j});
                }
                if (i < m - 1 && matrix.get(i + 1).get(j) == MAX_VALUE) {
                    matrix.get(i + 1).set(j, current);
                    queue.add(new int[] {i + 1, j});
                }
                if (j > 0 && matrix.get(i).get(j - 1) == MAX_VALUE) {
                    matrix.get(i).set(j - 1, current);
                    queue.add(new int[] {i, j - 1});
                }
                if (j < n - 1 && matrix.get(i).get(j + 1) == MAX_VALUE) {
                    matrix.get(i).set(j + 1, current);
                    queue.add(new int[] {i, j + 1});
                }
            }
            current++;
        }
        return matrix;
    }
}