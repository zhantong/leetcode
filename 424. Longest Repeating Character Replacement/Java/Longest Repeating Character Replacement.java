public class Solution {
    public int characterReplacement(String s, int k) {
        int result = 0;
        int[] counts = new int[128];
        int leftIndex = 0;
        int currentMax = 0;
        for (int rightIndex = 0; rightIndex < s.length(); rightIndex++) {
            char letter = s.charAt(rightIndex);
            counts[letter]++;
            currentMax = Math.max(currentMax, counts[letter]);
            while (rightIndex - leftIndex + 1 - currentMax > k) {
                counts[s.charAt(leftIndex)]--;
                leftIndex++;
            }
            result = Math.max(result, rightIndex - leftIndex + 1);
        }
        return result;
    }
}