public class Solution {
    public int findPoisonedDuration(int[] timeSeries, int duration) {
        if (timeSeries.length == 0) {
            return 0;
        }
        int result = duration;
        int gain;
        for (int i = 1; i < timeSeries.length; i++) {
            result += duration;
            gain = duration - (timeSeries[i] - timeSeries[i - 1]);
            if (gain > 0) {
                result -= gain;
            }
        }
        return result;
    }
}