public class Solution {
    public int integerBreak(int n) {
        switch (n) {
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 4;
        default:
            int result = 1;
            while (n > 4) {
                n -= 3;
                result *= 3;
            }
            switch (n) {
            case 4:
                result *= 4;
                break;
            case 3:
                result *= 3;
                break;
            case 2:
                result *= 2;
                break;
            }
            return result;
        }
    }
}