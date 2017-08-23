public class Solution {
    public int maxCount(int m, int n, int[][] ops) {
        int resultM = m;
        int resultN = n;
        for (int[] op : ops) {
            resultM = Math.min(resultM, op[0]);
            resultN = Math.min(resultN, op[1]);
        }
        return resultM * resultN;
    }
}