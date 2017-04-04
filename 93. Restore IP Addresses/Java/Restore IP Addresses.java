public class Solution {
    public List<String> restoreIpAddresses(String s) {
        class Utils {
            void backTrack(String s, List<String> result, String current, int index, int count) {
                if (count > 4) {
                    return;
                }
                if (count == 4 && index == s.length()) {
                    result.add(current.substring(0, current.length() - 1));
                } else if (count < 4) {
                    for (int i = 0; i < 3; i++) {
                        if (index + i >= s.length()) {
                            break;
                        }
                        String sub = s.substring(index, index + i + 1);
                        if (Integer.parseInt(sub) >= 256 || (sub.charAt(0) == '0' && sub.length() > 1)) {
                            continue;
                        }
                        backTrack(s, result, current + sub + ".", index + i + 1, count + 1);
                    }
                }
            }
        }
        List<String> result = new ArrayList<>();
        Utils utils = new Utils();
        utils.backTrack(s, result, "", 0, 0);
        return result;
    }
}