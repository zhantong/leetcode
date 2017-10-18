class Solution {
    public String fractionAddition(String expression) {
        class Utils {
            int gcd(int x, int y) {
                return x != 0 ? gcd(y % x, x) : y;
            }

            String addition(String a, String b) {
                String[] partsA = a.split("/");
                String[] partsB = b.split("/");
                int up = Integer.parseInt(partsA[0]) * Integer.parseInt(partsB[1])
                         + Integer.parseInt(partsA[1]) * Integer.parseInt(partsB[0]);
                int down = Integer.parseInt(partsA[1]) * Integer.parseInt(partsB[1]);
                String sign = "";
                if (up < 0) {
                    sign = "-";
                    up *= -1;
                }
                return sign + (up / gcd(up, down)) + "/" + (down / gcd(up, down));
            }
        }
        String[] fractions = expression.split("(?=[-+])");
        String result = "0/1";
        Utils utils = new Utils();
        for (String fraction : fractions) {
            result = utils.addition(result, fraction);
        }
        return result;
    }
}