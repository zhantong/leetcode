public class Solution {
    public int superPow(int a, int[] b) {
        class Utils {
            int pow(int a, int n, int base) {
                a %= base;
                int result = 1;
                for (int i = 0; i < n; i++) {
                    result = (result * a) % base;
                }
                return result;
            }

            int pow(int a, int[] b, int index) {
                if (index == -1) {
                    return 1;
                }
                int base = 1337;
                return pow(pow(a, b, index - 1), 10, base) * pow(a, b[index], base) % base;
            }
        }
        Utils utils = new Utils();
        return utils.pow(a, b, b.length - 1);
    }
}