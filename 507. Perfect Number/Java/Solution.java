public class Solution {
    public boolean checkPerfectNumber(int num) {
        if (num == 1) {
            return false;
        }
        int result = 0;
        int i = 2;
        while (i * i <= num) {
            if (num % i == 0) {
                result += i;
                result += num / i;
            }
            i++;
        }
        result++;
        return result == num;
    }
}