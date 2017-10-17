public class Solution {
    public boolean isHappy(int n) {
        Set<Integer> got = new HashSet<>();
        while (n != 1 && !got.contains(n)) {
            got.add(n);
            int sum = 0;
            while (n != 0) {
                sum += Math.pow(n % 10, 2);
                n /= 10;
            }
            n = sum;
        }
        return n == 1;
    }
}