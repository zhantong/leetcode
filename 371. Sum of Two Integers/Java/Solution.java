public class Solution {
    public int getSum(int a, int b) {
        int sum = a ^ b;
        int part = a & b;
        while (part != 0) {
            int theA = sum;
            int theB = part << 1;
            sum = theA ^ theB;
            part = theA & theB;
        }
        return sum;
    }
}