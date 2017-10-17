public class Solution {
    public List<List<String>> partition(String s) {
        class Utils {
            boolean isPalindrome(String s) {
                int i = 0;
                int j = s.length() - 1;
                while (i < j) {
                    if (s.charAt(i) != s.charAt(j)) {
                        return false;
                    }
                    i++;
                    j--;
                }
                return true;
            }

            void part(String s, List<List<String>> result, List<String> current) {
                if (s.isEmpty()) {
                    result.add(new ArrayList<>(current));
                    return;
                }
                for (int i = 1; i <= s.length(); i++) {
                    String front = s.substring(0, i);
                    if (isPalindrome(front)) {
                        current.add(front);
                        part(s.substring(i), result, current);
                        current.remove(current.size() - 1);
                    }
                }
            }
        }
        List<List<String>> result = new ArrayList<>();
        Utils utils = new Utils();
        utils.part(s, result, new ArrayList<>());
        return result;
    }
}