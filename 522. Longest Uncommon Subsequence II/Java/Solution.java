public class Solution {
    public int findLUSlength(String[] strs) {
        class Utils {
            boolean isSubsequence(String a, String b) {
                int i = 0;
                for (char letter : b.toCharArray()) {
                    if (letter == a.charAt(i)) {
                        i++;
                        if (i == a.length()) {
                            return true;
                        }
                    }
                }
                return false;
            }
        }
        Utils utils = new Utils();
        int result = -1;
        for (int i = 0; i < strs.length; i++) {
            boolean flag = true;
            for (int j = 0; j < strs.length; j++) {
                if (i != j && utils.isSubsequence(strs[i], strs[j])) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                result = Math.max(result, strs[i].length());
            }
        }
        return result;
    }
}