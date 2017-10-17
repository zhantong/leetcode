public class Solution {
    public int compareVersion(String version1, String version2) {
        String[] tokens1 = version1.split("\\.");
        String[] tokens2 = version2.split("\\.");
        int length1 = tokens1.length;
        int length2 = tokens2.length;
        for (int i = 0; i < Math.max(length1, length2); i++) {
            int inInt1 = i < length1 ? Integer.parseInt(tokens1[i]) : 0;
            int inInt2 = i < length2 ? Integer.parseInt(tokens2[i]) : 0;
            if (inInt1 > inInt2) {
                return 1;
            } else if (inInt1 < inInt2) {
                return -1;
            }
        }
        return 0;
    }
}