public class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        class Utils {
            int gcd(int x, int y) {
                while (y != 0) {
                    int temp = y;
                    y = x % y;
                    x = temp;
                }
                return x;
            }
        }
        if (x + y < z) {
            return false;
        }
        if (x == z || y == z || x + y == z) {
            return true;
        }
        Utils utils = new Utils();
        return z % utils.gcd(x, y) == 0;
    }
}