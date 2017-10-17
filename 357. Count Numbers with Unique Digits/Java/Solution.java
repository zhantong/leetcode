public class Solution {
    public int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }
        int[] map = new int[n + 1];
        map[1] = 10;
        for (int i = 2; i <= n; i++) {
            int count = 9;
            for (int j = 9 - i + 2; j < 10; j++) {
                count *= j;
            }
            map[i] = map[i - 1] + count;
        }
        return map[n];
    }
}