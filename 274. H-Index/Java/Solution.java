public class Solution {
    public int hIndex(int[] citations) {
        int length = citations.length;
        int[] counts = new int[length + 1];
        for (int citation : citations) {
            if (citation >= length) {
                counts[length]++;
            } else {
                counts[citation]++;
            }
        }
        int paperSum = 0;
        for (int i = counts.length - 1; i >= 0; i--) {
            paperSum += counts[i];
            if (paperSum >= i) {
                return i;
            }
        }
        return 0;
    }
}