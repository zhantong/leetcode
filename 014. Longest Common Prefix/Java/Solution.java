public class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) {
            return "";
        }
        String firstStr = strs[0];
        int commonIndex = 0;
        while (true) {
            for (String str : strs) {
                if (str.length() == commonIndex || str.charAt(commonIndex) != firstStr.charAt(commonIndex)) {
                    return firstStr.substring(0, commonIndex);
                }
            }
            commonIndex++;
        }
    }
}