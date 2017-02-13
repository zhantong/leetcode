public class Solution {
    public int findContentChildren(int[] g, int[] s) {
        if (g.length == 0 || s.length == 0) {
            return 0;
        }
        Arrays.sort(g);
        Arrays.sort(s);
        int satisfyCount = 0;
        int lastIndex = s.length - 1;
        for (int i = g.length - 1; i >= 0; i--) {
            if (g[i] <= s[lastIndex]) {
                lastIndex--;
                satisfyCount++;
                if (lastIndex < 0) {
                    break;
                }
            }
        }
        return satisfyCount;
    }
}