public class Solution {
    public int lastRemaining(int n) {
        class Utils {
            int leftToRight(int n) {
                if (n == 1) {
                    return n;
                }
                return 2 * rightToLeft(n / 2);
            }

            int rightToLeft(int n) {
                if (n == 1) {
                    return n;
                }
                if (n % 2 == 1) {
                    return 2 * leftToRight(n / 2);
                }
                return 2 * leftToRight(n / 2) - 1;
            }
        }
        Utils utils = new Utils();
        return utils.leftToRight(n);
    }
}