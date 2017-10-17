public class Solution {
    public int hammingDistance(int x, int y) {
        int count = 0;
        int xor = x ^ y;
        while (xor != 0) {
            xor &= (xor - 1);
            count++;
        }
        return count;
    }
}