public class Solution {
    public int trapRainWater(int[][] heightMap) {
        if (heightMap.length == 0) {
            return 0;
        }
        PriorityQueue<int[]> heap = new PriorityQueue<>(new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[0] - o2[0];
            }
        });
        int m = heightMap.length;
        int n = heightMap[0].length;
        for (int i = 0; i < m; i++) {
            heap.offer(new int[] {heightMap[i][0], i, 0});
            heightMap[i][0] *= -1;
            heightMap[i][0] -= 1;
            heap.offer(new int[] {heightMap[i][n - 1], i, n - 1});
            heightMap[i][n - 1] *= -1;
            heightMap[i][n - 1] -= 1;
        }
        for (int j = 1; j < n - 1; j++) {
            heap.offer(new int[] {heightMap[0][j], 0, j});
            heightMap[0][j] *= -1;
            heightMap[0][j] -= 1;
            heap.offer(new int[] {heightMap[m - 1][j], m - 1, j});
            heightMap[m - 1][j] *= -1;
            heightMap[m - 1][j] -= 1;
        }
        int[][] steps = new int[][] {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int result = 0;
        while (!heap.isEmpty()) {
            int[] item = heap.poll();
            for (int[] step : steps) {
                int row = item[1] + step[0];
                int col = item[2] + step[1];
                if (row >= 0 && col >= 0 && row < m && col < n && heightMap[row][col] >= 0) {
                    result += Math.max(0, item[0] - heightMap[row][col]);
                    heap.offer(new int[] {Math.max(item[0], heightMap[row][col]), row, col});
                    heightMap[row][col] *= -1;
                    heightMap[row][col] -= 1;
                }
            }
        }
        return result;
    }
}