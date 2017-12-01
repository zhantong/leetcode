class Solution {
    public int numberOfBoomerangs(int[][] points) {
        int result = 0;
        for (int[] pointA : points) {
            Map<Integer, Integer> distances = new HashMap<>();
            for (int[] pointB : points) {
                int distance = (pointA[0] - pointB[0]) * (pointA[0] - pointB[0]) + (pointA[1] - pointB[1]) * (pointA[1] - pointB[1]);
                distances.put(distance, distances.getOrDefault(distance, 0) + 1);
            }
            for (int item : distances.values()) {
                result += item * (item - 1);
            }
        }
        return result;
    }
}