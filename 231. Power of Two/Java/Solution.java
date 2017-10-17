public class Solution {
    public boolean isPowerOfTwo(int n) {
        return n > 0 && 0x80000000 % n == 0;
    }
}