class Solution {
    public int largestPalindrome(int n) {
        if (n == 1) {
            return 9;
        }
        int max = (int) Math.pow(10, n) - 1;
        for (int i = max; i > max / 10; i--) {
            long current = Long.parseLong(String.valueOf(i) + new StringBuilder().append(i).reverse().toString());
            for (long item = max; item * item >= current; item--) {
                if (current % item == 0) {
                    return (int)(current % 1337);
                }
            }
        }
        return 0;
    }
}