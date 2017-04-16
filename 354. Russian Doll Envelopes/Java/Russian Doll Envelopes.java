public class Solution {
    public int maxEnvelopes(int[][] envelopes) {
        Arrays.sort(envelopes, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if (o1[0] != o2[0]) {
                    return o1[0] - o2[0];
                }
                return o2[1] - o1[1];
            }
        });
        int[] dp = new int[envelopes.length];
        int currentLength = 0;
        for (int[] envelope : envelopes) {
            int low = 0;
            int high = currentLength;
            int value = envelope[1];
            while (low < high) {
                int mid = (low + high) / 2;
                if (dp[mid] == value) {
                    low = mid;
                    break;
                }
                if (dp[mid] < value) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }
            dp[low] = value;
            if (low == currentLength) {
                currentLength++;
            }
        }
        return currentLength;
    }
}