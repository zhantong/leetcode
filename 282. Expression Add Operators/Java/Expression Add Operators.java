public class Solution {
    public List<String> addOperators(String num, int target) {
        class Utils {
            void backTrace(String num, int target, int i, String current, List<String> result, long value, long prev) {
                if (i == num.length()) {
                    if (value == target) {
                        result.add(current);
                    }
                    return;
                }
                for (int j = i; j < num.length(); j++) {
                    if (j != i && num.charAt(i) == '0') {
                        break;
                    }
                    String nowInStr = num.substring(i, j + 1);
                    long nowInInt = Long.parseLong(nowInStr);
                    if (i == 0) {
                        backTrace(num, target, j + 1, nowInStr, result, nowInInt, nowInInt);
                    } else {
                        backTrace(num, target, j + 1, current + "+" + nowInStr, result, value + nowInInt, nowInInt);
                        backTrace(num, target, j + 1, current + "-" + nowInStr, result, value - nowInInt, -nowInInt);
                        backTrace(num, target, j + 1, current + "*" + nowInStr, result, value - prev + prev * nowInInt, prev * nowInInt);
                    }
                }
            }
        }
        Utils utils = new Utils();
        List<String> result = new ArrayList<>();
        utils.backTrace(num, target, 0, "", result, 0, 0);
        return result;
    }
}