public class Solution {
    public int nthUglyNumber(int n) {
        int index2 = -1, index3 = -1, index5 = -1;
        int[] ugly = new int[n];
        int factor2 = 1, factor3 = 1, factor5 = 1;
        for (int i = 0; i < n; i++) {
            ugly[i] = Math.min(Math.min(factor2, factor3), factor5);
            if (ugly[i] == factor2) {
                index2++;
                factor2 = ugly[index2] * 2;
            }
            if (ugly[i] == factor3) {
                index3++;
                factor3 = ugly[index3] * 3;
            }
            if (ugly[i] == factor5) {
                index5++;
                factor5 = ugly[index5] * 5;
            }
        }
        return ugly[n - 1];
    }
}