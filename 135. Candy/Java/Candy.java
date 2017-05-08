public class Solution {
    public int candy(int[] ratings) {
        int length = ratings.length;
        int[] counts = new int[length];
        Arrays.fill(counts, 1);
        for (int i = 1; i < length; i++) {
            if (ratings[i] > ratings[i - 1]) {
                counts[i] = counts[i - 1] + 1;
            }
        }
        for (int i = length - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                counts[i] = Math.max(counts[i], counts[i + 1] + 1);
            }
        }
        int result = 0;
        for (int count : counts) {
            result += count;
        }
        return result;
    }
}