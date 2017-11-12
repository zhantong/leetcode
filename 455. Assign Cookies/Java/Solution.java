public class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int i = 0;
        int count = 0;
        for (int item : g) {
            while (i < s.length && item > s[i]) {
                i++;
            }
            if (i == s.length) {
                break;
            }
            count++;
            i++;
        }
        return count;
    }
}