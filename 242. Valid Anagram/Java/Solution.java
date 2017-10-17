public class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }
        Map<Character, Integer> check = new HashMap<>();
        for (char item : s.toCharArray()) {
            if (!check.containsKey(item)) {
                check.put(item, 0);
            }
            check.put(item, check.get(item) + 1);
        }
        for (char item : t.toCharArray()) {
            if (!check.containsKey(item)) {
                return false;
            }
            check.put(item, check.get(item) - 1);
        }
        for (int item : check.values()) {
            if (item != 0) {
                return false;
            }
        }
        return true;
    }
}