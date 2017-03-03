public class Solution {
    public List<String> generateParenthesis(int n) {
        class Utils {
            void parenthesis(List<String> result, String current, int left, int right) {
                if (left == 0 && right == 0) {
                    result.add(current);
                } else if (left >= 0 && right >= left) {
                    parenthesis(result, current + "(", left - 1, right);
                    parenthesis(result, current + ")", left, right - 1);
                }
            }
        }
        List<String> result = new ArrayList<>();
        Utils utils = new Utils();
        utils.parenthesis(result, "", n, n);
        return result;
    }
}