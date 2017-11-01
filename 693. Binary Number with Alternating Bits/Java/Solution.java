class Solution {
    public boolean hasAlternatingBits(int n) {
        int last = n & 1;
        while (n != 0 && (n & 1) == last) {
            last = 1 - last;
            n >>= 1;
        }
        return n == 0;
    }
}