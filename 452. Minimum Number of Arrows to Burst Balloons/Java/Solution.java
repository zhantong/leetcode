public class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[1] - o2[1];
            }
        });
        long currentStart = Long.MIN_VALUE;
        int result = 0;
        for (int[] point : points) {
            if (point[0] > currentStart) {
                currentStart = point[1];
                result += 1;
            }
        }
        return result;
    }
}