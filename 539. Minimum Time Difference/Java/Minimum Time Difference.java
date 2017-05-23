public class Solution {
    public int findMinDifference(List<String> timePoints) {
        if (timePoints.size() > 1440) {
            return 0;
        }
        int[] buckets = new int[1440];
        for (String point : timePoints) {
            int minutes = Integer.parseInt(point.substring(0, 2)) * 60 + Integer.parseInt(point.substring(3));
            buckets[minutes]++;
            if (buckets[minutes] > 1) {
                return 0;
            }
        }
        int result = Integer.MAX_VALUE;
        int prev = -1440;
        for (int i = 0; i < buckets.length; i++) {
            if (buckets[i] != 0) {
                result = Math.min(result, i - prev);
                prev = i;
            }
        }
        for (int i = 0; i < buckets.length; i++) {
            if (buckets[i] != 0) {
                result = Math.min(result, 1440 + i - prev);
                break;
            }
        }
        return result;
    }
}